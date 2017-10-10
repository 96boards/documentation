---
title: Linux Host Installation for DragonBoard-410c
permalink: /documentation/ConsumerEdition/DragonBoard-410c/Installation/LinuxFastboot.md.html
redirect_from: /db410c-getting-started/
---
## Linux Host

This section show how to install a new operating system to your DragonBoard™ 410c using the fastboot method on a Linux host computer.

***

- **Step 1**: Make sure fastboot is set up on host computer
- **Step 2**: Connect host computer to DragonBoard™ 410c
- **Step 3**: Boot DragonBoard 410c into fastboot mode
- **Step 4**: Flash Bootloader
- **Step 5**: Recall location of all downloaded files
- **Step 6**: Unzip all files
- **Step 7**: Flash all files to the DragonBoard™ 410c
- **Step 8**: Reboot DragonBoard 410c

***

#### **Step 1**: Make sure fastboot is set up on host computer.
##### You can install fastboot from source or using your distro package manager.

- ###### From source:
  - Android SDK “Tools only” for Linux can be downloaded <a href="https://developer.android.com/studio/releases/platform-tools.html" target="_blank">here</a>
  - The Linux “Tools Only” SDK download does not come with fastboot, you will need to use the Android SDK Manager to install platform-tools.
  - To do this follow the “SDK Readme.txt” instructions included in your SDK “Tools Only” download.

  If you are still having trouble setting up fastboot, <a href="https://youtu.be/W_zlydVBftA" target="_blank">click here</a> for a short tutorial video

- ###### Or using a distro package manager:
  ```
  # Red Hat flavour (Fedora, CentOS)
  $ sudo yum install android-tools
  
  # Debian (Ubuntu)
  $ sudo apt-get install android-tools
  ```

#### **Step 2**: Connect host computer to DragonBoard 410c

- DragonBoard™ 410c must be powered off (unplugged from power)
- Make sure microSD card slot on DragonBoard™ 410c is empty
- S6 switch on DragonBoard™ 410c must be set to ‘0-0-0-0’. All switches should be in “off” position
- Connect USB to microUSB cable from host computer to DragonBoard™ 410c

#### **Step 3**: Boot DragonBoard™ 410c into fastboot mode

**Please read all bullet points before attempting**

- Press and hold the Vol (-) button on the DragonBoard™ 410c, this is the S4 button. DragonBoard™ 410c should still NOT be powered on
- While holding the Vol (-) button, power on the DragonBoard™ 410c by plugging it in
- Once DragonBoard™ 410c is plugged into power, release your hold on the Vol (-) button.
- Wait for about 20 seconds.
- Board should boot into fastboot mode.

From the connected host machine terminal window, run the following commands:

```shell
# Check to make sure device is connected and in fastboot mode

$ fastboot devices
```

Typically it will show as below
```shell
de82318	fastboot
```

**At this point you should be connected to your DragonBoard™ 410c with a USB to microUSB cable. Your DragonBoard™ 410c should be booted into fastboot mode and ready to be flashed with the appropriate images.**

#### **Step 4**: Flash Bootloader

- Use host computer
- Open "Terminal" application
- Recall location of Bootloader download.
- The bootloader file should be named `dragonboard410c_bootloader_emmc_Y-XX`
- Y represents Android or Linux
- XX represents the release number of the Bootloader
- `cd` to the directory with your unzipped **Bootloader Folder**

```shell
$ cd <extraction directory>

#Example:
cd /Users/YourUserName/Downloads
#<extraction directory> = /Users/YourUserName/Downloads
#For this example we assume the "Bootloader" is in the Downloads folder.


$ cd <unzipped Bootloader folder>

#Example:
cd dragonboard410c_bootloader_emmc_linux-40
#<unzipped Bootloader folder> = dragonboard410c_bootloader_emmc_linux-40
#This example took place during release 40

# This command will execute the flashall script within the bootloader folder
$ ./flashall
```

The bootloader has now been flashed to the eMMC.  Rebooting will
launch the newly-flashed boot loader, which will allow us to flash
the remaining parts of the operating system.

```shell
# Reboot the system so we can flash the rest.
$ sudo fastboot reboot
```

#### **Step 5**: Recall location of all downloaded files

Recall location of all downloaded files from the downloads page, files will be different for Android and Linaro/Debian:

###### **Linaro/Debian**: Recall location of `boot` and `rootfs` downloaded from the downloads page
- You should have downloaded the `boot` file
- You should have downloaded ONE of rootfs` file (Either `Developer` or `Desktop - ALIP` version)

###### **Android**: Recall location of `boot.img.tar.xz`, `system.img.tar.xz`, `userdata.img.tar.xz`, `recovery.img.tar.xz`, `persist.img.tar.xz`, `cache.img.tar.xz`, downloaded from the downloads page
- All of these files should have been downloaded from the downloads page

#### **Step 6**: Unzip both files

#### **Step 7**: Flash all images to the DragonBoard 410c

- Use host computer
- Use "Terminal" application
- Recall location of extracted(unzipped) files
- `cd` to the directory with your unzipped files
- From within extraction directory, execute the following commands:

###### **Linaro/Debian**:
```shell
# (Once again) Check to make sure fastboot device connected
$ sudo fastboot devices
# It will show similar to below if the device is connected successfully
de82318	fastboot

# cd to the directory the boot image and  were extracted
$ cd <extraction directory>

# Make sure you have properly unzipped the boot and rootfs downloads
$ sudo fastboot flash boot boot-linaro-jessie-qcom-snapdragon-arm64-**BUILD#**.img
$ sudo fastboot flash rootfs linaro-jessie-developer-qcom-snapdragon-arm64-**BUILD#**.img
```
**Note**: Replace **BUILD#** in the above commands with the file-specific date/build stamp.

###### **Android**:
```shell
# (Once again) Check to make sure fastboot device connected
$ sudo fastboot devices
# It will show similar to bellow if the device is connected successfully
de82318	fastboot

# cd to the directory with extracted images
$ cd <extraction directory>

# Make sure you have properly unzipped the downloads
$ sudo fastboot flash boot boot.img
$ sudo fastboot flash system system.img
$ sudo fastboot flash userdata userdata.img
$ sudo fastboot flash recovery recovery.img
$ sudo fastboot flash persist persist.img
$ sudo fastboot flash cache cache.img
```

#### **Step 8**: Reboot DragonBoard™ 410c

- Unplug power to DragonBoard™ 410c
- Unplug micro USB cable from DragonBoard™ 410c
- Ensure HDMI connection to monitor
- Ensure keyboard and/or mouse connection (Depending on your rootfs selection)
- Plug power back into DragonBoard™ 410c
- Wait for board to boot up
- Board will boot into either command line or desktop depending on rootfs

**Note:** For Linaro/Debian the **username** and **password** are both **“linaro”** when the login information is requested.

**Congratulations! You are now booting your newly installed OS directly
from eMMC on the DragonBoard™ 410c!**
