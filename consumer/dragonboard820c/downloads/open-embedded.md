---
title: DragonBoard 820c OpenEmbedded
permalink: /documentation/consumer/dragonboard820c/downloads/open-embedded.md.html
---
# OpenEmbedded

**OpenEmbedded** is a software framework used for creating Linux distributions aimed for, but not restricted to, embedded devices. Below are pre-built console and desktop images of Debian with their respective bootloader and boot image. If desired, these images can be recreated by following the build from source instructions found [here](https://github.com/Linaro/documentation/blob/master/Reference-Platform/CECommon/OE.md) (Note: this link will take you to the Linaro Github)

[OpenEmbedded Releases Table](https://wiki.yoctoproject.org/wiki/Releases)

***

## Fastboot files

| Bootloader                                                                                                                             |
|:---------------------------------------------------------------------------------------------------------------------------------------|
| [Download](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/rescue/latest/dragonboard-820c-bootloader-ufs-linux-*.zip)       |
| [Release Notes](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/rescue/latest/)                                             |

Choose one boot image, the root file system you choose will be based on the boot image you download here:

| Boot image                                                                                                                                           |
|:-----------------------------------------------------------------------------------------------------------------------------------------------------|
| [RPB](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/openembedded/morty/latest/rpb/boot--4.11-r0-dragonboard-820c-*.img)                |
| [RPB-Wayland](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/openembedded/morty/latest/rpb-wayland/boot--4.11-r0-dragonboard-820c-*.img)|
| [Release Notes](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/openembedded/rocko/latest/)                                              |

Only download one root file system (Console or Desktop). You should match the type of rootfs to the boot image you downloaded above.

| Rootfs image (RPB)                                                    |                                                   |
|:----------------------------------------------------------------------|:-----------------------------------------------------------------------------|
| [Desktop](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/openembedded/morty/latest/rpb/rpb-desktop-image-dragonboard-820c-*.rootfs.ext4.gz) | 
| [Developer](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/openembedded/morty/latest/rpb/rpb-console-image-dragonboard-820c-*.rootfs.ext4.gz) |

| Rootfs image (RPB-Wayland)                                                                 | 
|:----------------------------------------------------------------------|:-----------------------------------------------------------------------------|
| [Desktop](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/openembedded/morty/latest/rpb-wayland/rpb-weston-image-dragonboard-820c-*.rootfs.ext4.gz) | 
| [Developer](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/openembedded/morty/latest/rpb-wayland/rpb-console-image-dragonboard-820c-*.rootfs.ext4.gz) |

## Continue to [Installation page](../installation)
