---
title: Create a Bootable SD Card for HiKey
permalink: /documentation/consumer/hikey/hikey620/installation/linux-sd-boot.md.html
redirect_from:
- /documentation/consumer/hikey/installation/linux-sd-boot.md
- /documentation/consumer/hikey/installation/linux-sd-boot.md.html
---

# Create Bootable SD Card

This section show how to install the Debian operating system that is bootable from the SD Card to your HiKey on a Linux host computer.

***

#### Step 1: Make sure you have the latest bootloader flashed:
  - [Board Recovery](board-recovery.md)

#### Step 2: Download SD Card Image
- Download
```shell
$ wget http://snapshots.linaro.org/96boards/hikey/linaro/debian/latest/linaro-stretch-developer-hikey-*.sd.gz -O linaro-stretch-developer-hikey.sd.gz
```
- Decompress
```shell
$ gunzip linaro-stretch-developer-hikey.sd.gz
```

#### Step 3: Flash image to SD Card

- Remove SD card from host computer and run the following command:
```shell
$ lsblk
```
- Note all recognized disk names
- **Insert SD card** and run the following command (again):
```shell
$ lsblk
```
- Note the newly recognized disk. This will be your SD card.
- **Remember** your SD card device name
- Flash SD card
```shell
$ dd if=linaro-stretch-developer-hikey.sd of=/dev/xxx status=progress
```
> NOTE: /dev/xxx is the device name of you sdcard

#### Step 4: Boot HiKey from SD Card
- Make sure the HiKey is Powered OFF
- Insert SD Card into HiKey
- Power On
- Hikey should now boot Debian from SD Card

>**NOTE: SD Card is the first boot preference, It will always boot irrespective of ANY OS flashed on the eMMC**
