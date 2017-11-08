---
title: OpenEmbedded and Yocto Guide for Hikey
permalink: /documentation/ConsumerEdition/HiKey/BuildSource/open_embedded.md.html
---

# OpenEmbedded and Yocto

This page provides the Hikey specific instructions for flashing OpenEmbedded and Yocto images. For instructions on building
the OE/Yocto images, please visit the generic [OpenEmbedded guide](../../guides/open_embedded.md).

# Updating eMMC partitions and Bootloader

Build artifacts from your OE build will be flashed into the on-board eMMC (in contrast to some other boards which run their images from an SDcard). The OpenEmbedded BSP layer assumes that the _Linux_ Bootloaders and eMMC partition layout are used on the 
board (not the _Android_ ones; by default HiKey comes pre-configured with the Android eMMC partition layout). 
You can download the latest Linux bootloader binaries from [here](http://builds.96boards.org/releases/hikey/linaro/binaries/latest/).

Whether your board is using the Android eMMC partition layout or the Linux partition eMMC layout, you will use the 
Android `fastboot` utility on your development host for managing the board's eMMC partitions. If you are using a 
relatively recent Linux distribution on your development host, it probably already has a package that includes 
the `fastboot` utility (it might be named something like `android-tools` or `android-tools-fastboot`) so go ahead and 
install it on your development host.

eMMC partiton in Hikey can be updated using the downloaded bootloader binaries by following the instructions [here](https://github.com/96boards/documentation/blob/master/ConsumerEdition/HiKey/Installation/BoardRecovery.md#installing-a-bootloader)

At this point your eMMC has the following partition layout:

* `/dev/mmcblk0p6` , aka `boot` is used for the boot image (kernel, device tree, initrd)
* `/dev/mmcblk0p9` , aka `system` is used for the root file system

# Flashing build artifacts

At the end of any successful build you will end up with the following artifacts (amongst others)
* `IMAGE-hikey.ext4.gz` and
* `boot-hikey.uefi.img`

> Note: Replace `IMAGE` with the name of image you built. For example, if you built `rpb-console-image` then `IMAGE` will 
be `rpb-console-image`

These will be found in your `tmp-rpb-glibc/deploy/images/hikey` directory.

After getting into `fastboot` mode, following commands can be used to flash built images onto HiKey's eMMC.

```shell
$ gunzip IMAGE-hikey.ext4.gz
$ sudo fastboot flash boot boot-hikey.uefi.img
$ ext2simg -v IMAGE-hikey.ext4 IMAGE-hikey.img
$ sudo fastboot flash system IMAGE-hikey.img
```
