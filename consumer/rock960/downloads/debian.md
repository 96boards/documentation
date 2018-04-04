---
title: Debian Downloads for ROCK960
permalink: /documentation/consumer/rock960/downloads/debian.md.html
---

# Debian

**Debian Linux** is a desktop/window or console (command line) based development environment comprised of some basic programs and utilities. Development can happen directly on the board, and within the OS. While applications and programs can be built directly on the board, they can also be built remotely and cross-compiled for the particular system.

***

## SD Card/eMMC AIO image

|   SD Card/eMMC AIO Image   |    Download     |
|:------------------|:------------------------------------|
|All-in-one image with bootloader/kernel/rootfs     |[Debian Stretch Desktop armhf](https://dl.vamrs.com/products/rock960/images/debian/rock960_debian_stretch_desktop_armhf_20180115.tar.gz)                             |

This image can be flashed to eMMC from USB or write and run on a SD card. Continue to [Installation page](../installation/README.md)

***

## Partition files

|   Bootloader |    Download            |
|:-------------|:-----------------------|
| Miniloader(flash helper) | [rk3399_loader_v1.08.106.bin](https://dl.vamrs.com/products/rock960/images/debian/partitions/u-boot/rk3399_loader_v1.08.106.bin)           |
| IDB loader(U-boot SPL)  | [idbloader.img](https://dl.vamrs.com/products/rock960/images/debian/partitions/u-boot/idbloader.img)           |
| ARM Trustzone firmware  | [trust.img](https://dl.vamrs.com/products/rock960/images/debian/partitions/u-boot/trust.img)           |
| U-boot                  | [uboot.img](https://dl.vamrs.com/products/rock960/images/debian/partitions/u-boot/uboot.img)           |

|   Boot image      |    Download        |
|:------------------|:-----------------------|
|FAT32 filesystem with kernel and dtb     |[boot.img.gz](https://dl.vamrs.com/products/rock960/images/debian/partitions/boot.img.gz)                |

|   Rootfs image    |    Download                    |
|:------------------|:----------------------------------|
|Debian rootfs armhf     | [debian_rootfs.img.gz](https://dl.vamrs.com/products/rock960/images/debian/debian_rootfs_armhf_rockchip_release_20171108.img.gz)                          |

Continue to [Installation page](../installation/README.md)
