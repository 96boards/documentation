---
title: Delta Camera Kit
permalink: /documentation/consumer/ultra96/ultra96-v1/kits/delta-camera.md.html
---

## Delta Camera Kit

### Table of Contents

- [1) Introduction](#1-introduction)
- [2) Hardware](#2-hardware)
   - [2.1) Hardware Requirements](#21-hardware-requirements)
   - [2.2) Hardware Setup](#22-hardware-setup)
- [3) Software](#3-software)
   - [3.1) Software Dependencies](#31-software-dependencies)
   - [3.2) Software Setup](#32-software-setup)

## 1) Introduction

Although the MIPI adapter board was primarily designed for Dragonboard 410c, it is hardware compatible with other Consumer Edition 96Boards like the Ultra96.

With this adapter, you can easily integrate image sensors into your camera projects. This mezzanine is ideal for surveillance, video conference and even robots projects. It provides multiple interfaces, and gives you a wide range of choices for selecting different camera boards/modules.

The software and hardware setup for this kit was provided by [Attila Tőkés](https://www.hackster.io/bluetiger9) as a part of his [Stereo Vision and LiDAR Powered Donkey Car](https://www.hackster.io/bluetiger9/stereo-vision-and-lidar-powered-donkey-car-575769)

## 2) Hardware

### 2.1) Hardware Requirements

- 1x [Ultra96](https://www.96boards.org/product/ultra96/)
- 1x [96Boards DUAL MIPI Adapter Mezzanine - AiStarVision](https://www.96boards.org/product/mipiadapter/)
- 2x [OV5647 Camera Module](https://uk.pi-supply.com/products/raspberry-pi-camera-board-v1-3-5mp-1080p)

### 2.2) Hardware Setup

Hardware setup can be followed over at Attila's guide. Here are the various sections:
- [8. MIPI Adapter for Ultra96](https://www.hackster.io/bluetiger9/stereo-vision-and-lidar-powered-donkey-car-575769#toc-8--mipi-adapter-for-ultra96-10)

## 3) Software

### 3.1) Software Dependencies

- [Vivado and SDx installed on host machine](https://japan.xilinx.com/html_docs/xilinx2017_4/sdaccel_doc/esq1504034314038.html)
- [PetaLinux Build Environment](https://xilinx-wiki.atlassian.net/wiki/spaces/A/pages/18841618/PetaLinux+Getting+Started)

### 3.2) Software Setup

**To get familiar with Vivado and PetaLinux, you can follow our getting started guides:**
- [Vivado [Video]](https://www.youtube.com/watch?v=NzWcRGjhfF8)
- [PetaLinux](/documentation/consumer/ultra96/ultra96-v1/build/peta-linux.md.html)

**Software and HDL setup can be followed over at Attila's guide. Here are the various sections:**
- [10. Building a MIPI CSI-2 Video Pipeline](https://www.hackster.io/bluetiger9/stereo-vision-and-lidar-powered-donkey-car-575769#toc-10--building-a-mipi-csi-2-video-pipeline-12)
- [11. Building PetaLinux](https://www.hackster.io/bluetiger9/stereo-vision-and-lidar-powered-donkey-car-575769#toc-11--building-petalinux-13)
- [12. Adding a 2nd Video Pipeline](https://www.hackster.io/bluetiger9/stereo-vision-and-lidar-powered-donkey-car-575769#toc-12--adding-a-2nd-video-pipeline-14)

> Note: [External Reference from Xilinx](https://www.xilinx.com/support/documentation/boards_and_kits/zcu102/2017_2/ug1221-zcu102-base-trd.pdf)