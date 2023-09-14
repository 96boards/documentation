---
title: Linux Host Installation for Qualcomm Robotics RB2 development kit
permalink: /documentation/consumer/dragonboard/qualcomm-robotics-rb2/installation/le.md.html
---
## Linux Host

This section show how to install a new operating system to your Qualcomm Robotics RB2 development kit using the fastboot method on a Linux host computer.

***

- **Step 1**: Make sure fastboot is set up on host computer
- **Step 2**: Connect host computer to Qualcomm Robotics RB2 dev kit
- **Step 3**: Boot RB2 into fastboot mode
- **Step 4**: Flash Images
- **Step 5**: Reboot the development kit

***

#### **Step 1**: Make sure fastboot is set up on host computer.
##### You can install fastboot from source or using your distro package manager.

- **From source:**
  - Android SDK “Tools only” for Linux can be downloaded <a href="https://developer.android.com/studio/releases/platform-tools.html" target="_blank">here</a>
  - The Linux “Tools Only” SDK download does not come with fastboot, you will need to use the Android SDK Manager to install platform-tools.
  - To do this follow the “SDK Readme.txt” instructions included in your SDK “Tools Only” download.

  If you are still having trouble setting up fastboot, <a href="https://youtu.be/W_zlydVBftA" target="_blank">click here</a> for a short tutorial video

- **Or using a distro package manager:**
  ```
  # Red Hat flavour (Fedora, CentOS)
  $ sudo yum install android-tools

  # Debian (Ubuntu)
  $ sudo apt-get install fastboot
  ```

#### **Step 2**: Connect host computer to Qualcomm Robotics RB2 development kit

- Development kit must be powered off (unplugged from power)
- Make sure microSD card slot on the development kit is empty
- Please check the Quick start guide to set the correct dip switches on the development kit.
- Connect USB to microUSB cable from host computer to the development kit.

#### **Step 3**: Boot Qualcomm Robotics RB2 dev kit into fastboot mode

**Please read all bullet points before attempting**

- Press and hold the Vol (-) button on the dev kit, this is the S4 button. Dev kit should still NOT be powered on
- While holding the Vol (-) button, power on the development kit by plugging it in
- Once the development kit is plugged into power, release your hold on the Vol (-) button.
- Wait for about 20 seconds.
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

**At this point you should be connected to your Qualcomm Robotics RB2 development kit with a USB to TypeC cable. Your development kit should be booted into fastboot mode and ready to be flashed with the appropriate images.**

#### **Step 4**: Flash Images

The LE build and recovery files can be downloaded by running [Thundercomm SDK Manager](https://www.thundercomm.com/product/qualcomm-robotics-rb2-platform/#sdk-manager). Follow the Thundercomm SDK Manager instructions to flash a full build for RB2 board recovery.

#### **Step 5**: Reboot the Qualcomm Robotics RB2 development kit

- ```fastboot reboot```

**Congratulations! You are now booting your newly installed OS directly
from UFS on the Qualcomm Robotics RB2 development kit!**



