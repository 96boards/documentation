---
title: Build Android Source for Parrot
permalink: /documentation/consumer/parrot/build/android.md.html
---

# Build Android from Source

### 1. Hardware resource
- A R18 development board
- Power adapter, USB to serial port, micro-usb line
- PC and/or compilation server

## 2. Software resource
- It is recommended to install Ubuntu 12.04 64bit on your workstation.
- Install Dependencies:
  - ```sudo apt-get install build-essential subversion git-core libncurses 5-dev zlib1g-dev gawk flex quilt libssl-dev```
- Firmware Flashing tools:
  - LiveSuit (Linux)
  - PhonixSuit (Windows)

## 3. Compiling Android
- Download Source
  > coming soon ...

- Setup build Environment  
  - ```$ source build/envsetup.sh```
- Choose Build Target
  - ```$ lunch```
  - Select tulip_*
- Start Build
  - ```$ make -j$(nproc)```
  - ```$ pack [-d]```
  - pack, -d: The serial port information of the firmware package is transferred to the TF card output.

After the compilation is completed. The system image will be packaged in the ```out/<board>/``` directory.
