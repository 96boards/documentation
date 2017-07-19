---
title: Linux Host Installation for HiKey
permalink: /documentation/ConsumerEdition/HiKey/Installation/LinuxFactoryImage.md/
---
## Linux Host

This section shows how to install new operating system to your HiKey using the fastboot method on a Linux host computer.

***

- **Step 1**: Make sure fastboot is set up on host computer
- **Step 2**: Extract zipfile
- **Step 3**: Boot HiKey into Recovery mode using J15 header
- **Step 4**: Flash factory image to the device
- **Step 5**: Reboot HiKey into new OS

***


*#### **Step 1**: Make sure fastboot is set up on host computer.

- Android SDK “Platform-Tools” for Linux can be downloaded <a href="https://developer.android.com/studio/releases/platform-tools.html" target="_blank">here</a>

#### Connect a standard microUSB cable between the HiKey microUSB and your Linux PC.

HiKey should **NOT** be power on at this stage

**Step 2**: Extract the zipfile

After downloading the factory image zip file, unzip the file and change into the newly created directory.


**Step 3**: Boot HiKey into Recovery mode using J15 header

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
There should be a new /dev/ttyUSB device

**Step 4**: Run the flashall script

Make sure the serial/modem interface is in the right ttyUSB as previously suggested. In this example, use ttyUSB0:

```
$ sudo flashall.sh /dev/ttyUSB0
```

Or if you're using a board with only 4gb of storage
```
$ sudo flashall.sh /dev/ttyUSB0 4g
```

#### If the flashing fails, please check that you have the current version of fastboot, and have selected the right ttyUSB serial device


**Step 5**: Reboot HiKey into new OS

- Wait untill all files have been flashed onto HiKey board
- Power down HiKey by unplugging the power adapter
- Remove microUSB cable from HiKey
- Remove Link 5-6 from J15 header

Name | Link | State
---- | ---- | -----
Auto Power up | Link 1-2 | closed
Boot Select | Link 3-4 | open
GPIO3-1 | Link 5-6 | open

- Power up HiKey by plugging in power adapter


**Congratulations! You are now booting your newly installed OS directly from internal eMMC on the HiKey!**
