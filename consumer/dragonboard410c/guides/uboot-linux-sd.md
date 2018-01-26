---
title: Instructions for loading Linux Kernel from SD card using U-Boot
permalink: /documentation/consumer/dragonboard410c/guides/uboot-linux-sd.md.html
redirect_from:
- /db410c-getting-started/Guides/uboot-linux-sd.md/
-  /documentation/ConsumerEdition/DragonBoard-410c/Guides/uboot-linux-sd.md.html
---

# Instructions for loading Linux Kernel from SD card using U-Boot

This document provides instructions for loading Linux Kernel from SD card using Das U-Boot (Universal Bootloader)

# Table of Contents

- [1) U-Boot](#1-uboot)
    - [1.1) Building and Flashing U-Boot](#11-building-and-flashing-uboot)
- [2) Booting Linux Kernel](#2-booting-linux-kernel)
    - [2.1) Preparing SD card](#21-preparing-sd-card)
    - [2.2) Booting Linux using U-Boot](#23-booting-linux-using-uboot)

 ***

# 1) U-Boot

U-Boot allows loading Linux Kernel from different file systems like FAT32, EXT4 etc... This allows us to place
the kernel image and RFS (Root File System) on to SD card for booting.

## 1.1) Building and Flashing U-Boot

The native U-Boot support for Dragonboard410c doesn't directly allows to fetch kernel and device tree blob from
SD card, it needs a bit of work to be done on the U-Boot command line. In order to eliminate this overhead, SD
boot support has been added to the custom U-Boot tree.

The following instructions allows to build and deploy patched version of U-Boot onto Dragonboard410c using Linux host.

```shell
$ git clone https://github.com/Mani-Sadhasivam/u-boot.git
$ cd u-boot
$ git checkout db410c
$ export ARCH=arm
$ export CROSS_COMPILE=<path to your GCC cross compiler>/aarch64-linux-gnu-
$ make dragonboard410c_config
$ make -j2
```
Generate fake init ramdisk

```shell
$ touch rd
```
Get **dtbTool** and **mkbootimg** from **skales** git tree

```shell
$ git clone git://codeaurora.org/quic/kernel/skales
```
Create device tree table from generated DTB's

```shell
$ ./skales/dtbTool -o dt.img arch/arm/dts
```
Generate boot image compatible with LK (Second stage bootloader)

```shell
$ ./skales/mkbootimg --kernel=u-boot-dtb.bin --output=u-boot.img --dt=dt.img  \
  --pagesize 2048 --base 0x80000000 --ramdisk=rd --cmdline=""
```
Flash the generated boot image onto Dragonboard using Fastboot method

```shell
$ sudo fastboot flash boot u-boot.img
```
> Note: Instructions on getting Dragonboard into fastboot mode is provided
[here](https://github.com/96boards/documentation/blob/master/ConsumerEdition/DragonBoard-410c/Installation/LinuxFastboot.md#step-3-boot-dragonboard-410c-into-fastboot-mode)

# 2) Booting Linux Kernel

Follwing instructions provides information about booting Linux kernel along with OE based distribution from U-Boot

## 2.1) Preparing SD card

SD card needs to be partitioned into ext4 filesystem for placing RFS and kernel image into it. Ideally, RFS should be
placed in etx4 filesystem and kernel image should be in FAT based filesystem. But, for simplicity we can place kernel
image inside RFS.

Partition SD card using any of the available disk utility like gparted, gdisk etc... It is mandatory to have etx4 as the
first partition and of size >=500MB.

Then, prebuilt RFS should be flashed on to the SD card.

```shell
$ wget http://builds.96boards.org/snapshots/reference-platform/openembedded/morty/dragonboard-410c/rpb/latest/rpb-desktop-image-dragonboard-410c-*.rootfs.ext4.gz
$ gunzip rpb-desktop-image-dragonboard-410c-XXX.rootfs.ext4.gz
$ sudo dd if=rpb-desktop-image-dragonboard-410c-XXX.rootfs.ext4 of=/dev/sdx1 bs=4M
```
> Note:
> 1. Replace XXX in rpb-desktop-image-dragonboard-410c-XXX.rootfs.img with the image revision
> 2. Replace sdx1 with SD card's first partition

After flashing, ext4 partition should have populated with Linux Root File System.

## 2.2) Booting Linux using U-Boot

Now, Linux kernel needs to be complied and placed onto the SD card in order to allow U-Boot to load it. For
compiling Linux kernel, refer release notes [here](http://builds.96boards.org/releases/dragonboard410c/linaro/debian/latest/).
After compilation, generate U-Boot compatible Linux Image.

```shell
$ sudo apt-get install u-boot-tools
$ mkimage -A arm64 -O linux -C none -T kernel -a 0x80080000 -e 0x80080000 -n Dragonboard -d arch/arm64/boot/Image uImage
```
> Note: *arch/arm64/boot/Image* is inside the kernel directory

Once the image has been created successfully, you should get something similar to following output

```
Image Name:   Dragonboard
Created:      Sat Jul 29 15:15:27 2017
Image Type:   AArch64 Linux Kernel Image (uncompressed)
Data Size:    17349120 Bytes = 16942.50 kB = 16.55 MB
Load Address: 80080000
Entry Point:  80080000
```
Copy generated **uImage** and **apq8016-sbc.dtb** to */boot* directory in SD card.

```shell
$ sudo cp uImage /path/to/boot
$ sudo cp arch/arm64/boot/dts/qcom/apq8016-sbc.dtb /path/to/boot
```
> Note:
> 1. Replace /path/to/boot with the path of *boot* directory in SD card's ext4 partition.
> 2. Additionally, kernel modules can also be built and place onto */lib* directory in SD card which is optional.

Next, **uEnv.txt** file needs to be placd in the */boot* partiton. So, create a file called **uEnv.txt** in */boot*
partition and paste the following contents to it.

```
bootargs=root=/dev/mmcblk1p1 rw rootwait console=tty0 console=ttyMSM0,115200n8 rootfs=ext4 noinitrd selinux=0
bootcmd=ext4load mmc 1:1 ${kernel_addr_r} /boot/uImage; ext4load mmc 1:1 ${fdt_addr_r} /boot/apq8016-sbc.dtb; bootm ${kernel_addr_r} - ${fdt_addr_r}
uenvcmd=run bootcmd
```
Once the above mentioned steps are completed successfully, remove SD card from host and insert into Dragonboard410c and apply
power. U-Boot will import environment variables from uEnv.txt and automatically boots Linux kernel.
