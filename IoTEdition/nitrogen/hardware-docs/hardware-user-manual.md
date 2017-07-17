---
title: Hardware User Manual for Nitrogen
permalink: /documentation/IoTEdition/nitrogen/hardware-docs/hardware-user-manual.md/
---
# Carbon Hardware User Manual

<img src="https://github.com/96boards/documentation/blob/master/IoTEdition/Carbon/AdditionalDocs/Images/Logos/Seeed_Logo_White.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/IoTEdition/Carbon/AdditionalDocs/Images/Logos/Seeed_Logo_White.png?raw=true" width="180" height="50" align="right" />

### Table of Contents

- Table of Contents
- Introductions
- Specifications
- Hardware Overview
- Pinout Map
- Connection between nRF51822 and STM32F401
   - Hardware Connection
   - Serialization software setup
- How to Upgrade Firmware
   - DfuSe Demonstration procedures
   - Download a hex file through UART


[Click Here](https://github.com/96boards/documentation/tree/master/IoTEdition/Carbon/AdditionalDocs/Images) for access to raw images used in this doc.

***

## Introduction

The Carbon board is a 96Boards compliant IoT board based on the STM32F401RET6 in LQFP64 package.

<img src="https://github.com/96boards/documentation/blob/master/IoTEdition/Carbon/AdditionalDocs/Images/Carbon_Front-SD.png?raw=true" data-canonical-src="hhttps://github.com/96boards/documentation/blob/master/IoTEdition/Carbon/AdditionalDocs/Images/Carbon_Front-SD.png?raw=true" width="300" height="150" />
<img src="https://github.com/96boards/documentation/blob/master/IoTEdition/Carbon/AdditionalDocs/Images/Carbon_Back_SD.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/IoTEdition/Carbon/AdditionalDocs/Images/Carbon_Back_SD.png?raw=true" width="300" height="150" />


The following table lists it's key features:

- **Microcontroller**:
   - STM32F401RET6 in LQFP64 package
   - ARM®32-bit Cortex®-M4 CPU with FPU
   - 84 MHz max CPU frequency
   - VDD from 1.7 V to 3.6 V
   - 512 KB Flash
   - 96 KB SRAM
   - GPIO (50) with external interrupt capability
   - 12-bit ADC with 16 channels
   - RTC
   - Advanced-control Timer
   - General Purpose Timers (7)
   - Watchdog Timers (2)
   - USART/UART (4)
   - I2C (3)
   - SPI (3)
   - SDIO
   - USB 2.0 OTG FS
- **Board Features**:
   - STM32F401 microcontroller with 512kB Flash, 96kB ram
   - USB power supply with fuse protect
   - 6LEDs
      - USR1, USR2, BT, PWR, RX, TX
   - Two push buttons
      - USR and RESET
   - SWD debug connectors
   - On board chip antenna
   - 3.3V work voltage
   - 2x15pin at 2.54mm pitch Low speed connector
   - Fully compatible with 96Boards IoT standards

***

## Specifications

| Parameter                                     | Value                                              |
|:----------------------------------------------|:---------------------------------------------------|
| Chipset                                       | STM32F401                                          |
| BT                                            | nRF51822                                           |
| Clock Speed                                   | 84MHz max CPU frequency                            |
| Flash                                         | 512KB                                              |
| SRAM                                          | 96KB                                               |
| Digital Output Voltage                        | 3.3V                                               |
| Analog Pins                                   | 6                                                  |
| Analog Input Voltage                          | 0~3.3V                                             |
| Dimensions                                    | 60x30mm                                            |

***

## Hardware Overview

<img src="https://github.com/96boards/documentation/blob/master/IoTEdition/Carbon/AdditionalDocs/Images/HardwareUserManual/Carbon_Numbered_Front.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/IoTEdition/Carbon/AdditionalDocs/Images/HardwareUserManual/Carbon_Numbered_Front.png?raw=true" width="600" height="300" />

1. **OTG** - Can be used as USB OTG/HOST and USB device, also used for USB DFU.
2. **LED Indicators**
   - USR1 - User controlled led, connected to PD2
   - USR2 - User controlled led, connected to PA15
   - BT - Bluetooth indicator, connected to PB5. This led will light up when connect to a device.
   - PWR - Light up when Power on.
   - RX - Indicator of FT230X - RX
   - TX - Indicator of FT230X - TX
3. **UART** - for debugging or firmware update, connected to USART1.
4. Reset Button - Press to reset the system
5. BOOT0 Button – user button or select boot mode, connect to PC12, default low.
6. UART and SWD for debug (STM32F401 and nRF51822 both)
7. BT Chip antenna
8. Pins – Details refer to Pin map
9. IC1 - FT230X
   - IC2 - STM32F401
   - IC3 - nRF51822

***

## PinOut Map

<img src="https://github.com/96boards/documentation/blob/master/IoTEdition/Carbon/AdditionalDocs/Images/HardwareUserManual/Carbon_Pinout.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/IoTEdition/Carbon/AdditionalDocs/Images/HardwareUserManual/Carbon_Pinout.png?raw=true" width="600" height="300" />

***

## Connection between nRF51822 and STM32F401

If you want to use a BLE SoftDevice in applications that cannot be ported to nRF5, for example because they use specific peripherals or need more resources like RAM, flash memory, or CPU speed, you should consider using serialization.

### Hardware Connection

Hardware connection as below:

| STM32F401 | nRF51822          | function |
|:---------:|:-----------------:|:--------:|
| PA4       | P0.25             | SPI_CSN  |
| PB1       | P0.28             | SPI_REQ  |
| PB0       | P0.29             | SPI_RDY  |
| PA7       | P0.00             | SPI_MOSI |
| PA6       | P0.30             | SPI_MISO |
| PA5       | P0.07             | SPI_CLK  |
| PB2       | SWDIO/NRESET      | RESET    |

### Serialization software setup

**Prepare the connectivity board by performing the following steps**:

1. Connect the board to the computer and make sure that the RESET wire is disconnected.
2. Program the SoftDevice on the connectivity board. See Programming SoftDevices for instructions.
3. In Keil, open the Connectivity Example for the physical transport layer that you want to use:

`<InstallFolder>\examples\ble_central_and_peripheral\ble_connectivity\board\ser_s13x_spi`

4. Compile the application and download the created.hex file to the connectivity board.

For more details, please refer to [Running a serialized application](http://infocenter.nordicsemi.com/index.jsp?topic=%2Fcom.nordic.infocenter.s130.api.v2.0.0%2Findex.html)

***

## How to Upgrade Firmware

### DfuSe demonstration procedures

#### How to download a DFU file

1. Press BOOT0 button and connect OTG to your PC.
2. Run the “DfuSe demonstration” application (Start -> All Programs -> STMicroelectronics -> DfuSe Demonstration).
3. Click the “Choose” button (Item 1 in following figure) to select a DFU file. the displayed Information such as VID, PID, Version and target number is read from the DFU file.
4. Check the “Optimize upgrade duration” checkbox to ignore FF blocks during the upload.
5. Check the “Verify after download” checkbox if you want to launch the verification process after downloading data.
6. Click the “Upgrade” button (Item 2 in following figure) to start upgrading file content to the memory.
7. Click the “Verify” button (Item 3 in following figure) to verify if the data was successfully downloaded.

<img src="https://github.com/96boards/documentation/blob/master/IoTEdition/Carbon/AdditionalDocs/Images/HardwareUserManual/DfuSe_Demo.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/IoTEdition/Carbon/AdditionalDocs/Images/HardwareUserManual/DfuSe_Demo.png?raw=true" width="400" height="550" />

#### How to generate DFU files from S19/Hex/Bin files

1. Run the “DFU File Manager” application (Start -> All Programs -> STMicroelectronics -> DFU File Manager).
2. Select “I want to GENERATE a DFU file from S19, HEX or BIN files” item in the “Want to do” dialog box hen click “OK”.
3. To create the image from an S19 or Hex file, click the “S19 or Hex” button and select your file, a DFU image will be created for each added file.
4. To create the DFU file, click “Generate”.

> Note: For more details, please to read the user manual([UM0412](http://www.st.com/content/ccc/resource/technical/document/user_manual/3f/61/72/ff/c5/5a/4a/7b/CD00155676.pdf/files/CD00155676.pdf/jcr:content/translations/en.CD00155676.pdf)) from ST.

### Download a hex file through UART

1. Press BOOT0 button and connect UART to your PC.
2. Run the “Demonstrator GUI” application (Start -> All Programs -> STMicroelectronics -> Demonstrator GUI).
3. Follow the steps below to download the firmware.

<img src="https://github.com/96boards/documentation/blob/master/IoTEdition/Carbon/AdditionalDocs/Images/HardwareUserManual/DownloadUART_1.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/IoTEdition/Carbon/AdditionalDocs/Images/HardwareUserManual/DownloadUART_1.png?raw=true" width="400" height="550" />

<img src="https://github.com/96boards/documentation/blob/master/IoTEdition/Carbon/AdditionalDocs/Images/HardwareUserManual/DownloadUART_2.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/IoTEdition/Carbon/AdditionalDocs/Images/HardwareUserManual/DownloadUART_2.png?raw=true" width="400" height="550" />

<img src="https://github.com/96boards/documentation/blob/master/IoTEdition/Carbon/AdditionalDocs/Images/HardwareUserManual/DownloadUART_3.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/IoTEdition/Carbon/AdditionalDocs/Images/HardwareUserManual/DownloadUART_3.png?raw=true" width="400" height="550" />

<img src="https://github.com/96boards/documentation/blob/master/IoTEdition/Carbon/AdditionalDocs/Images/HardwareUserManual/DownloadUART_4-5.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/IoTEdition/Carbon/AdditionalDocs/Images/HardwareUserManual/DownloadUART_4-5.png?raw=true" width="400" height="550" />

<img src="https://github.com/96boards/documentation/blob/master/IoTEdition/Carbon/AdditionalDocs/Images/HardwareUserManual/DownloadUART_6.png?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/IoTEdition/Carbon/AdditionalDocs/Images/HardwareUserManual/DownloadUART_6.png?raw=true" width="400" height="550" />
