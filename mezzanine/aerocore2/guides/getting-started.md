---
title: Getting Started with the AeroCore2
permalink: /documentation/mezzanine/aerocore2/guides/getting-started.md.html
---

# Basic Setup Guide

## Table of Content
- [1. Hardware](#1-hardware)
  - [1.1 Hardware Overview](#11-hardware-overview)
  - [1.2 Hardware Requirements](#12-hardware-requirements)
  - [1.3 Hardware Setup](#13-hardware-setup)
- [2 Software Setup](#2-software-setup)
  - [2.1 Building the Firmware](#21-building-the-firmware)
  - [2.2 Flashing the Bootloader](#22-flashing-the-bootloader)
  - [2.3 Dragonboard Yocto Build](#23-dragonboard-yocto-build)

# 1. Hardware
## 1.1 Hardware Overview
<img src="../files/aerocore2-labled.png?raw=true" data-canonical-src="../files/aerocore2-labled.png?raw=true" width="330" height="215" />

## 1.2 Hardware Requirements
1. 1x Aerocore2 Mezzanine
2. 1x Host machine with Ubuntu
3. 1x Consumer Edition 96Boards
4. 1x Mouse and Keyboard
5. 1x HDMI Display
6. 1x 12v 2A Power Supply

# 2 Software Setup
## 2.1 Building the Firmware

Gumstix has customized the MAVLink PX 4 software suite to the MAV’s standard features and the source code is available online from GitHub at [https://github.com/aerocore/Firmware](https://github.com/aerocore/Firmware).

Instructions for building the AeroCore 2 PX4 firmware are provided below:

- 1. Add dialout permissions to your user: `$ sudo usermod -a -G dialout $USER`
- 2. Remove Modem Manager `$ sudo apt-get remove modemmanager`
- 3. Install dependencies `$ sudo apt-get install python3-serial openocd flex bison libncurses5-dev autoconf texinfo build-essential libftdi-dev libtool zlib1g-dev python-empy`
- 4. Clone the repository and select a branch: master, stable, or beta

```shell
$ git clone https://github.com/aerocore/Firmware.git aerocore2_firmware
$ cd aerocore2_firmware && git checkout aerocore2-〈master OR stable OR beta〉
```
- 5. Ensure all submodule repositories are up-to-date `$ git submodule update --init --recursive`
- 6. Compile `$ make aerocore2_default`

## 2.2 Flashing the Bootloader

It is rarely necessary to flash the AeroCore 2 bootloader as it is shipped pre-flashed. However, if you are having difficulty flashing the firmware to your board, re-flashing the bootloader may resolve the underlying issue. To install the bootloader you will need dfu-util and the boot-loader binaries from Gumstix. 

You can download the bootloader at: [http://gumstix-misc.s3.amazonaws.com/aerocore2/px4aerocore_bl.bin](http://gumstix-misc.s3.amazonaws.com/aerocore2/px4aerocore_bl.bin)

Optionally, you can download and compile it from: [https://github.com/aerocore/Bootloader/tree/aerocore2](https://github.com/aerocore/Bootloader/tree/aerocore2). Enter these commands to build the bootloader from source:
```shell
$ git clonehttps://github.com/libopencm3/libopencm3.git
$ cd libopencm3 && make
$ cd ..  && git clonehttps://github.com/aerocore/Bootloader.git
$ cd Bootloader && make
```

On a Ubuntu development machine (Windows and Mac OS users check dfu-util documentation):
- 1. Install dfu-util `$  sudo apt-get install dfu-util`
- 2. Download the latest bootloader binary `$  wget http://gumstix-aerocore.s3.amazonaws.com/Bootloader/px4aerocore_bl.bin`
- 3. locate the BOOT0 button on the back of the AeroCore 2
- 4. While holding down BOOT0, plug the microUSB connector into the USB port labled stm_console or aerocore. Then release BOOT0.
- 5. Flash the downloaded bootloader binary to the AeroCore 2 `$  sudo dfu-util -a 0 -D px4aerocore_bl.bin -s 0x08000000`
- 6. Press the AeroCore 2 reset button. There should be a solid blue Light Emitting Diode(LED)and flashing yellow

## 2.3 Dragonboard Yocto Build

1. Latest Build of Yocto for Dragonboard 410c baked for AeroCore2: [Download](https://gumstix-yocto.s3.amazonaws.com/2018-03-13/dragonboard-410c/morty/gumstix-xfce-image-dragonboard-410c.sdcard.xz)

2. Follow Aerocore2 PDF Guide for detailed instructions: [Download](../files/aerocore_2_user_manual.pdf)