---
title: Getting Started with the TB-96AIoT
permalink: /documentation/som/tb-96aiot/getting-started/
---
# Getting Started

Learn about your TB-96AI board as well as how to prepare and set up for basic use

## Setup - What you will need

**Need**
- TB-96AIoT
	- SOM based on the RK1808 Application Processor and NPU
- [96Boards SOM Carrier Board](../../96boards-som-carrier-board/)
	- SOM Baseboard
- Power adapter
	- 96Boards specifications requires a 8V-18V with 2000mA Power adapter
- Typc C to Type A Cable
	- To connect Baseboard to PC

***

# Out of the Box

The following subsections should describe how to get started with the TB-96AIoT SoM.

<img src="../additional-docs/images/images-board/sd/tbaiot-back-sd.png" data-canonical-src="" width="300" height="300" />
<img src="../additional-docs/images/images-board/sd/tbaiot-front-sd.png" data-canonical-src="" width="300" height="300" />

## Features

|   Component          |   Description                                                                                    |
|:---------------------|:--------------------------------------------------------------------------------------------|
| SoC:                 | Rockchip RK1808(22nm FD-SOI) with Dedicated NPU |
| CPU:                 | ARM Dual Cortex-A35@1.6GHz |
| NPU:                 | Support 8bit/16bit operation, computing power up to 3.0TOPS<br>Support TensorFlow, Caffe model |
| VPU: | 1080p@60P H.264 Decoder<br>1080p@30P H.264 Encoder|
| RAM:                 | Optional configuration with the following options:<br>1GB LPDDR3<br>2GB LPDDR3<br>1GB LPDDR3 |
| Storage:             | Optional configuration with the following options:<br>16GB eMMC<br>32GB eMMC<br>64GB eMMC<br>128GB eMMC |
| Connectivity:        | Built-in WiFi/BT module, reserved antenna holder, can be directly inserted into the antenna.<br>Built-in Gigabit Ethernet PHY chip, 10/100/1000Mbps adaptive. |
| Camera:              | MIPI-CSI,Maximum support 1920 × 1080 resolution |
| Display Interface:   | One MIPI-DSI interface, up to 1920×1080@60fps display output |
| USB: | Type C: USB3.0 DRM ×1<br>USB: USB2.0 HOST ×1 |
| Expansion Interface: | PCIE×1<br>I2C×3<br>UART Debug×1<br>SPI×2<br>SD Card ×1<br>PWM×1<br>ADC×2 |
| OS Support:          | Linux |
| Mechanical:          | 150mm×50mm×1.6mm 96Boards SoM standard dimensions specifications. |
| SoM Connectors       | X1 X2 |


***

## Starting the board for the first time

<img src="../additional-docs/images/images-wiki/som-insert.png" data-canonical-src="" width="300" height="300" />

- Insert the TB-96AIoT SoM in the 96Boards Carrier Board as Shown in the figure above, making sure that connectors X1 and X2 are bing utilised.
- Configure the MUX Switches on the Carrier Board as follows
	- The switches for TB-96AIoT are configured as follows
	- All switch on S1,S2,S6,S7 ,S10,S11,S12,S14,S15, config to disconnect.
	- All switch on S8,S9 config to connect for TFcard
	- Bit2 & Bit3 on S16 config to connect.
	- Bit1 & Bbit2 on S5 config to connect fot debug uart
	- Bit4 on S3 config to connect for debug uart
	- Bit1 & Bit2 on S13 config to connect for USB
- Connect the TYPEC to PC
- Long press and hold the Maskrom button as shown in the following figure.
- Insert power supply.
- Continue to the [Installation page](../installation/).

***

## What's Next?

If you are already familiar with the TB-96AIoT board and would like to change out the stock operating system, please proceed to one of the following pages:

- [Downloads page](../downloads/): This page lists all Linaro and 3rd party operating systems available for TB-96AIoT
- [Installation page](../installation/): If you already have the images you need, this page has information on how to install the different operating systems onto your TB-96AIoT board
- [Support](../support/)
   - From bug reports and current issues, to forum access and other useful resources, we want to help you find answers

Back to the [TB-96AIoT documentation home page](../)

***   
