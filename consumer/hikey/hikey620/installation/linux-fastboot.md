---
title: Linux Host Installation for HiKey
permalink: /documentation/consumer/hikey/hikey620/installation/linux-fastboot.md.html
redirect_from:
- /documentation/ConsumerEdition/HiKey/Installation/LinuxFastboot.md.html
- /documentation/consumer/hikey/installation/linux-fastboot.md.html
---
## Linux Host

This section shows how to install new operating system to your HiKey using the fastboot method on a Linux host computer.

***

- **Step 1**: Make sure fastboot is set up on host computer
- **Step 2**: Make sure you have the latest bootloader installed
- **Step 3**: Boot HiKey into Fastboot mode using J15 header
- **Step 4**: Install Operating System update using downloaded files
- **Step 5**: Reboot HiKey into new OS

***

#### **Step 1**: Make sure fastboot is set up on host computer.

- [Android SDK “Platform-Tools” for Linux can be downloaded](https://developer.android.com/studio/releases/platform-tools.html)

#### **Step 2**: Make sure you have the latest bootloader installed.

  - [Board Recovery](board-recovery.md)

#### **Step 3**: Boot HiKey into Fastboot mode using J15 header

- Link pins 1 and 2
- Link pins 5 and 6
- Connect host computer to HiKey board using USB to microUSB cable

Name | Link | State
---- | ---- | -----
Auto Power up | Link 1-2 | closed
Boot Select | Link 3-4 | open
GPIO3-1 | Link 5-6 | closed

- Power on HiKey board by plugging in power adapter
- Esure HiKey is detected by host computere
- Wait for about 10 seconds
- Open Terminal application and execute the following:

```shell
$ sudo fastboot devices
0123456789abcdef fastboot
```
>Note: If your HiKey is not being detected by fastboot, you might want to try [Board Recovery](board-recovery.md) and return to this step once your board is ready

#### **Step 3**: Install Operating System update using downloaded files

>**NOTE:** the ptable must be flashed first. Wait for a few seconds after the reboot command to allow the bootloader to restart using the new partition table.

###### Debian Linux

- Download and decompress Files
```shell
# BOOT IMAGE
$ wget http://snapshots.linaro.org/96boards/hikey/linaro/debian/latest/boot-linaro-stretch-developer-hikey-*.img.gz -O boot-linaro-stretch-developer-hikey.img.gz
$ gunzip boot-linaro-stretch-developer-hikey.img.gz
# ROOTFS IMAGE
$ wget http://snapshots.linaro.org/96boards/hikey/linaro/debian/latest/rootfs-linaro-stretch-developer-hikey-*.img.gz -O rootfs-linaro-stretch-developer-hikey.img.gz
$ gunzip rootfs-linaro-stretch-developer-hikey.img.gz
# PTABLE IMAGE FOR 8GB EMMC
$ wget https://snapshots.linaro.org/reference-platform/components/uefi-staging/latest/hikey/debug/ptable-linux-8g.img
# PTABLE IMAGE FOR 4GB EMMC
$ wget https://snapshots.linaro.org/reference-platform/components/uefi-staging/latest/hikey/debug/ptable-linux-4g.img
```
- Flash eMMC
```shell
$ sudo fastboot getvar partition-size:ptable
$ sudo fastboot flash ptable ptable-linux-8g.img #OR ptable-linux-4g.img
$ sudo fastboot reboot
$ sudo fastboot flash boot boot-linaro-stretch-developer-hikey.img
$ sudo fastboot flash system rootfs-linaro-stretch-developer-hikey.img
```

###### AOSP

```shell
$ sudo fastboot getvar partition-size:ptable
$ sudo fastboot flash ptable ptable-aosp-8g.img
$ sudo fastboot reboot
$ sudo fastboot flash boot boot_fat.uefi.img
$ sudo fastboot flash cache cache.img
$ sudo fastboot flash system system.img
$ sudo fastboot flash userdata userdata-8gb.img
```

**Step 4**: Reboot HiKey into new OS

- Wait untill all files have been flashed onto HiKey board
- Power down HiKey by unplugging the power adapter
- Remove microUSB cable from HiKey
- Remove Link 5-6 from J15 header

Name | Link | State
---- | ---- | -----
Auto Power up | Link 1-2 | closed
Boot Select | Link 3-4 | open
GPIO3-1 | Link 5-6 | open

- Plug mouse/keyboard USB into type A USB ports
- Power up HiKey by plugging in power adapter


**Note:** the **username** and **password** are both **“linaro”** when the login information is requested.

**Congratulations! You are now booting your newly installed OS directly
from eMMC on the HiKey!**
