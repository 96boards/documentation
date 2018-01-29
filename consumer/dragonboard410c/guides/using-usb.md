---
title: Using USB Guide for DragonBoard-410c
permalink: /documentation/consumer/dragonboard410c/guides/using-usb.md.html
redirect_from:
- /db410c-getting-started/Guides/using-usb.md/
- /documentation/ConsumerEdition/DragonBoard-410c/Guides/using-usb.md.html
---
# Using USB

On this board, both USB Host and USB On-The-Go (OTG) are available,
however they cannot be used simultaneously. OTG is used by the
bootloader for fastboot. USB Host is also supported.

To use USB OTG:

- plug a micro USB cable in J4 connector and the other end of the cable plugged into the host PC. Note that if either end of this cable is disconnected, USB OTG mode will not be entered. Nothing else is required as the software auto-detects the USB connection and places the DB410c into OTG mode
- Note the when in this mode, devices such as keyboard and mouse may not work on the DB410c

To use USB Host:

- unplug the micro USB cable from J4.  The software will auto-detect no connection on J4 and will enter USB Host mode.
- plug one (or more) USB devices into J2 or J3 such as a keyboard, mouse, etc.

Note that several keyboards, mice, USB Memory sticks, ethernet adaptors
and other peripherals have been tested. However, there is still as
chance that your device might not work properly. If this occurs, please
submit a bug to the 96Boards bug tracking system located
[**here**](https://bugs.96boards.org/enter_bug.cgi?product=Dragonboard%20410c).

If you use an ethernet dongle, once you configure the USB in HOST mode,
and insert the dongle, the physical ethernet connection should automatically be established (generally as eth0, assuming that an active physical connection exists on the ethernet cable):

```shell
ip link show
```
