---
title: Windows Host Installation for MediaTek X20 Pro
permalink: /documentation/ConsumerEdition/MediaTekX20Pro/Downloads/ThirdParty/AOSP/WindowsFastboot.md/
---
## Windows Host

This section show how to install the Android operating system to your MediaTek X20 using the fastboot method on a Windows host computer.

***

- **Step 1**: Download and untar/unzip all necessary files
- **Step 2**: Make sure "fastboot" and "adb" are set up on you Windows host machine
- **Step 3**: Prepare MediaTek X20 development board
- **Step 4**: Boot MediaTek X20 development board into Fastboot mode
- **Step 5**: Install Operating System update using downloaded files(images)

***

#### **Step 1**: Download and untar/unzip all necessary files

|   Tarball                             |   Option               |  Description                                                        |
|:--------------------------------------|:-----------------------|:--------------------------------------------------------|
| mediatek-x20-aosp-16.10-image.tar.xz  | [Download](http://builds.96boards.org/releases/helio-x20-pro/mediatek/aosp/latest/mediatek-x20Pro-aosp-*-image.tar.xz) | This is an "Image only" tarball, here you will find all pre-built images needed for OS installation |
| mediatek-x20-aosp-16.10-source.tar.xz | [Download](http://builds.96boards.org/releases/helio-x20-pro/mediatek/aosp/latest/mediatek-x20Pro-aosp-*-code.tar.xz) | This download includes source files for building images |
| sla.tar.gz | [Download](http://builds.96boards.org/releases/helio-x20-pro/mediatek/aosp/latest/sla.tar.gz) |  |

Visit [builds.96boards.org](http://builds.96boards.org/releases/helio-x20-pro/mediatek/aosp/latest/) for more information on downloads.

**Step 2**: Make sure "fastboot" and "adb" are set up on you Windows host machine

- Android SDK “Tools only” for Windows can be downloaded <a href="http://developer.android.com/sdk" target="_blank">here</a>
- The Windows “Tools Only” SDK download does not come with fastboot, you will need to use the Android SDK Manager to install platform-tools.
- To do this follow the “SDK Readme.txt” instructions included in your SDK “Tools Only” download.

If you are still having trouble setting up fastboot and adb, <a href="https://youtu.be/W_zlydVBftA" target="_blank">click here</a> for a short tutorial video

**Step 3**: Prepare MediaTek X20 development board

Before flashing the new Operating System files onto a MediaTek X20 development board, you must first ensure a successful stock Android boot. **For this step you must have adb (Android Debug Bridge) successfully setup on your Windows host machine**.

- Connect the HDMI cable to the MediaTek X20 Development Board connector (marked CON6501) and to the LCD Monitor (Optional)
- Set the the third pin (USB HOST SET) of switch SW3205 to the position OFF position and connect the micro-usb to the host machine.
- Plug the power supply into the power outlet
- Press down the button (marked SW3201), and keep more than 3 seconds, the Android system will start
- Verify your MediaTek X20 board is detected using adb with the following command:

```shell
$ adb devices
```

Once you have ensured the board is detected by your Windows host machine using adb, proceed to the next step. If you are experiencing issues with this step you may want to:

1. Troubleshoot the adb setup on your host machine (**Step 2**)
2. Attempt a [Board Recovery](../Installation/BoardRecovery.md)
3. Visit the MediaTek X20 [Troubleshooting Page](../Troubleshooting/)

**Step 4**: Boot MediaTek X20 development board into Fastboot mode

Using adb, the MediaTek X20 can be easily booted into fastboot mode with the following command:

```shell
$ adb reboot bootloader
```

To ensure the MediaTek X20 development board is in fact booted into fastboot mode, execute the following command:

```shell
$ fastboot devices
```

Once you have ensured the board is detected by your Windows host machine using fastboot, proceed to the next step. If you are experiencing issues with this step you may want to:

1. Troubleshoot the fastboot setup on your host machine (**Step 2**)
2. Attempt a [Board Recovery](../../../Installation/BoardRecovery.md)
3. Visit the MediaTek X20 [Troubleshooting Page](../../../Troubleshooting/)

**Step 5**: Install Operating System update using downloaded files(images) and reboot

Please re-visit **Step 1** if you have not already downloaded the appropriate MediaTek X20 operating system images.

Executing the following commands from your command line while within the appropriate directory, will flash each individual component to your MediaTek X20 development board. Once you have done this, the `fastboot reboot` command will reboot your board into your newly installed operating system.

```shell
fastboot flash gpt PGPT
fastboot flash preloader preloader_amt6797_64_open.bin
fastboot flash recovery recovery.img
fastboot flash scp1 tinysys-scp.bin
fastboot flash scp2 tinysys-scp.bin
fastboot flash lk lk.bin
fastboot flash lk2 lk.bin
fastboot flash boot boot.img
fastboot flash logo logo.bin
fastboot flash tee1 trustzone.bin
fastboot flash tee2 trustzone.bin
fastboot flash system system.img
fastboot flash cache cache.img
fastboot flash userdata userdata.img
fastboot reboot
```

**Congratulations! You are now booting your newly installed OS directly
from eMMC on the MediaTek X20!**

***

## Windows Host - OLD

This section show how to install a new operating system to your Helio X20 using the fastboot method on a Windows host computer.

***

#### **Necessary Condition**

You need prepare 6 components:
- PC Host has installed [Driver]() and [ADB]()
- [xflash tools]()
- [Normal images]() (Include image files and scatter file etc.)
- [Special images]() and scatter file
- [fastboot]()
- fastboot command script file eg. [xflash.bat]()

#### **Flash Tool access path**

From code source : alps\vendor\mediatek\proprietary\system\core\xflash
You can also get it from the link above.

#### **How to build special images**

Execute following commands, build system will automatically create FES folder and come out the special lk.bin, where FES store the needed files for xflash download to target befor entering fastboot mode.

`$ source build/envsetup.sh`

`$ lunch full_amt6797_64_open-eng`

`$ make -j16 PLATFORM_FASTBOOT_EMPTY_STORAGE=yes -k 2>&1 | tee build.log`

Then, you can find a folder named FES.

PATH: \out\target\product\amt6797_64_open\FES

#### **Prepare your Windows host machine**

- A Windows PC host
   - ADB and ADB Driver need installed in this windows PC, thus, we can send adb command by it.
- Normal load(Include image files and scatter file etc.)
   - You can put it in anywhere, eg, \xflash\bin\win\img
   - The PGPT file can't generated from your build system, so if you build new images, this file should be reserved(it can format the eMMC into constant partition).
- Special images and scatter file
   - You can put it in anywhere, eg, \xflash\bin\win\FES.
   - How to build it? Please see “How to build special images”.
- fastboot.exe
   - you can put it in normal load folder.
- fastboot command script file
   - Written by yourself, you should put it in normal load folder.

#### **Windows Download**

Step 1. Make a device to enter fastboot mode
- Prepare special images and corresponding scatter file.
- Run program in command line mode like this:

    `xflash.exe enter-fastboot “G:\xflash\bin\win\FES\MT6797_Android_scatter.txt”`
- Then plug in USB cable to device without power adapter.
- Plug in power adapter then
- Xflash will scan and open device COM port and connect it, download some necessary images to devices, then make device to enter fastboot mode.

Step 2. Run fastboot command script file
- You need write a download script.

        Such as xflash.bat

        fastboot devices
        fastboot flash gpt PGPT
        fastboot flash preloader preloader_amt6797_64_open.bin
        fastboot flash recovery recovery.img
        fastboot flash scp1 tinysys-scp.bin
        fastboot flash scp2 tinysys-scp.bin
        fastboot flash lk lk.bin
        fastboot flash lk2 lk.bin
        fastboot flash boot boot.img
        fastboot flash logo logo.bin
        fastboot flash tee1 trustzone.bin
        fastboot flash tee2 trustzone.bin
        fastboot flash system system.img
        fastboot flash cache cache.img
        fastboot flash userdata userdata.img
        fastboot reboot

- Run the download script, download success.
