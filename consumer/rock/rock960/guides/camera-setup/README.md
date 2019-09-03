---
title: Setting up CSI camera with Rock960 Model A&B board
permalink: /documentation/consumer/rock/rock960/guides/camera-setup/
---

# Setting up CSI camera with Rock960 Model A&B board

This guide provides instructions for setting up camera with Rock960 board.
This guide should be read in conjunction with [Using CSI camera with Rock960 family boards](../../guides/camera-module.md) guide.

## Prerequisities

* [Deltavision MIPI adapter Mezzanine](https://www.96boards.org/product/mipiadapter/)
* [Rock960 Model A/B](https://www.96boards.org/product/rock960/)
* OV5645 MIPI CSI Camera

## Camera Setup

Below sections are used to setup camera modules on two different versions
of the Deltavision Mezzanine. Choose the one based on requirement.

**Note: Rock960 Model A&B boards support only single CSI interface on the
High speed expansion connector. So connecting dual camera is not possible.**

### Deltavision MIPI v2.0

On v2.0 mezzanine, OV5645 camera modules can be connected to different
connectors based on the available cable type. Below sections describe few
of them.

#### OV5645 with IPEX Micro-Coax Connector

* Connect the OV5645 camera to **J10** connector.
* Connect pins: 8-7 on **J14** header.
* Connect pins: 5-6 on **J15** header.
* Connect pins: 19-20 and 21-22 on **J13** connector.

Connections should look like below:

![camera_setup](../additional-docs/images/images-guides/ov5645.png)

##### Software Setup

Build and install the below kernel as per this [guide](../../build/linux-kernel.md).

Kernel: https://github.com/96rocks/kernel.git
Branch: release-4.4-rock960

#### OV5645 with standard 24 Pin cable

* Connect the OV5645 camera to **J3** connector.
* Connect pins: 8-7 on **J14** header.
* Connect pins: 19-20 and 21-22 on **J13** connector.

##### Software Setup

Build and install the below kernel as per this [guide](../../build/linux-kernel.md).

Kernel: https://git.linaro.org/people/manivannan.sadhasivam/96b-common.git
Branch: release-4.4-rock960
