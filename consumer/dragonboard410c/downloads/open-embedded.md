---
title: OpenEmbedded Downloads for DragonBoard-410c
permalink: /documentation/consumer/dragonboard410c/downloads/open-embedded.md.html
redirect_from:
- /db410c-getting-started/Downloads/OpenEmbedded.md/
- /documentation/ConsumerEdition/DragonBoard-410c/Downloads/OpenEmbedded.md.html
---
# OpenEmbedded

**OpenEmbedded** is a software framework used for creating Linux distributions aimed for, but not restricted to, embedded devices. Below are pre-built console and desktop images of Debian with their respective bootloader and boot image. If desired, these images can be recreated by following the build from source instructions found [here](https://github.com/Linaro/documentation/blob/master/Reference-Platform/CECommon/OE.md) (Note: this link will take you to the Linaro Github)

***

## Fastboot files (Advanced users)

| Bootloader                                                                                                                              |
|:----------------------------------------------------------------------------------------------------------------------------------------|
| [Download](http://builds.96boards.org/releases/dragonboard410c/linaro/rescue/latest/dragonboard410c_bootloader_emmc_linux-*.zip)        |
| [Release Notes](http://builds.96boards.org/releases/dragonboard410c/linaro/rescue/latest/)      |

Choose between RPB and RPB-Wayland. You will need to download the "boot image" and your choice of "Desktop" or "Console" rootfs.

| RPB                                                                                                                                     |
|:----------------------------------------------------------------------------------------------------------------------------------------|
| [Boot Image](https://releases.linaro.org/96boards/dragonboard410c/linaro/openembedded/latest/rpb/boot--*-dragonboard-410c-*.img)                                                                                                               |
| [Desktop](https://releases.linaro.org/96boards/dragonboard410c/linaro/openembedded/latest/rpb/rpb-desktop-image-dragonboard-410c-*.rootfs.ext4.gz) or [Console](https://releases.linaro.org/96boards/dragonboard410c/linaro/openembedded/latest/rpb/rpb-console-image-dragonboard-410c-*.rootfs.ext4.gz)                                                       |
| [Build Folder](https://releases.linaro.org/96boards/dragonboard410c/linaro/openembedded/latest/)                         |

| RPB-Wayland                                                                                                                             |
|:----------------------------------------------------------------------------------------------------------------------------------------|
| [Boot Image](https://releases.linaro.org/96boards/dragonboard410c/linaro/openembedded/latest/rpb-wayland/boot--*-dragonboard-410c-*.img)                                                                                                               |
| [Desktop](https://releases.linaro.org/96boards/dragonboard410c/linaro/openembedded/latest/rpb-wayland/rpb-weston-image-dragonboard-410c-*.rootfs.ext4.gz) or [Console](https://releases.linaro.org/96boards/dragonboard410c/linaro/openembedded/latest/rpb-wayland/rpb-console-image-dragonboard-410c-*.rootfs.ext4.gz)                                               |
| [Build Folder](https://releases.linaro.org/96boards/dragonboard410c/linaro/openembedded/latest/)                 |

> NOTE: Only download one root file system (Console or Desktop). You should match the type of rootfs to the boot image you downloaded above.

#### Continue to [Installation page](../installation/)
