---
title: How to use PMU hardware events of ARM architecture on HiKey960
permalink: /documentation/consumer/hikey960/support/ds-5-jtag-debugging-hikey960.md.html
redirect_from: /documentation/ConsumerEdition/HiKey960/Support/How-to-use-DS-5-JTAG-debugging-HiKey960.md.html
---
DS-5 Development Studio is a suite of tools for embedded C/C++ software development on any ARM-based SoC, featuring editor, compilers, debugger and system profiler.

This document describes how to using DS-5 on HiKey960.

Written by: Kaiyou Wang <Kaiyou.Wang@arm.com>

## Preparation
1. DS-5 can connect the Hikey960 board if you have ```welded the JTAG connecter``` on the board to match DSTREAM connector.
2. Download files:
  2.1 [ds5-jtag-scripts/Hikey960.zip](https://github.com/96boards-hikey/tools-images-hikey960/blob/master/ds5-jtag-scripts/Hikey960.zip)
 create mode 100644 ds5-jtag-scripts/README.md
 2.2 [ds5-jtag-scripts/close_idle.sh](https://github.com/96boards-hikey/tools-images-hikey960/blob/master/ds5-jtag-scripts/close_idle.sh)


## Step 1
Please unzip the "Hikey960.zip" and add the Hikey960 CDB to DS-5 CDB, you can refer the link ["10.2 About importing platform and model configurations
"](http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.100953_0527_00_en/deb1359981692428.html)

## Step 2
Before connect the board with DS-5 please disable the CPU idle if it is enabled, or else the connection might fail.
```
$ adb devices
(to check whethter the board is bring up sucessful and list the device)
$ adb root
$ adb remout
$ adb push close_idle.sh /system/
$ adb shell chmod +x /system/close_idle.sh
$ adb shell ./system/close_idle.sh
```
## Step 3
Connect the board successfully now
