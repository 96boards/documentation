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

<img src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/MeerkatRegistration.jpeg?raw=true" data-canonical-src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/MeerkatRegistration.jpeg?raw=true" width="391" height="419" />

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

<img src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/win32DiskImager.png?raw=true" data-canonical-src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/win32DiskImager.png?raw=true" width="529" height="377" />

## Installing i.MX7 96Boards - Meerkat<sup>®</sup> Virtual Machine

Updating and recompiling the images will require access to a properly configured Linux machine. A virtual machine has been provided with the Meerkat<sup>®</sup> to speed your development. Refer to the [Software Guide for the Meerkat<sup>®</sup>](../guides/software-guide.md) for further information on compilation.

Once all prerequisites are met, using 7Zip or any acceptable unzip program, unzip the **NovTech_VM_U14.04.4_Meerkat.7z** file to your PC hard drive. After unzipping, navigate to the created folder **NovTech_VM_U14.04.4_Meerkat**. Double Click on the file **NovTech_VM_U14.04.4.vmx**. VMware® Player should load the virtual machine.
Another method could be to open VMware Player and click on ‘Open a Virtual Machine’ then navigate to the **NovTech_VM_U14.04.4_Meerkat** folder to find the virtual machine setup file.

<img src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/OpenVM.png?raw=true" data-canonical-src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/OpenVM.png?raw=true" width="385" height="386" />
*VMware<sup>®</sup> Player Open Virtual Machine*

<img src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/MeerkatVM.png?raw=true" data-canonical-src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/MeerkatVM.png?raw=true" width="396" height="378" />
*VMware<sup>®</sup> Player Select Virtual Machine*

To save on storage and transmission, the Meerkat<sup®</sup> virtual machine is preconfigured to use 1G of RAM. NovTech recommends increasing this value to a minimum of 2GB. You can edit this value to increase or decrease the amount of RAM assigned to the VM. After opening VMware<sup>®</sup> Player, click on **Edit Virtual Machine Settings**, navigate to **Hardware** tab and select **Memory**. Adjust memory to the desired size.

## Configure the RAM dedicated to your VM.

To minimize the size of the VM image in storage and transit, the VM has been limited to 1GB of RAM. For optimal performance, increase the amount of RAM allocated to the VM.
NovTech recommends allocating a minimum of 2GB of memory to the machine, and optimally 6GB of RAM.

This setting is under **Virtual machine->virtual machine settings->hardware**, and can be modified when the virtual machine has been powered off.
<img src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/VMsettingsWindow.png?raw=true" data-canonical-src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/VMsettingsWindow.png?raw=true" width="393" height="443" />
*Virtual Machine settings window*
*Note: Allocating more than ¼ of the physical ram on your machine to the VM will degrade overall performance and may cause issues.*

You can modify other setting from this window. Once the Virtual Machine starts for the first time, you will be asked to choose whether you **Moved it** or **Copied it**. Please select the **Moved it** option.

## Logging into the VM

To log into the virtual machine please type **novtech** for the password.

*Note: A pop-up window may ask you to update the VMware<sup>®</sup> Linux Tools. It is not necessary to do so, but if you wish to stop seeing the message tab on the bottom of the VM, click ‘Install’ button when asked. VMware<sup>®</sup> will then mount a CD drive and open the mounted folder with the install files contained in that folder. Copy all the files in that folder and paste them in your home folder. Open a Terminal window where you placed the files. Run these two commands:*
```
sudo chmod 777 auto*.sh
```
Enter the **novtech** password when prompted.
To install the tools run:
```
sudo ./autorun.sh
```

*After installation is complete you can delete the files from the folder and eject the CD drive that VMware® auto mounted. This should remove the tab on the bottom of the VM, notifying you about the VMware Linux Tools install.*

<img src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/VMdesktopScreen.png?raw=true" data-canonical-src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/VMdesktopScreen.png?raw=true" width="490" height="466" />
*Meerkat<sup>®</sup> Virtual Machine Desktop Screen.*

## Contents of the Virtual Machine Desktop
Along the left side of desktop are multiple icons:

- Search for software on computer and online:
<img src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/Search.png?raw=true" data-canonical-src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/Search.png?raw=true" width="77" height="75" />

- File Manager

<img src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/FileManager.png?raw=true" data-canonical-src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/FileManager.png?raw=true" width="77" height="75" />

- Terminal

<img src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/Terminal.png?raw=true" data-canonical-src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/Terminal.png?raw=true" width="77" height="75" />

- Putty - Serial Terminal Tool

<img src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/Putty.png?raw=true" data-canonical-src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/Putty.png?raw=true" width="77" height="75" />

- GHex - Hex Editor

<img src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/GHex.png?raw=true" data-canonical-src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/GHex.png?raw=true" width="77" height="75" />

- Meld - Code Comparison Tool

<img src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/Meld.png?raw=true" data-canonical-src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/Meld.png?raw=true" width="77" height="75" />

- Firefox

<img src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/Firefox.png?raw=true" data-canonical-src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/Firefox.png?raw=true" width="77" height="75" />

- Libre Office Writer

<img src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/LibreWriter.png?raw=true" data-canonical-src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/LibreWriter.png?raw=true" width="77" height="75" />

_ Libre Office Calc

<img src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/LibreCalc.png?raw=true" data-canonical-src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/LibreCalc.png?raw=true" width="77" height="75" />

- Libre Office Impre

<img src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/LibreImpre.png?raw=true" data-canonical-src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/LibreImpre.png?raw=true" width="77" height="75" />

- Ubuntu Software Center - update and install Ubuntu software packages

<img src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/UbuntuSoftwareCenter.png?raw=true" data-canonical-src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/UbuntuSoftwareCenter.png?raw=true" width="77" height="75" />

- System settings

<img src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/Settings.png?raw=true" data-canonical-src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/Settings.png?raw=true" width="77" height="75" />

# Meerkat Overview

<img src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/MeerkatTop.png?raw=true" data-canonical-src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/MeerkatTop.png?raw=true" width="720" height="480" />

<img src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/MeerkatBottom.png?raw=true" data-canonical-src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/MeerkatBottom.png?raw=true" width="535" height="320" />

# Serial Connections

The supplied cable connects to the Meerkat<sup></sup> as follows:

<img src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/TTL.png?raw=true" data-canonical-src="https://github.com/nazik5/documentation/blob/master/consumer/imx7-96/additional-docs/images/images-hw-user-manual/TTL.png?raw=true" width="77" height="75" />
