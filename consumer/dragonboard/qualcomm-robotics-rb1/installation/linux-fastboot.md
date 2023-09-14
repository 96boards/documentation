---
title: Linux Host Installation for Qualcomm Robotics RB1 development kit
permalink: /documentation/consumer/dragonboard/qualcomm-robotics-rb1/installation/linux-fastboot.md.html
---
## Linux Host

This section show how to install a new operating system to your Qualcomm Robotics RB1 development kit using the fastboot method on a Linux host computer.

***

- **Step 1**: Make sure fastboot is set up on host computer
- **Step 2**: Connect host computer to RB1
- **Step 3**: Boot RB1 into fastboot mode
- **Step 4**: Recall location of all downloaded files
- **Step 5**: Unzip all files
- **Step 6**: Flash all files to the RB1
- **Step 7**: Reboot RB1

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
  $ sudo apt-get install google-android-platform-tools-installer

  # Ubuntu 16.04 (Xenial) and beyond
  $ sudo apt-get install android-tools-fastboot
  ```

#### **Step 2**: Connect host computer to RB1

- RB1 must be powered off (unplugged from power)
- please check the Quick start guide to set the dip switches on the development kit

#### **Step 3**: Boot RB1 into fastboot mode

**Please read all bullet points before attempting**

- Disconnect the power cable from the board and make sure no USB cable is plugged into the board
- Hold down the "VOL-" button while reconnecting the power supply.
- Tap the "ON/OFF" button while continuing to hold the "VOL-" button for ~5 seconds after the green LED lights up.
- Release "VOL-" button
- Connect the USB3 Type C between the Linux PC and the board
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

#### **Step 4**: Recall location of all downloaded files

Recall location of all downloaded files from the downloads page:

###### **Linaro/Debian**: Recall location of `boot` and `rootfs` downloaded from the downloads page
- You should have downloaded the `boot` file
- You should have downloaded the `rootfs` file

#### **Step 5**: Unzip required files

##### For Debian
```shell
$ gunzip boot-linaro-sid-arm64-qcom_qrb2210-rb1-*.img.gz
$ gunzip linaro-sid-developer-arm64-*.img.gz
```

#### **Step 6**: Flash all images to the RB1

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
$ sudo fastboot flash boot boot-linaro-sid-arm64-qcom_qrb2210-rb1-**BUILD#**.img
$ sudo fastboot flash userdata linaro-sid-developer-arm64-**BUILD#**.img
```
**Note**: Replace **BUILD#** in the above commands with the file-specific date/build stamp.

#### **Step 7**: Reboot RB1

- Unplug power to RB1
- Ensure HDMI connection to a monitor
- Plug power back into RB1
- Wait for board to boot up
- Board will boot into command line

**Note:** For Linaro/Debian the **username** and **password** are both **“linaro”** when the login information is requested.

**Congratulations! You are now booting your newly installed OS directly from eMMC on the RB1!**


