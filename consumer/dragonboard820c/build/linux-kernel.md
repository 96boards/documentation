---
title: Building Linux Kernel for Dragonboard-820c
permalink: /documentation/consumer/dragonboard820c/build/linux-kernel.md.html
---

# Building Linux Kernel for Dragonboard-820c

Following instructions can be used to build Linux Kernel from source
for Dragonboard-820c.

## Cloning the Source

The Linux kernel used for DragonBoard 820c can be found in the
[Linaro Qualcomm Landing Team git repository](https://git.linaro.org/landing-teams/working/qualcomm/kernel.git).

There are two main relevant kernel branches that provide the support for this board.
1. `release` branches named as `release/qcomlt-x.y`
(the latest one being the most up-to-date/recent)  
1. the `integration-linux-qcomlt` branch, which is regularly rebased on recent mainline,
and is used by developers.

Using the `release` branch is recommended for most users. The development branch is meant to be used by kernel developers willing to contribute patch upstream.

Following commands can be used to fetch the latest kernel source:

```shell
$ git clone http://git.linaro.org/landing-teams/working/qualcomm/kernel.git
$ cd kernel
$ git checkout -t origin/release/qcomlt-x.y
```

> Note: Replace x and y with kernel major and minor release versions.

## Building the Kernel

After cloning and checking out the source, kernel can be built by the following
commands:

```shell
$ cd kernel
$ export ARCH=arm64
$ export CROSS_COMPILE=<path to your GCC cross compiler>/aarch64-linux-gnu-
$ make defconfig distro.config
$ make -j$(nproc) Image dtbs KERNELRELEASE=`make kernelversion`-qcomlt-${ARCH}
```
For building the kernel modules:

```shell
$ make -j$(nproc) modules KERNELRELEASE=`make kernelversion`-qcomlt-${ARCH}
```

## Booting the Kernel

To boot the kernel image, you will need a fastboot compatible boot image. For
that you can refer to [Dragonboard-Boot-Image](https://github.com/96boards/documentation/wiki/Dragonboard-Boot-Image)
for instructions to create such an image. Only change required is to replace
the command line with below:

```shell
export cmdline="root=/dev/sda7 rw rootwait console=ttyMSM0,115200n8"
```
