---
title: Linux Host Installation for DragonBoard 820c
permalink: /documentation/consumer/dragonboard/dragonboard820c/installation/linux-sd.md.html
redirect_from: /documentation/consumer/dragonboard820c/installation/linux-sd.md.html

---
## Linux Host

This section show how to install an operating system to your DragonBoard™ 820c using the SD Card method on a Linux host computer.

### Flash the SD Card

As mentioned above, SD rescue images are published with on 96boards.org, download all files from:
http://builds.96boards.org/snapshots/dragonboard820c/linaro/rescue/latest/

Then, extract the SD card image from the file `dragonboard-820c-sdcard-rescue-xx.zip` and on your PC, you can write the image file to a micro SD card:

`dd if=dragonboard-820c-sdcard-rescue-20.img of=/dev/<your micro SD card> bs=4M oflag=sync status=noxfer`

### Connecting the DB820c

* In order to force the DB820c to boot from SD you need to configure S1 switch properly. S1 is on the back of the board underneath the micro SD slot. Set S1 to `OFF,ON,ON,OFF`
* Connect a USB cable from the micro USB to your PC.
* Connect UART console
* Connect the power whilst holding S4 (Vol-Minus)

### Boot from SD card into fasboot mode

If all the steps above were done properly you should see some debug traces on the console, and at the end something like:

`fastboot: processing commands`

which means that the board has entered in fastboot mode properly.

### Flashing the bootloader in onboard UFS drive

When booting with the SD rescue image, the `fastboot flash` command will in turn write into the onboard UFS. So it can be used to (re)partition the UFS, and/or flash any partition.

From the files downloaded earlier, extract the content of `dragonboard-820c-bootloader-ufs-linux-xx.zip` and then you can reflash the entire UFS using the provided script:

`./flashall`

If everything works fine, you should be all set now. And you can proceed further with this wiki to install Debian or OpenEmbedded images released on 96boards.
