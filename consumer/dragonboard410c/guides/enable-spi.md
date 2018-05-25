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
- [3) Testing SPIDEV](#3-testing-spidev)

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

1. Run the following commands on the Dragonboard410c:

```shell
$ git clone https://github.com/96boards/dt-update
$ cd dt-update
$ make
$ sudo scripts/db410c/enable-spidev.sh
```

2. Reboot your Dragonboard410c

## Kernel warning when booting the kernel:

Since the SPIDEV module is not a representation of a real hardware,
kernel will produce a warning when booting the system, such as:

```shell
[   11.566840] spidev spi1.0: buggy DT: spidev listed directly in DT
[   11.566934] ------------[ cut here ]------------
[   11.571901] WARNING: at ../drivers/spi/spidev.c:719
```

The device will still be functional, so just ignore while testing the
SPIDEV devices.

# 3) Testing SPIDEV

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
