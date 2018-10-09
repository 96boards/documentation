---
title: NextBio Mezzanine Getting Started using SD Card Image
permalink: /documentation/mezzanine/arrow-nextbio/guides/sdcard.md.html
---

# BOOTABLE SD CARD IMAGE FOR DRAGONBOARD 410C

For quick start with application development, SD card image with installed Linux operating system is available.

The main advantage of using SD card is that the system runs from the card. The OS in internal eMMC memory is not overwritten.

This SD Card image has already configured the environment and installed demo app. Any post-installation steps
are not needed.

## How to deploy SD card image:
- Download NEXTBiometrics_DB410c.zip from [here](https://na01.safelinks.protection.outlook.com/?url=https%3A%2F%2Fwww.dropbox.com%2Fs%2Ffl4saqywszs5lwc%2FNEXTBiometrics_DB410c_Linux.zip%3Fdl%3D0&data=02%7C01%7Crobin.roitsch%40arroweurope.com%7C143e1addc3c74257320f08d5c609a03f%7C0beb0c359cbb4feb99e5589e415c7944%7C1%7C0%7C636632667045684285&sdata=bzvVln7dFN0v8uszC%2FZQ3Kp1%2BuuDRMiIgOo6cuWuXvg%3D&reserved=0)
- Unzip the archive and flash the image to a SD card with minimum size of 4GB.
  - Linux and MacOS Users can use Etcher or dd
  - Windows users can use Etcher or W32Diskimager
- Plug the SD card and set S6 switch on bottom side to position 0100 (SD BOOT)
- Plug SPI shield board with NB-2023-S2-VAIX module
- Power on Dragonboard
- The system will boot from SD. You can click on NEXT demo icon to launch the demo application. Demo application together with NBBiometrics AIX SDK is stored under /home/linaro/next folder.
