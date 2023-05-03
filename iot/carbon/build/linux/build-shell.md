---
title: How to build the Shell Zephyr application from source - Linux Host
permalink: /documentation/iot/carbon/build/linux/build-shell.md.html
redirect_from: /documentation/IoTEdition/carbon/build/LinuxBuild/BuildShell.md.html
---
## How to build the Shell Zephyr application from source - Linux Host

These instructions will show how to build a sample Zephyr application using a Linux Host machine as a development environment.

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

#### **Step 1**: Build the Zephyr shell application

**Build the sample shell application as follows:**

```shell
$ cd zephyr
$ source zephyr-env.sh
$ cd samples/subsys/shell/shell_module/
$ mkdir outdir; cd outdir
$ cmake -DBOARD=96b_carbon ..
$ make
```

#### **Step 2**: Flashing

- Connect the micro-USB cable to the OTG port
- Press the BOOT0 switch and hold
- While holding BOOT0 switch, also press the RST switch (At this point you should be pressing two switches)
- Release the RST switch, then release the BOOT0 switch.

```shell
$ sudo make flash
```

#### Proceed to Installation page for legacy flashing instructions

The application will be available at ```samples/subsys/shell/shell/outdir/96b_carbon/zephyr.bin```.

Proceed to flash the Zephyr application binary over USB-UART or USB-DFU. Host machine specific flashing instructions can be found on the "Installation" page, link found below.

- [Installation Page](../../installation/)
