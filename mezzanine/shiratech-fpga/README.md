---
title: Documentation for Shiratech FPGA Mezzanine
permalink: /documentation/mezzanine/shiratech-fpga/
---
## Shiratech FPGA Mezzanine

# Shiratech LTE Mezzanine

- [1) Introduction](#introduction)
	- [1.1) About the Shiratech FPGA Mezzanine](#11-about-the-shiratech-fpga-mezzanine)
	- [1.2) Features & Specifications](#12-features-and-specifications)
- [2) Guides](#2-guides)
- [3) Schematics](#3-schematics)

## 1) Introduction
### 1.1) About the Shiratech FPGA Mezzanine

Shiratech FPGA Mezzanine is a 96Boards compatible mezzanine board accommodating Intel MAX10 FPGA. It is 96Boards compatible board, both consumer addition(CE) and enterprise edition (EE).The mezzanine has Arduino, Raspberry PI and Grove connectors and can serve as HW bridge between those development platforms to 96Boards.

The mezzanine consists of the following key elements:
- Intel MAX10 FPGA
- Arduino shield format connector
- Raspberry PI hat format connector
- Grove connectors
- USB PHY

<img src="images/hd/shiratech-fpga-front-hd.jpg?raw=true" width="330" height="215" />

### 1.2) Features & Specifications

**Intel MAX-10 10M04:**
- 256 FBGA package
- 4K Logic Elements
- 189Kb Block memory
- Up to 156KB user FLASH memory
- Dual internal configuration
- 178 GPIO
- FPGA programming using Altera standard programming connector.
- Ordering option to enhance to Intel MAX-10 10M50

**Expansion connectors:**
- 1 x Raspberry Pi expansion connector
- 1 x Arduino expansion connector
- 6 x Grove expansion connectors:
  - 4 digital
  - 2 analog
- All expansion connectors are directly connected to the FPGA and can be controlled by the FPGA or the CPU.

## 2) [Guides](guides/)

## 3) [Schematics](files/srt-96b-mez-fpga-29-09-2018.pdf)
