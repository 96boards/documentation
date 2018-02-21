---
title: Linux Host Installation for DragonBoard 820c
permalink: /documentation/consumer/dragonboard820c/installation/linux-fastboot.md.html
redirect_from:

---
## Linux Host

This section show how to install an operating system to your DragonBoard™ 820c using the Fastboot method on a Linux host computer.

## Flashing using Fastboot

Alternatively, the Dragonboard 820c can also be recovered/flashed using USB. An open source tool that implements the Qualcomm Sahara protocol has been developed by Linaro. When booting from `USB` the internal SoC ROM code (also called PBL) implements the Sahara protocol to communicate with a PC host. After an initial setup phase, the Sahara protocol can be used to download a flashing programmer into the SoC internal memory, which implements the Firehose protocol. This protocol allows the host PC to send commands to write into the onboard storage (eMMC or UFS). The programmer file is included in the QDN Linux board support release from Qualcomm.

### Get the Linux flashing tool

`git clone https://git.linaro.org/landing-teams/working/qualcomm/qdl.git`

This is provided in source code, and it needs to be compiled locally. It uses libxml, so on Ubuntu/Debian you will need:

`sudo apt-get install libxml2-dev`

To compile `qdl` project, it should be as simple as running `make` command in the root of the project.

### Connecting the DB820c

* In order to force the DB820c to boot on USB, you need to configure S1 switch properly. S1 is on the back of the board underneath the micro SD slot.
* If you have a P2 board (or above, which is the most likely situation), set it to `ON,OFF,OFF,ON`. Otherwise if you have a P1 board, set it to `ON,ON,OFF,ON`
* Connect a USB cable from the micro USB to your PC.
* Connect UART console

### Flashing the device

Download and unzip the most recent bootloader package:

`http://snapshots.linaro.org/96boards/dragonboard820c/linaro/rescue/latest/dragonboard-820c-bootloader-ufs-linux-*.zip`

Then run:

```shell
cd dragonboard-820c-bootloader-ufs-linux-*/
sudo <PATH to qdl>/qdl prog_ufs_firehose_8996_ddr.elf rawprogram.xml patch.xml
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
* Connect the debug UART / serial console to your Linux PC, if not done already
* Connect the micro USB cable (J4) to your Linux PC.
* Open UART/serial console
* Power on the device

You should some see debug traces on the console, and at the end something like:

```shell
	S- QC_IMAGE_VERSION_STRING=BOOT.XF.1.0-00301
	...
	...
	fastboot: processing commands
```

Some board might have a valid boot partition pre-flashed, in which case the bootloader will load it and boot it. So if you see a Linux kernel being booted before flashing it yourself, then power cycle the board and press the Vol (-) key , so that it will force the bootloader to stop in fastboot mode. And normally you should now see the following in the UART console:

`fastboot: processing commands`

And you can now erase the boot partition, so that you don't need to press Vol (-) when powering it, on your PC, run:

`fastboot erase boot`

If the board boots into the OS by default and you do not have any way to interrupt in between, then once you get a root prompt after booting into the OS, use the following command to erase the boot partition:

`cat /dev/zero > /dev/disk/by-partlabel/boot`

## Installing Debian

### Debian Buster images

As of build #108, the Linaro builds for Dragonboard 820c have been migrated to Debian Buster release. All images released on 96boards.org include firmware files for the hardware co processors such as GPU, WLAN, Venus or DSP.  

### Console (no graphics) image

Debian builds for the DB820c can be found here: http://builds.96boards.org/snapshots/dragonboard820c/linaro/debian/. They have for now has minimal features set (mostly console, UFS, 4 core running at the lowest speed). Features will be added in this builds stream. 

To install the Debian root file system:

1. Download either the `developer`` image from the link above
1. Uncompress the root file system image
1. Flash the image into `userdata` (or `system`).

So, assuming you are trying to use the latest build:

```shell
$ wget http://builds.96boards.org/snapshots/dragonboard820c/linaro/debian/latest/linaro-buster-developer-dragonboard-820c-*.img.gz
$ gunzip linaro-buster-developer-dragonboard-820c-*.img.gz
$ fastboot flash userdata linaro-buster-developer-dragonboard-820c-*.img

You can also mount the rootfs image on an NFS partition; to do that and since the image above is an sparse image you will have to first unsparse it and then mount it.

```shell
$ simg2img linaro-buster-developer-dragonboard-820c-*.img rootfs.img
$ mount -t nfs rootfs.img mnt/
```

You can download the prebuilt boot image as well, from the same location.

```shell
$ wget http://builds.96boards.org/snapshots/dragonboard820c/linaro/debian/latest/boot-linaro-buster-dragonboard-820c-*.img.gz
$ gunzip boot-linaro-buster-dragonboard-820c-*.img.gz
$ fastboot flash boot boot-linaro-buster-dragonboard-820c-*.img
```

To update the kernel command line embedded in the .img to support an NFS mounted root partition the command could be as follows (for an nfs server in 192.168.1.4)

```shell
$ abootimg -u boot-linaro-buster-dragonboard-820c-*.img -c "cmdline=root=/dev/nfs rw nfsroot=192.168.1.4:/Exports/qcom/rootfs,v3,tcp rootwait console=tty0 console=ttyMSM0,115200n8"
```

### Graphical image (with GPU)

Instead of using the ``developer`` image as per the previous section, you can use the ``desktop`` image, e.g. 

```shell
$ wget http://builds.96boards.org/snapshots/dragonboard820c/linaro/debian/latest/linaro-buster-alip-dragonboard-820c-*.img.gz
$ gunzip linaro-buster-alip-dragonboard-820c-*.img.gz
$ fastboot flash userdata linaro-buster-alip-dragonboard-820c-*.img
```

You can use the same boot image as mentioned in the previous section.

If all steps went fine, you should now have a Debian desktop with working GPU. The default image uses LxQt desktop, with the SDDM login manager. The desktop should be started by default with the `linaro` user, it can be stopped/restarted using `systemctl` commands, such as:

`sudo systemctl stop sddm`

### Installing an Open Embedded based image

Initial support for DragonBoard 820c has been added into the OpenEmbedded QCOM BSP later, including the appropriate kernel recipe. To build an image for Dragonboard 820c , simply follow the same instructions as usual, from [Dragonboard-410c-OpenEmbedded-and-Yocto](https://github.com/Linaro/documentation/blob/master/Reference-Platform/CECommon/OE.md). When you select the MACHINE to build for, pick `dragonboard-820c`.

The board has been added to the Linaro Reference Platform OpenEmbedded builds, and prebuilt images for this board are available here: http://builds.96boards.org/snapshots/dragonboard820c/linaro/openembedded/morty/latest/.