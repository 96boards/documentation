---
title: Booting Linux Kernel using U-Boot
permalink: /documentation/consumer/hikey/hikey620/guides/booting-linux-kernel-using-uboot.md.html
---

# Booting Linux Kernel using U-Boot

This guide provides instructions for loading Linux Kernel from SD card using
Das U-Boot (Universal Bootloader)

# Table of Contents

- [1) U-Boot](#1-u-boot)
    - [1.1) Building and Flashing U-Boot](#11-building-and-flashing-u-boot)
- [2) Booting Linux Kernel](#2-booting-linux-kernel)
    - [2.1) Preparing uImage](#21-preparing-uImage)
    - [2.2) Flashing Debian Root File System](#22-flashing-debian-root-file-system)
- [3) Booting Linux using U-Boot](#3-booting-linux-using-u-boot)

***

# 1) U-Boot

U-Boot allows loading Linux Kernel from different file systems like FAT32, EXT4 etc... This allows us to place
the kernel image and RFS (Root File System) on to SD card and eMMC for booting.

## 1.1) Building and Flashing U-Boot

The native U-Boot support for HiKey doesn't directly allows to fetch kernel and device tree blob from
any storage medium, it needs a bit of work to be done on the U-Boot command line.

First, Build and Flash U-Boot onto HiKey from below tree using the instructions provided
in the [README](https://git.denx.de/?p=u-boot.git;a=blob_plain;f=board/hisilicon/hikey/README;hb=HEAD).

**U-Boot Tree:** https://github.com/Mani-Sadhasivam/u-boot
**Branch:** hikey_mmc_fix

# 2) Booting Linux Kernel

Following instructions provides information about booting Linux kernel along with
Debian distro from U-Boot.

## 2.1) Preparing uImage

Linux kernel needs to be complied and placed onto the SD card in order to allow U-Boot to load it. For
compiling Linux kernel, refer this [guide](https://github.com/96boards/documentation/blob/master/consumer/hikey/hikey620/build/linux-kernel.md).
After compilation, generate U-Boot compatible Linux Image using `mkimage` utility.

```shell
$ sudo apt-get install u-boot-tools
$ mkimage -A arm64 -O linux -C none -T kernel -a 0x00080000 -e 0x00080000 -n HiKey -d arch/arm64/boot/Image uImage
```
> Note: *arch/arm64/boot/Image* is inside the kernel directory

Once the image has been created successfully, you should get something similar to following output

```
Image Name:   HiKey
Created:      Thu Dec 20 19:05:49 2018
Image Type:   AArch64 Linux Kernel Image (uncompressed)
Data Size:    20699648 Bytes = 20214.50 kB = 19.74 MB
Load Address: 00080000
Entry Point:  00080000
```
Now, copy the generated **uImage** and **hi6220-hikey.dtb** to FAT32 partition in SD card.

```shell
$ sudo cp uImage /path/to/sd
$ sudo cp arch/arm64/boot/dts/hisilicon/hi6220-hikey.dtb /path/to/sd
```
> Note: Replace /path/to/sd with the path of SD card's FAT32 partition.

## 2.2) Flashing Debian Root File System

Now, flash the pre built Debian Root File System onto the eMMC as per [Installation Guide](https://github.com/96boards/documentation/blob/master/consumer/hikey/hikey620/installation/linux-fastboot.md#step-3-install-operating-system-update-using-downloaded-files).

> Note: By default, Root File System will be flashed into 9th partition of eMMC

# 3) Booting Linux using U-Boot

Now, insert the SD card onto HiKey and power on the board. By default, boot will stop
at the U-Boot prompt. From there, enter below commands to boot Linux Kernel with Debian
Root File System.

```shell
=> setenv bootargs 'console=ttyAMA3,115200 root=/dev/mmcblk0p9'
=> load mmc 1:1 $kernel_addr_r uImage
=> load mmc 1:1 $fdt_addr_r hi6220-hikey.dtb
=> bootm $kernel_addr_r - $fdt_addr_r
```

The above commands will fetch uImage and DTB from SD card and loads onto RAM. Finally, it
boots Linux kernel with console and root information passed via `bootargs`.
