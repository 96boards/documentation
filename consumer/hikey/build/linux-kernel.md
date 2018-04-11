---
title: Build & Update Linux kernel on HiKey
permalink: /documentation/consumer/hikey/build/linux-kernel.md.html
---

# Build & Update Linux kernel on HiKey
  
This page provides the instructions for building and deploying linux
kernel on HiKey from x86 host machine.

## Prerequisites:
- A host machine with relevant OS to install cross compiler and packages (Preferrably Ubuntu/Debian)
- A HiKey board running latest Debian release from Linaro


## Download GNU cross-toolchain binaries

You need to download the correct GCC toolchain on your host depending the
architecture. Usually host is a standard Intel x86-64 computer, target is
the HiKey which is AARCH64. <a href="https://www.linaro.org/downloads"> Linaro </a>  provides linux host binaries.
```shell
       $ mkdir toolchain
       $ wget releases.linaro.org/components/toolchain/binaries/latest/aarch64-linux-gnu/gcc-*-x86_64_aarch64-linux-gnu.tar.xz
       $ tar -xf gcc-*-x86_64_aarch64-linux-gnu.tar.xz -C ./toolchain --strip-components=1
```

## Install packages

Install the required packages on host by following the instructions below:

```shell
$ sudo apt update
$ sudo apt install build-essential fakeroot bc kmod cpio libssl-dev bison flex
```

## Get Linux Kernel Source

```shell
$ git clone https://github.com/suihkulokki/linux.git
$ git checkout -t origin/hikey-v4.15
```

## Build the Linux Kernel

```shell
$ export ARCH=arm64
$ export CROSS_COMPILE=<path-to-cross-compiler>/aarch64-linux-gnu-gcc-
```
> Note: Replace <path-to-cross-compiler> in the above command with the location
>       where you have extracted the toolchain

```shell
$ make defconfig distro.config
```
> Note: You can add any extra string to the kernel version by editing the
>       LOCALVERSION in generated .config file

```shell
$ make bindeb-pkg
```

After the compilation, in the directory one level above the kernel source tree,
you will get:

* linux-image-xxx.deb, a Debian package with the kernel and modules
* linux-headers-xxx.deb, a Debian package with kernel headers (not needed mostly)

## Installing the Kernel

Copy linux-image-xxx.deb file to your target device and install it by:

```shell
$ dpkg -i linux-image-xxx.deb
```
> Note: Replace xxx in the image name with the generated version string 

