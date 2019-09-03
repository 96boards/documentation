---
title: Setting up CSI camera with Rock960 Model C board
permalink: /documentation/consumer/rock/rock960c/guides/camera-setup/
---

# Setting up CSI camera with Rock960 Model C board

This guide provides instructions for setting up camera with Rock960 board.
This guide should be read in conjunction with [Using CSI camera with Rock960 family boards](../../guides/camera-module/) guide.

## Prerequisities

- [Deltavision MIPI adapter Mezzanine](https://www.96boards.org/product/mipiadapter/)
- [Rock960 Model C](https://www.96boards.org/product/rock960c/)
- OV5645 MIPI CSI Camera

## Camera Setup

Below sections are used to setup camera modules on two different versions
of the Deltavision Mezzanine. Choose the one based on requirement.

Rock960 model C boards support two CSI on the High speed expansion connector.

### Deltavision MIPI v2.0

On v2.0 mezzanine, OV5645 camera modules can be connected to different
connectors based on the available cable type. Below sections describe few
of them.

#### OV5645 with J3 or J10 Connector

- Connect pins: 5-6 on **J15** header if use **J10** connector.
- Connect pins: 8-7 on **J14** header.
- Connect pins: 19-20 and 21-22 on **J13** connector.

Connections should look like below:

![camera_setup](../../rock960/additional-docs/images/images-guides/ov5645.png)

##### Software Setup

Build and install the below kernel as per this [guide](../../build/linux-kernel/).

Kernel: https://github.com/96rocks/kernel.git
Branch: release-4.4-rock960

#### OV5645 with J1 or J4 Connector

- Connect pins: 13-14 on **J15** header if use **J1** connector.
- Connect pins: 1-2 on **J14** header.
- Connect pins: 15-16 and 17-18 on **J13** connector.

##### Software Setup

Build and install the below kernel as per this [guide](../../build/linux-kernel/).

Kernel: https://github.com/96rocks/kernel.git
Branch: release-4.4-rock960
