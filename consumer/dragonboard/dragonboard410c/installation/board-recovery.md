---
title: DragonBoard 410c Board Recovery
permalink: /documentation/consumer/dragonboard/dragonboard410c/installation/board-recovery.md.html
redirect_from:
- /db410c-getting-started/
-  /documentation/ConsumerEdition/DragonBoard-410c/Installation/BoardRecovery.md.html
- /documentation/consumer/dragonboard410c/installation/board-recovery.md.html
---
# DragonBoard 410c Board Recovery

This page outlines steps needed to recover your DragonBoard 410c board from a bricked software state. This instruction set is suggested to those who are experiences boot issues due to a corrution in the file system and/or other software components.

There are a couple ways to recover your DragonBoard 410c from a "bricked" state.

## SD card Recovery image

In most cases this will be your sure-fire way to recover your board from a software bricked state. A recovery image has been created and made ready to be flashed onto a micro SD card. Simply download the SD card recovery image, and follow the sd card installation instructions found on our [Installation page](README.md).

- Download [SD Card Recovery image](http://releases.linaro.org/96boards/dragonboard410c/linaro/rescue/latest/dragonboard-410c-sdcard-rescue-*.zip)
- Choose host machine under SD card installation instructions from [Installation Page](README.md)

> Note: For those already familiar with the SD card flashing process, 96Boards build folder can be found [here](http://releases.linaro.org/96boards/dragonboard410c/linaro/rescue/latest/)

## Fastboot recovery

In many cases, simply re-flashing the bootloader, boot image, and root file system, using the [fastboot method](README.md#fastboot-method) is enough. While the generic fastboot method might not always work due to certain complications, the sd card recovery image is always available (as seen above).

## Using USB flashing tools

Alternatively, the Dragonboard 410c can also be recovered/flashed over USB, using the Linaro QDL flashing tools. For more information about QDL, including installation instructions, please check this [guide](../../../guides/qdl.md).

### Connecting the board in USB flashing mode (aka EDL mode)

In order to force the DB410c to boot on USB (EDL mode), you need to configure S6 switch properly. S6 is on the back of the board underneath the micro SD slot.

* Power off the board and make sure no USB cable is plugged into the board
* Set switch S6-1 to `ON`.
* Connect the micro USB cable (J4) between the Linux PC and the board
* Power on the device

### Flashing the device

Download and unzip the most recent bootloader package:

http://snapshots.linaro.org/96boards/dragonboard410c/linaro/rescue/latest/dragonboard-410c-bootloader-emmc-linux-*.zip

Then run:

    cd dragonboard-410c-bootloader-emmc-linux-*/
    sudo <PATH to qdl>/qdl prog_emmc_firehose_8916.mbn rawprogram*.xml patch*.xml

It should take a few seconds. And you should eventually get something like below
from QDL stdout:

    ...
    ...
    Update Backup Header with CRC of Backup Header.
    LOG: crc start sector 15269887, over bytes 92
    LOG: Patched sector 15269887 with E4874975
    LOG: Set bootable drive to 0.
    partition 0 is now bootable

### Booting into fastboot

If the flashing process succeeded, all the right bootloaders and partition table should have been set. And fastboot can now be used to flash Linux root file system. The first thing to try is to get into fastboot, to make sure the flashing completed properly.

* Power off the board and make sure no USB cable is plugged into the board
* Set Switch S6-1 to `OFF`.
* Connect the micro USB cable (J4) between the Linux PC and the board
* Power on the device

Execute below command on the PC to confirm that the board has entered `fastboot` mode:

```shell
$ sudo fastboot devices
bacb2a4		fastboot
```
