---
title: How to force display resolution and bypass EDID
permalink: /documentation/consumer/dragonboard410c/guides/force-display-res.md.html
redirect_from:
- /db410c-getting-started/Guides/ForceDisplayRes.md/
- /documentation/ConsumerEdition/DragonBoard-410c/Guides/ForceDisplayRes.md.html
---
# How to force display resolution and bypass EDID

## Abstract

Sometimes when using HDMI monitor it might be needed (or useful) to force a display resolution, and bypass the processing of the EDID. Note this wiki page is applicable to Linux releases only, not Android (for now).

## Method 1: Using DRM_LOAD_EDID_FIRMWARE

### Details

This is a Linux kernel feature that can be used:

    if you want to use EDID data to be loaded from the
    /lib/firmware directory or one of the provided built-in
    data sets. This may be necessary, if the graphics adapter or
    monitor are unable to provide appropriate EDID data. Since this
    feature is provided as a workaround for broken hardware, it is
    disabled by default.

Details and instructions how to build your own EDID data are given in [Documentation/EDID/HOWTO.txt](https://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/tree/Documentation/EDID/HOWTO.txt).

So basically, when using this feature the real EDID is not used, and is being replaced by a fake one.

By default, the kernel has the following prebuilt EDID:

    #define GENERIC_EDIDS 6
    static const char *generic_edid_name[GENERIC_EDIDS] = {
            "edid/800x600.bin",
            "edid/1024x768.bin",
            "edid/1280x1024.bin",
            "edid/1600x1200.bin",
            "edid/1680x1050.bin",
            "edid/1920x1080.bin",
    };

This structure is defined in the kernel, in [drivers/gpu/drm/drm_edid_load.c](https://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/tree/drivers/gpu/drm/drm_edid_load.c).

### How to boot with a custom EDID file?

In order to use this kernel feature, the following kernel config must be enabled:

    CONFIG_DRM_LOAD_EDID_FIRMWARE=y

Note: it is enabled by default on DragonBoard 410c Linux releases from http://builds.96boards.org/releases/dragonboard410c/linaro/debian/.

The name of the custom EDID file needs to be given in the kernel boot arguments.

#### Using a DragonBoard 410c release

If you are using a binary release for DragonBoard 410c from Linaro/96boards, you do not need to recompile the Linux kernel in order to modify the bootargs. You can follow the next instructions:

##### Download the boot image

Identify which release or build you are running and download the released boot image. This file is usually called ` boot-linaro-jessie-qcom-snapdragon-arm64-xxx.img.gz` and can be found for example in http://builds.96boards.org/releases/dragonboard410c/linaro/debian/. Once you have the file, you need to unzip it.

##### Modify the boot image to use different bootargs

To manipulate boot image file, you need to install a tool called `abootimg`, if you are running Debian or Ubuntu or your host machine, you can get it with:

    sudo apt-get install abootimg

Before you modify the bootargs, you first need to extract the current bootargs, so that we can later append the custom EDID to them. To print the current bootargs, run:

    abootimg -i

You will see in the output a line like this one:

    * cmdline = root=/dev/disk/by-partlabel/rootfs rw rootwait console=tty0 console=ttyMSM0,115200n8

This is what the current bootargs is for your release. You can now create a new boot image with the custom EDID configuration appended to the current bootargs:

    cp boot-linaro-jessie-qcom-snapdragon-arm64-xxx.img. boot-new-edid.img
    abootimg -u boot-new-edid.img -c "cmdline=root=/dev/disk/by-partlabel/rootfs rw rootwait console=tty0 console=ttyMSM0,115200n8 drm_kms_helper.edid_firmware=edid/1280x1024.bin"

It is important to note:
* the first part of the bootargs used above must be the same as the one you got from the output of `abootimg -i` command above
* You can use any of the custom EDID files described above, in which case, replace 1280x1024.bin by another valid resolution

##### Booting the new boot image

In order to use a new boot image, you need to put the device into fastboot mode, so that the boot partition can be flashed again.
* connect the micro USB cable between the board and the host
* power off the board
* press the Vol- (down) button, and power on the board

At this point, you can run fastboot from the host PC. You can run the following fastboot command to boot it on the board:

    sudo fastboot boot boot-new-edid.img

If it worked fine, and that you want to permanently use this new boot image, you canflash it into the boot partition:

    sudo fastboot flash boot boot-new-edid.img

#### Compiling your own kernel

If you are compiling and booting your own kernel you need to add the following to the bootargs you are using:

    drm_kms_helper.edid_firmware=edid/1280x1024.bin

You can use any of the custom EDID files described above, of course.
