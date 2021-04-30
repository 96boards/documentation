---
title: OpenEmbedded Downloads for Qualcomm Robotics RB5 development kit
permalink: /documentation/consumer/dragonboard/qualcomm-robotics-rb5/downloads/open-embedded.md.html
---
# OpenEmbedded

**OpenEmbedded** is a software framework used for creating Linux distributions aimed for, but not restricted to, embedded devices. Below are pre-built console and desktop images of Debian with their respective bootloader and boot image. If desired, these images can be recreated by following the build from source instructions found [here](https://github.com/Linaro/documentation/blob/master/Reference-Platform/CECommon/OE.md) (Note: this link will take you to the Linaro Github)

***

## Fastboot files (Advanced users)

| Bootloader                                                                                                                              |
|:----------------------------------------------------------------------------------------------------------------------------------------|
| [Download](http://releases.linaro.org/96boards/dragonboard845c/linaro/rescue/latest/dragonboard-845c-bootloader-ufs-linux-*.zip)       |
| [Release Notes](http://releases.linaro.org/96boards/dragonboard845c/linaro/rescue/latest/)      |

Choose between RPB and RPB-Wayland. You will need to download the "boot image" and your choice of "Desktop" or "Console" rootfs.

| RPB                                                                                                                                     |
|:----------------------------------------------------------------------------------------------------------------------------------------|
| [Boot Image](https://releases.linaro.org/96boards/rb5/linaro/openembedded/latest/rpb/boot--*-r0-qrb5165-rb5-*-*.img)                                                                                                               |
| [Desktop](https://releases.linaro.org/96boards/rb5/linaro/openembedded/latest/rpb/rpb-desktop-image-qrb5165-rb5-*-*.rootfs.ext4.gz) or [Console](https://releases.linaro.org/96boards/rb5/linaro/openembedded/latest/rpb/rpb-console-image-qrb5165-rb5-*-*.rootfs.ext4.gz)                                                       |
| [Build Folder](https://releases.linaro.org/96boards/rb5/linaro/openembedded/latest/rpb/)                         |

| RPB-Wayland                                                                                                                             |
|:----------------------------------------------------------------------------------------------------------------------------------------|
| [Boot Image](https://releases.linaro.org/96boards/rb5/linaro/openembedded/latest/rpb-wayland/boot--*-r0-qrb5165-rb5-*-*.img)                                                                                                               |
| [Desktop](https://releases.linaro.org/96boards/rb5/linaro/openembedded/latest/rpb-wayland/rpb-weston-image-qrb5165-rb5-*-*.rootfs.ext4.gz) or [Console](https://releases.linaro.org/96boards/rb5/linaro/openembedded/latest/rpb-wayland/rpb-console-image-qrb5165-rb5-*-*.rootfs.ext4.gz)                                                       |
| [Build Folder](https://releases.linaro.org/96boards/rb5/linaro/openembedded/latest/rpb-wayland/)                 |

> NOTE: Only download one root file system (Console or Desktop). You should match the type of rootfs to the boot image you downloaded above.

#### Continue to [Installation page](../installation/)
