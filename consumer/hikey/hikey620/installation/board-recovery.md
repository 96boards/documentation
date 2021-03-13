---
title: BoardRecovery for HiKey
permalink: /documentation/consumer/hikey/hikey620/installation/board-recovery.md.html
redirect_from:
- /documentation/ConsumerEdition/HiKey/Installation/BoardRecovery.md.html
- /documentation/consumer/hikey/installation/board-recovery.md
- /documentation/consumer/hikey/installation/board-recovery.md.html
---
# HiKey Board Recovery

This page outlines steps needed to recover your HiKey board from a bricked software state. This instruction set is suggested to those who are experiences boot issues due to a corrution in the file system and/or other software components.

## Installing a Bootloader

For most users a board can be “recovered” from a software failure by reloading the operating system. However, if the primary bootloader in the eMMC flash memory has been corrupted then the bootloader will need to be re-installed. This section describes how to reinstall the primary bootloader.

#### Choose your Operating System and download the following files

- **Build Folders [UEFI debug](https://snapshots.linaro.org/reference-platform/components/uefi-staging/latest/hikey/debug/)**

|  Debian                      |
|:----------------------------:|
| [recovery.bin](https://snapshots.linaro.org/reference-platform/components/uefi-staging/latest/hikey/debug/recovery.bin)  |  
| [l-loader.bin](https://snapshots.linaro.org/reference-platform/components/uefi-staging/latest/hikey/debug/l-loader.bin)  |  
|  [fip.bin](https://snapshots.linaro.org/reference-platform/components/uefi-staging/latest/hikey/debug/fip.bin)           |  
| [ptable-linux-4g.img](https://releases.linaro.org/96boards/hikey/linaro/binaries/latest/ptable-linux-4g.img) or [ptable-linux-8g.img](https://releases.linaro.org/96boards/hikey/linaro/binaries/latest/ptable-linux-8g.img)     |

- **Build Folders [UEFI release](https://snapshots.linaro.org/reference-platform/components/uefi-staging/latest/hikey/debug/)**

|  AOSP                      |
|:----------------------------:|
| [recovery.bin](https://snapshots.linaro.org/reference-platform/components/uefi-staging/latest/hikey/debug/recovery.bin)  |  
| [l-loader.bin](https://snapshots.linaro.org/reference-platform/components/uefi-staging/latest/hikey/debug/l-loader.bin)  |  
|  [fip.bin](https://snapshots.linaro.org/reference-platform/components/uefi-staging/latest/hikey/debug/fip.bin)           |  
| [ptable-aosp-4g.img](https://releases.linaro.org/96boards/hikey/linaro/binaries/latest/ptable-aosp-8g.img) or [ptable-linux-8g.img](https://releases.linaro.org/96boards/hikey/linaro/binaries/latest/ptable-aosp-8g.img)     |

You can do this from your browser(above links) or from the command prompt(below commands):

For a full recovery you will need: **recovery.bin**, **l-loader.bin**, **fip.bin**, and the appropriate **p-table image**(this is board specific)

- Debug Builds
```shell
$ wget https://snapshots.linaro.org/reference-platform/components/uefi-staging/latest/hikey/debug/recovery.bin
$ wget https://snapshots.linaro.org/reference-platform/components/uefi-staging/latest/hikey/debug/l-loader.bin
$ wget https://snapshots.linaro.org/reference-platform/components/uefi-staging/latest/hikey/debug/fip.bin
$ wget https://releases.linaro.org/96boards/hikey/linaro/binaries/latest/ptable-linux-4g.img
$ wget https://releases.linaro.org/96boards/hikey/linaro/binaries/latest/ptable-linux-8g.img
```
- Release Builds
```shell
$ wget https://snapshots.linaro.org/reference-platform/components/uefi-staging/latest/hikey/release/recovery.bin
$ wget https://snapshots.linaro.org/reference-platform/components/uefi-staging/latest/hikey/release/l-loader.bin
$ wget https://snapshots.linaro.org/reference-platform/components/uefi-staging/latest/hikey/release/fip.bin
$ wget https://releases.linaro.org/96boards/hikey/linaro/binaries/latest/ptable-linux-4g.img
$ wget https://releases.linaro.org/96boards/hikey/linaro/binaries/latest/ptable-linux-8g.img
```

#### Make sure fastboot is set up on host computer

- Android SDK “Tools only” for Linux can be downloaded <a href="http://developer.android.com/sdk" target="_blank">here</a>
- The Linux “Tools Only” SDK download does not come with fastboot, you will need to use the Android SDK Manager to install platform-tools.
- To do this follow the “SDK Readme.txt” instructions included in your SDK “Tools Only” download.

If you are still having trouble setting up fastboot, <a href="https://youtu.be/W_zlydVBftA" target="_blank">click here</a> for a short tutorial video

#### Connect a standard microUSB cable between the HiKey microUSB and your Linux PC.

HiKey should **NOT** be power on at this stage

#### Set Board Link options

For flashing the bootloader, the top two links should be installed (closed) and the 3rd link should be removed (open):

Name | Link | State
---- | ---- | -----
Auto Power up | Link 1-2 | closed
Boot Select | Link 3-4 | closed
GPIO3-1 | Link 5-6 | open

Link 1-2 causes HiKey to auto-power up when power is installed. Link 3-4 causes the HiKey SoC internal ROM to start up in at a special "install bootloader" mode which will install a supplied bootloader from the microUSB OTG port into RAM, and will present itself to a connected PC as a ttyUSB device.

Please refer to the [Hardware User Guide](https://github.com/96boards/documentation/blob/master/consumer/hikey/hikey620/hardware-docs/HiKey_User_Guide_CircuitCo.pdf) (Chapter 1. Settings Jumper) for more information on the HiKey link options.

#### Connect the HiKey power supply to the board.

**NOTE:** USB does NOT power the HiKey board. You must use an external power supply.

**NOTE:** The HiKey board will remain in USB load mode for 90 seconds from power up. If you take longer than 90 seconds to start the install then power cycle the board before trying again.

#### Wait about 5 seconds and then check that the HiKey board has been recognized by your Linux PC:

```
$ ls /dev/ttyUSB*
or
$ dmesg
```

#### Download hisi-idt.py "download tool" for the HiKey

[hisi-idt.py](https://snapshots.linaro.org/reference-platform/components/uefi-staging/latest/hikey/debug/hisi-idt.py) is the download tool for the HiKey. This is used to install the bootloader as follows:

This script can also be downloaded using the wget command in your commandline:

```
$ wget https://snapshots.linaro.org/reference-platform/components/uefi-staging/latest/hikey/release/hisi-idt.py
```

#### Run the script to initially prepare fastboot

Make sure the modem interface is in the right ttyUSB as previously suggested. In this example, use ttyUSB1:

```
$ sudo python hisi-idt.py -d /dev/ttyUSB1 --img1 recovery.bin
```

> Note: This script only works with Python2.7

#### After the python command has been issued you should see the following output. If you do not then see the "Problems with Python Downloader" section below

```
+----------------------+
 Serial:  /dev/ttyUSB0
 Image1:  recovery.bin
 Image2:  
+----------------------+

Sending recovery.bin ...
Done
```

The bootloader has now been installed into RAM. Wait a few seconds for the fastboot application to actually load. The following fastboot commands
loads the **partition table, bootloader, and other necessary files into the HiKey eMMC flash memory (4GB or 8GB)**.


```
$ sudo fastboot flash ptable ptable-linux-8g.img
```
> HiKey with 8GB eMMC is used for this example.

```
$ sudo fastboot flash loader l-loader.bin
$ sudo fastboot flash fastboot fip.bin
```

Once this has been completed the bootloader has been installed into eMMC.

#### Power off the HiKey board by removing the power supply jack and change the link configuration as follows:

Name | Link | State
---- | ---- | -----
Auto Power up | Link 1-2 | closed
Boot Select | Link 3-4 | open
GPIO3-1 | Link 5-6 | closed

#### Connect power supply jack to your HiKey again

Check that the HiKey board is detected by your Linux PC

Wait about 10 seconds.

You should see the ID of the HiKey board returned

```
$ sudo fastboot devices
0123456789abcdef fastboot
```

Your bootloader has been successfully installed and you are now ready to install the operating system files into the eMMC flash memory, for this go to the ([HiKey Installation](README.md)) page.

**NOTE:**

This bootloader is based on UEFI and includes:
- ARM Trusted Firmware
- UEFI with DeviceTree
- GRUB
- fastboot support
- OP-TEE support
