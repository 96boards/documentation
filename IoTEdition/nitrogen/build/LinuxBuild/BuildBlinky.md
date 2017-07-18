---
title: Blinky Build for Nitrogen
permalink: /documentation/IoTEdition/nitrogen/build/LinuxBuild/BuildBlinky.md/
---
## How to build the blinky Zephyr application from source - Linux Host

These instructions can be used to build a simple 'blinky' demo using a Linux host machine as a development environment. The demo works by blinking the User LED (USR1) present on Nitrogen board.

After startup, the program looks up a predefined GPIO device, and configures the GPIO pin in output mode (USR1 LED). During each iteration of the main loop, the state of GPIO line will be changed so that the LED turns ON and OFF in an alternating pattern.

Once running, you should see the USR1 (green) blinking with 1 sec interval.

***

- **Step 0**: Download and setup Zephyr
- **Step 1**: Build a sample application in Zephyr
- **Step 2**: Proceed to Installation page for flashing instructions

***

#### **Step 0**: Download and setup Zephyr

- Download and setup the Zephyr development environment from https://www.zephyrproject.org. You can find more information about installing the Zephyr SDK at https://www.zephyrproject.org/doc/getting_started/getting_started.html

```shell
$ git clone https://gerrit.zephyrproject.org/r/zephyr
```

#### **Step 1**: Build the Zephyr disco application

```shell
$ cd zephyr
$ source zephyr-env.sh
$ make -C samples/basic/blinky BOARD=96b_nitrogen
```

The application will be available at ```samples/basic/blinky/outdir/96b_nitrogen/zephyr.hex```.

#### **Step 2**: Proceed to Installation page for flashing instructions

Proceed to flash the Zephyr application binary over USB-UART or USB-DFU. Host machine specific flashing instructions can be found on the "Installation" page, link found below.

- [Installation Page](../../installation/)
