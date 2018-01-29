---
title: Enabling SPI on Dragonboard 410c with SPIDEV
permalink: /documentation/consumer/dragonboard410c/guides/enable-spi.md.html
redirect_from:
- /db410c-getting-started/Guides/EnableSPI.md/
- /documentation/ConsumerEdition/DragonBoard-410c/Guides/EnableSPI.md.html
---

# Enabling SPI on Dragonboard 410c with SPIDEV

This document provides instructions for enabling SPI (Serial Peripheral Interface)
subsystem on Dragonboard410c along with SPIDEV userspace interface.

# Table of Contents

- [1) SPIDEV](#1-spidev)
- [2) Modifying device tree](#2-modifying-device-tree)
- [3) Building device tree](#3-building-device-tree)
- [4) Flashing boot and rootfs image](#4-flashing-boot-and-rootfs-image)
- [5) Testing SPIDEV](#5-testing-spidev)

 ***

# 1) SPIDEV

SPI devices have a limited userspace API, supporting basic half-duplex
read() and write() access to SPI slave devices. SPIDEV is a kernel driver
used to provide userspace interface to SPI subsystem.

This driver can be enabled by the following Kconfig option:

CONFIG_SPI_SPIDEV=y (or)
CONFIG_SPI_SPIDEV=m

First option builds the driver into kernel while the later builds it as
a separate module. Since latest linaro builds have this option enabled
by default, only device tree modification is required.

# 2) Modifying device tree

For using SPIDEV driver it is necessary to add the relevant device tree node.
Following instructions are used to add SPIDEV nodes into Dragonboard410c
device tree.

1. Clone the kernel

```shell
$ git clone -n http://git.linaro.org/landing-teams/working/qualcomm/kernel.git
$ cd kernel
$ git checkout -b kernel-<RELEASE> debian-qcom-dragonboard410c-<RELEASE>
```
> Note: Replace < RELEASE > with latest release version found
[here](http://builds.96boards.org/releases/dragonboard410c/linaro/debian/latest/)

2. Add SPIDEV nodes to device tree

Apply the following diff to `arch/arm64/boot/dts/qcom/apq8016-sbc.dtsi`

```
diff --git a/arch/arm64/boot/dts/qcom/apq8016-sbc.dtsi b/arch/arm64/boot/dts/qcom/apq8016-sbc.dtsi
index 5d0d5a3..c4a5ba7 100644
--- a/arch/arm64/boot/dts/qcom/apq8016-sbc.dtsi
+++ b/arch/arm64/boot/dts/qcom/apq8016-sbc.dtsi
@@ -476,6 +476,26 @@
        };
 };

+/* On Low speed expansion header */
+&blsp_spi5 {
+               status = "okay";
+               spidev@0 {
+                               compatible = "spidev";
+                               spi-max-frequency = <500000>;
+                               reg = <0>;
+               };
+};
+
+/* On High speed expansion header */
+&blsp_spi3 {
+               status = "okay";
+               spidev@0 {
+                               compatible = "spidev";
+                               spi-max-frequency = <500000>;
+                               reg = <0>;
+               };
+};
+
```

# 3) Building device tree

Build the device tree with above mentioned changes.

```shell
$ export ARCH=arm64
$ export CROSS_COMPILE=<path to your GCC cross compiler>/aarch64-linux-gnu-
$ make defconfig distro.config
$ make -j$(nproc) dtbs
```
Now, prepare the boot image.

```shell
$ git clone git://codeaurora.org/quic/kernel/skales
$ ./skales/dtbTool -o dt.img -s 2048 arch/arm64/boot/dts/qcom/
$ wget http://builds.96boards.org/releases/dragonboard410c/linaro/debian/latest/initrd.img-<KERNELRELEASE>-linaro-lt-qcom
$ wget http://builds.96boards.org/releases/dragonboard410c/linaro/debian/latest/Image
$ ./skales/mkbootimg --kernel Image \
                   --ramdisk initrd.img.<KERNELRELEASE>-linaro-lt-qcom \
                   --output boot-db410c.img \
                   --dt dt.img \
                   --pagesize 2048 \
                   --base 0x80000000 \
                   --cmdline "root=/dev/disk/by-partlabel/rootfs rw rootwait console=ttyMSM0,115200n8"
```

> Note: Replace < KERNELRELEASE > with latest kernel release version found
[here](http://builds.96boards.org/releases/dragonboard410c/linaro/debian/latest/).

# 4) Flashing boot and roofs image

Boot Dragonboard410c into fastboot mode by following the
[instructions](https://www.96boards.org/documentation/consumer/dragonboard410c/installation/linux-fastboot.md.html).

1. Download latest `rootfs` image from
[here](http://builds.96boards.org/releases/dragonboard410c/linaro/debian/latest/linaro-*-alip-qcom-snapdragon-arm64-*.img.gz).
2. Flash boot and rootfs images onto Dragonboard410c

```shell
$ sudo fastboot flash boot boot-db410c.img
$ sudo fastboot flash rootfs linaro-<DEBIANRELEASE>-alip-qcom-snapdragon-arm64-<BUILD>.img
```
> Note: Replace < DEBIANRELEASE > and < BUILD > according to the downloaded rootfs image.

### Kernel warning when booting the kernel:

Since the SPIDEV module is not a representation of a real hardware,
kernel will produce a warning when booting the system, such as:

```shell
[   11.566840] spidev spi1.0: buggy DT: spidev listed directly in DT
[   11.566934] ------------[ cut here ]------------
[   11.571901] WARNING: at ../drivers/spi/spidev.c:719
```

The device will still be functional, so just ignore while testing the
SPIDEV devices.

# 5) Testing SPIDEV

Login to Dragnoboard410c and execute the following commands to test
SPI using SPIDEV module with the help of `spidev_test` utility.

```shell
$ wget https://raw.githubusercontent.com/torvalds/linux/master/tools/spi/spidev_test.c
$ gcc -o spidev_test spidev_test.c
$ sudo ./spidev_test -CHO -D /dev/spidev0.0  0xaa,0xbb,0xcc,0,0,0,0,0
 AA BB CC 00 00 00 00 00
 00 00 00 00 00 00 00 00
```

Since, SPI driver in Dragonboard410c supports Loopback functionality, we can
test that too without any hardware connections.

```shell
$ sudo ./spidev_test -CHO -D /dev/spidev0.0  0xaa,0xbb,0xcc,0,0,0,0,0 --loop
 AA BB CC 00 00 00 00 00
 AA BB CC 00 00 00 00 00
```
