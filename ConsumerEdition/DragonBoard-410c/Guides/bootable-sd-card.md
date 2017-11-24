---
title: Create a bootable SD card
permalink: /documentation/ConsumerEdition/DragonBoard-410c/Guides/bootable-sd-card.md.html
---
# Create a bootable SD card for Dragonboard410c

This page provides information to create a bootable SD card for DragonBoard410c. It is possible to boot the entire OS from the SD card, without modifying the eMMC content, assuming you are using a Linux based system. The instructions in this section will not work with Android (or Windows).

# Table of Contents

- [1) Software Required](#1-software-required)
- [2) Partition SD card](#2-partition-sd-card)
- [3) Booting OpenEmbedded image](#3-booting-openembedded-image)
- [4) Booting Debian image](#4-booting-debian-image)

# 1) Software Required

For booting from SD card we need to have patched version of LK bootloader, Boot image and a Root file system. These could be downloaded using the following commands:

```shell
$ wget http://builds.96boards.org/snapshots/dragonboard410c/linaro/rescue/latest/dragonboard-410c-bootloader-sd-linux-*.zip -O dragonboard410c_bootloader_sd_linux.zip
$ wget http://builds.96boards.org/snapshots/dragonboard410c/linaro/openembedded/morty/latest/rpb/boot--*-dragonboard-410c-*.img
$ wget http://builds.96boards.org/snapshots/dragonboard410c/linaro/openembedded/morty/latest/rpb/rpb-desktop-image-dragonboard-410c-*.rootfs.img.gz
$ gunzip rpb-desktop-image-dragonboard-410c-XXX.rootfs.img.gz
```

> Note: Replace XXX with the downloaded image revision number

If you are curious to see the source code of LK bootloader modified for SD boot, clone the source as mentioned below, ignore otherwise.

```shell
$ git clone --depth 1 \
     https://git.linaro.org/landing-teams/working/qualcomm/lk.git \
     -b release/LA.BR.1.1.2-02210-8x16.0+sdboot lk_sdboot
```

# 2) Partition SD card

For booting from SD card, the boot media is required to be partitioned using very specific GPT scheme. The tool below will take care of that. You can inspect the tool to understand the low level details. The SD card will be created with a default partition scheme that includes all the required boot partitions, as well as 2 partitions for the kernel and the rootfs, called *boot* and *rootfs*. Once the SD card is created you can load any valid boot image and rootfs into these partitions.

To create the bootable SD card:

```shell
$ unzip -d qcom_bootloaders dragonboard410c_bootloader_sd_linux.zip
$ git clone https://git.linaro.org/landing-teams/working/qualcomm/db-boot-tools.git
$ cd db-boot-tools
$ sudo ./mksdcard -o /dev/XXX -p dragonboard410c/linux/sdcard.txt \
     -i ../qcom_bootloaders -s 2G
```

Notes:
* /dev/XXX represents your SD card, plugged to your PC. The SD card will be completely erased during this process.  
* be very cautious about the SD card device name, or you could seriously damage your PC
* 2G is the default size of the SD card image. It can be less than the actual SD card size, but not more.

When the command above finishes, your SD card should be partitioned using right GPT. You now need to provision a valid boot image and rootfs onto the SD card.

# 3) Booting OpenEmbedded image

You can boot one of our OpenEmbedded reference image from the SD card. But it is possible to boot any valid boot and rootfs image.

The downloaded boot image will by default try to mount the rootfs on the eMMC, so we need to modify the root parameter in the bootargs:

```shell
$ sudo apt-get install abootimg
$ abootimg -u boot-XXX.img -c "cmdline=root=/dev/mmcblk1p9 rw rootwait console=ttyMSM0,115200n8"
```

Where:
* /dev/mmcblk1p9 represents the rootfs partition on SD card to Linux kernel.

You can now write the boot and rootfs image into the SD card:

```shell
$ sudo dd if=boot-XXX.img of=/dev/XXX7
$ sudo dd if=rpb-desktop-image-dragonboard-410c-XXX.rootfs.img of=/dev/XXX9
```

Where:
* /dev/XXX7 represents the 'boot' partition on the SD card
* /dev/XXX9 represents the 'rootfs' partition on the SD card
* you can check the mapping between partition IDs and partition names using `gdisk -l` command

If you insert the SD card into the DragonBoard410c and set the switch S6-2 (on the back) to ON, you should now be able to boot from SD card.

# 4) Booting Debian image

Download boot and root images from:
  - **Release:** http://builds.96boards.org/releases/dragonboard410c/linaro/debian/latest/
  ```
  $ wget http://builds.96boards.org/releases/dragonboard410c/linaro/debian/latest/boot-sdcard-linaro-stretch-qcom-snapdragon-arm64-*.img.gz
  $ wget http://builds.96boards.org/releases/dragonboard410c/linaro/debian/latest/linaro-stretch-alip-qcom-snapdragon-arm64-*.img.gz
  ```


  - **Snapshot:** http://builds.96boards.org/snapshots/dragonboard410c/linaro/debian/latest/
  ```shell
  $ wget https://builds.96boards.org/snapshots/dragonboard410c/linaro/debian/latest/boot-sdcard-linaro-*-dragonboard-410c-*.img.gz
  $ wget https://builds.96boards.org/snapshots/dragonboard410c/linaro/debian/latest/linaro-*-alip-dragonboard-410c-*.img.gz
  ```
  And then extract the images using ```gunzip```

  Example:
  ```shell
  $ gunzip boot-sdcard-linaro-stretch-qcom-snapdragon-arm64-*.img.gz
  $ gunzip linaro-stretch-alip-qcom-snapdragon-arm64-*.img.gz
  ```

Since we are already downloading the boot-sdcard-xxx.img.gz, we do not need to modify the boot parameters.

You can now write the boot and rootfs image into the SD card:

```shell
$ sudo dd if=boot-sdcard-XXX.img of=/dev/XXX7
$ sudo simg2img linaro-stretch-alip-XXX.img /dev/XXX9
```
NOTE: you may need to install the ```simg2img``` package using:
```shell
$ sudo apt install simg2img
# OR
$ sudo apt install android-tools-fsutils
```

Where:
* /dev/XXX7 represents the 'boot' partition on the SD card
* /dev/XXX9 represents the 'rootfs' partition on the SD card
* you can check the mapping between partition IDs and partition names using `gdisk -l` command

If you insert the SD card into the DragonBoard410c and set the switch S6-2 (on the back) to ON, you should now be able to boot to Debian from the SD Card.
