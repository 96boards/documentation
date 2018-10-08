---
title: Installing NextBio Demo Application
permalink: /documentation/mezzanine/arrow-nextbio/guides/installation.md.html
---

# Installing NextBio Demo Application

- Environment Setup
  - Once your system is running Linux from internal eMMC and has enabled SPI, connect to
a wifi network with Internet access, open a terminal (e.g XTerm) and update the system:
  ```shell
  sudo apt-get update
  sudo apt-get upgrade
  ```
  - NBBiometrics requires libusb-1.0 library, even only SPI module is used. Install libusb-1.0
package:
  ```shell
  sudo apt-get install libusb-1.0
  ```
  - The demo is written in QT application framework. Building the application requires QT5-
default package. Open a terminal and install the package.
```shell
sudo apt-get install qt5-default
```
- Building the Demo
  - Download demo application package from [NEXT Support Portal](https://support.nextbiometrics.com/home?p_p_id=110_INSTANCE_YKal9iBkH91g&_110_INSTANCE_YKal9iBkH91g_struts_action=/document_library_display/view_file_entry&_110_INSTANCE_YKal9iBkH91g_fileEntryId=279088).
  - Now extract the source code and build the demo:
  ```shell
  unzip DB410c_Demo.zip
  cd DB410c_Demo/src
  qmake
  make
  ```
- Launching the Demo
```shell
sudo ./DB410C-demo
```
