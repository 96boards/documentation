---
title: DragonBoard 845c Board Recovery
permalink: /documentation/consumer/dragonboard/dragonboard845c/installation/board-recovery.md.html
---

# DragonBoard 845c Board Recovery

This page outlines steps needed to recover your DragonBoard 845c board from a bricked software state. This instruction set is suggested to those who are experiences boot issues due to a corrution in the file system and/or other software components.

There are a couple ways to recover your DragonBoard 845c from a "bricked" state.

## SD card Recovery image

Unlike other Dragonboard (410c and 820c) the Dragonboard 845c cannot boot from SD card. It is a hardware limitation of the SOM used, and there is no plan to fix this limitation at this point.

## Fastboot recovery

In many cases, simply re-flashing the bootloader, boot image, and root file system, using the fastboot method is enough.

## Using USB flashing tools

Alternatively, the Dragonboard 845c can also be recovered/flashed over USB, using the Linaro QDL flashing tools. For more information about QDL, including installation instructions, please check this [guide](../../../guides/qdl.md).

### Connecting the board in USB flashing mode (aka EDL mode)

In order to force the DB845c to boot on USB (EDL mode), you need to press the on-board button 18 (Force USB BOOT) while powering on the board. This button is on the back of the board and is marked as "F_DL".

*Warning*: putting the device into EDL mode while the device is powered or when USB is plugged can cause damage to the board.

* Power off the board and make sure the USB type-C cable is not plugged into the board
* Press button 18 (e.g. marked with F_DL), and
* Power on the device using the proper power supply
* Connect the USB3 Type C (5) between the Linux PC and the board


### Flashing the device

Download and unzip the most recent bootloader package from the following link:

http://snapshots.linaro.org/96boards/dragonboard845c/linaro/rescue/latest/

Then run:

    cd dragonboard-845c-bootloader-ufs-linux-[BUILD-NUM].zip/
    sudo <PATH to qdl>/qdl prog_firehose_ddr.elf rawprogram?.xml patch?.xml

It should take a few seconds. And you should eventually get something like below
from QDL stdout:

    ...
    ...
    LOG: INFO: Calling handler for patch
    LOG: INFO: Calling handler for setbootablestoragedrive
    LOG: INFO: Using scheme of value= 1
    partition 1 is now bootable
    LOG: INFO: Calling handler for power
    LOG: INFO: Will issue reset/power off 100 useconds, if this hangs check if watchdog is enabled
    LOG: INFO: bsp_target_reset() 0

### UFS provisioning

UFS provisioning is not support yet.

### Booting into fastboot

If the flashing process succeeded, all the right bootloaders and partition table should have been set. And fastboot can now be used to flash Linux root file system. The first thing to try is to get into fastboot, to make sure the flashing completed properly.

* Power off the board and make sure no USB cable is plugged into the board
* Power on the device using the proper power supply
* Connect the USB3 Type C (5) between the Linux PC and the board

Execute below command on the PC to confirm that the board has entered fastboot mode:

```shell
$ sudo fastboot devices
01234567	fastboot
```
