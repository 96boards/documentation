---
title: Build & Update Linux kernel on Rock960
permalink: /documentation/consumer/rock/build/linux-kernel/
---

# Build & Update Linux kernel on Rock960

This page provides the instructions for building and deploying linux
kernel on Rock960 from x86 host machine.

## Prerequisites:
- A host machine with relevant OS to install cross compiler and packages (Preferrably Ubuntu/Debian)
- Rock960 Model AB/C

## Download GNU cross-toolchain binaries

You need to download the correct GCC toolchain on your host depending the
architecture. Usually host is a standard Intel x86-64 computer, target is
the Rock960 which is AARCH64. <a href="https://www.linaro.org/downloads"> Linaro </a>  provides linux host binaries.
```shell
       $ mkdir toolchain
       $ wget releases.linaro.org/components/toolchain/binaries/latest/aarch64-linux-gnu/gcc-*-x86_64_aarch64-linux-gnu.tar.xz
       $ tar -xf gcc-*-x86_64_aarch64-linux-gnu.tar.xz -C ./toolchain --strip-components=1
```

## Install packages

Install the required packages on host by following the instructions below:

```shell
$ sudo apt update
$ sudo apt install build-essential libncurses5-dev git make
```

## Get Linux Kernel Source

```shell
$ git clone https://github.com/96rocks/kernel.git
$ cd kernel
$ git checkout -t origin/rock960-4.4-dev
```

## Build the Linux Kernel

```shell
$ export ARCH=arm64
$ export CROSS_COMPILE=<path-to-cross-compiler>/aarch64-linux-gnu-
```
**Note:** Replace `path-to-cross-compiler` in the above command with the location
          where you have extracted the toolchain

```shell
$ make rockchip_linux_defconfig
$ make Image dtbs -j$(nproc)
```

After compilation, you should get the following files:

#### For Rock960 Model AB:

* arch/arm64/boot/Image
* arch/arm64/boot/dts/rockchip/rock960-model-ab-linux.dtb

#### For Rock960 Model C:

* arch/arm64/boot/Image
* arch/arm64/boot/dts/rockchip/rock960-model-c-linux.dtb

## Creating a Boot Image

Following instructions are used to build a boot image to be flashed
onto Rock960 board:

#### Clone Build Repo

```shell
$ git clone https://github.com/96rocks/build.git
```

#### Change the FDT Entry

Change the FDT entry in `build/extlinux/rk3399.conf` only if you are using
**Rock960 Model C** board. Otherwise skip this section.

```
    fdt /rock960-model-c-linux.dtb
```

#### Copy the Generated Images

```shell
$ mkdir out && cd out
$ mkdir kernel && cd kernel
```

Copy the built `Image` and `rock960-model-x-linux.dtb` files into it.

> Note: Replace `x` with model name `ab/c` in `rock960-model-x-linux.dtb`.

#### Build Boot Image

```shell
cd ../../build
./build/mk-image.sh -c rk3399 -t boot
```

At the end, you can find the `boot.img` in `out/`.

## Flash Boot image onto Rock960

Finally, the boot image can be flashed onto Rock960 as per the instructions
specified in the [installation guide](https://github.com/96boards/documentation/blob/master/consumer/rock/installation/linux-mac-rkdeveloptool.md#flash-by-partitions).
