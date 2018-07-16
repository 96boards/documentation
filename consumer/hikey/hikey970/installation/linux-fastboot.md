---
title: Linux Host Installation for HiKey970
permalink: /documentation/consumer/hikey/hikey970/installation/linux-fastboot.md.html
redirect_from: /documentation/consumer/hikey970/installation/linux-fastboot.md.html
---
# Linux Host

This section show how to install a new operating system to your HiKey970 using the fastboot method on a Linux host computer.

***

- **Step 1**: Materials and Preperations
- **Step 2**: Dependencies
- **Step 3**: Flash base firmware (if needed)
- **Step 4**: Boot HiKey970 into fastboot mode
- **Step 5**: Flash Operating System
- **Step 6**: Reboot

***

## Step 1: Materials and Preperations

**Materials**

- HiKey970
- USB Type-A (Host machine) to USB Type-C (96Boards) cable
- [96Boards compliant power supply](https://www.96boards.org/product/power/)

**Preperations**

Both are located at the bottom side of the board  |
------------------------------------------------- |
Jumper Pin 1-2 = DIP switch 1                     |
Jumper Pin 3-4 = DIP switch 2                     |
Jumper Pin 5-6 = DIP switch 3                     |

- To boot into fastboot mode everytime set switch 1 & 3 to ON state
  and switch 2 to OFF state.
- To boot into fastboot mode at every alternate rebooot set switch 1
  to ON and switch 2 & 3 to OFF state.
- To boot into recovery mode set switch 1, 2 & 3 to ON state.`

## Step 2: Dependencies

**Host Linux Machine**

- Android SDK “Platform-Tools” for Linux can be downloaded <a href="https://developer.android.com/studio/releases/platform-tools.html" target="_blank">here</a>
- Download appropriate operating system images from ["Downloads page"](../downloads/)

## Step 3: Flash base firmware (only if necessary)

Most release-level devices should not require this step to updating the base firmware, so this step mostly applies to pre-release boards, and can be skipped (head on to **Step 4** of the instructions). However, if your board does not boot after being flashed, its advised to do a recovery flash to ensure lower-level firmware components are properly flashed.

Instructions on how to do a recovery flash of the base firmware can be found [here](board-recovery.md).

## Step 4: Boot HiKey 970 into fastboot mode

- HiKey970 must be powered off (unplugged from power, this includes both 96Boards compliant power supply and USB Type-C connections)
- Make sure microSD card slot on HiKey970 is empty
- Jumper/Dip Switch setting should be set as follows

Name          | Switch   | State
------------- | -------- | ----------
Auto Power up | Switch 1 | closed / ON
Recovery      | Switch 2 | open / OFF
Fastboot      | Switch 3 | closed / ON

- Connect USB Type-C cable AND 96Boards compliant power supply to HiKey970, ensure USB is connected to host machine
- Open "Terminal" on host machine and execute the following command

```shell
$ sudo fastboot devices
```

If your HiKey970 is pre-flashed with appropriate firmware, you should see your device lised as an output:

```shell
447786182000000         fastboot
```

**At this point you should be connected to your HiKey970 with a USB Type-A to USB Type-C cable. Your HiKey970 should be booted into fastboot mode and ready to be flashed with the appropriate images.**

## Step 5: Flash Operating System

#### AOSP

Unzip the downloaded image in a directory and execute the below commands
from it to flash HiKey970 with AOSP.

```shell
$ sudo fastboot flash ptable prm_ptable.img
$ sudo fastboot flash xloader sec_xloader.img
$ sudo fastboot flash fastboot l-loader.bin
$ sudo fastboot flash fip fip.bin
$ sudo fastboot flash boot boot.img
$ sudo fastboot flash cache cache.img
$ sudo fastboot flash system system.img
$ sudo fastboot flash userdata userdata.img
```

#### Debian Linux

Coming soon...

## Step 6: Reboot

- Unplug power to HiKey970 (both 96Boards compliant power supply and USB Type-C)
- Jumper/Dip Switch setting should be set as follows

Name          | Switch   | State
------------- | -------- | ----------
Auto Power up | Switch 1 | closed / ON
Recovery      | Switch 2 | open / OFF
Fastboot      | Switch 3 | open / OFF

- Ensure HDMI connection to monitor
- Ensure keyboard and/or mouse connection
- Plug power back into HiKey970 (96Boards compliant power supply)
- Wait for board to boot up

**Congratulations! You are now booting your newly installed OS directly
from UFS on the HiKey970!**

[Return to HiKey970 documentation home](../)
