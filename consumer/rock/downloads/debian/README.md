---
title: Debian Downloads for ROCK960
permalink: /documentation/consumer/rock/downloads/debian/
redirect_from: /documentation/consumer/rock960/downloads/debian/
---

# Debian

**Debian Linux** is a desktop/window or console (command line) based development environment comprised of some basic programs and utilities. Development can happen directly on the board, and within the OS. While applications and programs can be built directly on the board, they can also be built remotely and cross-compiled for the particular system.

***

> NOTE: default user name and password
>
>    **username: rock**
>    **password: rock**
>
> or
>
>    **username: linaro**
>    **password: linaro**

***

## SD Card/eMMC AIO GPT image

### For ROCK960 model A&B

|   SD Card/eMMC AIO GPT Image   |    Download     |
|:------------------|:------------------------------------|
| All-in-one GPT image with bootloader/kernel/rootfs     | [Debian Stretch Desktop armhf](https://dl.vamrs.com/products/rock960/images/debian/rock960_debian_stretch_desktop_armhf_20180115.tar.gz) |


### For ROCK960 model C

|   SD Card/eMMC AIO GPT Image   |    Download     |
|:------------------|:------------------------------------|
| All-in-one GPT image with bootloader/kernel/rootfs     | [Debian Stretch Desktop armhf](https://dl.vamrs.com/products/rock960c/images/debian/rock960c_debian_stretch_lxde_armhf_20180920.tar.gz) |


This image can be flashed to eMMC from USB or write and run on a SD card. Continue to [Installation page](../installation)

***

## Partition files

### For ROCK960 model A&B

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
|Debian rootfs armhf     | [debian_rootfs.img.gz](https://dl.vamrs.com/products/rock960c/images/debian/partitions/roofs/rockchip_debian_rootfs_armhf_v2.2_20180704.ext4.gz)                          |

### For ROCK960 model C

|   Bootloader |    Download            |
|:-------------|:-----------------------|
| Miniloader(flash helper) | [rk3399_loader_v1.12.112.bin](https://dl.vamrs.com/products/rock960c/images/loader/rk3399_loader_v1.12.112.bin) |
| IDB loader(U-boot SPL)  | [idbloader.img](https://dl.vamrs.com/products/rock960c/images/debian/partitions/u-boot/idbloader.img)          |
| ARM Trustzone firmware  | [trust.img](https://dl.vamrs.com/products/rock960c/images/debian/partitions/u-boot/trust.img)          |
| U-boot                  | [uboot.img](https://dl.vamrs.com/products/rock960c/images/debian/partitions/u-boot/uboot.img)          |

|   Boot image      |    Download        |
|:------------------|:-----------------------|
|FAT32 filesystem with kernel and dtb     |[boot.img.gz](https://dl.vamrs.com/products/rock960c/images/debian/partitions/boot.img.gz)                |

|   Rootfs image    |    Download                    |
|:------------------|:----------------------------------|
|Debian rootfs armhf     | [debian_rootfs.img.gz](https://dl.vamrs.com/products/rock960c/images/debian/debian_rootfs_armhf_rockchip_release_20171108.img.gz)                         |

Continue to [Installation page](../installation)
