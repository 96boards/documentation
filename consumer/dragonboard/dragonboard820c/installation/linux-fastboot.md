---
title: Linux Host Installation for DragonBoard 820c
permalink: /documentation/consumer/dragonboard/dragonboard820c/installation/linux-fastboot.md.html
redirect_from: /documentation/consumer/dragonboard820c/installation/linux-fastboot.md.html

---
## Linux Host

This section shows how to install an operating system to your DragonBoard™ 820c using the Fastboot method on a Linux host computer.
Please refer to the **[Build Linux Host Computer](build-linux-host.md)** for the initial setup.

### Booting into fastboot

If the board is flashed properly, all the right bootloaders and partition table should have been set. And fastboot can be used to flash Linux root file system. The first thing to try is to get into fastboot, to confirm that the board was flashed properly.

* Power off the board
* Make sure that switch S1 to `OFF,OFF,OFF,OFF`. If you have a P1 or earlier board you may need to use `OFF,ON,OFF,OFF`.
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

## (re)Flashing the bootloaders

It the board does not come up into `fastboot` mode (e.g. it is bricked), or if you want to install a different version of the bootloaders, please follow instructions from this document: [board recovery](./board-recovery.md), and then come back to the previous section.

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
