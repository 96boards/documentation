---
title: Qualcomm RB5 Board Recovery
permalink: /documentation/consumer/dragonboard/qualcomm-robotics-rb5/installation/board-recovery.md.html
---

# Qualcomm RB5 Board Recovery

This page outlines steps needed to recover your Qualcomm RB5 board from a bricked software state. This instruction set is suggested to those who are experiencing boot issues due to a corruption in the file system and/or other software components.

There are a couple ways to recover your board from a "bricked" state.

## SD card Recovery image

Unlike other Dragonboard (410c and 820c) the Qualcomm RB5 cannot boot from SD card, and there is no plan to support SD card recovery at this point.

## Fastboot recovery

In many cases, simply re-flashing the bootloader, boot image, and root file system, using the fastboot method is enough.

## Using USB flashing tools

Alternatively, the Qualcomm RB5 can also be recovered/flashed over USB, using the Linaro QDL flashing tools. For more information about QDL, including installation instructions, please check this [guide](../../../guides/qdl.md).

### Connecting the board in USB flashing mode (aka EDL mode)

In order to force the Qualcomm RB5 to boot on USB (EDL mode), you need to press the on-board button 18 (Force USB BOOT) while powering on the board. This button is on the back of the board and is marked as "F_DL".

*Warning*: putting the device into EDL mode while the device is powered or when USB is plugged can cause damage to the board.

* Power off the board and make sure the USB type-C cable is not plugged into the board
* Press button 18 (e.g. marked with F_DL), and
* Power on the device using the proper power supply
* Connect the USB3 Type C (5) between the Linux PC and the board

If the above instructions do not work, please try the following:

- Set the switch "DIP_SW" to "0 1 1 0 0 0"
- (Turn on SW2 on the dip switch to enable the USB2.0 debug port
- Turn on SW3 on the Dip Switch to enable the auto power up on USB-C cable connection)
- Power off the board and make sure the USB type-C cable is not plugged into the board
- Press button 18 (e.g. marked with F_DL), and
- Connect the USB3 Type C (5) between the Linux PC and the board

*Warning*: putting the device into EDL mode while the device is powered or when USB is plugged can cause damage to the board.

### Flashing the device

Download and unzip the most recent bootloader release from the following link:

http://releases.linaro.org/96boards/rb5/linaro/rescue/21.04/

Then run:

    cd <PATH to extracted folder>
    sudo <PATH to qdl>/qdl prog_firehose_ddr.elf rawprogram?.xml patch?.xml

It should take a few seconds. And you should eventually get something like below from QDL stdout:

    ...
    ...
    LOG: INFO: Calling handler for patch
    LOG: INFO: Calling handler for setbootablestoragedrive
    LOG: INFO: Using scheme of value= 1
    partition 1 is now bootable
    LOG: INFO: Calling handler for power
    LOG: INFO: Will issue reset/power off 100 useconds, if this hangs check if watchdog is enabled
    LOG: INFO: bsp_target_reset() 0

*Note*: Linaro regularly publishes development builds for the bootloader package. Instead of flashing the most recent bootloader release, users might want to experiment with development builds, which can be found at http://snapshots.linaro.org/96boards/qrb5165-rb5/linaro/rescue/latest/.

### UFS provisioning

UFS provisioning is not supported yet.

### Booting into fastboot

If the flashing process succeeded, all the right bootloaders and partition table should have been set. And fastboot can now be used to flash Linux root file system. The first thing to try is to get into fastboot, to make sure the flashing completed properly.

* Disconnect the power cable from the board and make sure no USB cable is plugged into the board
* Hold down the "VOL-" button while reconnecting the power supply.
* Tap the "ON/OFF" button while continuing to hold the "VOL-" button for ~5 seconds after the blue LED lights up.
* Release "VOL-" button
* Connect the USB3 Type C (5) between the Linux PC and the board

Execute below command on the PC to confirm that the board has entered fastboot mode:

```shell
$ sudo fastboot devices
01234567	fastboot
```
