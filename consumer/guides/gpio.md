---
title: General Purpose Input/Output
permalink: /documentation/consumer/guides/gpio.md.html
redirect_from:
- /documentation/Extras/ConsumerEdition/GPIO/Advanced/
- /documentation/ConsumerEdition/guides/gpio.md.html
---
# General Purpose Input/Output

GPIO provides the basic Input and Output access to the physical world for 96Boards. GPIO pins can perform 'read' and
'write' operation for controlling devices connected to 96Boards.

96Boards provides access to GPIO pins through 40pin **Low Speed Expansion Header** available on all CE boards.

## GPIO access through Command Line

The following instructions are applicable to all Linux based distributions and is based on sysfs interface.

To access the GPIOs through the Linux shell, open the terminal (start menu > other > LXTerminal; right click this to add shortcut to your desktop if you desire) and give yourself super user access:

```shell
$ sudo su
```

Giving yourself superuser access will allow you to modify the GPIOs (if you get an access denied for a GPIO, this means you’re trying to modify a GPIO the board is using for itself)

Once you have superuser access, navigate to the gpio folder with the following command:

```shell
# cd /sys/class/gpio
```

Before accessing any GPIO, it needs to be exported using the following command:

```shell
# echo 36 > export
```

> Note: Each 96Boards uses different SoC(System On Chip) which has different GPIO pins exported. The following list
specifies the GPIO pins exported by Linux kernel for different CE boards. For mapping these pins to LS expansion header pins,
consult the board documentation availabe in [Products page](https://www.96boards.org/products/ce/)

> **DragonBoard410c:** 36, 12, 13, 69, 115, 4, 24, 25, 35, 34, 28, 33  
> **HiKey620:** 488, 489, 490, 491, 492, 415, 463, 495, 426, 433, 427, 434  
> **Bubblegum:** 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 155, 154

After exporting GPIO, move into that gpio directory
```shell
# cd gpio36
```

Following command returns the direction of GPIO
```shell
# cat direction
```

Following command sets the direction of GPIO
```shell
# echo [out or in] > direction
```

Following command returns 0 if the pin is off, 1 if the pin is on
```shell
# cat value
```

Following command sets value of GPIO
```shell
# echo [0 or 1] > value
```

Using a multimeter set to measuring voltage, you can probe the pin you are toggleing along with one of the ground nodes (Pins 1,2,39, and 40), to watch the voltage switch between ~1.8V and 0V.

## GPIO access through MRAA library

[MRAA library](https://github.com/intel-iot-devkit/mraa) can be used for accessing GPIO's present on 96Boards. More
information on accessing GPIO though MRAA is provided [here](https://iotdk.intel.com/docs/master/mraa/gpio_8h.html)
