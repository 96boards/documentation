---
title: Carbon Hardware User Manual
permalink: /documentation/IoTEdition/carbon/installation/LinuxOTG.md/
---
## Linux Host

This section show how to install an operating system to your Carbon using the Flashing over OTG method on a Linux host computer.
***

- **Step 1**: Enter the DFU mode
- **Step 2**: Build or Download a sample application in Zephyr
- **Step 3**: Flash the application to Carbon


***

####**Step 1**: Enter the DFU mode

- Connect the micro-USB cable to the OTG port
- Press the BOOT0 switch and hold
- While holding BOOT0 switch, also press the RST switch (At this point you should be pressing two switches)
- Release the RST switch, then release the BOOT0 switch.


**Run the following command:**

```shell
$ sudo apt-get install dfu-util
$ sudo dfu-util -l

dfu-util 0.8
Copyright 2005-2009 Weston Schmidt, Harald Welte and OpenMoko Inc.
Copyright 2010-2014 Tormod Volden and Stefan Schmidt
This program is Free Software and has ABSOLUTELY NO WARRANTY
Please report bugs to dfu-util@lists.gnumonks.org
Found DFU: [0483:df11] ver=2200, devnum=15, cfg=1, intf=0, alt=3, name="@Device Feature/0xFFFF0000/01*004 e", serial="3574364C3034"
Found DFU: [0483:df11] ver=2200, devnum=15, cfg=1, intf=0, alt=2, name="@OTP Memory /0x1FFF7800/01*512 e,01*016 e", serial="3574364C3034"
Found DFU: [0483:df11] ver=2200, devnum=15, cfg=1, intf=0, alt=1, name="@Option Bytes /0x1FFFC000/01*016 e", serial="3574364C3034"
Found DFU: [0483:df11] ver=2200, devnum=15, cfg=1, intf=0, alt=0, name="@Internal Flash /0x08000000/04*016Kg,01*064Kg,03*128Kg", serial="3574364C3034"
Found Runtime: [05ac:8290] ver=0104, devnum=2, cfg=1, intf=5, alt=0, name="UNKNOWN", serial="UNKNOWN"
You should see the following at your Linux host:
usb 1-2.1: new full-speed USB device number 14 using xhci_hcd
usb 1-2.1: New USB device found, idVendor=0483, idProduct=df11
usb 1-2.1: New USB device strings: Mfr=1, Product=2, SerialNumber=3
usb 1-2.1: Product: STM32 BOOTLOADER
usb 1-2.1: Manufacturer: STMicroelectronics
usb 1-2.1: SerialNumber: 3574364C3034
```

**If you see something similar to the output above, you're in DFU mode.**

####**Step 2**: Build or Download a sample application in Zephyr

[Build](../Building/) or [Download](../Downloads/) an application and proceed to **Step 3**

####**Step 3**: Flash the application to Carbon

- Flash the application and OS to Carbon STM32F4 as follows:

```shell
$ sudo dfu-util -d [0483:df11] -a 0 -D samples/<path>/<to>/zephyr.bin -s 0x08000000
```
The path to your zephyr.bin file will depend on the type of file you have built.  

Example:

- Path to disco: /samples/drivers/outdir/96b_carbon/disco.bin
- Path to shell: /samples/shell/outdir/96b_carbon/shell.bin

***

**Congratulations! You are now booting your newly compiled operating system and application on your Carbon!**
