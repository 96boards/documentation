---
title: Setting Up the UART console for DragonBoard-410c
permalink: /documentation/consumer/dragonboard410c/guides/uart-serial-console.md.html
redirect_from:
- /db410c-getting-started/Guides/uart-serial-console.md/
- /documentation/ConsumerEdition/DragonBoard-410c/Guides/uart-serial-console.md.html
---
# Setting Up the UART console

A UART serial console can be optionally connected from a host PC USB port
to UART1, which is available on the DB410c low speed expansion connector
(J8). This allows a developer to bring up a terminal emulator on the
host PC and communicate with the DB410c using a command line interface. This
can be very valuable when performing in depth debugging as well as
using fastboot. The following defines the pins used for UART1 on the J8
connector:

- PIN1 is GND
- PIN11 is TX
- PIN13 is RX

A standard USB TTL FTDI cable, such as Part Number: *TTL-232RG-VREG1V8-WE*, that steps up the 1.8 volts available on the DB410c is required.   If one with the part number highlighted is used, the the pinout is as follows:

- BLACK -> PIN1
- YELLOW -> PIN11
- ORANGE -> PIN13

**Warning:** The FTDI cable above is required to be 1.8 volts (this is
denoted VREG1V8 in the part number above). Damage can occur to your
hardware if the wrong voltage cable is used.

A picture of the FTDI cable connected to the DragonBoard™ 410c is shown
below:

![](https://github.com/96boards/documentation/blob/master/consumer/dragonboard410c/additional-docs/images/images-wiki/image01.jpg)
Figure 1: FTDI Cable connected to J8 Header on DragonBoard™ 410c

**Warning:** Make sure that the extra wires are not touching the board in
any way. This can cause a short and damage the hardware. It is
recommended to either clip and tape the unused wires on the cable or to
solder a small header onto the end of the cable.

**Warning:** Never install the wires while the DragonBoard™ 410c is plugged
into power or has USB cables plugged into it.

**Warning:** Always wear safety glasses when working with any hardware to
avoid personal injury.

Warning: It is recommended that developers use an ESD compliant
environment when handling the DragonBoard™ 410c to avoid damaging the
electronics on the board.

After the above is completed, the user can perform the following steps
to access the DB410c serial console:

- Connect the USB connector of the FTDI cable to the host PC. This
  assumes that the other end is already connected to the DB410c
- Open a terminal on the host PC
- On the host PC find the full path of the FTDI cable in the /dev/…
  device tree
- On the host PC use a terminal emulator application to bring up the
  console. For purposes of example, these instructions use “screen”
```shell
sudo screen /dev/<path of the FTDI> 115200
```

Note: The default speed of UART1 is 115200 Baud on the DB410c.

- Once the above has been executed, power on the DB410c and the user
  will see boot sequence text scroll in the console on the host PC
  ending with a Linux command prompt once the DB410c is booted.
