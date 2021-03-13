---
title: Documentation Vision Mezzanine
permalink: /documentation/mezzanine/vision-mezzanine/
---

## Vision Mezzanine

# Table of Contents
- [1) Introduction](#1-introduction)
  - [1.1) Specifications & Features](#11-specifications-and-features)
- [2) Guides and Documentation](#2-guides-and-documentation)

# 1) Introduction

<img src="images/vision-top.jpeg?raw=true" data-canonical-src="images/vision-top.jpeg?raw=true" width="300"/>


## 1.1) Specifications and Features

### Features

- **Input**：
  - 2x 4 Ports input High-Speed FAKRA Mini (HSFM) connectors
  - DC12V@2A DC Jack input
  - 2x Quad GMSL Deserializer by MAXIM Integrated (MAX9286)
	- Support for 2*4 ON Semiconductor image sensors modules (AR0231AT+AP0202+MAX96705)
  - Connect with 96Boards through HS/LS connector using the 60pin and 40 pin connector.
- **Output**：
	- Connect with 96Boards through HS/LS connector using the 60pin and a 40 pin connector.
	- 2*FD CAN ports output （converting the two SPI(SPI ports form HS/LS connector) to CAN bridge)
	- UART to USB debug connector
	- ETH port ( converting from USB2.0 of the HS connector to ETH bridge )
	- Two CSI-2 connector interface:two 4Lanes CSI-2 connector from MAX9286 output


# 2) Guides and Documentation

### 2.1) Guides

- [User Manual](files/vision-user-manual.pdf)
- [Schematics](files/vision-sch.pdf)

### 2.2) Component Datasheets

- [AMIS-41682](files/AMIS-41682-D.pdf)
- [AR0231](files/AR0231-D.PDF)
- [AX88178A](files/AX88178A_Datasheet_v131.pdf)
- [AX88179](files/AX88179_Datasheet_v131.pdf)
- [ESDONCAN1](files/ESDONCAN1-D.pdf)
- [MAX9286_DS](files/MAX9286_DS_2016.pdf)
- [MCP2561FDT](files/MCP2561FDT-E_M.pdf)
- [MCP2715](files/MCP2715.pdf)
- [SG1-AR0143RGB-0101-GMSL-Hxxx](files/SG1-AR0143RGB-0101-GMSL-Hxxx.pdf)
- [SG2-AR0231RGB–AP0202-GMSL-Hxxx](files/SG2-AR0231RGB-AP0202-GMSL-Hxxx.pdf)
- [TXS0104E](files/txs0104e.pdf)
