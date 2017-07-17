---
title: Carbon Hardware User Manual
permalink: /documentation/IoTEdition/carbon/installation/LinuxUART.md/
---
## Linux Host

This section show how to install an operating system to your Carbon using the Flashing over UART method on a Linux host computer.
***

- **Step 1**: Enter the STM32 Bootloader mode
- **Step 2**: Build or Download a sample application in Zephyr
- **Step 3**: Flash the application to Carbon


***

####**Step 1**: Enter the STM32 Bootloader mode

- Connect the micro-USB cable to the USB-UART port
- Press the BOOT0 switch and hold
- While holding BOOT0 switch, also press the RST switch (At this point you should be pressing two switches)
- Release the RST switch, then release the BOOT0 switch.


**Run the following command:**

```shell
$ sudo apt-get install stm32flash
$ sudo stm32flash /dev/ttyUSB0
stm32flash 0.5

http://stm32flash.sourceforge.net/

Interface serial_posix: 57600 8E1
Version      : 0x31
Option 1     : 0x00
Option 2     : 0x00
Device ID    : 0x0433 (STM32F401xD(E))
- RAM        : 96KiB  (12288b reserved by bootloader)
- Flash      : 512KiB (size first sector: 1x16384)
- Option RAM : 16b
- System RAM : 30KiB
```

**If you see something similar to the output above, you're in the STM32 Bootloader mode.**

####**Step 2**: Build or Download a sample application in Zephyr

[Build](../Building/) or [Download](../Downloads/) an application and proceed to **Step 3**

####**Step 3**: Flash the application to Carbon

- Go over Step 1 again, to enter the STM32 Bootloader mode
- Flash the application and OS to Carbon STM32F4 as follows:
```shell
$ sudo stm32flash -b 115200 -g 0x0 -w samples/<path>/<to>/zephyr.bin /dev/ttyUSB0
```
The path to your zephyr.bin file will depend on the type of file you have built.

Example:

- Path to disco: /samples/basic/disco/outdir/96b_carbon/zephyr.bin
- Path to shell: /samples/shell/outdir/96b_carbon/zephyr.bin

***

**Congratulations! You are now booting your newly compiled operating system and application on your Carbon!**
