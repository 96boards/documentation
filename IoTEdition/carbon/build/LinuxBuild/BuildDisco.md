---
title: How to build the disco Zephyr application from source - Linux Host
permalink: /documentation/IoTEdition/carbon/build/LinuxBuild/BuildDisco.md/
---
## How to build the disco Zephyr application from source - Linux Host

These instructions can be used to build a simple 'disco' demo using a Linux host machine as a development environment. The demo assumes that 2 LEDs are connected to GPIO outputs of the MCU/board. The sample code is configured to work on Carbon, with LEDs connected to PA15 and PB5 pins.

After startup, the program looks up a predefined GPIO devices, and configures the GPIO pins in output mode (LEDs). During each iteration of the main loop, the state of GPIO lines will be changed so that one of the lines is in high state, while the other is in low, thus switching the LEDs on and off in an alternating pattern.

Once running, you should see the USR1 (green) and BT (blue) LEDs blinking, like a disco :-)

***

- **Step 0**: Download and setup Zephyr
- **Step 1**: Build a sample application in Zephyr
- **Step 2**: Proceed to Installation page for flashing instructions

***

####**Step 0**: Download and setup Zephyr

- Download and setup the Zephyr development environment from https://www.zephyrproject.org. You can find more information about installing the Zephyr SDK at https://www.zephyrproject.org/doc/getting_started/getting_started.html

```shell
$ git clone https://gerrit.zephyrproject.org/r/zephyr
```

####**Step 1**: Build the Zephyr disco application

**Build the sample shell application as follows:**

```shell
$ cd zephyr
$ source zephyr-env.sh
$ make -C samples/basic/disco BOARD=96b_carbon
```

The application will be available at ```samples/basic/disco/outdir/96b_carbon/zephyr.bin```.

#### **Step 2**: Proceed to Installation page for flashing instructions

Proceed to flash the Zephyr application binary over USB-UART or USB-DFU. Host machine specific flashing instructions can be found on the "Installation" page, link found below.

- [Installation Page](../../Installation/)
