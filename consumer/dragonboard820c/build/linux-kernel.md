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
For now the support for this board is preliminary and can only be found in
either `release` branches named as `release/db820c/qcomlt-x.y`
(the latest one being the most up-to-date/recent) or the
`integration-linux-qcomlt` branch, which is regularly rebased on recent mainline,
and is used by developers.

Following commands can be used to fetch the latest kernel source:

```shell
$ git clone http://git.linaro.org/landing-teams/working/qualcomm/kernel.git
$ git checkout release/db820c/qcomlt-x.y -b db820c
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
$ make -j$nproc Image dtbs KERNELRELEASE=`make kernelversion`-linaro-lt-qcom
```
For building the kernel modules:

```shell
$ make -j4 modules KERNELRELEASE=`make kernelversion`-linaro-lt-qcom
```

## Booting the Kernel

To boot the kernel image, you will need a fastboot compatible boot image. For
that you can refer to [Dragonboard-Boot-Image](https://github.com/96boards/documentation/wiki/Dragonboard-Boot-Image)
for instructions to create such an image. Only change required is to replace
the command line with below:

```shell
export cmdline="root=/dev/sda9 rw rootwait console=ttyMSM0,115200n8"
```
