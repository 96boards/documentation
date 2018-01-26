---
title: DragonBoard 820c OpenEmbedded
permalink: /documentation/consumer/dragonboard820c/downloads/open-embedded.md.html
---
# OpenEmbedded

**OpenEmbedded** is a software framework used for creating Linux distributions aimed for, but not restricted to, embedded devices. Below are pre-built console and desktop images of Debian with their respective bootloader and boot image. If desired, these images can be recreated by following the build from source instructions found [here](https://github.com/Linaro/documentation/blob/master/Reference-Platform/CECommon/OEYocto.md) (Note: this link will take you to the Linaro Github)

***

## Fastboot files (Advanced users)

|   Bootloader    |    [Download](http://builds.96boards.org/releases/dragonboard410c/linaro/rescue/latest/dragonboard410c_bootloader_emmc_linux-*.zip)    |
|:------------------|:-----------------------|
|Release Notes:     |[Link](http://builds.96boards.org/releases/dragonboard410c/linaro/rescue/latest/)      |

Choose one boot image, the root file system you choose will be based on the boot image you download here:

|   Boot image    |  Build Folder ([RPB](http://builds.96boards.org/releases/reference-platform/openembedded/dragonboard410c/latest/rpb/) / [RPB-Wayland](http://builds.96boards.org/releases/reference-platform/openembedded/dragonboard410c/latest/rpb-wayland/))   |
|:------------------|:-----------------------|
| RPB    | [Download](http://builds.96boards.org/releases/reference-platform/openembedded/dragonboard410c/latest/rpb/boot--4.4-r0.1-dragonboard-410c-*.img)   |
| RPB-Wayland    |  [Download](http://builds.96boards.org/releases/reference-platform/openembedded/dragonboard410c/latest/rpb-wayland/boot--4.4-r0.1-dragonboard-410c-*.img)  |

Only download one root file system (Console or Desktop). You should match the type of rootfs to the boot image you downloaded above.

|   Rootfs image    |  Build Folder ([RPB](http://builds.96boards.org/releases/reference-platform/openembedded/dragonboard410c/latest/rpb/) / [RPB-Wayland](http://builds.96boards.org/releases/reference-platform/openembedded/dragonboard410c/latest/rpb-wayland/))    |
|:------------------|:----------------------------------|
| RPB  | ([Desktop](http://builds.96boards.org/releases/reference-platform/openembedded/dragonboard410c/latest/rpb/rpb-desktop-image-dragonboard-410c-*.rootfs.ext4.gz) / [Console](http://builds.96boards.org/releases/reference-platform/openembedded/dragonboard410c/latest/rpb/rpb-console-image-dragonboard-410c-*.rootfs.ext4.gz))    |
| RPB-Wayland  | ([Desktop](http://builds.96boards.org/releases/reference-platform/openembedded/dragonboard410c/latest/rpb-wayland/rpb-weston-image-dragonboard-410c-*.rootfs.ext4.gz) / [Console](http://builds.96boards.org/releases/reference-platform/openembedded/dragonboard410c/latest/rpb-wayland/rpb-console-image-dragonboard-410c-*.rootfs.ext4.gz))     |

Continue to [Installation page](../Installation/README.md)
