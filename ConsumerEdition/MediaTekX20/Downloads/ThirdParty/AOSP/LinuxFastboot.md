---
title: Linux Host Downloads for MediaTek X20
permalink: /documentation/ConsumerEdition/MediaTekX20/Downloads/ThirdParty/AOSP/LinuxFastboot.md/
---
## Linux Host

This section show how to install the Android operating system to your MediaTek X20 using the fastboot method on a Linux host computer.

***

- **Step 1**: Download and untar/unzip all necessary files
- **Step 2**: Make sure "fastboot" and "adb" are set up on you Linux host machine
- **Step 3**: Prepare MediaTek X20 development board
- **Step 4**: Boot MediaTek X20 development board into Fastboot mode
- **Step 5**: Install Operating System update using downloaded files(images)

***

#### **Step 1**: Download and untar/unzip all necessary files

In order to proceed with these installation instructions, you will need to download all necessary files/images onto your Linux host machine.

|   Tarball                             |   Option               |  Description                                                        |
|:--------------------------------------|:-----------------------|:--------------------------------------------------------------------|
| mediatek-x20-aosp-16.10-image.tar.xz  | [Download](http://builds.96boards.org/releases/helio-x20/mediatek/aosp/latest/mediatek-x20-aosp-*-image.tar.xz) | This is an "Image only" tarball, here you will find all pre-built images needed for OS installation |
| mediatek-x20-aosp-16.10-source.tar.xz | [Download](http://builds.96boards.org/releases/helio-x20/mediatek/aosp/latest/mediatek-x20-aosp-*-source.tar.xz) | This download includes source files for building images |
| mediatek-x20-aosp-16.10.tar.xz | [Download](http://builds.96boards.org/releases/helio-x20/mediatek/aosp/latest/mediatek-x20-aosp-16.10.tar.xz) | This download includes all of the above files, both pre-built images and source |

Visit [builds.96boards.org](http://builds.96boards.org/releases/helio-x20/mediatek/aosp/latest/) for more information on downloads.

#### **Step 2**: Make sure "fastboot" and "adb" are set up on you Linux host machine

- Android SDK “Tools only” for Linux can be downloaded <a href="http://developer.android.com/sdk" target="_blank">here</a>
- The Linux “Tools Only” SDK download does not come with fastboot, you will need to use the Android SDK Manager to install platform-tools.
- To do this follow the “SDK Readme.txt” instructions included in your SDK “Tools Only” download.

If you are still having trouble setting up fastboot and adb, <a href="https://youtu.be/W_zlydVBftA" target="_blank">click here</a> for a short tutorial video

#### **Step 3**: Prepare MediaTek X20 development board

Before flashing the new Operating System files onto a MediaTek X20 development board, you must first ensure a successful stock Android boot. **For this step you must have adb (Android Debug Bridge) successfully setup on your Linux host machine**.

- Connect the HDMI cable to the MediaTek X20 Development Board connector (marked CON6501) and to the LCD Monitor (Optional)
- Set the the third pin (USB HOST SET) of switch SW3205 to the position OFF position and connect the micro-usb to the host machine.
- Plug the power supply into the power outlet
- Press down the button (marked SW3201), and keep more than 3 seconds, the Android system will start
- Verify your MediaTek X20 board is detected using adb with the following command:

```shell
$ adb devices
```

Once you have ensured the board is detected by your Linux host machine using adb, proceed to the next step. If you are experiencing issues with this step you may want to:

1. Troubleshoot the adb setup on your host machine (**Step 2**)
2. Attempt a [Board Recovery](../../../Installation/BoardRecovery.md)
3. Visit the MediaTek X20 [Troubleshooting Page](../../../Troubleshooting/)

#### **Step 4**: Boot MediaTek X20 development board into Fastboot mode

Using adb, the MediaTek X20 can be easily booted into fastboot mode with the following command:

```shell
$ adb reboot bootloader
```

To ensure the MediaTek X20 development board is in fact booted into fastboot mode, execute the following command:

```shell
$ fastboot devices
```

Once you have ensured the board is detected by your Linux host machine using fastboot, proceed to the next step. If you are experiencing issues with this step you may want to:

1. Troubleshoot the fastboot setup on your host machine (**Step 2**)
2. Attempt a [Board Recovery](../../../Installation/BoardRecovery.md)
3. Visit the MediaTek X20 [Troubleshooting Page](../../../Troubleshooting/)

#### **Step 5**: Install Operating System update using downloaded files(images) and reboot

Please re-visit **Step 1** if you have not already downloaded the appropriate MediaTek X20 operating system images.

Executing the following commands from your command lin,e while within the appropriate directory, will flash each individual component to your MediaTek X20 development board. Once you have done this, the `fastboot reboot` command will reboot your board into your newly installed operating system.

```shell
$ fastboot flash gpt PGPT
$ fastboot flash preloader preloader_amt6797_64_open.bin
$ fastboot flash recovery recovery.img
$ fastboot flash scp1 tinysys-scp.bin
$ fastboot flash scp2 tinysys-scp.bin
$ fastboot flash lk lk.bin
$ fastboot flash lk2 lk.bin
$ fastboot flash boot boot.img
$ fastboot flash logo logo.bin
$ fastboot flash tee1 trustzone.bin
$ fastboot flash tee2 trustzone.bin
$ fastboot flash system system.img
$ fastboot flash cache cache.img
$ fastboot flash userdata userdata.img
$ fastboot reboot
```

**Congratulations! You are now booting your newly installed OS directly
from eMMC on the MediaTek X20!**
