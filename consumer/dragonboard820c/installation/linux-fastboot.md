---
title: Linux Host Installation for DragonBoard 820c
permalink: /documentation/consumer/dragonboard820c/installation/linux-fastboot.md.html
redirect_from:

---
## Linux Host

This section show how to install an operating system to your DragonBoard™ 820c using the Fastboot method on a Linux host computer.
Please refer to the **[Build Linux Host Computer](build-linux-host.md)** for the initial setup.

## Flashing the Bootloader

Bootloader on Dragonboard820c can be flashed using the USB interface. An open source tool that implements the Qualcomm Sahara protocol has been developed by Linaro. When booting from `USB`, the internal SoC ROM code (also called PBL) implements the Sahara protocol to communicate with a PC host. After an initial setup phase, the Sahara protocol can be used to download a flashing programmer into the SoC internal memory, which implements the Firehose protocol. This protocol allows the host PC to send commands to write into the onboard storage (eMMC or UFS). The programmer file is included in the QDN Linux board support release from Qualcomm.

### Getting the Qualcomm Download (QDL) tool

#### Packages required:

```shell
$ sudo apt-get install libxml2-dev
```

#### Building QDL: 

```
$ git clone https://git.linaro.org/landing-teams/working/qualcomm/qdl.git
$ cd qdl
$ make
```

### Make sure that ModemManager is not running

Some Linux distributions come with ModemManager, a tool for configuring Mobile Broadband.
When the dragonboard is connected in USB mode, it will be identified as a Qualcomm modem,
and ModemManager will try to configure the device. This will interfere with the QDL flashing,
so if you have ModemManager running, you need to disable it before connecting your dragonboard.
If you are using a Linux distribution with systemd, ModemManager can be stopped by:

```shell
$ sudo systemctl stop ModemManager
```

If you actually need ModemManager, you can start it again after the flashing is complete.

### Connecting the DB820c

* In order to force the DB820c to boot on USB, you need to configure S1 switch properly. S1 is on the back of the board underneath the micro SD slot.
* If you have a P2 board (or above, which is the most likely situation), set it to `ON,OFF,OFF,ON`. Otherwise if you have a P1 board, set it to `ON,ON,OFF,ON`
* Connect a USB cable from the micro USB on Dragonboard820c to your PC.
* Connect UART console (optional)

### Flashing the bootloader

Download and unzip the most recent bootloader package:
The script downloads the latest build and prints the BUILD number for your information.
 
```shell
$ BUILD=$(curl http://snapshots.linaro.org/96boards/dragonboard820c/linaro/rescue/latest/ | grep -oP '(?<=/)\d{2}(?=/")')
$ echo "BUILD=$BUILD"
$ wget http://snapshots.linaro.org/96boards/dragonboard820c/linaro/rescue/latest/dragonboard-820c-bootloader-ufs-linux-*.zip
$ unzip dragonboard-820c-bootloader-ufs-linux-*.zip
$ rm dragonboard-820c-bootloader-ufs-linux-*.zip
$ mv dragonboard-820c-bootloader-ufs-linux-$BUILD bootloader-ufs-linux
$ cd bootloader-ufs-linux
$ sudo <PATH to qdl>/qdl prog_ufs_firehose_8996_ddr.elf rawprogram.xml patch.xml
```
It should take a few seconds. And you should eventually get something like that:

```shell
	...
	...
	Update Backup Header with CRC of Backup Header.
	LOG: crc start sector 393215, over bytes 92
	LOG: Patched sector 393215 with 8FDB38DF
	LUN1 is now bootable device
	LOG: Inside handlePower() - Requested POWER_RESET
	LOG: Issuing bsp_target_reset() after 1 seconds, if this hangs, do you have WATCHDOG enabled?
```

### Booting into fastboot

If the flashing process succeeded, all the right bootloaders and partition table should have been set. And fastboot can now be used to flash Linux root file system. The first thing to try is to get into fastboot, to make sure the flashing completed properly.

* Power off the board
* Set Switch S1 to `OFF,OFF,OFF,OFF`. If you have a P1 or earlier board you may need to use `OFF,ON,OFF,OFF`.
* Connect the debug UART / serial console to your Linux PC (optional)
* Connect the micro USB cable (J4) to your Linux PC.
* Open UART/serial console (optional)
* Power on the device while holding Vol (-) button

You should see some debug traces on the console indicating that the board booted into fastboot mode, and at the end something like:

```shell
	S- QC_IMAGE_VERSION_STRING=BOOT.XF.1.0-00301
	...
	...
	fastboot: processing commands
```
On the host, you can verify the fastboot mode of Dragonboard820c using the following command:

```shell
$ sudo fastboot devices
```

It will show as below:
```shell
452bb893	fastboot
```
> Note: If the board is not going into fastboot mode and it boots the already available boot image,
>       you can delete the boot partition after login using the command `cat /dev/zero > /dev/disk/by-partlabel/boot`.
>       Then next time it will boot into fastboot mode directly.

## Installing Debian

Recall the location of boot and rootfs downloaded from the [downloads](../downloads/debian.md) page.
- You should have downloaded the `boot` file
- You should have downloaded ONE of rootfs` file (Either `Developer` or `Desktop - ALIP` version)

Now, Unzip both files:

```shell
$ gunzip boot-linaro-buster-dragonboard-820c-BUILD.img.gz
$ gunzip linaro-buster-alip-dragonboard-820c-BUILD.img.gz
			(or)
$ gunzip linaro-buster-developer-dragonboard-820c-BUILD.img.gz
```
> Note: Replace **BUILD#** in the above commands with the image build number.

Once the images are extracted, those can be flashed using fastboot:

```shell
$ sudo fastboot flash boot boot-linaro-buster-dragonboard-820c-BUILD.img
$ sudo fastboot flash rootfs linaro-buster-alip-dragonboard-820c-BUILD.img
			(or)
$ sudo fastboot flash rootfs linaro-buster-developer-dragonboard-820c-BUILD.img
```
> Note: Replace **BUILD#** in the above commands with the image build number.

If all steps went fine and you have flashed `ALIP` image, you should now have a Debian desktop with working GPU. The default image uses LxQt desktop, with the SDDM login manager. The desktop should be started by default with the `linaro` user, it can be stopped/restarted using `systemctl` commands, such as:

`sudo systemctl stop sddm`

### Installing an Open Embedded based image

Initial support for DragonBoard 820c has been added into the OpenEmbedded QCOM BSP later, including the appropriate kernel recipe. To build an image for Dragonboard 820c , simply follow the same instructions as usual, from [Dragonboard-410c-OpenEmbedded-and-Yocto](https://github.com/Linaro/documentation/blob/master/Reference-Platform/CECommon/OE.md). When you select the MACHINE to build for, pick `dragonboard-820c`.

The board has been added to the Linaro Reference Platform OpenEmbedded builds, and prebuilt images for this board are available here: [http://snapshots.linaro.org/96boards/dragonboard820c/linaro/openembedded/rocko/latest/](http://snapshots.linaro.org/96boards/dragonboard820c/linaro/openembedded/rocko/latest/).
