---
title: Linux Host Installation for HiKey960
permalink: /documentation/ConsumerEdition/HiKey960/Installation/LinuxFastboot.md/
---
# Linux Host

This section show how to install a new operating system to your HiKey960 using the fastboot method on a Linux host computer.

***

- **Step 1**: Materials and Preperations
- **Step 2**: Dependencies
- **Step 3**: Flash base firmware (if needed)
- **Step 4**: Boot HiKey960 into fastboot mode
- **Step 5**: Flash Operating System
- **Step 6**: Reboot

***

## Step 1: Materials and Preperations

**Materials**

- [HiKey960](http://www.96boards.org/product/hikey960/)
- USB Type-A (Host machine) to USB Type-C (96Boards) cable
- [96Boards compliant power supply](http://www.96boards.org/product/power/)

**Preperations**

There are two versions of HiKey960  |
----------------------------------- |
v1 uses Jumpers (J2001)             |
v2 uses DIP Switches (SW2201)       |

Both are located at the bottom side of the board  |
------------------------------------------------- |
Jumper Pin 1-2 = DIP switch 1                     |
Jumper Pin 3-4 = DIP switch 2                     |
Jumper Pin 5-6 = DIP switch 3                     |

- To boot into fastboot mode everytime set switch 1 & 3 to ON state
  and switch 2 to OFF state.
- To boot into fastboot mode at every alternate rebooot set switch 1
  to ON and switch 2 & 3 to OFF state.
- To boot into recovery mode set switch 1 & 2 to ON state and switch 3
  to OFF state

## Step 2: Dependencies

**Host Linux Machine**

- Android SDK “Platform-Tools” for Linux can be downloaded <a href="https://developer.android.com/studio/releases/platform-tools.html" target="_blank">here</a>
- Download appropriate operating system images from ["Downloads page"](../Downloads/)

## Step 3: Flash base firmware (only if necessary)

Most release-level devices should not require this step to updating the base firmware, so this step mostly applies to pre-release boards, and can be skipped (head on to **Step 4** of the instructions). However, if your board does not boot after being flashed, its advised to do a recovery flash to ensure lower-level firmware components are properly flashed.

Instructions on how to do a recovery flash of the base firmware are kept in a seperate repository and can be found [here](https://github.com/96boards-hikey/tools-images-hikey960/blob/master/)

## Step 4: Boot HiKey 960 into fastboot mode

- HiKey960 must be powered off (unplugged from power, this includes both 96Boards compliant power supply and USB Type-C connections)
- Make sure microSD card slot on HiKey960 is empty
- Jumper/Dip Switch setting should be set as follows

Name          | Link / Switch       | State
------------- | ------------------- | ----------
Auto Power up | Link 1-2 / Switch 1 | closed / ON
Recovery      | Link 3-4 / Switch 2 | open / OFF
Fastboot      | Link 5-6 / Switch 3 | closed / ON

- Connect USB Type-C cable AND 96Boards compliant power supply to HiKey960, ensure USB is connected to host machine
- Open "Terminal" on host machine and execute the following command

```shell
$ sudo fastboot devices
```

If your HiKey960 is pre-flashed with appropriate firmware, you should see your device lised as an output:

```shell
447786182000000         fastboot
```

**At this point you should be connected to your HiKey960 with a USB Type-A to USB Type-C cable. Your HiKey960 should be booted into fastboot mode and ready to be flashed with the appropriate images.**

## Step 5: Flash Operating System

Run the flash-all.sh script located in your download to update boot files using fastboot.
This script assumes you have already built all HiKey960 AOSP images locally.

```shell
$ sudo ./flash-all.sh
```

## Step 6: Reboot

- Unplug power to HiKey960 (both 96Boards compliant power supply and USB Type-C)
- Jumper/Dip Switch setting should be set as follows

Name          | Link / Switch       | State
------------- | ------------------- | ----------
Auto Power up | Link 1-2 / Switch 1 | closed / ON
Recovery      | Link 3-4 / Switch 2 | open / OFF
Fastboot      | Link 5-6 / Switch 3 | open / OFF

- Ensure HDMI connection to monitor
- Ensure keyboard and/or mouse connection
- Plug power back into HiKey960 (96Boards compliant power supply)
- Wait for board to boot up

**Congratulations! You are now booting your newly installed OS directly
from eMMC on the HiKey960!**

[Return to HiKey960 documentation home](../)
