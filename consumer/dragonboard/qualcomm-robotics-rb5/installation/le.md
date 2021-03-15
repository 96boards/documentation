---
title: Linux Host Installation for DragonBoard-845c
permalink: /documentation/consumer/dragonboard/dragonboard845c/installation/le.md.html
---
## Linux Host

This section show how to install a new operating system to your DragonBoard™ 845c using the fastboot method on a Linux host computer.

***

- **Step 1**: Make sure fastboot is set up on host computer
- **Step 2**: Connect host computer to DragonBoard™ 845c
- **Step 3**: Boot DragonBoard 845c into fastboot mode
- **Step 4**: Flash Images
- **Step 5**: Reboot DragonBoard 845c

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
  $ sudo apt-get install android-tools

  # Ubuntu 16.04 (Xenial) and beyond
  $ sudo apt-get install android-tools-fastboot
  ```

#### **Step 2**: Connect host computer to DragonBoard 845c

- DragonBoard™ 845c must be powered off (unplugged from power)
- Make sure microSD card slot on DragonBoard™ 845c is empty
- S6 switch on DragonBoard™ 845c must be set to ‘0-0-0-0’. All switches should be in “off” position
- Connect USB to microUSB cable from host computer to DragonBoard™ 845c

#### **Step 3**: Boot DragonBoard™ 845c into fastboot mode

**Please read all bullet points before attempting**

- Press and hold the Vol (-) button on the DragonBoard™ 845c, this is the S4 button. DragonBoard™ 845c should still NOT be powered on
- While holding the Vol (-) button, power on the DragonBoard™ 845c by plugging it in
- Once DragonBoard™ 845c is plugged into power, release your hold on the Vol (-) button.
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

**At this point you should be connected to your DragonBoard™ 845c with a USB to TypeC cable. Your DragonBoard™ 845c should be booted into fastboot mode and ready to be flashed with the appropriate images.**

#### **Step 4**: Flash Images

```shell
cd <path-to-images>
fastboot flash abl_a abl.elf
fastboot flash boot_a sda845-boot.img
fastboot flash system_a sda845-sysfs_1.ext4
fastboot flash systemrw sda845-systemrw.ext4
fastboot flash cache sda845-cache_1.ext4
fastboot flash userdata sda845-usrfs_1.ext4
fastboot flash persist sda845-persist_1.ext4
```

#### **Step 5**: Reboot DragonBoard™ 845c

- ```fastboot reboot```
- Follow the [Getting Started Guide](../getting-started/rb3-kit/) to setup terminal.

**Congratulations! You are now booting your newly installed OS directly
from UFS on the DragonBoard™ 845c!**
