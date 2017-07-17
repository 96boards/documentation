---
title: BoardRecovery for HiKey
permalink: /documentation/ConsumerEdition/HiKey/Installation/BoardRecovery.md/
---
# HiKey Board Recovery

This page outlines steps needed to recover your HiKey board from a bricked software state. This instruction set is suggested to those who are experiences boot issues due to a corrution in the file system and/or other software components.

## Installing a Bootloader

For most users a board can be “recovered” from a software failure by reloading the operating system. However, if the primary bootloader in the eMMC flash memory has been corrupted then the bootloader will need to be re-installed. This section describes how to reinstall the primary bootloader.

#### Choose your Operating System and download the following files

Build Folders <a href="http://builds.96boards.org/releases/reference-platform/debian/hikey/16.06/bootloader/" target="_blank">Debian</a>


|  Debian                      |
|:----------------------------:|
| [l-loader.bin](http://builds.96boards.org/releases/reference-platform/debian/hikey/16.06/bootloader/l-loader.bin)  |  
|  [fip.bin](http://builds.96boards.org/releases/reference-platform/debian/hikey/16.06/bootloader/fip.bin)           |  
| [nvme.img](http://builds.96boards.org/releases/reference-platform/debian/hikey/16.06/bootloader/nvme.img)          |
| [ptable-linux-4g.img](http://builds.96boards.org/releases/reference-platform/debian/hikey/16.06/bootloader/ptable-linux-4g.img) or [ptable-linux-8g.img](http://builds.96boards.org/releases/reference-platform/debian/hikey/16.06/bootloader/ptable-linux-8g.img)     |

#### You will also need the boot partition for the OS Image you want to run

- [boot-linux.uefi.img](http://builds.96boards.org/releases/reference-platform/debian/hikey/16.06/hikey-boot-linux-*.uefi.img.gz) (For Debian)

You can do this from your browser(above links) or from the command prompt(below commands):

For a full recovery you will need: **l-loader.bin**, **fip.bin**, **nvme.img**, **hikey-boot-linux-*.uefi.img.gz**, and the appropriate **p-table image**(this is board specific)

```shell
$ wget http://builds.96boards.org/releases/reference-platform/debian/hikey/16.06/bootloader/l-loader.bin
$ wget http://builds.96boards.org/releases/reference-platform/debian/hikey/16.06/bootloader/fip.bin
$ wget http://builds.96boards.org/releases/reference-platform/debian/hikey/16.06/bootloader/ptable-linux-4g.img
$ wget http://builds.96boards.org/releases/reference-platform/debian/hikey/16.06/bootloader/ptable-linux-8g.img
$ wget http://builds.96boards.org/releases/reference-platform/debian/hikey/16.06/bootloader/nvme.img
$ wget http://builds.96boards.org/releases/reference-platform/debian/hikey/16.06/hikey-boot-linux-*.uefi.img.gz
```

#### Uncompress the boot image as follows:

```shell
$ gunzip boot-fat.uefi.img.gz
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

Please refer to the [Hardware User Guide](https://www.96boards.org/wp-content/uploads/2015/02/HiKey_User_Guide_Rev0.2.pdf) (Chapter 1. Settings Jumper) for more information on the HiKey link options.

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

[hisi-idt.py](http://builds.96boards.org/releases/reference-platform/debian/hikey/16.06/bootloader/hisi-idt.py) is the download tool for the HiKey. This is used to install the bootloader as follows:

This script can also be downloaded using the wget command in your commandline:

```
$ wget http://builds.96boards.org/releases/reference-platform/debian/hikey/16.06/bootloader/hisi-idt.py
```

#### Run the script to initially prepare fastboot

Make sure the modem interface is in the right ttyUSB as previously suggested. In this example, use ttyUSB0:

```
$ sudo python hisi-idt.py -d /dev/ttyUSB0 --img1=l-loader.bin
```

#### After the python command has been issued you should see the following output. If you do not then see the "Problems with Python Downloader" section below

```
+----------------------+
 Serial:  /dev/ttyUSB0
 Image1:  l-loader.bin
 Image2:  
+----------------------+

Sending l-loader.bin ...
Done
```
**NOTE:** You may see the word “failed” before Done. This is under investigation but is not fatal. As long as the “Done” is printed at the end you may proceed.

The bootloader has now been installed into RAM. Wait a few seconds for the fastboot application to actually load. The following fastboot commands

#### Load the partition table, the bootloader, and other necessary files into the HiKey eMMC flash memory (4GB or 8GB).

8GB is used for this example.

**NOTE:** the ptable must be flashed first. Wait for a few seconds after the reboot command to allow the bootloader to restart using the new partition table. (Example goes with 8G)

```
$ sudo python hisi-idt.py -d /dev/ttyUSB0 --img1=l-loader.bin (again, remember ttyUSB* can change)
$ sudo fastboot flash ptable ptable-linux-8g.img
$ sudo fastboot flash fastboot fip.bin
$ sudo fastboot flash nvme nvme.img
$ sudo fastboot flash boot boot-fat.uefi.img (boot image file name can change based on build)
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
