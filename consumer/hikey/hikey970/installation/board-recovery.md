---
title: BoardRecovery for HiKey970
permalink: /documentation/consumer/hikey/hikey970/installation/board-recovery.md.html
redirect_from:  /documentation/consumer/hikey970/installation/board-recovery.md.html
---
# HiKey970 Board Recovery

This page outlines steps needed to recover your HiKey970 board from a bricked software state. This instruction set is suggested to those who are experiences boot issues due to a corrution in the file system and/or other software components.

## Installing a Bootloader

For most users a board can be “recovered” from a software failure by reloading the operating system. However, if the primary bootloader in the UFS flash memory has been corrupted then the bootloader will need to be re-installed. This section describes how to reinstall the primary bootloader.

#### Make sure fastboot is set up on host computer

- Android SDK “Tools only” for Linux can be downloaded <a href="http://developer.android.com/sdk" target="_blank">here</a>
- The Linux “Tools Only” SDK download does not come with fastboot, you will need to use the Android SDK Manager to install platform-tools.
- To do this follow the “SDK Readme.txt” instructions included in your SDK “Tools Only” download.

If you are still having trouble setting up fastboot, <a href="https://youtu.be/W_zlydVBftA" target="_blank">click here</a> for a short tutorial video

#### Connect your Linux PC and HiKey970 using USB Type-A to Type-C cable.

HiKey970 should **NOT** be power on at this stage

#### Set Board Switch options

Name          | Switch   | State
------------- | -------- | ----------
Auto Power up | Switch 1 | closed / ON
Recovery      | Switch 2 | closed / ON
Fastboot      | Switch 3 | open / OFF

Switch 1 causes HiKey970 to auto-power up when power is installed. Switch 2 causes the HiKey970 SoC internal ROM to start up in at a special "install bootloader" mode which will install a supplied bootloader from the Type-C port into RAM, and will present itself to a connected PC as a ttyUSB device.

#### Connect the HiKey970 power supply to the board.

**NOTE:** USB does NOT power the HiKey970 board. You must use an external power supply.

#### Wait about 5 seconds and then check that the HiKey board has been recognized by your Linux PC:

```
$ ls /dev/ttyUSB*
or
$ dmesg
```

#### Clone HiKey970 Recovery tool

For recovering the HiKey970 board, clone the **tools-images-hikey970** repository and move into it.

```shell
$ git clone https://github.com/96boards-hikey/tools-images-hikey970
$ cd tools-images-hikey970
```

#### Run the script to initially prepare fastboot

Make sure the modem interface is in the right ttyUSB as previously suggested. In this example, use ttyUSB1:

```
$ sudo python hisi-idt.py -d /dev/ttyUSB1 --img1 ./sec_usb_xloader.img --img2 ./sec_usb_xloader2.img --img3 ./l-loader.bin
```

> Note: This script only works with Python2.7


You should see the following output on PC after executing the above command:

```
+----------------------+
 Serial: /dev/ttyUSB1
 Image1: fastboot1.img
 Image2: fastboot2.img
+----------------------+
Sending fastboot1.img ...
Done
Sending fastboot2.img ...
Done
```

The bootloader has now been installed into RAM. Wait a few seconds for the fastboot application to actually load. The following fastboot commands

```
$ sudo fastboot flash fastboot l-loader.bin
$ sudo fastboot flash fip fip.bin
```

Once this has been completed the bootloader has been installed into UFS.

#### Power off the HiKey970 board by removing the power supply jack and change the link configuration as follows:

Name          | Switch   | State
------------- | -------- | ----------
Auto Power up | Switch 1 | closed / ON
Recovery      | Switch 2 | open / OFF
Fastboot      | Switch 3 | closed / ON

#### Connect power supply jack to your HiKey970 again

Check that the HiKey board is detected by your Linux PC

Wait about 10 seconds.

You should see the ID of the HiKey970 board returned

```
$ sudo fastboot devices
0123456789abcdef fastboot
```

Your bootloader has been successfully installed and you are now ready to install the operating system files into the UFS memory, for this go to the ([HiKey970 Installation](README.md)) page.

**NOTE:**

This bootloader is based on UEFI and includes:
- ARM Trusted Firmware
- UEFI with DeviceTree
- GRUB
- fastboot support
- OP-TEE support
