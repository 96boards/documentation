---
title: User Guide for i.MX7 96Board
permalink: /documentation/consumer/imx7-96/guides/user-guide.md.html
redirect_from:
- /documentation/ConsumerEdition/i.MX7-96/Guides/user-guide.md.html
---

# i.MX7 96Board - Meerkat<sup>®</sup> User Guide

**Registering Meerkat<sup>®</sup>**

- Please register your i.MX7 96Boards - Meerkat<sup>®</sup> [here](http://www.novtech.com/registration).
- Provide the serial # from the back side of Meerkat<sup>®</sup> board.
- Provide the requested information and select **Meerkat** from the version drop down.

<img src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/MeerkatRegistration.jpeg?raw=true" data-canonical-src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/MeerkatRegistration.jpeg?raw=true" width="558" height="598" />

# Download Support files

Support files can be downloaded from [here](http://bit.ly/iMX7-96B).

This location contains documents, schematics, installable tools and a Virtual Machine pre-configured with tools to speed application development.

See the **Read Me First.txt** file located there for additional information.



Note that there are two distributions provided for the i.MX7 96Boards - Meerkat<sup>®</sup>:
-	A graphical system with xfce and enlightenment based on Angstrom. Full source code, recipes and pre-compiled images are provided.
-	A simple system with a command console. Full source code, a configured build-root and pre-compiled images are provided.

# Installing the tools

## Introduction and Prerequisites

The following prerequisites are required:
-	PC with VMware Player 12 or higher
-	PC with ability to open .7z zip files, ie. 7Zip
-	PC with 50G+ available hard drive space.
-	PC with sufficient RAM to allocate 4GB to the VM.
-	Meerkat<sup>®</sup> VMware<sup>®</sup> virtual machine, .7z compressed file provided by NovTech
-	SD/MMC card programming software, such as Win32DiskImager, “dd” or equivalent.

## Creating boot cards from pre-compiled images

Pre-compiled boot images are provided on the [ShareFile site](http://bit.ly/iMX7-96B). To program one of these images to a card for use in the system, use a program like Win32DiskImager.

To create a card with Win32DiskImager:

- Download and decompress the desired image from the **03 – Compiled SD Images** directory on the [ShareFile site](http://bit.ly/iMX7-96B).

- Insert a SD/MMC card of at least 4GB size. The contents of this card will be destroyed in the programming process, so be sure to back up any important data.

- Run the Win32 Disk Imager software, and within the **Image File** block of the tool, browse to the decompressed disk image.

- Select the drive letter which corresponds to the SD/MMC card inserted on your PC.

- If you are satisfied with your selections, select “Write” from the bottom center of the Win32 Disk Imager window. Writing the card will take several minutes, refer to the progress bar on the window for status.

<img src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/win32DiskImager.png?raw=true" data-canonical-src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/win32DiskImager.png?raw=true" width="756" height="538" />
