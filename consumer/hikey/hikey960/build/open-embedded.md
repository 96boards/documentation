---
title: OpenEmbedded and Yocto Guide for Hikey960
permalink: /documentation/consumer/hikey/hikey960/build/open-embedded.md.html
---

# OpenEmbedded and Yocto

This page provides the Hikey specific instructions for flashing OpenEmbedded and Yocto images. For instructions on building
the OE/Yocto images, please visit the generic [OpenEmbedded guide](../../../guides/open_embedded.md).

# Updating UFS partitions and Bootloader

To make sure that the UFS partitions and Bootloader is up to date follow our [Board Recovery Guide](../installation/board-recovery.md)

At this point your eMMC has the following partition layout:

* `boot` is used for the boot image (kernel, device tree, initrd)
* `system` or `userdata` can used for the root file system but not both

# Flashing build artifacts

At the end of any successful build you will end up with the following artifacts (amongst others)
* `IMAGE-hikey960.ext4.gz` and
* `boot-hikey960.uefi.img`

> Note: Replace `IMAGE` with the name of image you built. For example, if you built `rpb-console-image` then `IMAGE` will
be `rpb-console-image`

These will be found in your `tmp-rpb-glibc/deploy/images/hikey960` directory.

After getting into `fastboot` mode, following commands can be used to flash built images onto HiKey960's eMMC.

```shell
$ gunzip --force IMAGE-hikey960.ext4.gz
$ sudo fastboot flash boot boot-hikey960.uefi.img
$ ext2simg -v IMAGE-hikey960.ext4 IMAGE-hikey960.img
```

For using `system` partition for root file system:

```shell
$ sudo fastboot flash system IMAGE-hikey960.img
$ sudo fastboot erase userdata
```

For using `userdata` partition for root file system:

```shell
$ sudo fastboot flash userdata IMAGE-hikey960.img
$ sudo fastboot erase system
```

> Note: Since in HiKey960, root partition is being detected by UUID, so we
>       need to make sure that only one partition has the generated
>       file system image and other one should be empty.
