---
title: Instructions for Dynamically Loading Device Tree Overlays into Linux Kernel
permalink: /documentation/consumer/dragonboard410c/guides/dt-overlays.md.html
redirect_from:
- /db410c-getting-started/Guides/dt-overlays.md/
- /documentation/ConsumerEdition/DragonBoard-410c/Guides/dt-overlays.md.html
---

# Instructions for Dynamically Loading Device Tree Overlays into Linux Kernel

This document provides instructions for dynamically loading the device tree overlays (dtbo) into
linux kernel running on DragonBoard410c.

# Table of Contents

- [1) Device Tree Compiler](#1-device-tree-compiler)
    - [1.1) Installing the Compiler](#11-installing-the-compiler)
- [2) Enable Overlay Support in Kernel](#2-enable-overlay-support-in-kernel)
    - [2.1) Cloning and Building the kernel](#21-cloning-and-building-the-kernel)
- [3) Load Overlays Dynamically](#3-load-overlays-dynamically)
    - [3.1) Compiling the Overlays](#31-compiling-the-overlays)
    - [3.2) Loading Overlays via Configfs](#32-loading-overlays-via-configfs)

 ***

 # 1) Device Tree Compiler

 First of all we need to install device tree compiler (dtc) for compiling the source files (dts) into
 overlays (dtbo). Overlay support was added to the mainline dtc by v1.4.2 only. But, the one which is available
 as a package in debian based distros is v1.4.0. So, we need to install the compiler from source.

 ## 1.1 Installing the Compiler

```shell
$ sudo apt-get install flex bison swig
$ git clone git://git.kernel.org/pub/scm/utils/dtc/dtc.git
$ cd dtc
$ make -j$(nproc)
$ sudo make install PREFIX=/usr
```

# 2) Enable Overlay Support in Kernel

Next, overlay support needs to be enabled in the kernel. For which a custom kernel would be used other than
the one available in Qualcomm landing page.

## 2.1 Cloning and Building the kernel

```shell
$ export ARCH=arm64
$ export CROSS_COMPILE=<path to your GCC cross compiler>/aarch64-linux-gnu-
$ git clone -n http://git.linaro.org/landing-teams/working/qualcomm/kernel.git
$ cd kernel
$ git checkout -b kernel-<release> debian-qcom-dragonboard410c-<release>
```
> Note: Replace < release > with latest release version found [here](http://builds.96boards.org/releases/dragonboard410c/linaro/debian/latest/)

Now, custom kernel should be added as a source in order to fetch the configfs-overlay changes

```shell
$ git remote add source https://github.com/Mani-Sadhasivam/linux-qcom.git
```
Fetch latest changes and merge into release branch

```shell
$ git fetch source release/qcomlt-4.9+configfs_overlay
```
Now merge **configfs_overlay** changes into the **release** branch

```shell
$ git merge source/release/qcomlt-4.9+configfs_overlay
```
Configfs overlay feature has been enabled by default in **defconfig**

```shell
$ make defconfig distro.config
$ make -j$(nproc) Image dtbs
$ make -j$(nproc) modules
$ make modules_install INSTALL_MOD_STRIP=1 INSTALL_MOD_PATH=<folder>
```
> Note: Replace < folder > with the path of folder to place kernel modules. Kernel modules needs to be transferred
to the root file system, under ***/lib/modules*** folder on DragonBoard410c.

For further instructions on how to create bootable image and flashing onto Dragonboard410c, refer release notes
[here](http://builds.96boards.org/releases/dragonboard410c/linaro/debian/latest/)

# 3) Load Overlays Dynamically

After flashing the patched kernel onto Dragonboad410c, following instructions allows to load device tree overlays
dynamically through configfs.

## 3.1 Compiling the Overlays

There are some example overlays available for reference. You can modify them according to the preferred device. Below
example shows compiling the overlays for i2c based **TSYS01** and **MS8607** sensors. Device drivers for the appropriate
sensors should have device tree support enabled for allowing cold plug.

```shell
$ git clone https://github.com/Mani-Sadhasivam/DT-Overlays.git
$ cd DT-Overlays
$ make -j$(nproc)
```

After successful compilation, device tree blobs (dtbo) will be available in ***bin*** directory.

## 3.2 Loading Overlays via Configfs

Now its the time to insert the device tree blobs into running kernel using configfs.

```shell
$ sudo su
# mount -t configfs none /sys/kernel/config
```
When configfs has been mounted properly, that directory should have been populated with subdirectories
***/sys/kernel/config/device-tree/overlays***

```shell
# mkdir -p /sys/kernel/config/device-tree/overlays/tsys01
# cd <bin directory under DT-Overlays>
# cat tsys01.dtbo > /sys/kernel/config/device-tree/overlays/tsys01/dtbo
```

After loading, the device should appear under ***/proc/device-tree/soc/i2c@78b6000/***

That't it! You have loaded device tree overlay dynamically. But this wont be sufficient, you need to load your device driver
also to work with the device. By this time, if the driver has been compiled into the kernel (by selecting *y* during **make
 menuconfig**), then the driver should have been probed successfully and it will appear under ***/sys/bus/i2c/devices/***

If the driver was compiled as a kernel module, then insert it using **modprobe**
