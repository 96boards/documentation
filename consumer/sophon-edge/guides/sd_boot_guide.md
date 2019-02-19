---
title: Sophon Edge SOC SD Card Installation Guide
permalink: /documentation/consumer/sophon-edge/guides/sd_boot_guide.md.html
description: This guide will describe the process of booting the Sophon Edge in SOC mode using an SD card. SOC mode allows on board programming through the UART port on the Sophon Edge.
---
# Sophon Edge SOC SD Card Installation Guide

This guide will describe the process of booting the Sophon Edge in SOC mode using an SD card. SOC mode allows on board programming through the UART port on the Sophon Edge.

## Relavent Links:
- [Sophon-Edge Developer Board SD-Boot Section](https://sophon-edge.gitbook.io/project/overview/edge-tpu-developer-board#sd-boot)

## Setup - What You Will Need:

  * [Sophon Edge](https://www.96boards.org/)
    * Board based on Sophon BM1880
  * Micro USB Cable
  * SD Card >= 3GB
  * Ubuntu PC for Cross Compilation
  * Either:
    * [Power Adapter](http://avnet.me/96BoardPower) 
      * 12V @ 2A AC/DC converter compatible with the 96Boards specification
  * Or:
    * Male to Male USB cable


## Setting Up The Host Environment

In order to have access to the boards logs and terminal, your host machine needs to read information from the Sophon Edge’s UART port. In order to do this the minicom command must be configured.

To do this first check what port the Sophon Edge is using. Without the Sophon Edge plugged in execute:

`$ ls /dev/tty*`

Plug the Sophon Edge in via micro USB and once again execute $ ls /dev/tty*. A new entry should have appeared, for example /dev/ttyUSB0.

Next configure minicom to read from /dev/ttyUSB0. Execute the following, and then navigate to “Serial port setup”. 

`$ minicom -s`

Press ‘A’ in order to access the “Serial Device” option, and rename it to ‘/dev/ttyUSB0’. Press Escape twice to get back to the [configuration] page. Select ‘Save setup as dfl’ and then Exit.

Now that minicom has been configured it’s time to get the relevant files for formatting the SD card. First clone the bm1880-system-sdk repository.

`$ git clone https://github.com/BM1880-BIRD/bm1880-system-sdk.git`

Next it's important to configure the cross comilpation toolchain for the rootfs. [Download the toolchian here](https://sophon-file.bitmain.com.cn/sophon-prod/drive/18/11/08/11/gcc-linaro-6.3.1-2017.05-x86_64_aarch64-linux-gnu.tar.xz.zip), and unzip it into the bm1880-system-sdk directory.

Navigate to the bm1880-system-sdk directory and configure envsetup_edb.sh to point to the downloaded toolchain.

`$ vim build/envsetup_edb.sh`

Find the following line at the bottom of the file:

```
export CROSS_COMPILE_64=${CROSS_COMPILE_64:-$TOP_DIR/host-tools/gcc/gcc-linaro-6.3.1-2017.05-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-}
```

And point it to where you downloaded the toolchain as following:
```
export CROSS_COMPILE_64=${CROSS_COMPILE_64:-$TOP_DIR/gcc-linaro-6.3.1-2017.05-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-}
```

## Formatting the SD Card
Next mount the SD card to an Ubuntu system, and format the SD card into two partitions: an IMAGES vFAT partition (128MB) and a rootfs EXT4 partition, (3GB or more).

Optionally Bitmain provides a script to format the SD card for you. In order to do this execute the following:
```
$ sudo apt-get install expect
$ cd bm1880-system-sdk/build/sd_tools
$ sudo sd_create_rootfs_sd.sh /dev/<sdx>
<sdx> being the location of the mounted SD card.
```
Now it’s time to build the Sophon Edge’s rootfs. As there were some issues encountered when trying to execute a total build (including IMAGES partition) it is recommended to do a component build to update the rootfs while leaving the IMAGES partition (fip.bin and sdboot.itb) as they are.
```
$ cd bm1880-system-sdk
$ clean_rootfs
$ build_rootfs
```
After this has finished the Sophon Edge rootfs should have been created in bm1880-system-sdk/install/soc_bm1880_asic_adb/rootfs directory.

Copy the relevant files from the install directory into the corresponding partitions.
```
$ cd install/soc_bm1880_asic_adb
$ cp fip.bin sdboot.itb /media/<USERNAME>/IMAGES; sync
$ sudo cp -fr rootfs/* /media/<USERNAME>/rootfs; sync
```

## Booting the Sophon Edge

Remove the SD card from the Ubuntu PC and insert into the Sophon Edge. Set the boot options on the Sophon Edge: 10100010 (3b’101)

With the Micro USB plugged in and the Sophon Edge connected, execute:

`$ sudo minicom`

You should see the minicom startup page. 

Control-A Z will allow you to see the minicom help page.

Now boot up the Sophon Edge by connected either the Male to Male USB to your computer, or the power cord, and you should see the Sophon Edge boot into BusyBox.

