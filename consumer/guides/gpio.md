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

## GPIO access through Command Line using sysfs Interface

The following instructions are applicable to all Linux based distributions and is based on sysfs interface. Note that the sysfs interface to the GPIO is deprecated.

For details about the sysfs interface for the GPIO pins see [GPIO Sysfs Interface for Userspace](https://www.kernel.org/doc/html/latest/admin-guide/gpio/sysfs.html) which contains details about the paths to use and how to use the various control interfaces.

To access the GPIOs through the Linux shell you can use the sysfs interface and the psudo files that act as an interface to the kernel implementation of the GPIO device drivers. You will need to have superuser access to manipulate the pseudo files.

Start by opening up a terminal window to access the command shell, open the terminal (start menu > other > LXTerminal; right click this to add shortcut to your desktop if you desire) and give yourself super user access:

```shell
$ sudo su
```

Giving yourself superuser access will allow you to modify the GPIOs (if you get an access denied for a GPIO, this means you’re trying to modify a GPIO the board is using for itself)

Once you have superuser access, navigate to the gpio folder with the following command:

```shell
# cd /sys/class/gpio
```

Before accessing any GPIO, it needs to be exported. The `export` command will instruct the kernel to create the various files and directories, pseudo files, representing the GPIO pin. After doing an `export` of a pin, the GPIO pin functionality can be used by reading and writing to various files created by using standard file I/O commands. There is also an `unexport` command to undo a previous `export` command. Also note that after a reboot, the exporting will need to be done again unless a change is made to do the pin export as part of Linux startup.

Use the following command to create the pseudo files for GPIO pin #36. For other pins, you would replace 36 with the pin number you want to use.

```shell
# echo 36 > export
```

> Note: Each 96Boards uses different SoC(System On Chip) which has different GPIO pins exported. The following list
specifies the GPIO pins exported by Linux kernel for different CE boards. For mapping these pins to LS expansion header pins,
consult the board documentation availabe in [Products page](/products/ce/)

> **DragonBoard410c:** 36, 12, 13, 69, 115, 4, 24, 25, 35, 34, 28, 33  
> **HiKey620:** 488, 489, 490, 491, 492, 415, 463, 495, 426, 433, 427, 434  
> **Bubblegum:** 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 155, 154

After exporting GPIO, move into that gpio directory
```shell
# cd gpio36
```

Following command returns the direction of GPIO which is a string value of "out" or "in"
```shell
# cat direction
```

Following command sets the direction of GPIO
```shell
# echo [out or in] > direction
```

Following command returns 0 if the pin is off or low, 1 if the pin is on or high
```shell
# cat value
```

Following command sets value of GPIO
```shell
# echo [0 or 1] > value
```

Using a multimeter set to measuring voltage, you can probe the pin you are toggleing along with one of the ground nodes (Pins 1,2,39, and 40), to watch the voltage switch between ~1.8V and 0V as the content of `value` is changed.

### GPIO signal pin attribute files

GPIO signal pins have paths like `/sys/class/gpio/gpio42`. Each has a set of attributes accessed through pseudo files that can be read from or written to. See [Paths in Sysfs](https://www.kernel.org/doc/html/latest/admin-guide/gpio/sysfs.html#paths-in-sysfs) for details.

> “direction” …
>
> reads as either “in” or “out”. This value may normally be written. Writing as “out” defaults to initializing the value as low. To ensure glitch free operation, values “low” and “high” may be written to configure the GPIO as an output with that initial value.
>
> Note that this attribute will not exist if the kernel doesn’t support changing the direction of a GPIO, or it was exported by kernel code that didn’t explicitly allow userspace to reconfigure this GPIO’s direction.
>
> “value” …
>
> reads as either 0 (low) or 1 (high). If the GPIO is configured as an output, this value may be written; any nonzero value is treated as high.
>
> If the pin can be configured as interrupt-generating interrupt and if it has been configured to generate interrupts (see the description of “edge”), you can poll(2) on that file and poll(2) will return whenever the interrupt was triggered. If you use poll(2), set the events POLLPRI and POLLERR. If you use select(2), set the file descriptor in exceptfds. After poll(2) returns, either lseek(2) to the beginning of the sysfs file and read the new value or close the file and re-open it to read the value.
>
> “edge” …
>
> reads as either “none”, “rising”, “falling”, or “both”. Write these strings to select the signal edge(s) that will make poll(2) on the “value” file return.
>
> This file exists only if the pin can be configured as an interrupt generating input pin.
>
> “active_low” …
>
> reads as either 0 (false) or 1 (true). Write any nonzero value to invert the value attribute both for reading and writing. Existing and subsequent poll(2) support configuration via the edge attribute for “rising” and “falling” edges will follow this setting.


## GPIO access through MRAA library

[MRAA library](https://github.com/intel-iot-devkit/mraa) can be used for accessing GPIO's present on 96Boards. More
information on accessing GPIO though MRAA is provided [here](https://iotdk.intel.com/docs/master/mraa/gpio_8h.html)
