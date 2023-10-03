---
title: Linux Host Installation for DragonBoard-845c
permalink: /documentation/consumer/dragonboard/dragonboard845c/installation/linux-fastboot.md.html
---
## Linux Host

This section show how to install a new operating system to your DragonBoard™ 845c based RB3 kit using the fastboot method on a Linux host computer.

***

- **Step 1**: Make sure fastboot is set up on host computer
- **Step 2**: Connect host computer to RB3
- **Step 3**: Boot RB3 into fastboot mode
- **Step 4**: Flash Bootloader
- **Step 5**: Recall location of all downloaded files
- **Step 6**: Unzip all files
- **Step 7**: Flash all files to the RB3
- **Step 8**: Reboot RB3

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
  $ sudo apt-get install fastboot
  ```

#### **Step 2**: Connect host computer to RB3

- RB3 must be powered off (unplugged from power)
- S6 switch on RB3 must be set to ‘0-0-0-0’. All switches should be in “off” position

#### **Step 3**: Boot RB3 into fastboot mode

**Please read all bullet points before attempting**

- Disconnect the power cable from the board and make sure no USB cable is plugged into the board
- Hold down the "VOL-" button while reconnecting the power supply.
- Tap the "ON/OFF" button while continuing to hold the "VOL-" button for ~5 seconds after the blue LED lights up.
- Release "VOL-" button
- Connect the USB3 Type C (5) between the Linux PC and the board
- Board should boot into fastboot mode.

From the connected host machine terminal window, run the following commands:

```shell
# Check to make sure device is connected and in fastboot mode

$ sudo fastboot devices
```

Typically it will show as below
```shell
de82318	fastboot
```

#### **Step 4**: Flash Bootloader

- Use host computer
- Download Bootloader from the [Downloads Page](../downloads/).
- Open "Terminal" application
- Recall location of Bootloader download.
- The bootloader file should be named `dragonboard-845c-bootloader-ufs-Y-XX`
- Y represents AOSP or Linux, use either one or the other based on the image you want to use. They both use different GPT.
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
cd dragonboard-845c-bootloader-ufs-linux-14
#<unzipped Bootloader folder> = dragonboard-845c-bootloader-ufs-linux-14
#This example took place during release 14

# This command will execute the flashall script within the bootloader folder
$ sudo ./flashall
```

The bootloader has now been flashed to the UFS.  Rebooting will
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

###### **AOSP**: Recall location of `boot.img.tar.xz`, `system.img.tar.xz`, `userdata.img.tar.xz`, `recovery.img.tar.xz`, `persist.img.tar.xz`, `cache.img.tar.xz`, downloaded from the downloads page
- All of these files should have been downloaded from the downloads page

#### **Step 6**: Unzip required files

##### For Debian
```shell
$ gunzip boot-*.img.gz
$ gunzip linaro-*.img.gz
```

##### For AOSP
```shell
$ tar -xvf boot.img.tar.xz
$ tar -xvf system.img.tar.xz
$ tar -xvf userdata.img.tar.xz
$ tar -xvf recovery.img.tar.xz
$ tar -xvf persist.img.tar.xz
$ tar -xvf cache.img.tar.xz
```

#### **Step 7**: Flash all images to the RB3

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
$ sudo fastboot flash boot boot-linaro-buster-dragonboard-845c-**BUILD#**.img
$ sudo fastboot flash rootfs linaro-buster-developer-dragonboard-845c-**BUILD#**.img
```
**Note**: Replace **BUILD#** in the above commands with the file-specific date/build stamp.

###### **AOSP**:
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

#### **Step 8**: Reboot RB3

- Unplug power to RB3
- Ensure HDMI connection to monitor
- Ensure keyboard and/or mouse connection (Depending on your rootfs selection)
- Plug power back into RB3
- Wait for board to boot up
- Board will boot into either command line or desktop depending on rootfs

**Note:** For Linaro/Debian the **username** and **password** are both **“linaro”** when the login information is requested.

**Congratulations! You are now booting your newly installed OS directly from UFS on the RB3!**
