---
title: DragonBoard 820c OpenEmbedded
permalink: /documentation/consumer/dragonboard820c/downloads/open-embedded.md.html
---
# OpenEmbedded

**OpenEmbedded** is a software framework used for creating Linux distributions aimed for, but not restricted to, embedded devices. Below are pre-built console and desktop images of Debian with their respective bootloader and boot image. If desired, these images can be recreated by following the build from source instructions found [here](https://github.com/Linaro/documentation/blob/master/Reference-Platform/CECommon/OE.md) (Note: this link will take you to the Linaro Github)

***

## Fastboot files (Advanced users)

|   Bootloader    |    Download    |
|:------------------|:-----------------------|
|Release Notes:     |[Link](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/rescue/latest/)      |

Choose one boot image, the root file system you choose will be based on the boot image you download here:

|   Boot image    |  Build Folder ([RPB](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/openembedded/morty/latest/rpb/) / [RPB-Wayland](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/openembedded/morty/latest/rpb-wayland/))   |
|:------------------|:-----------------------|
| RPB    | [Download](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/openembedded/morty/latest/rpb/boot--4.11-r0-dragonboard-820c-*.img)   |
| RPB-Wayland    |  [Download](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/openembedded/morty/latest/rpb-wayland/boot--4.11-r0-dragonboard-820c-*.img)  |

Only download one root file system (Console or Desktop). You should match the type of rootfs to the boot image you downloaded above.

|   Rootfs image    |  Build Folder ([RPB](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/openembedded/morty/latest/rpb/) / [RPB-Wayland](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/openembedded/morty/latest/rpb-wayland/))    |
|:------------------|:----------------------------------|
| RPB  | [Downloads Desktop](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/openembedded/morty/latest/rpb/rpb-desktop-image-dragonboard-820c-*.rootfs.ext4.gz)/[Download Console](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/openembedded/morty/latest/rpb/rpb-console-image-dragonboard-820c-*.rootfs.ext4.gz)    |
| RPB-Wayland  | [Download Desktop](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/openembedded/morty/latest/rpb-wayland/rpb-weston-image-dragonboard-820c-*.rootfs.ext4.gz)/[Download](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/openembedded/morty/latest/rpb-wayland/rpb-console-image-dragonboard-820c-*.rootfs.ext4.gz)     |

Continue to [Installation page](../installation)
