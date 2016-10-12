# MediaTek X20 Board Recovery

- For most users, a board could be “recovered” from a software failure by reloading the operating system using the instructions found on the [Installation page](README.md). 
- You could also recover the board by Backup & reset option in Settings Application.

The following instructions are for board recovery if and when the above recovery options fail to work (more specifically, when you screw up and cannot enter the fastboot mode). Only proceed if you have exercised all other options.

#### **Necessary Condition**

You need prepare 6 components:
- PC Host has installed ADB
- xflash tools
- Normal images (including image files and scatter file etc.)
- Special images (preloader and bootloader (lk) images for xflash) and scatter file
- fastboot command need be support
- fastboot command script file eg. xflash.sh (optional, you can flash images one by one manually)

xflash, normal images, and special images are in a file distributed by Linaro [the latest .tar.gz file] (http://builds.96boards.org/releases/helio-x20/mediatek/aosp/latest/96board_v3.tar.gz)

#### **Flash Tool (the xflash)**

source code: vendor/mediatek/proprietary/system/core/xflash of [sla.tar.gz]
(http://builds.96boards.org/releases/helio-x20/mediatek/aosp/latest/sla.tar.gz)
binary: the 96board_v3.0/xflash_test/bin/linux/xflash in [the binary .tar.gz file] (http://builds.96boards.org/releases/helio-x20/mediatek/aosp/latest/96board_v3.tar.gz)

#### **How to build special images**

Execute following commands, build system will automatically create a FES folder and come out the special lk.bin, where FES stores the needed files for xflash download to target so that the target can enterfastboot mode.

`$ source build/envsetup.sh`

`$ lunch full_amt6797_64_open-eng`

`$ make -j16 PLATFORM_FASTBOOT_EMPTY_STORAGE=yes -k 2>&1 | tee build.log`

Then, you can find a folder named FES in

`$ANROID_SRC_ROOT/out/target/product/amt6797_64_open/`

#### **Prepare your Linux host machine**

- A Linux PC host
   - ADB need installed in this linux PC, thus, we can send adb command by it.
- Normal load(Include image files and scatter file etc.)
   - You can put it in anywhere, eg, /xflash/bin/linux/img
   - The PGPT file can't generated from your build system, so if you build new images, this file should be reserved(it can format the eMMC into constant partition).
- Special images and scatter file
   - You can put it in anywhere, eg, /xflash/bin/linux/FES.
   - How to build it? Please see “How to build special images”.
- fastboot
   - Install fastboot to your linux PC.
- fastboot command script file
   - Written by yourself, you should put it in normal load folder.

#### **Ubuntu Download**

Step 1. Make a device to enter fastboot mode
- Prepare special images and corresponding scatter file.
- Run program in command line mode like this:

    `$ sudo ./xflash enter-fastboot "/xflash/bin/linux/FES/MT6797_Android_scatter.txt"`
- Then plug in USB cable to device without power adapter.
- Plug in power adapter then
- Xflash will scan and open device COM port and connect it, download some necessary images to devices, then boot the device into fastboot mode.

Step 2. Run fastboot command script file
- You need write a download script.

        Such as xflash.sh
        
        #!/bin/bash
        
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
        
- Run the download script or execute these commands line by line, download success.
