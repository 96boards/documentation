---
title: Build & Update Linux kernel for Debian/OpenEmbedded
permalink: /documentation/consumer/dragonboard/dragonboard410c/build/kernel/
redirect_from: /documentation/consumer/dragonboard410c/build/kernel/
---

# Build & Update Linux kernel for Debian/OpenEmbedded

This page provides the instructions for building and deploying linux kernel
on Dragonboard410c from x86 host machine.

##### Prerequisites:
- A Linux OS (debian, openembedded...) already running on the Dragonboard410c (emmc).

#### 1. Download GNU cross-toolchain binaries.
You need to download the correct GCC toolchain depending your host/target architecture. Usually host is a standard Intel x86-64 computer, target is the Dragonboard which is AARCH64. <a href="https://www.linaro.org/downloads"> Linaro </a>  provides linux host binaries.
```shell
       $ mkdir toolchain
       $ wget releases.linaro.org/components/toolchain/binaries/latest-7/aarch64-linux-gnu/gcc-*-x86_64_aarch64-linux-gnu.tar.xz
       $ tar -xf gcc-*-x86_64_aarch64-linux-gnu.tar.xz -C ./toolchain --strip-components=1
```

#### 2. Install Required Packages

The following command installs packages which are required to build the
kernel on Debian based systems:

```shell
$ sudo apt-get install git build-essential kernel-package fakeroot libncurses5-dev libssl-dev ccache
```

> Note: For other distributions, try installing the development packages needed to build a native kernel.

#### 3. Get Linux Kernel source

- ##### Clone Qualcomm landing team linux repository
  ```shell
     $ git clone http://git.linaro.org/landing-teams/working/qualcomm/kernel.git
  ```

- ##### Checkout the release branch you're interested in
  ```shell
    $ cd kernel
    $ git checkout origin/release/qcomlt-4.14 -b my-custom-4.14
  ```

  [optional] Customize kernel source/config or edit the device tree (arch/arm64/boot/dts/qcom/apq8016-sbc.dtsi).

#### 4. Build Linux kernel
- ##### Set compilation environment variables
 ```shell
    $ export ARCH=arm64
    $ export CROSS_COMPILE=`pwd`/../toolchain/bin/aarch64-linux-gnu-
 ```
- ##### Generate Linux kernel config file
 ```shell
    $ make defconfig distro.config
 ```
- ##### Make kernel
 ```shell
    $ make -j$(nproc) Image.gz dtbs
    $ make -j$(nproc) modules
 ```

Make command generates the **kernel** (arch/$(ARCH)/boot/Image.gz) itself (as a compressed image), the **kernel modules**(in-tree) and the **device-tree blob** (arch/$(ARCH)/boot/dts/qcom/apq8016-sbc.dtb).


#### 5. Generate and flash new Dragonboard boot image (abootimg)
The kernel image and DTB file need to be packed into an Android boot image. Such image can be generated with abootimg tool.

- ##### Install abootimg
  ```shell
  $ sudo apt-get install abootimg
  ```

- ##### Build image
  ```shell
  # DTB has to be appended to the compressed kernel image:
  $ cat arch/$ARCH/boot/Image.gz arch/$ARCH/boot/dts/qcom/apq8016-sbc.dtb > Image.gz+dtb

  # abootimg requires a ramdisk, but we don't really use it, so create a dummy one:
  $ echo "not a ramdisk" > ramdisk.img

  # finally, generate the boot image (here our rootfs is located an mmcblk0p10 partition)
  $ abootimg --create boot-db410c.img -k Image.gz+dtb -r ramdisk.img \
             -c pagesize=2048 -c kerneladdr=0x80008000 -c ramdiskaddr=0x81000000 \
             -c cmdline="root=/dev/mmcblk0p10 rw rootwait console=tty0 console=ttyMSM0,115200n8"
  ```
- ##### Flash image
  Use fastboot to flash the new boot image.
  ```shell
  $ fastboot flash boot boot-db410c.img
  ```
You should then be able on your kernel.

#### 6. Install modules

Kernel modules typically live on rootfs in /lib/modules. These modules need to be aligned/compatible with the kernel version. If you updated the kernel you probably have a new release, therefore current modules will no be loaded. You can check loaded modules with **lsmod** command and your kernel release/version with **uname -r**.

- ##### Generate module directory
  ```shell
  # In kernel directory
  $ mkdir db410c-modules
  $ make modules_install INSTALL_MOD_PATH=./db410c-modules
  ```
All modules are installed in db410c-modules directory (e.g. db410c-modules/lib/modules/4.14.0-00132-ge3e0a10). You need to copy this directory to /lib/modules on dragonboard. You can perform this transfer either via USB key, SD Card or network.

Your board is now updated with the new kernel, modules and DTB.
