---
title: OpenEmbedded Downloads for HiKey
permalink: /documentation/consumer/hikey/hikey620/downloads/open-embedded.md.html
redirect_from:
- /documentation/ConsumerEdition/HiKey/Downloads/OpenEmbedded.md.html
- /documentation/ConsumerEdition/HiKey/Downloads/OpenEmbedded.md.html
-  /documentation/consumer/hikey/downloads/open-embedded.md.html
---

# OpenEmbedded

**OpenEmbedded** is a software framework used for creating Linux distributions aimed for, but not restricted to, embedded devices. Below are pre-built console and desktop images of Debian with their respective bootloader and boot image. If desired, these images can be recreated by following the build from source instructions found [here](https://github.com/Linaro/documentation/blob/master/Reference-Platform/CECommon/OE.md) (Note: this link will take you to the Linaro Github)

***

## Fastboot files (Advanced users)

|   Bootloader    |   |
|:------------------|:-----------------------|
| l-loader.bin      | [Download](https://releases.linaro.org/reference-platform/embedded/hikey/latest/rpb/bootloader/l-loader.bin)           |
| fip.bin           | [Download](https://releases.linaro.org/reference-platform/embedded/hikey/latest/rpb/bootloader/fip.bin)           |
| nvme.img          | [Download](https://releases.linaro.org/reference-platform/embedded/hikey/latest/rpb/bootloader/nvme.img)           |
| ptable-linux.img  | [4GB](https://releases.linaro.org/reference-platform/embedded/hikey/latest/rpb/bootloader/ptable-linux-4g.img) / [8GB](https://releases.linaro.org/reference-platform/embedded/hikey/latest/rpb/bootloader/ptable-linux-8g.img)      |
| hisi-idt.py       | [Download](https://releases.linaro.org/reference-platform/embedded/hikey/latest/rpb/bootloader/hisi-idt.py)           |

Choose one boot image, the root file system you choose will be based on the boot image you download here:

|   Boot image    |  Build Folder ([RPB](https://releases.linaro.org/reference-platform/embedded/hikey/latest/rpb/) / [RPB-Wayland](https://releases.linaro.org/reference-platform/embedded/hikey/latest/rpb-wayland/))   |
|:------------------|:-----------------------|
| RPB    | [Download](https://releases.linaro.org/reference-platform/embedded/hikey/latest/rpb/boot*.uefi.img)   |
| RPB-Wayland    |  [Download](https://releases.linaro.org/reference-platform/embedded/hikey/latest/rpb-wayland/boot*.uefi.img)  |

Only download one root file system (Console or Desktop). You should match the type of rootfs to the boot image you downloaded above.

|   Rootfs image    |  Build Folder ([RPB](https://releases.linaro.org/reference-platform/embedded/hikey/latest/rpb/) / [RPB-Wayland](https://releases.linaro.org/reference-platform/embedded/hikey/latest/rpb-wayland/))    |
|:------------------|:----------------------------------|
| RPB  | ([Desktop](https://releases.linaro.org/reference-platform/embedded/hikey/latest/rpb/rpb-desktop-image-hikey-*.rootfs.ext4.gz) / [Console](https://releases.linaro.org/reference-platform/embedded/hikey/latest/rpb/rpb-console-image-hikey-*.rootfs.ext4.gz))    |
| RPB-Wayland  | ([Desktop](https://releases.linaro.org/reference-platform/embedded/hikey/latest/rpb-wayland/rpb-weston-image-hikey-*.rootfs.ext4.gz) / [Console](https://releases.linaro.org/reference-platform/embedded/hikey/latest/rpb-wayland/rpb-console-image-hikey-*.rootfs.ext4.gz))     |

### Continue to [Installation page](../installation/)
