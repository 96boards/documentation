---
title: OpenEmbedded Downloads for HiKey
permalink: /documentation/ConsumerEdition/HiKey/Downloads/OpenEmbedded.md/
---
# OpenEmbedded

**OpenEmbedded** is a software framework used for creating Linux distributions aimed for, but not restricted to, embedded devices. Below are pre-built console and desktop images of Debian with their respective bootloader and boot image. If desired, these images can be recreated by following the build from source instructions found [here](https://github.com/Linaro/documentation/blob/master/Reference-Platform/CECommon/OE.md) (Note: this link will take you to the Linaro Github)

***

## Fastboot files (Advanced users)

|   Bootloader    |   |
|:------------------|:-----------------------|
| l-loader.bin      | [Download](http://builds.96boards.org/releases/reference-platform/openembedded/hikey/latest/rpb/bootloader/l-loader.bin)           |
| fip.bin           | [Download](http://builds.96boards.org/releases/reference-platform/openembedded/hikey/latest/rpb/bootloader/fip.bin)           |
| nvme.img          | [Download](http://builds.96boards.org/releases/reference-platform/openembedded/hikey/latest/rpb/bootloader/nvme.img)           |
| ptable-linux.img  | [4GB](http://builds.96boards.org/releases/reference-platform/openembedded/hikey/latest/rpb/bootloader/ptable-linux-4g.img) / [8GB](http://builds.96boards.org/releases/reference-platform/openembedded/hikey/latest/rpb/bootloader/ptable-linux-8g.img)      |
| hisi-idt.py       | [Download](http://builds.96boards.org/releases/reference-platform/openembedded/hikey/latest/rpb/bootloader/hisi-idt.py)           |

Choose one boot image, the root file system you choose will be based on the boot image you download here:

|   Boot image    |  Build Folder ([RPB](http://builds.96boards.org/releases/reference-platform/openembedded/hikey/latest/rpb/) / [RPB-Wayland](http://builds.96boards.org/releases/reference-platform/openembedded/hikey/latest/rpb-wayland/))   |
|:------------------|:-----------------------|
| RPB    | [Download](http://builds.96boards.org/releases/reference-platform/openembedded/hikey/latest/rpb/boot-0.0+AUTOINC+76c7cfcc22-bdec62eeb8-r0-hikey-*.uefi.img)   |
| RPB-Wayland    |  [Download](http://builds.96boards.org/releases/reference-platform/openembedded/hikey/latest/rpb-wayland/boot-0.0+AUTOINC+76c7cfcc22-bdec62eeb8-r0-hikey-*.uefi.img)  |

Only download one root file system (Console or Desktop). You should match the type of rootfs to the boot image you downloaded above.

|   Rootfs image    |  Build Folder ([RPB](http://builds.96boards.org/releases/reference-platform/openembedded/hikey/latest/rpb/) / [RPB-Wayland](http://builds.96boards.org/releases/reference-platform/openembedded/hikey/latest/rpb-wayland/))    |
|:------------------|:----------------------------------|
| RPB  | ([Desktop](http://builds.96boards.org/releases/reference-platform/openembedded/hikey/latest/rpb/rpb-desktop-image-hikey-*.rootfs.ext4.gz) / [Console](http://builds.96boards.org/releases/reference-platform/openembedded/hikey/latest/rpb/rpb-console-image-hikey-*.rootfs.ext4.gz))    |
| RPB-Wayland  | ([Desktop](http://builds.96boards.org/releases/reference-platform/openembedded/hikey/latest/rpb-wayland/rpb-weston-image-hikey-*.rootfs.ext4.gz) / [Console](http://builds.96boards.org/releases/reference-platform/openembedded/hikey/latest/rpb-wayland/rpb-console-image-hikey-*.rootfs.ext4.gz))     |

### Continue to [Installation page](../Installation/)
