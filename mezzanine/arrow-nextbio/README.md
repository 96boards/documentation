---
title: Documentation for NextBio Mezzanine
permalink: /documentation/mezzanine/arrow-nextbio/
---
## NextBio Mezzanine

# Table of Contents

- 1) [Introduction](#introduction)
	- 1.1) [About the Arrow Next-Biometrics Mezzanine](#11-about-the-arrow-next-biometrics-mezzanine)
	- 1.2) [Specifications & Features](#12-specifications-and-features)
- 2) [Pin Mapping](#2-pin-mapping)
- 3) [Downloads](#3-downloads)
- 4) [Guides and Documentation](#4-guides-and-documentation)

# NextBio Mezzanine

# 1) Introduction
# 1.1) About the Arrow Next-Biometrics Mezzanine

The NB-2023-S2 shield board with assembled NB-2023-S2-VAIX (SPI) fingerprint module is a fingerprint development shield for the DragonBoard 410c development board by Arrow Electronics. The mezzanine includes a software Development Kit (SDK), which can be downloaded from NEXT Biometrics Support Portal https://support.nextbiometrics.com/. The NB-2023-S2 shield board has been paired with the DragonBoard 410c development board and used as a one solid piece of hardware (However, other 96Boards may be compatible).

<img src="https://www.96boards.org/product/mezzanine/arrow-nextbio/images/nextbio-back-sd.jpg?raw=true" data-canonical-src="https://www.96boards.org/product/mezzanine/arrow-nextbio/images/nextbio-back-sd.jpg?raw=true" width="330" height="215" />

# 1.2) Specifications

| NB 2023-S2-VAIX Sensor Specifications:      |                                                                      |
|:--------------------------------------------|:---------------------------------------------------------------------|
| Sensor Technology                           | NEXT Active Thermal™ sensing (patented)                              |
| Active Sensing area                         | 11.9 x 16.9 mm2                                                      |
| Pixels                                      | 180 x256                                                             |
| Resolutions                                 | 385 ppi (pixel size 66 µm * 66 µm)                                   |
| Image scan time                             | 0.53s                                                                |
| Ingress protection                          | Ready for IP68 (note: sample housing in development kit not IP rated)|
| Fingerprint module interface                | SPI                                                                  |
| Biometric algorithm license                 | NBBiometrics AIX SDK License included                                |

| NB Biometrics AIX Library Specification:                                            |                               |
|:------------------------------------------------------------------------------------|:------------------------------|
| Fingerprint enrolment (full process from finger detection to capture and extraction)| ~970 ms (to be confirmed)     |
| 1:1 matching time*                                                                  | 7.5 - 8ms                     |
| Biometric performance                   | False-match-rate 0.01 % (default, configurable) False Non-Match Rate (FNMR):1% (at default FMR) |
| Maximum Fingerprint Database                                                        | 1000 templates                |

| Shield board Specifications:                |                                                                                     |
|:--------------------------------------------|:------------------------------------------------------------------------------------|
| Total dimensions                            | 53 x 40 x 14 mm                                                                     |
| Weight                                      | 18g                                                                                 |
| Power Supply                                | 3.3V                                                                                |
| Physical interface to fingerprint module    | 12-pin FFC connector                                                                |
| Ordering Options for the development Kit    | Development Kit with Shield board for Arrow Dragonboard® (NBDK-2023-S2-VAIX-DB)     |

Note: Measurement taken on reference DB platform (Qualcomm Snapdragon 410 (APQ8016), 4 x ARM Cortex A53 64-bits, 1.2GHz, 2GB RAM, Linux linaro-alip 4.9.56).

# 2) Pin Mapping

NB-2023-S2-VAIX fingerprint module utilizes SPI interface and two GPIO pins to
communicate with the DragonBoard 410c.Table 1 shows the mapping of fingerprint
module pins to LS expansion connector on the board.

| Pin | Name   | LS Connector Pin | Function             |
|:---:|:------:|:----------------:|:--------------------:|
| 1   | MOSI   | 14 (APQ GPIO_16) | SPI Data – Slave In  |
| 2   | MISO   | 10 (APQ GPIO_17) | SPI Data – Slave Out |
| 3   | GND    | 1, 2, 39, 40     | Ground               |
| 4   | SCLK   | 8 (APQ GPIO_19)  | SPI Clock            |
| 5   | GND    | 1, 2, 39, 40     | Ground               |
| 6   | nAWAKE | 24 (APQ GPIO_69) | Finger Detect        |
| 7   | nSS    | 12 (APQ GPIO_18) | SPI Slave Select     |
| 11  | nReset | 26 (APQ GPIO_12) | Reset                |

# 3) Downloads

All needed software (and not only SW) for development with Dragonboard410c can be
downloaded from developer community on [NEXT Support Portal](https://support.nextbiometrics.com/web/guest/home/-/document_library_display/YKal9iBkH91g/view/63877)

You will need to create a login ID Here: [Next Support Portal Registration](https://www.nextbiometrics.com/support/registration/)

# 3) [Useful Guides](guides/)
