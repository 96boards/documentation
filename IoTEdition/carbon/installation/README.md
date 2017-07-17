---
title: Carbon Hardware User Manual
permalink: /documentation/IoTEdition/carbon/installation/
redirect_from:
- /documentation/IoTEdition/carbon/installation/README.md/
---
# Installation

Choose and install an operating system on your Carbon. To appropriately follow this installation guide you will need to:

- Choose an installation method
- Download necessary files
- Choose host machine
- Follow flashing instructions

***

## Methods of Installation

In most cases, you will be presented with two options when installing your new operating system onto your Carbon:

- Flashing over micro-USB (OTG port)
- Flashing over UART (UART port)

Each method has it's own benifits, and requires different levels of experience

### Flashing over USB-UART Method

Flashing over USB-UART is usually easier as only a single USB port can be used for both flashing and console access.

This method requires the following hardware:

- Carbon
- Host Linux machine
- USB to microUSB cable
- stm32flash tool

You may choose to [Downloads](../Downloads/) or [Build](../Building/) an application for your Carbon

Choose host machine

- [Linux](LinuxUART.md)

***

### Flashing over OTG Method

Flashing over OTG is generally faster and should be used by beginners.

This method requires the following hardware:

- Carbon
- Host Linux machine
- USB to microUSB cable
- dfu-util tool

You may choose to [Downloads](../Downloads/) or [Build](../Building/) an application for your Carbon

Choose host machine

- [Linux](LinuxOTG.md)

***
