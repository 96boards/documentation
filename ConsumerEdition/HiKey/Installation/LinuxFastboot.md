---
title: Linux Host Installation for HiKey
permalink: /documentation/ConsumerEdition/HiKey/Installation/LinuxFastboot.md/
---
## Linux Host

This section shows how to install new operating system to your HiKey using the fastboot method on a Linux host computer.

***

- **Step 1**: Make sure fastboot is set up on host computer
- **Step 2**: Boot HiKey into Fastboot mode using J15 header
- **Step 3**: Install Operating System update using downloaded files
- **Step 4**: Reboot HiKey into new OS

***

#### **Step 1**: Make sure fastboot is set up on host computer.

- Android SDK “Platform-Tools” for Linux can be downloaded <a href="https://developer.android.com/studio/releases/platform-tools.html" target="_blank">here</a>

**Step 2**: Boot HiKey into Fastboot mode using J15 header

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
>Note: If your HiKey is not being detected by fastboot, you might want to try [Board Recovery](BoardRecovery.md) and return to this step once your board is ready

**Step 3**: Install Operating System update using downloaded files

>**NOTE:** the ptable must be flashed first. Wait for a few seconds after the reboot command to allow the bootloader to restart using the new partition table.

###### Debian Linux

```shell
$ sudo fastboot flash ptable <ptable_FILE_NAME>.img
$ sudo fastboot reboot
$ sudo fastboot flash boot <boot_FILE_NAME>.uefi.img
$ sudo fastboot flash system hikey-jessie_alip_2015MMDD-nnn-Xg.emmc.img
```

###### AOSP

```shell
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
