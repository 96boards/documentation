---
title: Documentation for Shiratech LTE and Sensor Mezzanine
permalink: /documentation/mezzanine/shiratech-lte/
---
# Shiratech LTE Mezzanine

- 1) [Introduction](#introduction)
	- 1.1) [About the Shiratech LTE Mezzanine](#11-about-the-shiratech-lte-and-sensors-mezzanine)
	- 1.2) [Features & Specifications](#12-features-and-specifications)
- 2) [Guides](#2-guides)
- 3) [Schematics](#3-schematics)

## 1) Introduction
### 1.1) About the Shiratech LTE and Sensor Mezzanine

Shiratech LTE and Sensor Mezzanine is a 96Boards compatible mezzanine board that adds LTE modem functionality and a set of sensors to any 96Boards compatible board, both consumer addition (CE) and enterprise edition (EE).The mezzanine consists of the following key elements:
- Quectel EC25 LTE –A high throughput LTE CAT-4 delivering 150Mbit/s down-link 50Mbit/s uplink data rates.
- Bosch BNO055 –A high quality 9-axis absolute orientation sensor that includes a tri-axial gyroscope, tri9axial accelerometer and magnetometer.
- Analog Device ADUX1020 –Gesture and proximity sensor.ST VL53L0CX –Range and gesture detection sensor.
- Analog Device ADT7410 –High accuracy digital temperature sensor.
- 96Boards High Speed and Low Speed Expansion connectors -allows to plugin additional 96Boards mezzanines as needed.

<img src="https://www.96boards.org/product/mezzanine/shiratech-lte/images/shiratech-lte-front-sd.jpg?raw=true" data-canonical-src="https://www.96boards.org/product/mezzanine/shiratech-lte/images/shiratech-lte-front-sd.jpg?raw=true" width="330" height="215" />

### 1.2) Features & Specifications

**Key Elements:**
- Quectel EC25 LTE – A high throughput LTE CAT 4 delivering 150Mbit/s down-link 50Mbit/s uplink data rates.
- Bosch BNO055 – A high quality 9-axis absolute orientation sensor that includes a tri-axial gyroscope, tri-axial accelerometer and magnetometer.
- Analog Device ADUX1020 – Gesture and proximity sensor.
- ST VL53L0CX – Range and gesture detection sensor.
- Analog Device ADT7410 – High accuracy digital temperature sensor.

**CELLULAR MODEM QUECTEL EC25 LTE**
- LTE CAT 4 Max 150Mbps (DL) 50Mbps (UL).
- LTE category 4 module optimized for M2M and IoT applications.
- Worldwide LTE, UMTS/HSPA+ and GSM/GPRS/EDGE coverage.
- Multi-constellation GNSS receiver available for applications requiring fast and accurate fixes in any environment.
- MIMO technology meets demands for data rate and link reliability in modem wireless communication systems.

**ON-BOARD SENSOR KEY FEATURES**
- BOSCH BNO055: Outputs fused sensor data – Quaternion, Euler angles, Rotation vector, Linear acceleration, Gravity, Heading.
 - 3 sensors in one device – triaxial 16bit gyroscope, triaxial 14bit accelerometer and full performance geomagnetic sensor.
 - Intelligent power management – normal, low power and suspended modes.
- ANALOG DEVICE ADUX1020:
 - Multifunction photometric sensor and signal conditioning.
 - Fully integrated AFE, ADC, LED driver and timing core.
 - Enables an ambient light rejection capability using both optical and analog filtering.
 - Gesture recognition with 0.5cm to 15cm range
 - Proximity sensing to 20cm.•Gesture/proximity works under infrared (IR) transparent glass or other materials
- ST VL53L0CX:
 - Fully integrated miniature module: 940nm Laser VCSEL, VCSEL driver, ranging sensor with advanced embedded micro controller.
 - Fast accurate distance ranging – Measures absolute range up to 2m, Reported range is independent of the target reflectance.
 - Eye safe – Class 1 laser device.
- ANALOG DEVICE ADT7410:
 - High performance temperature sensor.
 - Temperature accuracy
 - +/-0.5C from -40C to +105C (2.7V to 3.6V)
 - +/-0.4C from -40C to +105C (3.0V)
 - 16 bit temperature resolution.
 - Fast first temperature conversion on power up of 6ms.
 - Easy implementation- No temperature calibration/correction required by user, No linearity correction required.


 **Quectel EC25 LTE Modem:**

 Quectel EC25 is a series of LTE category 4 module optimized specially for M2M and IoT applications. Adopting the 3GPP Rel.11 LTE technology, it delivers 150Mbit/s downlink and 50Mbit/s uplink data rates. Designed in the compact and unified form factor, EC25 is compatible with Quectel MTS/HSPA+ UC20 module and multi-mode LTE EC20/EC21 module, which allows for flexible migration among them in design and manufacturing.EC25 contains 6 variants: EC25-V, EC25-J, EC25-A, EC25-AU, EC25-AUT and EC25-E. This makes it backward-compatible with existing EDGE and GSM/GPRS networks, ensuring that it can be connected even in remote areas devoid of 4G or 3G coverage.EC25 supports Qualcomm® IZat™ location technology Gen8C Lite (GPS, GLONASS, BeiDou, Galileo and QZSS). The integrates GNSS greatly simplifies product design, and provides quicker, more accurate and more dependable positioning.

 A rich set of Internet protocols, industry-standard interfaces and abundant functionality (USB drivers for Windows XP,Windows Vista, Windows 7/8/8.1/10, Linux, Android/eCall) extend the applicability of the module to a wide range of M2Mand IoT applications such as industrial router, industrial PDA, rugged tablet PC, video surveillance, and digital signage.

 The Quectel EC25 CAT-4 LTE Modem module is powered by 3.8V.It is connected to 96Boards carrier board USB0 (HS connector), UART0, I2C0, GPIO A,B,C,K (LS Connector) and (u)SIM connector.RF lines connected to two RF antenna jacks: Main and GNSS.Four LEDs are used to indicate modem status.

**Bosch BNO055:**

The BNO055 is a System in Package (SiP) integrating a tri-axial 14 bit accelerometer, a tri-axial 16 bit gyroscope with a range of ±2000 degrees per second, a tri-axial geomagnetic sensor and a 32 bit cortex M0+ microcontroller running Bosch Sensortec sensor fusion software, in a single package.The corresponding chipsets are integrated into one simple 28 pin LGA 3.8mm x 5.2mm x 1.1mm housing. For optimum system integration the BNO055 is equipped with digital bidirectional I2C and UART interfaces.

The Bosch BNO055 absolute orientation sensor VDD pins are powered from 3V3 power.The sensor is connected to the CPU through I2C1 bus.

Sensor I2C address: 0x28

**Analog Devices ADUX1020:**

The ADUX1020 is a highly efficient photometric sensor with an integrated 14-bit analog-to-digital converter (ADC) and a 20-bit burst accumulator that works in concert with a flexible light emitting diode (LED) driver. It is designed to modulate a LED and measure the corresponding optical return signal. The digital engine includes circuitry and control for data aggregation and proximity detection.The data output and device configuration use a 1.8 V I2C interface.

The control circuitry includes flexible LED pulse width and period generation combined with synchronous detection. This circuitry is complemented by a low noise, low power, and wide dynamic range configurable analog front end (AFE), clock generation, LED driver, and digital logic for position and smart sample mode (event driven x, y coordinates, relative z data).This complete AFE features ambient light rejection, avoiding corruption due to external interference.One inexpensive standard surface mount, broad angle or narrow angle IR LED (depending upon application) is required. This LED mounts externally to the ADUX1020.Packaged in a small, clear mold, 2 mm × 3 mm, 8-lead LFCSP,the ADUX1020 is specified over an operating temperature range of −40°C to +85°C.

The Analog Devices ADUX1020 gesture and proximity sensor is powered by 1.8V. It is connected to I2C1 bus and GPIO G.The sensor controls a high power infrared emitter, SFH4056. It receives the IR returning from an object for gesture and proximity analysis.

Sensor I2C address: 0x64

**ST VL53L0CX:**
The VL53L0X is a new generation Time-of-Flight (ToF) laser-ranging module housed in the smallest package on the market today, providing accurate distance measurement whatever the target reflectance's unlike conventional technologies.

It can measure absolute distances up to 2m, setting a new benchmark in ranging performance levels, opening the door to various new applications.The VL53L0X integrates a leading-edge SPAD array (Single Photon Avalanche Diodes) and embeds ST’second generation FlightSenseTM patented technology.

The VL53L0X’s 940nm VCSEL emitter (Vertical Cavity Surface-Emitting Laser), is totally invisible to the human eye, coupled with internal physical infrared filters, it enables longer ranging distance, higher immunity to ambient light and better robustness to cover-glass optical cross-talk.The ST VL53L0CX time of flight range and gesture detection sensor is powered by 3.3V. It is connected to 1.8V I2C1 bus and GPIO J.

Sensor I2C address: 0x52

**Analog Devices ADT7410:**
The ADT7410 is a high accuracy digital temperature sensor in a narrow SOIC package. It contains a band gap temperature reference and a 13-bit ADC to monitor and digitize the temperature to a 0.0625°C resolution. The ADC resolution, by default, is set to 13 bits (0.0625°C). This can be changed to 16 bits (0.0078°C) by setting Bit 7 in the configuration register (Register Address 0x03).

The ADT7410 is guaranteed to operate over supply voltages from 2.7 V to 5.5 V. Operating at 3.3 V, the average supply current is typically 210 μA. The ADT7410 has a shutdown mode that powers down the device and offers a shutdown current of typically 2 μA.The ADT7410 is rated for operation over the −55°C to +150°C temperature range.

Pin A0 and Pin A1 are available for address selection, giving the ADT7410 four possible I2C addresses. The CT pin is an open drain output that becomes active when the temperature exceeds a programmable critical temperature limit. The default critical temperature limit is 147°C. The INT pin is also an open-drain output that becomes active when the temperature exceeds a programmable limit. The INT and CT pins can operate in either comparator or interrupt mode.The Analog Devices ADT7410 high accuracy temperature sensor is powered by 3.3V.

It is connected to I2C1 through 1.8V to 3.3V I2C buffer and to GPIO H and I.

Sensor I2C address: 0x48

## 2) [Guides](guides/)

## 3) [Schematics](files/SRT-PCB-MEZ-LTE-R3_1-29-09-2018.pdf)
