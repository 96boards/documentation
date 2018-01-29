---
title: OpenEmbedded Guide for Dragonboard820c
permalink: /documentation/consumer/dragonboard820c/build/open-embedded.md.html
---

# OpenEmbedded

This page provides the Dragonboard820c specific instructions for flashing OpenEmbedded images. For instructions on building
the OE images, please refer the generic [OpenEmbedded guide](../../guides/open_embedded.md).

# Updating UFS partitions and Bootloader

To make sure that the UFS partitions and Bootloader is up to date follow our [Board Recovery Guide](../installation/board-recovery.md)

# Install fastboot

Whether your board is using the Android UFS partition layout or the Linux partition UFS layout, you will use the
Android `fastboot` utility on your development host for managing the board's UFS partitions. If you are using a
relatively recent Linux distribution on your development host, it probably already has a package that includes
the `fastboot` utility (it might be named something like `android-tools` or `android-tools-fastboot`) so go ahead and
install it on your development host.

# Flashing build artifacts

At the end of any successful build you will end up with the following artifacts (amongst others)
* `IMAGE-dragonboard-820c.ext4.gz` and
* `boot-dragonboard-820c.img`

> Note: Replace `IMAGE` with the name of image you built. For example, if you built `rpb-console-image` then `IMAGE` will
be `rpb-console-image`

These will be found in your `tmp-rpb-glibc/deploy/images/dragonboard-820c` directory.

After getting into `fastboot` mode, following commands can be used to flash built images onto Dragonboard820c's UFS.

```shell
$ gunzip IMAGE-dragonboard-820c.ext4.gz
$ sudo fastboot flash boot boot-dragonboard-820c.img
$ sudo fastboot flash system IMAGE-dragonboard-820c.ext4
```
