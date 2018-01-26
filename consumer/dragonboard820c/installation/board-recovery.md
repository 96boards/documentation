---
title: DragonBoard™ 820c Board Recovery
permalink: /documentation/consumer/dragonboard820c/installation/board-recovery.md.html
---
# DragonBoard 410c Board Recovery

This page outlines steps needed to recover your DragonBoard 410c board from a bricked software state. This instruction set is suggested to those who are experiences boot issues due to a corrution in the file system and/or other software components.

There are a couple ways to recover your DragonBoard 410c from a "bricked" state.

## SD card Recovery image

In most cases this will be your sure-fire way to recover your board from a software bricked state. A recovery image has been created and made ready to be flashed onto a micro SD card. Simply download the SD card recovery image, and follow the sd card installation instructions found on our [Installation page](../installation/).

- Download [SD Card Recovery image](http://builds.96boards.org/releases/dragonboard410c/linaro/rescue/latest/dragonboard410c_sdcard_rescue-*.zip)
- Choose host machine under SD card installation instructions from [Installation Page](../installation/)

> Note: For those already familiar with the SD card flashing process, 96Boards build folder can be found [here](http://builds.96boards.org/releases/dragonboard410c/linaro/rescue/latest/)

## Fastboot recovery

In many cases, simply re-flashing the bootloader, boot image, and root file system, using the [fastboot method](../installation/#fastboot-method) is enough. While the generic fastboot method might not always work due to certain complications, the sd card recovery image is always available (as seen above).
