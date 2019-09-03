---
title: OpenCL support on Debian/hikey960
permalink: /documentation/consumer/hikey/hikey960/guides/openCL-support/
---

# Enable OpenCL support on Debian/hikey960

This guide provides steps for installing Mali G71 drivers and enabling openCL
support on your HiKey960 running Debian.

# Table of Contents

- [1) Mali bitfrost GPU kernel driver](#1-mali-bitfrost-gpu-kernel-driver)
    - [1.1) Check Mali GPU devicetree node](#11-check-mali-gpu-devicetree-node)
    - [1.2) Build and install kernel driver](#12-build-and-install-kernel-driver)
- [2) Mali user-space binary drivers](#2-mali-user-space-binary-drivers)
    - [2.1) Install user-space drivers](#21-install-user-space-drivers)
- [3) Run OpenCL client tool](#3-run-openCL-client-tool)

***

# 1) Mali bitfrost GPU kernel driver

ARM provides open source mali bifrost GPU kernel drivers [here](https://developer.arm.com/products/software/mali-drivers/bifrost-kernel).
Go ahead and download the latest release. For the sake of this guide, release r16p0-01rel0 is considered.

## 1.1) Check Mali GPU devicetree node

Once hikey960 is up and running Debian distro, use following command to check
for mali gpu devicetree node:

```shell
$ sudo dtc -I fs /proc/device-tree | grep mali
```

In case mali gpu node isn't present then either check if you are using latest
edk2/UEFI build image or update devicetree with appropriate mali gpu node.

## 1.2) Build and install kernel driver

Follow below steps to build and install kernel driver:

```shell
$ sudo apt-get update
$ sudo apt-get install linux-headers-$(uname -r)
$ tar -xzf BX301A01B-SW-99002-r16p0-01rel0.tgz
$ make -C /usr/src/linux-headers-$(uname -r)/ M=${PWD}/BX301A01B-SW-99002-r16p0-01rel0/driver/product/kernel/drivers/gpu/arm/midgard/ CONFIG_MALI_MIDGARD=m CONFIG_MALI_GATOR_SUPPORT=y CONFIG_MALI_MIDGARD_DVFS=y CONFIG_MALI_EXPERT=y CONFIG_MALI_PLATFORM_FAKE=y CONFIG_MALI_PLATFORM_THIRDPARTY=y CONFIG_MALI_PLATFORM_THIRDPARTY_NAME=devicetree modules
$ sudo mkdir -p /lib/modules/$(uname -r)/extras
$ sudo cp BX301A01B-SW-99002-r16p0-01rel0/driver/product/kernel/drivers/gpu/arm/midgard/mali_kbase.ko /lib/modules/$(uname -r)/extras/
$ sudo depmod -a
$ sudo modprobe mali_kbase
```
> Note: BX301A01B-SW-99002-r16p0-01rel0.tgz is the kernel driver package downloaded from ARM developer site.

# 2) Mali user-space binary drivers

ARM provides mali GPU user-space binary drivers for hikey960 [here](https://developer.arm.com/products/software/mali-drivers/user-space).
Go ahead and download the latest release. For the sake of this guide, release mali-G71_r9p0-01rel0_linux_1fbdev.tar.gz is considered.

## 2.1) Install user-space drivers

Follow below steps to install mali user-space drivers:

```shell
$ tar -xvf mali-G71_r9p0-01rel0_linux_1fbdev.tar.gz
$ sudo cp fbdev/libmali.so /usr/lib/aarch64-linux-gnu/
$ sudo cp fbdev/liboffline_compiler_api_gles.so /usr/lib/aarch64-linux-gnu/
```
> Note: mali-G71_r9p0-01rel0_linux_1fbdev.tar.gz is the user-space driver package downloaded from ARM developer site.

# 3) Run OpenCL client tool

Now, install and run OpenCL client tool (clinfo) using below steps:

```shell
$ sudo mkdir -p /etc/OpenCL/vendors/
$ echo "libmali.so" | sudo tee /etc/OpenCL/vendors/mali.icd
$ sudo apt-get install clinfo
$ sudo clinfo
```

The above commands will show available GPU hardware info for OpenCL usage.
Now we are good to run OpenCL based applications. For sample applications,
refer to Compute Library provided by ARM [here](https://developer.arm.com/technologies/compute-library).
