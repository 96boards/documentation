---
title: Restore Factory Firmware
permalink: /documentation/mezzanine/shiratech-fpga/guides/restore-factory-firmware/
---
# Introduction

This guide will walk you through restore the factory FPGA Firmware which has the in-built functionality of translating Arduino / RaspberryPi IO standards to the 96Boards IO.

## Hardware Setup

- **[Any 96Boards CE Board](/products/ce/)**
- **Shiratech FPGA Mezzanine**
- **JTAG USB Blaster Programmer**
  - [Clones](https://www.amazon.com/gp/search/ref=sr_gnr_fkmr0?rh=i%3Aaps%2Ck%3Aaltera+usb+blaster&keywords=altera+usb+blaster&ie=UTF8&qid=1541022971)
  - [Genuine](https://www.arrow.com/en/products/p0302/terasic-technologies)
- **Host machine running Linux or Windows**

> Note: Hikey 6620 will not fit the FPGA Mezzanine due to slight offset in the LS and HS headers

## Software setup

- **[Quartus Lite](http://fpgasoftware.intel.com/)**
- **[Factory Firmware: Click to Download](https://github.com/ric96/documentation/raw/mezzanine-doc/mezzanine/shiratech-fpga/files/firmware/fpga_mezzanine_RELEASE_1_0.pof)**

## Video Walk-through

[![video](https://img.youtube.com/vi/YjVS5DqwFx8/0.jpg)](https://youtu.be/YjVS5DqwFx8)
