---
title: OpenEmbedded and Yocto Guide for Dragonboard410c
permalink: /documentation/ConsumerEdition/DragonBoard-410c/BuildSource/open_embedded.md.html
---

# OpenEmbedded and Yocto

This page provides the Dragonboard410c specific instructions for flashing OpenEmbedded and Yocto images. For instructions on building
the OE/Yocto images, please refer the generic [OpenEmbedded guide](../../guides/open_embedded.md).

# Updating eMMC partitions and Bootloader

Build artifacts from your OE build will be flashed into the on-board eMMC (in contrast to some other boards which run their images from an SDcard). The OpenEmbedded BSP layer assumes that the _Linux_ Bootloaders and eMMC partition layout are used on the 
board (not the _Android_ ones; by default DragonBoards come pre-configured with the Android eMMC partition layout). 
You can download the latest Linux bootloader package for Dragonboard410c from [here](http://builds.96boards.org/releases/dragonboard410c/linaro/rescue/latest/) 
to your development host, it will be named something like `dragonboard410c_bootloader_emmc_linux-<version>.zip`.

Whether your board is using the Android eMMC partition layout or the Linux partition eMMC layout, you will use the 
Android `fastboot` utility on your development host for managing the board's eMMC partitions. If you are using a 
relatively recent Linux distribution on your development host, it probably already has a package that includes 
the `fastboot` utility (it might be named something like `android-tools` or `android-tools-fastboot`) so go ahead and 
install it on your development host.

The procedure for booting Dragonboard410c into `fastboot` mode is given [here](https://github.com/96boards/documentation/blob/master/ConsumerEdition/DragonBoard-410c/Installation/LinuxFastboot.md#step-3-boot-dragonboard-410c-into-fastboot-mode). 
After getting into fastboot mode, update eMMC partition using the downloaded bootloader package by following 
instructions [here](https://github.com/96boards/documentation/blob/master/ConsumerEdition/DragonBoard-410c/Installation/LinuxFastboot.md#step-4-flash-bootloader)

At this point your eMMC has the following partition layout:

* `/dev/mmcblk0p8` , aka `boot` is used for the boot image (kernel, device tree, initrd)
* `/dev/mmcblk0p10` , aka `rootfs` is used for the root file system

# Flashing build artifacts

At the end of any successful build you will end up with the following artifacts (amongst others)
* `IMAGE-dragonboard-410c.ext4.gz` and
* `boot-dragonboard-410c.img`

> Note: Replace `IMAGE` with the name of image you built. For example, if you built `rpb-console-image` then `IMAGE` will 
be `rpb-console-image`

These will be found in your `tmp-rpb-glibc/deploy/images/dragonboard-410c` directory.

After getting into `fastboot` mode, following commands can be used to flash built images onto Dragonboard410c's eMMC.

```shell
$ gunzip IMAGE-dragonboard-410c.ext4.gz
$ sudo fastboot flash boot boot-dragonboard-410c.img
$ sudo fastboot flash rootfs IMAGE-dragonboard-410c.ext4
```
