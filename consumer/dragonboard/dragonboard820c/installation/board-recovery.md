---
title: DragonBoard™ 820c Board Recovery
permalink: /documentation/consumer/dragonboard/dragonboard820c/installation/board-recovery.md.html
redirect_from:  /documentation/consumer/dragonboard820c/installation/board-recovery.md.html
---
# DragonBoard 820c Board Recovery

This page outlines steps needed to recover your DragonBoard 820c board from a bricked software state. This instruction set is suggested to those who are experiences boot issues due to a corrution in the file system and/or other software components.

There are a couple ways to recover your DragonBoard 820c from a "bricked" state.

## SD card Recovery image

In most cases this will be your sure-fire way to recover your board from a software bricked state. A recovery image has been created and made ready to be flashed onto a micro SD card. Simply download the SD card recovery image, and follow the sd card installation instructions found on our [Installation page](../installation/).

- Download [SD Card Recovery image](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/rescue/latest/dragonboard-820c-sdcard-rescue-*.zip)
- Choose host machine under SD card installation instructions from [Installation Page](../installation/)

> Note: For those already familiar with the SD card flashing process, 96Boards build folder can be found [here](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/rescue/latest/)

## Fastboot recovery

In many cases, simply re-flashing the bootloader, boot image, and root file system, using the fastboot method is enough. While the generic fastboot method might not always work due to certain complications, the sd card recovery image is always available (as seen above).

## Using USB flashing tools

Alternatively, the Dragonboard 820c can also be recovered/flashed over USB, using the Linaro QDL flashing tools. For more information about QDL, including installation instructions, please check this [guide](../../../guides/qdl.md).

### Connecting the board in USB flashing mode (aka EDL mode)

In order to force the DB820c to boot on USB (EDL mode), you need to configure S1 switch properly. S1 is on the back of the board underneath the micro SD slot.

*Warning*: putting the device into EDL mode while the device is powered or when USB is plugged can cause damage to the board, the actual root cause is under investigation, and a hardware fix will be implemented in newer board revision.

* Power off the board and make sure no USB cable is plugged into the board
* Set switch S1 to `ON,OFF,OFF,ON`. If you have a P1 board (very unlikely) you need to set to `ON,ON,OFF,ON`.
* Connect the debug UART / serial console to your Linux PC, if not done already
* Connect the micro USB cable (J4) between the Linux PC and the board
* Open UART/serial console
* Power on the device

### Flashing the device

Download and unzip the most recent bootloader package:

http://snapshots.linaro.org/96boards/dragonboard820c/linaro/rescue/latest/dragonboard-820c-bootloader-ufs-linux-*.zip

Then run:

    cd dragonboard-820c-bootloader-ufs-linux-*/
    sudo <PATH to qdl>/qdl prog_ufs_firehose_8996_ddr.elf rawprogram.xml patch.xml

It should take a few seconds. And you should eventually get something like that:

    ...
    ...
    Update Backup Header with CRC of Backup Header.
    LOG: crc start sector 393215, over bytes 92
    LOG: Patched sector 393215 with 8FDB38DF
    LUN1 is now bootable device
    LOG: Inside handlePower() - Requested POWER_RESET
    LOG: Issuing bsp_target_reset() after 1 seconds, if this hangs, do you have WATCHDOG enabled?

### UFS provisioning

If the previous step failed, or if you want to reprovision the UFS disk on the board, the `qdl` flashing tool can also be used. Note that it should be very unlikely that you need to reprovision the UFS disk, and it should be considered as *expert zone*. In case of doubts, please check with the 96boards forum before running these instructions. Not running these instructions properly can create irreversible damage on the board!

To (re)provision the board, you need to connect the board in "USB flashing mode" as explained in the previous sections, then run the following commands:

    cd dragonboard-820c-bootloader-ufs-linux-*/
    sudo <PATH to qdl>/qdl prog_ufs_firehose_8996_ddr.elf ufs-provision_toshiba.xml

It should take a few seconds. And you should eventually get something like that:

    ...
    ...
    LOG: LUNum=6 bLUEnable=0 bBootLunID=0 bLUWriteProtect=0 bMemoryType=0 size_in_KB=0 bDataReliability=0 bLogicalBlockSize=12 bProvisioningType=0 wContextCapabilities=0
    LOG: LUNum=7 bLUEnable=0 bBootLunID=0 bLUWriteProtect=0 bMemoryType=0 size_in_KB=0 bDataReliability=0 bLogicalBlockSize=12 bProvisioningType=0 wContextCapabilities=0
    LOG: Set storage parameters successfully
    UFS provisioning succeeded

### Booting into fastboot

If the flashing process succeeded, all the right bootloaders and partition table should have been set. And fastboot can now be used to flash Linux root file system. The first thing to try is to get into fastboot, to make sure the flashing completed properly.

* Power off the board and make sure no USB cable is plugged into the board
* Set Switch S1 to `OFF,OFF,OFF,OFF`. If you have a P1 board (very unlikely) you may need to use `OFF,ON,OFF,OFF`.
* Connect the debug UART / serial console to your Linux PC, if not done already
* Connect the micro USB cable (J4) between the Linux PC and the board
* Open UART/serial console
* Power on the device

You should some see debug traces on the console, and at the end something like:

    S- QC_IMAGE_VERSION_STRING=BOOT.XF.1.0-00301
    ...
    ...
    fastboot: processing commands
