---
title: DragonBoard 410c Hardware User Manual
permalink: /documentation/consumer/dragonboard/dragonboard410c/hardware-docs/hardware-user-manual.md.html
redirect_from:
- /db410c-getting-started/HardwareDocs/HardwareUserManual.md/
- /documentation/ConsumerEdition/DragonBoard-410c/HardwareDocs/HardwareUserManual.md.html
- /documentation/consumer/dragonboard410c/hardware-docs/hardware-user-manual.md.html
---
# DragonBoard 410c User Manual

### Table of Contents

- [Table of Contents](#table-of-contents)
- [Introduction](#introduction)
- [What's in the Box](#whats-in-the-box)
- [Board Overview](#board-overview)
- [System Block Diagram](#system-block-diagram)
- [Getting Started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Starting the board for the first time](#starting-the-board-for-the-first-time)
- [Component Details](#component-details)
  - [Processor](#processor)
  - [Memory (DRAM)](#memory-dram)
  - [Micro SDHC](#micro-sdhc)
  - [Networking](#networking)
    - [WiFi](#wifi)
    - [Bluetooth](#bluetooth)
    - [Worldwide FM Radio](#worldwide-fm-radio)
    - [GPS](#gps)
  - [HDMI](#hdmi)
  - [MIPI-DSI](#mipi-dsi)
  - [Camera Interface](#camera-interface)
  - [USB Ports](#usb-ports)
  - [USB Host ports](#usb-host-ports)
  - [USB Device ports](#usb-device-ports)
  - [Audio](#audio)
    - [BT Audio](#bt-audio)
    - [HDMI Audio](#hdmi-audio)
  - [DC Power and Battery Power](#dc-power-and-battery-power)
  - [External Fan Connection](#external-fan-connection)
  - [UART](#uart)
  - [Buttons](#buttons)
    - [Power Button](#power-button)
    - [Volume up](#volume-up)
    - [Volume down](#volume-down)
    - [Dip-switch](#dip-switch)
  - [LED Indicators](#led-indicators)
    - [Two activity LEDs](#two-activity-leds)
    - [Four User LEDs](#four-user-leds)
  - [Additional Functionality](#additional-functionality)
- [Expansion Connectors](#expansion-connectors)
  - [Low Speed Expansion Connector](#low-speed-expansion-connector)
    - [UART {0/1}](#uart-01)
    - [I2C {0/1}](#i2c-01)
    - [GPIO {A-L}](#gpio-a-l)
    - [SPI 0](#spi-0)
    - [PCM/I2S](#pcmi2s)
    - [Power and Reset](#power-and-reset)
    - [Power Supplies](#power-supplies)
  - [High Speed Expansion Connector](#high-speed-expansion-connector)
    - [MIPI DSI 0](#mipi-dsi-0)
    - [MIPI CSI {0/1}](#mipi-csi-01)
    - [I2C {2/3}](#i2c-23)
    - [SD/SPI](#sdspi)
    - [Clocks](#clocks)
    - [USB](#usb)
    - [HSIC](#hsic)
    - [Reserved](#reserved)
  - [Analog Expansion Connector](#analog-expansion-connector)
    - [Speaker](#speaker)
    - [Mic](#mic)
    - [Headset](#headset)
    - [FM Antenna](#fm-antenna)
- [Power Management Overview](#power-management-overview)
  - [Block Diagram](#block-diagram)
  - [DC Power Input](#dc-power-input)
  - [Power Source Selection](#power-source-selection)
  - [Power Consumption](#power-consumption)
  - [Power Sequencing](#power-sequencing)
  - [Voltage Rails](#voltage-rails)
  - [Power Measurements](#power-measurements)
    - [Power-In measurement](#power-in-measurement)
    - [PMIC Power-In measnurement](#pmic-power-in-measnurement)
- [Mechanical Specification](#mechanical-specification)
  - [2D Reference Drawing](#2d-reference-drawing)
- [Special care when using USB](#special-care-when-using-usb)
- [Statements regarding FCC](#statements-regarding-fcc)

[Click Here](https://github.com/96boards/documentation/tree/master/consumer/dragonboard/dragonboard410c/additional-docs/images) for access to raw images used in this doc.

***

https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-board/DragonBoard410c-Front-SD.jpg?raw=true

## Introduction

The DragonBoard 410c (‘410c’) board is a 96Boards compliant community board based on Qualcomm® Snapdragon 400 series of SoC’s.

<img src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-board/sd/dragonboard410c-front-sd.jpg?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-board/sd/dragonboard410c-front-sd.jpg?raw=true" width="250" height="160" />
<img src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-board/sd/dragonboard410c-angle-sd.jpg?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-board/sd/dragonboard410c-angle-sd.jpg?raw=true" width="250" height="160" />
<img src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-board/sd/dragonboard410c-back-sd.jpg?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-board/sd/dragonboard410c-back-sd.jpg?raw=true" width="250" height="160" />

The following table lists it's key features:

- **Processor**:
   - Qualcomm Snapdragon 410
   - Quad-core ARM® Cortex® A53 at up to 1.2 GHz per core
   - 64-Bit capable
   - Qualcomm Adreno 306 400MHz GPU for PC-class graphics with support for
   - Advanced APIs, including OpenGL ES 3.0, OpenCL, DirectX, and content security
- **Memory / Storage**:
   - 1GB LPDDR3, 533MHz
   - 8GB eMMC 4.51
   - SD 3.0 (UHS-I)
- **Video**:
   - 1080p@30fps HD video playback and capture with H.264 (AVC), and 720p
   - Playback with H.265 (HEVC)
- **Camera Support**:
   - Integrated ISP with support for image sensors up to 13MP
- **Audio**:
   - PCM/AAC+/MP3/WMA, ECNS, Audio+ post-processing (optional)
- **Connectivity**:
   - WLAN 802.11 b/g/n 2.4GHz
   - _Bluetooth_® wireless technology 4.1
   - One USB 2.0 micro B (device mode only)
   - Two USB 2.0 (host mode only)
   - GPS
   - On-board GPS antenna
   - On-board BT and WLAN antenna
- **I/O Interfaces**:
   - One 40-pin Low Speed (LS) expansion connector
      - UART, SPI, I2S, I2C x2, GPIO x12, DC power
   - One 60-pin High Speed (HS) expansion connector
      - 4L-MIPI DSI, USB, I2C x2, 2L+4L-MIPI CSI
   - One 16-pin analog expansion header
      - Stereo headset/line-out, speaker and analog line-in
   - Footprint for one optional 16-pin analog expansion connector for stereo headset/line-out, speaker and analog line-in
   - The board can be made compatible with Arduino using an add-on mezzanine board
- **EXternal Storage**:
   - Micro SD card slot
- **User Interface**:
   - 4 Buttons: Power/Reset/Volume Up/down
   - 6 LED indicators
      -  4 -user controllable
      -  2 -for radios (BT and WLAN activity)
- **OS Support**:
   - Android 5.1
   - Linux based on Debian
   - OpenEmbedded
   - Windows IoT Core
   - Ubuntu Snappy Core
- **Mechanical**:
   - Power: +6.5V to +18V
   - Dimensions: 54mm by 85mm meeting 96Boards™ Consumer Edition standard dimensions specifications
- **Environmental**:
   - Operating Temp: 0°C to +70°C
   - RoHS and Reach compliant

***

## What's in the Box

The box contains one DragonBoard 410c and a quick start guide.

<img src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-hw-user-manual/BoxBoard.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-hw-user-manual/BoxBoard.png?raw=true" width="400" height="270" />
<img src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-hw-user-manual/BoxPamplet.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-hw-user-manual/BoxPamplet.png?raw=true" width="450" height="250" />




***

## Board Overview

| Position | Reference | Description                                               |
|---------:|:----------|:----------------------------------------------------------|
|    1     |  J8       |  (J8) Low Speed Expansion Connector                       |
|    2     |           |  APQ8016 Snapdragon Processor                             |
|    3     |  U9       |  (U9) Power Management PMIC                               |
|    4     |  J7       |  (J7) Analog Expansion Connector                          |
|    5     |           |  WLAN/Bluetooth/GPS                                       |
|    6     |  J1       |  (J1) Power Jack                                          |
|    7     |  J5       |  (J5) uSD Card Socket                                     |
|    8     |  J6       |  (J6) HDMI Type A Port                                    |
|    9     |  J9       |  (J9) High Speed Connector                                |
|    10    |  J4       |  (J4) Micro USB Type B Connector                          |
|    11    |           |  Bluetooth/WLAN LED's                                     |
|    12    |  J3       |  (J3) USB Host 2 Connector                                |
|    13    |           |  User LED's 1-4                                           |
|    14    |  J2       |  (J2) USB Host 1 Connector                                |
|    15    |  S3-4     |  (S3-4) Vol+/Vol- Buttons                                 |
|    16    |  S2       |  (S2) Power Button                                        |
|    17    |           |  Bluetooth/WLAN Antenna                                   |
|    18    |           |  GPS Antenna                                              |
|    19    |  S6       |  (S6) Boot Switches                                       |

<img src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-hw-user-manual/DB410c_Numbered_Front.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-hw-user-manual/DB410c_Numbered_Front.png?raw=true" width="400" height="270" />
<img src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-hw-user-manual/DB410c_Numbered_Back.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-hw-user-manual/DB410c_Numbered_Back.png?raw=true" width="400" height="270" />



***

## System Block Diagram

<img src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-hw-user-manual/BlockDiagram.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-hw-user-manual/BlockDiagram.png?raw=true" width="750" height="480" />


***

## Getting Started

#### Prerequisites

Before you power up your DragonBoard 410c for the first time you will need the following:

- DragonBoard 410c
- A 96Boards compliant power supply (sold separately by Arrow).
- A HDMI or DVI LCD Monitor that supports a resolution of 1080P/30Hz.
- HDMI-HDMI cable or HDMI-DVI cable to connect the board to the Monitor.
- A computer keyboard with USB interface.
- A computer mouse with USB interface.

#### Starting the board for the first time

To start the board, follow these simple steps:

1. Connect the HDMI cable to the 410c HDMI connector (marked J6) and to the LCD Monitor
2. Connect the keyboard to the boards USB connector marked J3 and the mouse to the USB connector marked J2. (It doesn’t matter which order you connect them in. You can also connect via an external USB Hub.)
3. Ensure that the boot switches S6 are set to ‘0000’, all in Off position
4. Connect the power supply to power connector J1.

Once you plug the power supply into a power outlet the board will start the booting process, and you should see Android
boot up.

> Note: The first boot takes several minutes due to Androids initialization. Subsequent boot times should be faster.


***

## Component Details

### Processor

The Snapdragon 410 APQ8016 is a quad 64-bit ARM Cortex-A53 MPcore Harvard Superscalar core, supports both LP-DDR2 / LP-DDR3 SDRAM interface, Hexagon QDSP6, 13.5 MP camera input support, Adreno 306 GPU, 1080p video encode/decode, gpsOneGen 8C with GLONASS, _Bluetooth_® wireless technology 4.1, OpenGL ES 3.0, DirectX, OpenCL, Renderscript Compute, FlexRender support.

### Memory (DRAM)

The 410c uses a single embedded Multi Chip Package (eMCP) dual function LPDDR3/eMMC memory solution. The installed chip provides 8Gbyte of solid state storage and 1Gbyte of LPDDR3.

- The LPDDR3 is a 32bit width bus implementation interfacing directly to the APQ8016 build-in LPDDR controller. The maximum DDR clock is 533Mhz
- The eMMC is an 8bit implementation interfacing with APQ8016 SDC1 interface supporting eMMC 4.5 specifications

### Micro SDHC

The 96Boards specification calls for a microSDHC socket to be present on the board

The 410c board SD slot (J5) signals are routed directly to the APQ8016 SDC2 interface. The slot is a push-push type with a dedicated support for card detect signal (many SD slots do not have a dedicated CD pins, they use DATA3 state as the card detected signal). The 410c board uses APQ GPIO_38 as the SD_CARD_DET_N.

### Networking

The 96Boards specifications calls for a WiFi (minimally 802.11g/n) and Bluetooth 4.1 (Bluetooth Low Energy)

The 410c board deployed Qualcomm’s RF chip WCN3620 (U5) solution that integrates three different wireless connectivity technologies into a single device, the interfaces are:

#### WiFi

WLAN compliant with IEEE 802.11 b/g/n specifications, meeting 96Boards minimal requirements for WiFi.

#### Bluetooth

Bluetooth compliant with the BT specifications version 4.1 (BR/EDT + BLE), meeting the 96Boards requirements for BT

#### Worldwide FM Radio

Worldwide FM radio, this interface is not part of the 96Boards mandatory specification. It is an optional addition that has not been tested is not officially supported.

#### GPS

The GPS implementation is based on Qualcomm WGR7640 GNSS RF receiver (U7) supporting GPS, GLONASS and COMPASS. The APQ8016 communicates directly with the WGR7640.

### HDMI

The 96Boards specification calls for an HDMI port to be present on the board. The APQ8016 doesn’t include a built-in HDMI interface. The 410c deploys the built-in MIPI-DSI 4 lanes interface as the source for the HDMI output. A peripheral DSI to HDMI Bridge (U3, Analog Devices ADV7533) performs this task and it supports a resolution from 480i to 1080p at 30Hz.

While the ADV7533 supports automatic input video format timing detection (CEA-861E), an I2C channel from the APQ8016 allows the user to configure the operation of this bridge. It is I2C3 interface from the SoC that connects to the bridge.

This bridge supports audio as well (meeting the 96Boards requirements to provide audio via HDMI). The 410c uses a single bit I2S2 interface from the APQ8016 for this task.

Please note that the 96Boards specification calls for a MIPI-DSI interface to be routed to the High Speed Expansion connector. Since the APQ8016 has only one MIPI-DSI interface. A muxing device (U11, FSA644UCX) is being use on the board. Only one interface, HDMI, or the Expansion MIPI-DSI can be active at a given time. The controlling signal is named ‘DSI_SW_SEL_APQ’. When this signal is logic low, ‘0’, the MIPI-DSI is routed to the DSI-HDMI Bridge. When ‘DSI_SW_SEL_APQ’ is logic level high, ‘1’, the MIPI-DSI is routed to the High Speed Expansion connector. This design assigned the ‘DSI_SW_SEL_APQ’ function to GPIO_32.

User can overwrite the software control by sliding switch 4 of DipSwitch S6 to the ‘ON’ position. That action forces the DSI mux to route the MIPI-DSI to the DSI-HDMI Bridge. The overwrite option exist for the HDMI only, you cannot hardware overwrite the mux to the High Speed Expansion connector.

### MIPI-DSI

The 96Boards specification calls for a MIPI-DSI implementation via the High Speed Expansion Connector.

The 410c implemented a four-lane MIPI_DSI interface meeting this requirement. More information about this implementation can be found in chapter 6 High speed expansion connector.

### Camera Interface

The 96Boards specification calls for two camera interfaces.

The 410c implements two camera interfaces, one with a four-lane MIPI_CSI interface and one with two-lane MIPI_CSI interface, meeting this requirement. More information about this implementation can be found in chapter 6 High speed expansion connector.

### USB Ports

<img src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-hw-user-manual/USBPorts.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-hw-user-manual/USBPorts.png?raw=true" width="750" height="480" />

### USB Host ports

The 96Boards specification calls for three USB host ports. The APQ8016 includes a single USBOTG channel. A USB Mux, S1, routes this single USB channel either to a USB HUB or to the MicroUSB connector (J4). The control of S1 is done via a software controlled GPIO (USB_SW_SEL_PM, GPIO_4 from the board PMIC). When this signal is logic low, ‘0’, the USB data lines are routed to the MicroUSB connector and the APQ8016 built-in USBOTG port is set to device mode. When ‘USB_SW_SEL_PM’ is logic level high, ‘1’, the USB data lines are routed to U10 (a 3-port USB HUB) and the APQ8016 builtin USBOTG port is set to host mode. The user can overwrite the software control by sliding switch 3 of DipSwitch S6 to the ‘ON’ position. That action forces the USB–mux S1 to route the built-in USBOTG data lines to the USB HUB. The overwrite option exists for the host mode only, you cannot hardware overwrite the mux to force device mode.

- **Port 1 of the USB HUB** is routed to J3, a Type ‘A’ USB Host connector. A current limited controller (U4) sets the Power Current limit to 1.18A. This port is named HOST2 in the board schematic.
- **Port 2 of the USB HUB** is routed to J2, a Type ‘A’ USB Host connector. A current limited controller (U6) sets the Power Current limit to 1.18A. This port is named HOST1 in the board schematic
- **Port 3 of the USB HUB** is routed to the High Speed Expansion connector. No current limited controller is implemented on the board for this channel.

> Please Note: the board can work in one mode at a time, Host mode or Device mode, not both

> Please Note: Since the APQ8016 has only a single USBOTG channel, care needs to be taken when the USB HOST function is
to be used. Please verify that no cable is connected to the MicroUSB type B connector (and to a host on the other side of
the cable) as the hardware of the 410c board will inform software about the presence of a request to configure the
USBOTG to device mode. Depending on the software release that is used on the board, the driver may configure the USB
Mux to Device mode and none of the USB HOST ports will be connected to the SoC.

### USB Device ports

The 96Boards specification calls for a USB port to be implemented as an OTG port or a device port.

The 410c board implements a device port. The port is located at J4, a MicroUSB type B. If an application requires the use of the device port, USB_SW_SEL_PM signal must be set to low ‘0’ and the user must verify that switch 3 of Dip Switch S6 is set to the ‘OFF’ position.

> Please Note: the board can work in one mode at a time, Host mode or Device mode, not both

### Audio

The 96Boards specifications calls for a minimum of single channel audio through two interfaces, BT and HDMI/MHL/DisplayPort

The 410c meets this requirement and has additional audio channels. More information about these additional channels can be found in chapter 4.18 Additional Functionality.

#### BT Audio

The BT implementation on the 410c is via a MAC in the APQ8016 and an external modem, WCN3620 (U5). A two wire interface between the SoC and the modem carries all communication including audio.

#### HDMI Audio

A 3-wire (audio out only) I2S channel is routed directly from the APQ8016 SoC I2S interface pins to the DSI-HDMI bridge (U3)

### DC Power and Battery Power

The 96Boards specification calls for power to be provided to the board in one of the following ways:

- An 8V to 18V power from a dedicated DC jack
- An 8V to 18V power from the SYS_DCIN pins on the Low Speed Expansion Connector
- A USB Type C port at 5V

### External Fan Connection

The 96Boards specification calls for support for an external fan. That can be achieved by using the 5V or the SYS_DCIN, both present on the Low Speed Expansion connector.

### UART

The 96Boards specification calls for support for one SoC UART and an optional second UART both to be routed to the Low Speed Expansion Connector.

The 410c meets these requirements and additionally routes UART0 Tx/Rx lines to an on-board connector (J15). If the user wants to use this on-board UART, J15 needs to be soldered to the board as well as R173 and R174 (0 ohm 0201).

### Buttons

The 96Boards specification calls for the present of two buttons, a Power on/sleep button and a Reset button.

The 410c meets these requirements. Please see section 10 for detailed information on the buttons of the 410c board.

#### Power Button

The push-button serves as the power-on/sleep button. Upon applying power to the board, press the power button for more than 3 seconds, the board will boot up. Once the board is running you can turn power-off by pressing the power button for more than 3 seconds. If the board is in a sleep mode, pressing the power bottom will wake up the board. Oppositely, if the board is in an active mode, pressing the power bottom will change the board into sleep mode.

#### Volume up

The Volume UP button is used to control the output speaker volume of the 410c.

#### Volume down

The Volume Down button is used to control the output speaker volume of the 410c.

#### Dip-switch

There is a 4 switch DipSwitch marked S6 located at the bottom side of the 410c board. For normal operation all four
switched need to be set to the ‘off’ position.

- **Switch 1, ‘USB BOOT’**, when set to ‘on’ position, will force boot over USB connection with a PC. This is only required for eMMC boot image upgrade. Please review the proper OS User Guide for more information on this process.
- **Switch 2, ‘SD BOOT’**, when set to ‘on’ position, will force the SD, J5, to serve as the boot source for the 410c board when set. You can use uSD as the main boot source or it can serve as a method for eMMC boot image upgrade. Please review the proper OS User Guide for more information on this process.
- **Switch 3, ‘USB HOST’**, is described in section 5.8. This switch in not part of the boot configuration.
- **Switch 4, ‘HDMI SEL’**, is described in section 5.6.1. This switch is not part of the boot configuration.

<img src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-hw-user-manual/BootConfiguration.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-hw-user-manual/BootConfiguration.png?raw=true" width="200" height="125" />

### LED Indicators

The 96Boards specifications calls for six LEDs to be implemented on the board. The specification defines the LEDs color
and mechanical location on the board.

#### Two activity LEDs

- WiFi activity LED – 410c board drives this Yellow LED via MPP_2, an IO from the PMIC.
- BT activity LED – 410c board drives this Blue LED via MPP_3, an IO from the PMIC

#### Four User LEDs

The four user LEDs are surface mount Green in 0603 size located next to the two USB type A connector and labeled ‘USER
LEDS 4 3 2 1’. The 410c board drives two LEDs from the SoC GPIO, APQ GPIO_21 and APQ GPIO_120. The other two User
LEDs are driven by the PMIC via PM GPIO_1 and PM GPIO_2.

### Additional Functionality

The 96Boards specifications allows for additional functionality provided that all mandatory functionality is available and
there is no impact on the physical footprint specifications including height and do not prevent the use of the 96Boards CE
low speed and high speed expansion facilities
The 410c board implements a few additional functions, which are listed in the following sub-chapters.


***

## Expansion Connectors

The 96Boards specification calls for two Expansion Connectors, a Low Speed and a High Speed.

The 410c meets this requirement, the following sub-sections cover these connectors.

### Low Speed Expansion Connector

|  410c Signals                                    |96Boards Signals|PIN|PIN|96Boards Signals|  410c Signals                         |
|:-------------------------------------------------|:---------------|:--|--:|---------------:|--------------------------------------:|
|    GND                                           |     GND        |1  |2  |GND             |GND                                    |
|    UART0_CTS_N (APQ GPIO_2)                      |     UART0_CTS  |3  |4  |PWR_BTN_N       |PHONE_ON_N                             |
|    UART0_TX (APQ GPIO_0)                         |     UART0_TxD  |5  |6  |RST_BTN_N       |PM_RESIN_N                             |
|    UART0_RX (APQ GPIO_1)                         |     UART0_RxD  |7  |8  |SPI0_SCLK       |SPI0_CLK (APQ GPIO_19)                 |
|    UART0_RTS_N (APQ GPIO_3)                      |     UART0_RTS  |9  |10 |SPI0_DIN        |SPI0_MISO (APQ GPIO_17)                |
|    UART1_TX (APQ GPIO_4)                         |     UART1_TxD  |11 |12 |SPI0_CS         |SPI0_CS_N (APQ GPIO_18)                |
|    UART1_RX (APQ GPIO_5)                         |     UART1_RxD  |13 |14 |SPI0_DOUT       |SPI0_MOSI (APQ GPIO_16)                |
|    I2C0_SCL (APQ GPIO_7)                         |     I2C0_SCL   |15 |16 |PCM_FS          |LS_EXP_MI2S_WS (APQ GPIO_110)          |
|    I2C0_SDA (APQ GPIO_6)                         |     I2C0_SDA   |17 |18 |PCM_CLK         |LS_EXP_MI2S_SCK(APQ GPIO_113)(ALPS_INT)|
|    I2C1_SCL (APQ GPIO_23)                        |     I2C1_SCL   |19 |20 |PCM_DO          |LS_EXP_MI2S_DATA0 (APQ GPIO_114)       |
|    I2C1_SDA (APQ GPIO_22)                        |     I2C1_SDA   |21 |22 |PCM_DI          |N.C.                                   |
|    LS_EXP_GPIO_A (APQ GPIO_36) (APQ INT)         |     GPIO-A     |23 |24 |GPIO-B          |LS_EXP_GPIO_B (APQ GPIO_12) (TS_RST_N) |
|    LS_EXP_GPIO_C (APQ GPIO_13) (TS_INT_N)        |     GPIO-C     |25 |26 |GPIO-D          |LS_EXP_GPIO_D (APQ GPIO_69) (MAG_INT)  |
|    LS_EXP_GPIO_E (APQ GPIO_115) (GYRO_ACCL_INT_N)|     GPIO-E     |27 |28 |GPIO-F          |LS_EXP_GPIO_F (PM_MPP_4) (DSI_BLCTRL)  |
|    LS_EXP_GPIO_G (APQ GPIO_24) (DSI_VSYNC)       |     GPIO-G     |29 |30 |GPIO-H          |LS_EXP_GPIO_H (APQ GPIO_25) (DSI_RST)  |
|    LS_EXP_GPIO_I (APQ GPIO_35) (CSI0_RST)        |     GPIO-I     |31 |32 |GPIO-J          |LS_EXP_GPIO_J (APQ GPIO_34) (CSI0_PWDN)|
|    LS_EXP_GPIO_K (APQ GPIO_28) (CSI1_RST)        |     GPIO-K     |33 |34 |GPIO-L          |LS_EXP_GPIO_L (APQ GPIO_33) (CSI1_PWDN)|
|    LS_EXP_1P8                                    |     +1V8       |35 |36 |SYS_DCIN        |SYS_DCIN                               |
|    SYS_5P0                                       |     +5V        |37 |38 |SYC_DCIN        |SYS_DCIN                               |
|    GND                                           |     GND        |39 |40 |GND             |GND                                    |

#### UART {0/1}

The 96Boards specifications calls for a 4-wire UART implementation, UART0 and an optimal second 2-wire UART, UART1 on
the Low Speed Expansion Connector.

The 410c board implements UART0 as a 4-wire UART that connects directly to the APQ8016 SoC. These signals are driven
at 1.8V.

The 410c board implements UART1 as a 2-wire UART that connects directly to the APQ8016 SoC. These signals are driven
at 1.8V.

#### I2C {0/1}

The 96Boards specification calls for two I2C interfaces to be implemented on the Low Speed Expansion Connector.

The 410c board implements both interfaces, I2C0 and I2C1 that connects directly to the APQ8016SoC. A 2K resistor is
provided as pull-up for each of the I2C lines per the I2C specifications, these pull-ups are connected to the 1.8V voltage
rail.

#### GPIO {A-L}

The 96Boards specifications calls for 12 GPIO lines to be implemented on the Low Speed Expansion Connector. Some of
these GPIOs may support alternate functions for DSI/CSI control

The 410c board implements this requirement. 11 GPIOs are routed to the APQ8016 SoC and one GPIO is connected to the
on-board PMIC.

- GPIO A - Connects to GPIO_36 of APQ8016 SoC, can serves as AQP_INT supporting the 96Boards requirements to create a wake-up event for the SoC. It is a 1.8V signal
- GPIO B - Connects to GPIO_12 of APQ8016 SoC. It is a 1.8V signal
- GPIO C - Connects to GPIO_13 of APQ8016 SoC. It is a 1.8V signal. Can be configured to be an IRQ line
- GPIO D - Connects to GPIO_69 of APQ8016 SoC. It is a 1.8V signal. Can be configured to be an IRQ line
- GPIO E - Connects to GPIO_115 of APQ8016 SoC. It is a 1.8V signal. Can be configured to be an IRQ line
- GPIO F - Connects to MPP_4 of PM8916 PMIC. It is a 1.8V signal. Can be configured to be the DSI backlight control
- GPIO G - Connects to GPIO_24 of APQ8016 SoC. It is a 1.8V signal. Can be configured to be DSI VSYNC signal.
- GPIO H - Connects to GPIO_25 of APQ8016 SoC. It is a 1.8V signal. Can be configured to be a DSI_RST signal.
- GPIO I - Connects to GPIO_35 of APQ8016 SoC. It is a 1.8V signal. Can be configured to be a CSI0_RST signal.
- GPIO J - Connects to GPIO_34 of APQ8016 SoC. It is a 1.8V signal. Can be configured to be a CSI0_PWDN signal.
- GPIO K - Connects to GPIO_28 of APQ8016 SoC. It is a 1.8V signal. Can be configured to be a CSI1_RST signal.
- GPIO L - Connects to GPIO_33 of APQ8016 SoC. It is a 1.8V signal. Can be configured to be a CSI1_PWDN signal.

#### SPI 0

The 96Boards specification calls for one SPI bus master to be provided on the Low Speed Expansion Connector.

The 410c board implements a full SPI master with 4 wires, CLK, CS, MOSI and MISO all connect directly to the APQ8016
SoC. These signals are driven at 1.8V.

#### PCM/I2S

The 96Boards specification calls for one PCM/I2S bus to be provided on the Low Speed Expansion Connector. The CLK, FS
and DO signals are required while the DI is optional.

The 410c board implements a PCM/I2S with 3 wires, CLK, FS and DO, the optional DI signal is not implemented on the 410c
board. The I2S signals are connected directly to the APQ8016 SoC. These signals are driven at 1.8V.

#### Power and Reset

The 96Boards specification calls for a signal on the Low Speed Expansion Connector that can power on/off the board and a
signal that serves as a board reset signal.

The 410c board routes the PWR_BTN_N (named PHONE_ON_N on 410c schematic) signal to the KYPDPWR_N pin of the
PM8916 PMIC. This signal is driven by S2 as well, the on-board power on push-button switch. Please note that the push
button only provides an On/Sleep function and not OFF functionality.

A mezzanine implementation of this signals should not drive it with any voltage, the only allowed operation is to force it to
GND to start the board from a sleep mode. A board shutdown will occur when this signal is held to ground for more than
15 seconds (based on the current Android release).

The 410c board routes the RST_BTN_N (named PM_RESIN_N on 410c schematic) signal to the RESIN_N pin of the PM8916
PMIC. This signal is driven by S4, the on-board reset switch. This signals is a dual purpose, any press lasting less than 10
seconds serves as Volume Down or Zoom out, a press longer than 10 seconds will reset the board.

#### Power Supplies

The 96Boards specification calls for three power rails to be present on the Low Speed Expansion Connector:

- +1.8V : Max of 100mA
- +5V : Able to provide a minimum of 5W of power (1A).
- SYS_DCIN : 9-18V input with enough current to support all the board functions or the output DCIN from onboard DC Connector able to provide a minimum of 7W of power.

The 410c board supports these requirements as follows:

+1.8V : Driven by two PMIC LDOs, LDO15 and LDO16, each can provide 55mA. The PM8916 allows connecting the two
LDOs in parallel to provide 110mA on a 1.8V rail which meets the 96Boards requirement.

+5V : Driven by the 4A 5.0V buck switcher (U13). This buck switcher powers both USB limit current devices (each at
1.18A max). The remaining capacity provides a max current of 1.64A to the Low Speed Expansion Connector, for a total of
8.2W which meets the 96Boards requirements.

SYS_DCIN: Can serves as the board’s main power source or can receive power from the board.


***

### High Speed Expansion Connector

|  410c Signals            | 96Boards Signals  |PIN|PIN| 96Boards Signals| 410c Signals          |
|:-------------------------|:------------------|:--|--:|----------------:|----------------------:|
|SPI1_MOSI (APQ GPIO_8)    | SD_DAT0/SPI1_DOUT |1  |2  | CSI0_C+         | MIPI_CSI0_CLK_P       |
|N.C                       | SD_DAT1           |3  |4  | CSI0_C-         | MIPI_CSI0_CLK_M       |
|N.C                       | SD_DAT2           |5  |6  | GND             | GND                   |
|SPI1_CS_N (APQ GPIO_10)   | SD_DAT3/SPI1_CS   |7  |8  | CSI0_D0+        | MIPI_CSI0_DATA0_P     |
|SPI1_CLK (APQ GPIO_11)    | SD_SCLK/SPI1_SCLK |9  |10 | CSI0_D0-        | MIPI_CSI0_DATA0_M     |
|SPI1_MISO (APQ GPIO_9)    | SD_CMD/SPI1_DIN   |11 |12 | GND             | GND                   |
|GND                       | GND               |13 |14 | CSI0_D1+        | MIPI_CSI0_DATA1_P     |
|CSI0_MCLK (APQ GPIO_26)   | CLK0/CSI0_MCLK    |15 |16 | CCSI0_D1-       | MIPI_CSI0_DATA1_M     |
|CSI1_MCLK (APQ GPIO_27)   | CLK1/CSI1_MCLK    |17 |18 | GND             | GND                   |
|GND                       | GND               |19 |20 | CSI0_D2+        | MIPI_CSI0_DATA2_P     |
|MIPI_DSI0_CLK_P_EXP_CONN  | DSI_CLK+          |21 |22 | CSI0_D2-        | MIPI_CSI0_DATA2_M     |
|MIPI_DSI0_CLK_M_EXP_CONN  | DSI_CLK-          |23 |24 | GND             | GND                   |
|GND                       | GND               |25 |26 | CSI0_D3+        | MIPI_CSI0_DATA3_P     |
|MIPI_DSI0_DATA0_P_EXP_CONN| DSI_D0+           |27 |28 | CSI0_D3-        | MIPI_CSI0_DATA3_M     |
|MIPI_DSI0_DATA0_M_EXP_CONN| DSI_D0-           |29 |30 | GND             | GND                   |
|GND                       | GND               |31 |32 | I2C2_SCL        | I2C2_SCL (APQ GPIO_30)|
|MIPI_DSI0_DATA1_P_EXP_CONN| DSI_D1+           |33 |34 | I2C2_SCL        | I2C2_SDA (APQ GPIO_29)|
|MIPI_DSI0_DATA1_M_EXP_CONN| DSI_D1-           |35 |36 | I2C3_SDA        | I2C3_SCL (APQ GPIO_15)|
|GND                       | GND               |37 |38 | I2C3_SDA        | I2C3_SDA (APQ GPIO_14)|
|MIPI_DSI0_DATA2_P_EXP_CONN| DSI_D2+           |39 |40 | GND             | GND                   |
|MIPI_DSI0_DATA2_M_EXP_CONN| DSI_D2-           |41 |42 | CSI1_D0+        | MIPI_CSI1_DATA0_P     |
|GND                       | GND               |43 |44 | CSI1_D0-        | MIPI_CSI1_DATA0_M     |
|MIPI_DSI0_DATA3_P_EXP_CONN| DSI_D3+           |45 |46 | GND             | GND                   |
|MIPI_DSI0_DATA3_M_EXP_CONN| DSI_D3-           |47 |48 | CSI1_D1+        | MIPI_CSI1_DATA1_P     |
|GND                       | GND               |49 |50 | CSI1_D1-        | MIPI_CSI1_DATA1_M     |
|USB_HS_D_P_EXP            | USB_D+            |51 |52 | GND             | GND                   |
|USB_HS_D_M_EXP            | USB_D-            |53 |54 | CSI1_C+         | MIPI_CSI1_CLK_P       |
|GND                       | GND               |55 |56 | CSI1_C-         | MIPI_CSI1_CLK_M       |
|N.C.                      | HSIC_STR          |57 |58 | GND             | GND                   |
|N.C.                      | HSIC_DATA         |59 |60 | RESERVED        | N.C.                  |

#### MIPI DSI 0

The 96Boards specification calls for a MIPI-DSI to be present on the High Speed Expansion Connector. A minimum of one
lane is required and up to four lanes can be accommodated on the connector.

The 410c board implementation supports a full four lane MIPI-DSI interface that is routed to the High Speed Expansion
Connector. Since the APQ8016 has only single MIPI-DSI interface and it may be used to drive the DSI-HDMI Bridge, DSI
muxing is required.

A muxing device, U11 (FSA644UCK) is used on the board. Only one interface, HDMI, or the Expansion MIPI-DSI can be
active at a given time. The controlling signal is named ‘DSI_SW_SEL_APQ’. When this signal is logic low, ‘0’, the MIPI-DSI is
routed to the DSI-HDMI Bridge.

When ‘DSI_SW_SEL_APQ’ is logic level high, ‘1’, the MIPI-DSI is routed to the High Speed Expansion connector. This design
assigned the ‘DSI_SW_SEL_APQ’ function to GPIO_32.

The user can override the software control by sliding switch 4 of DipSwitch S6 to the ‘ON’ position. That action forces the
DSI mux to route the MIPI-DSI to the DSI-HDMI Bridge. The override option exists for HDMI only. You cannot force the mux
to the High Speed Expansion connector. While hardware forces the ESI Mux to the HDMI, software must configure the
HDMI bridge for proper functionality.

> Please note: If configuring the board to use the MIPI-DSI is done via software, the user must verify the switch 4 of
DipSwitch S6 is set to the ‘off’ position

#### MIPI CSI {0/1}

The 96Boards specification calls for two MIPI-CSI interfaces to be present on the High Speed Expansion Connector. Both
interfaces are optional. CSI0 interface can be up to four lanes while CSI1 is up to two lanes.

The current 410c board implementation supports a full four lane MIPI-CSI interface on CSI0 and two lanes of MIPI-CSI on
CSI1. All MIPI-CSI signals are routed directly to/from the APQ8016.

#### I2C {2/3}

The 96Boards specification calls for two I2C interfaces to be present on the High Speed Expansion Connector. Both
interfaces are optional unless a MIPI-CSI interface has been implemented. Then an I2C interface shall be implemented.

The current 410c board implementation supports two MIPI-CSI interfaces and therefore must support two I2C interfaces.

For MIPI-CSI0 the companion I2C2 is routed directly from the APQ8016. For MIPI-CSI1, the companion I2C is I2C3.

> Note: You will need to add R61 and R62, 0 ohm 0201 resistors, to the board to support the routing of I2C3 interface to the
High Speed Expansion Connector. Both interfaces, I2C2 and I2C3 have an on-board 2K pull-up resistors pulled-up to the
1.8V voltage rail.

#### SD/SPI

The 96Boards specification calls for an SD interface or a SPI port to be part of the High Speed Expansion Connector.

The 410c board implements a full SPI master with 4 wires (96Boards SPI Configuration), CLK, CS, MOSI and MISO all
connect directly to the APQ8016 SoC. These signals are driven at 1.8V.

#### Clocks

The 96Boards specification calls for one or two programmable clock interfaces to be provided on the High Speed Expansion
Connector. These clocks may have a secondary function of being CSI0_MCLK and CSI1_MCLK. If these clocks can’t be
supported by the SoC than an alternative GPIO or No-Connect is allowed by the specifications.

The 410c board implements two CSI clocks, CSI0_MCLK via APQ GPIO_26 and CSI1_MCLK via APQ GPIO_27. These signals
are driven at 1.8V.

#### USB

The 96Boards specification calls for a USB Data line interface to be present on the High Speed Expansion Connector.

The 410c board implements this requirements by routing USB channel 3 from the USB HUB to the High Speed Expansion
Connector.

#### HSIC

The 96Boards specification calls for an optional MIPI-HSIC interface to be present on the High Speed Expansion Connector.

The 410c board implementation doesn’t support this optional requirement.

#### Reserved

The 96Boards specification calls for a 10K pull-up to 1.8V to be connected to pin 60 of the High Speed Expansion
Connector.

The current 410c board implementation does not support this requirement. This issue will be addressed on a future
revision of the 410c board


***

### Analog Expansion Connector

|  PIN  |  Function       |    410c Signals                        |
|------:|----------------:|---------------------------------------:|
|   1   |   SPKR_OUT_P    |   PM8916 Audio signal CDC_SPKDRV_P     |
|   2   |   SPKR_OUT_M    |   PM8916 Audio signal CDC_SPKDRV_M D   |
|   3   |   VPH_PWR       |   A 3.7V from U12 buck switcher        |
|   4   |   GND           |   Ground                               |
|   5   |   GND_CFILT     |   PM8916 Audio signal CDC_GND_CFILT    |
|   6   |   CDC_MIC2_P    |   PM8916 Audio signal CDC_IN2_P        |
|   7   |   CDC_MIC3_P    |   PM8916 Audio signal CDC_IN3_P        |
|   8   |   CDC_HPH_R     |   PM8916 Audio signal CDC_HPH_R        |
|   9   |   CDC_HPH_REF   |   PM8916 Audio signal CDC_HPH_REF      |
|   10  |   CDC_HPH_L     |   PM8916 Audio signal CDC_HPH_L        |
|   11  |   CDC_HS_DET    |   PM8916 Audio signal CDC_HS_DET       |
|   12  |   CDC_MIC_BIAS1 |   PM8916 Audio signal CDC_MIC_BIAS1    |
|   13  |   N.C.          |                                        |
|   14  |   N.C.          |                                        |
|   15  |   FM_RX_ANT     |    WCN3620 RF signal FM_HS_RX          |
|   16  |   N.C.          |                                        |

#### Speaker

The speaker signals are routed from the PM8916 PMIC built-in Audio CODEC, the two signals are:

- SKPR_DRV_P - Class-D speaker amplifier output+
- SKPR_DRV_M - Class-D speaker amplifier output-

#### Mic

The microphone signals are rounded to the PM8916 PMIC Built-In CODEC, the three signals are:

- MIC2_IN - Headset mic
- MIC3_IN - Second mic, please note that the first microphone input, MIC1_IN is routed from an on-board analog microphone (not installed on current 410c builds)
- MIC_BIAS1 - Ground reference for PMIC bias

#### Headset

The headset signals are rounded from the PM8916 PMIC Built-In CODEC, one signal is routed from the connector to the
CODEC, the singles are:

- HPH_R - Headphone PA right channel output
- HPH_L - Headphone PA left channel output
- HPH_REF - Headphone PA ground sensing
- HS_DET - Headset detection

#### FM Antenna

The FM_RX_ANT signal is the path for the FM antenna to reach the WCN3620 (u5), an integrated three different
connectivity technologies device:

- WLAN IEE802.11 b/g/n
- BT 4.0 (BR/EDR/BLE)
- Worldwide FM radio

***

## Power Management Overview

### Block Diagram

<img src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-hw-user-manual/PowerManagement.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-hw-user-manual/PowerManagement.png?raw=true" width="750" height="480" />

### DC Power Input

The 96Boards specification calls for a power to be provided to the board in one of the following ways:

**An 8V to 18V power from a dedicated DC jack.**

The 410c board supports this requirement through the use of J1, ‘SYS_DCIN’ power connector.

> Please note: the SYS_DCIN can be as low as 6.5V on the 410c board.

An 8V to 18V power from the SYS_DCIN pins on the Low Speed Expansion Connector.

> Please note: the SYS_DCIN can be as low as 6.5V on the 410c board. The 410c board supports incoming power through this connector.

A USB Type C port at 5V.

> Please note: The 410c board does not implement a USB Type C port and therefore cannot be powered over USB

### Power Source Selection

Following the information in section 9.1, the 410c board has only two sources for board incoming power. The 96Boards
specification calls for only one power source to be applied to the board at any given time. Following this requirement, the
user of the 410c board should never apply power to the board from J1 and the Low Speed Expansion connector at the
same time. There is no active or passive mechanism on the 410c board to prioritize one source over the other.

### Power Consumption

TBD

### Power Sequencing

Upon applying power to the 410c board (either one of the two sources), both buck regulators will be enabled and will start
regulating their target voltages. When the output of U12 is on, it will power the on-board PMIC, the PM8916. This PMIC
has four buck regulators, one boost regulator and 20 LDOs. The sequencing of all power rails is set within the PM8916
configuration scheme during the production of this part. The user has no access to alter, modify or change the PMIC power
up sequencing.

### Voltage Rails

TBD

### Power Measurements

The 96Boards specification calls for a minimum of one current sense resistor to be placed on the board permitting a basic
power measurement functions.

The 410c implements two different power measurements.

#### Power-In measurement

A 0.1ohm resistor is placed inline to the SYS_DCIN power line coming from J1 (please note that this power in measurement
only works for SYS_DCIN from J1, it will not measure SYS_DCIN applied from the Low Speed Expansion Connector). Placing
a probe over this resistor will provide a voltage measurement of the voltage drop across the resistor. Dividing this
measurement by 0.1 will give you the amount of the current flowing into the board. The board provides a means to use
ARM Energy probe for this measurement, please verify that JP3 and JP4 are each shorted and J10 is soldered to the board
to take advantage of this probe.

#### PMIC Power-In measnurement

A 0.1ohm resistor should replace the existing inline 0 ohm resistor on VPH_PWR line, the output of U12 buck regulator
that feeds the PMIC. Placing a probe over this resistor will provide a voltage measurement of the voltage drop across the
resistor. Dividing this value by 0.1 will give you the amount of the current flowing into the PMIC. The board provides a
means to use an ARM Energy probe for this measurement, the following steps are requires to get this probe measuring this
rail:

1. **Remove R122 and R123 from the board to prevent a short between SYS_DCIN and VPH_PWR**
2. J10 needs to be soldered to the board.
3. R124 and R125, 0 ohm 0201 resistors, need to be soldered to the board.

***

## Mechanical Specification

### 2D Reference Drawing

<img src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-hw-user-manual/2DDrawing.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/consumer/dragonboard/dragonboard410c/additional-docs/images/images-hw-user-manual/2DDrawing.png?raw=true" width="750" height="800" />


***

## Special care when using USB

Since the APQ8016 has a single USBOTG channel, care needs to be taken when the USB HOST function is to be used.
Please verify that no cable is connected to the MicroUSB type B connector (and to a host on the other side of the cable) as
the hardware of the 410c board will inform software about the presence of a request to configure the USBOTG to device
mode. Depending on the software release that is used on the board, the driver may configure the USB Mux to Device
mode and none of the USB HOST ports will be connected to the SoC.


***

## Statements regarding FCC

###### FCC Label Warning

This device complies with Part 15 of the FCC Rules. Operation is subject to the following two conditions:

- This device may not cause harmful interference.
- This device must accept any interference received, including interference that may cause undesired operation.

Cet appareil se conforme aux principes de licence –exempts RSS de l’Industrie de Canada. Gestion dépende des conditions
suivantes :

- l'appareil ne doit pas produire de l’interférence, et
- l'appareil doit accepter toutes sortes d’interférences, cela incluet l’interférence qui va peut--‐être causer les résul‐ tats indésirables de l’appareil.

This device generates and uses radio waves and if not used properly may cause interference to radio and TV reception. It
has been tested and found to comply with the limits set by the FCC which are designed to provide reasonable protection
against such interference.

###### Caution

Arrow Electronics, Inc. (“Arrow”) is not responsible for any radio or TV interference caused by unauthorized modifications
to this equipment. Changes or modifications not expressly approved Arrow could void the user’s authority to operate the
equipment.

###### FCC Warning Statement

**Note**: This equipment has been tested and found to comply with the limits for a Class B digital device, pursuant to Part 15
of the FCC Rules. These limits are designed to provide reasonable protection against harmful interference in a residential
installation. This equipment generates uses and can radiate radio frequency energy and, if not installed and used in
accordance with the instructions, may cause harmful interference to radio communications. However, there is no
guarantee that interference will not occur in a particular installation. If this equipment does cause harmful interference to
radio or television reception, which can be determined by turning the equipment off and on, the user is encouraged to try
to correct the interference by one or more of the following measures:

- Reorient or relocate the receiving antenna.
- Increase the separation between the equipment and receiver.
- Connect the equipment into an outlet on a circuit different from that to which the receiver is connected.

Consult the dealer or an experienced radio/television technician for help.

###### CAN ICES-3 (B) NMB-3 (B)

This equipment complies with radiation exposure limits set forth for uncontrolled environment. The antenna(s) used for
this transmitter must be installed to provide a separation distance of at least 20 cm from all persons and must not be
collocated or operating in conjunction with any other antenna or transmitter.

Cet appareil se conforme aux limites d'exposition aux rayonnements pour un environnement non contrôlé. L'antenne (s)
qui est utilize pour cet émetteur doit être installé pour produire une distance de separation d'au moins 20 cm de toutes
personnes et ne doit pas être installé à proximité ou utilize en conjunction avec une autre antenne ou émetteur.
