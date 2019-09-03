---
title: User Guide for i.MX7 96Board - Meerkat
permalink: /documentation/consumer/imx7-96/guides/user-guide/
---

# i.MX7 96Board - Meerkat<sup>®</sup> User Guide

**Registering Meerkat<sup>®</sup>**

- Please register your i.MX7 96Boards - Meerkat<sup>®</sup> [here](http://www.novtech.com/registration).
- Provide the serial # from the back side of Meerkat<sup>®</sup> board.
- Provide the requested information and select **Meerkat** from the version drop down.

<img src="../additional-docs/images/images-hw-user-manual/MeerkatRegistration.jpeg" data-canonical-src="../imx7-96/additional-docs/images/images-hw-user-manual/MeerkatRegistration.jpeg" width="391" height="419" />

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

<img src="../additional-docs/images/images-hw-user-manual/win32DiskImager.png" data-canonical-src="../additional-docs/images/images-hw-user-manual/win32DiskImager.png" width="529" height="377" />

## Installing i.MX7 96Boards - Meerkat<sup>®</sup> Virtual Machine

Updating and recompiling the images will require access to a properly configured Linux machine. A virtual machine has been provided with the Meerkat<sup>®</sup> to speed your development. Refer to the [Software Guide for the Meerkat<sup>®</sup>](../guides/software-guide.md) for further information on compilation.

Once all prerequisites are met, using 7Zip or any acceptable unzip program, unzip the **NovTech_VM_U14.04.4_Meerkat.7z** file to your PC hard drive. After unzipping, navigate to the created folder **NovTech_VM_U14.04.4_Meerkat**. Double Click on the file **NovTech_VM_U14.04.4.vmx**. VMware® Player should load the virtual machine.
Another method could be to open VMware Player and click on ‘Open a Virtual Machine’ then navigate to the **NovTech_VM_U14.04.4_Meerkat** folder to find the virtual machine setup file.

<img src="../additional-docs/images/images-hw-user-manual/OpenVM.png" data-canonical-src="../additional-docs/images/images-hw-user-manual/OpenVM.png" width="385" height="386" />
*VMware<sup>®</sup> Player Open Virtual Machine*

<img src="../additional-docs/images/images-hw-user-manual/MeerkatVM.png" data-canonical-src="../additional-docs/images/images-hw-user-manual/MeerkatVM.png" width="396" height="378" />
*VMware<sup>®</sup> Player Select Virtual Machine*

To save on storage and transmission, the Meerkat<sup®</sup> virtual machine is preconfigured to use 1G of RAM. NovTech recommends increasing this value to a minimum of 2GB. You can edit this value to increase or decrease the amount of RAM assigned to the VM. After opening VMware<sup>®</sup> Player, click on **Edit Virtual Machine Settings**, navigate to **Hardware** tab and select **Memory**. Adjust memory to the desired size.

## Configure the RAM dedicated to your VM.

To minimize the size of the VM image in storage and transit, the VM has been limited to 1GB of RAM. For optimal performance, increase the amount of RAM allocated to the VM.
NovTech recommends allocating a minimum of 2GB of memory to the machine, and optimally 6GB of RAM.

This setting is under **Virtual machine->virtual machine settings->hardware**, and can be modified when the virtual machine has been powered off.

<img src="../additional-docs/images/images-hw-user-manual/VMsettingsWindow.png" data-canonical-src="../additional-docs/images/images-hw-user-manual/VMsettingsWindow.png" width="393" height="443" />

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

<img src="../additional-docs/images/images-hw-user-manual/VMdesktopScreen.png" data-canonical-src="../additional-docs/images/images-hw-user-manual/VMdesktopScreen.png" width="490" height="466" />
*Meerkat<sup>®</sup> Virtual Machine Desktop Screen.*

## Contents of the Virtual Machine Desktop
Along the left side of desktop are multiple icons:

- Search for software on computer and online:
<img src="../additional-docs/images/images-hw-user-manual/Search.png" data-canonical-src="../additional-docs/images/images-hw-user-manual/Search.png" width="77" height="75" />

- File Manager

<img src="../additional-docs/images/images-hw-user-manual/FileManager.png" data-canonical-src="../additional-docs/images/images-hw-user-manual/FileManager.png" width="77" height="75" />

- Terminal

<img src="../additional-docs/images/images-hw-user-manual/Terminal.png" data-canonical-src="../additional-docs/images/images-hw-user-manual/Terminal.png" width="77" height="75" />

- Putty - Serial Terminal Tool

<img src="../additional-docs/images/images-hw-user-manual/Putty.png" data-canonical-src="../additional-docs/images/images-hw-user-manual/Putty.png" width="77" height="75" />

- GHex - Hex Editor

<img src="../additional-docs/images/images-hw-user-manual/GHex.png" data-canonical-src="../additional-docs/images/images-hw-user-manual/GHex.png" width="77" height="75" />

- Meld - Code Comparison Tool

<img src="../additional-docs/images/images-hw-user-manual/Meld.png" data-canonical-src="../additional-docs/images/images-hw-user-manual/Meld.png" width="77" height="75" />

- Firefox

<img src="../additional-docs/images/images-hw-user-manual/Firefox.png" data-canonical-src="../additional-docs/images/images-hw-user-manual/Firefox.png" width="77" height="75" />

- Libre Office Writer

<img src="../additional-docs/images/images-hw-user-manual/LibreWriter.png" data-canonical-src="../additional-docs/images/images-hw-user-manual/LibreWriter.png" width="77" height="75" />

_ Libre Office Calc

<img src="../additional-docs/images/images-hw-user-manual/LibreCalc.png" data-canonical-src="../additional-docs/images/images-hw-user-manual/LibreCalc.png" width="77" height="75" />

- Libre Office Impress

<img src="../additional-docs/images/images-hw-user-manual/LibreImpress.png" data-canonical-src="../additional-docs/images/images-hw-user-manual/LibreImpre.png" width="77" height="75" />

- Ubuntu Software Center - update and install Ubuntu software packages

<img src="../additional-docs/images/images-hw-user-manual/UbuntuSoftwareCenter.png" data-canonical-src="../imx7-96/additional-docs/images/images-hw-user-manual/UbuntuSoftwareCenter.png" width="77" height="75" />

- System settings

<img src="../additional-docs/images/images-hw-user-manual/Settings.png" data-canonical-src="../additional-docs/images/images-hw-user-manual/Settings.png" width="77" height="75" />

# Meerkat Overview

<img src="../additional-docs/images/images-hw-user-manual/MeerkatTop.png" data-canonical-src="../additional-docs/images/images-hw-user-manual/MeerkatTop.png" width="535" height="320" />

<img src="../additional-docs/images/images-hw-user-manual/MeerkatBottom.png" data-canonical-src="../additional-docs/images/images-hw-user-manual/MeerkatBottom.png" width="535" height="320" />

# Serial Connections

The supplied cable connects to the Meerkat<sup></sup> as follows:

<img src="../additional-docs/images/images-hw-user-manual/TTL.png" data-canonical-src="../additional-docs/images/images-hw-user-manual/TTL.png" width="526" height="349" />

# Booting i.MX7 96 - Meerkat<sup>®</sup>

## Hardware Setup

To setup the Meerkat<sup>®</sup> board for booting, follow these steps:

- Plug in supplied USB cable to the UART port on the board and connect to PC. Verify the USB serial driver is found.
- Insert the SD card into the SD slot.

## Serial Console Setup

Open a Serial Terminal like Hyper-Terminal, putty or UConn, with settings of 115200, 8, N, 1.
For convenience, putty and a preconfigured settings file are provided in the supplied Virtual Machine (available from the download link as indicated in section 2).

The VM provides a preinstalled environment with tools to speed development.

A link to putty can be found on the desktop

<img src="../additional-docs/images/images-hw-user-manual/Putty.png" data-canonical-src="../additional-docs/images/images-hw-user-manual/Putty.png" width="77" height="75" />

Configure putty to use an 8n1 UART at 115200 bps.

For convenience, a preconfigured setting called “USB to TTL UART” is also provided in the virtual machine.

<img src="../additional-docs/images/images-hw-user-manual/config-putty.png" data-canonical-src="../additional-docs/images/images-hw-user-manual/config-putty.png" width="508" height="511" />

## Power the board

Using the provided power adaptor apply +8 to 18V power to the NovTech Meerkat®
Monitoring the serial terminal, you can stop at u-boot or boot all the way into Linux.

Note that for the graphical image, a terminal console is not available and all system control must be done through the graphical interface.

<img src="../additional-docs/images/images-hw-user-manual/init-boot.png" data-canonical-src="../additional-docs/images/images-hw-user-manual/init-boot.png" width="672" height="1020" />

# Initial Network Setup

The Meerkat<sup>®</sup> will need to be configured for your specific wireless network. Once configured, the network will start automatically when the board is powered up.

## Graphical Image Networking

The SD card delivered with your Meerkat<sup>®</sup> has a graphical desktop based on xfce. This desktop will require a mouse and keyboard to navigate. Those can be connected to the USB ports on the Meerkat<sup>®</sup>.

The networking on this image is managed by **connman**, but is not enabled by default. If you want wireless networking on your Meerkat<sup>®</sup>, the connman applet will need to be enabled to start at boot, and configured for your network.

After booting the Meerkat<sup>®</sup> image per the instructions above, select **Applications** from the upper left corner of the screen.

Click on:
Applications->Settings->Settings Manager

Then select:
System->Session and Startup->Application Autostart->Connection Manager.

There should now be a black checkmark next to **Connection Manager**.

Select **Close** (close all open settings manager windows).

Power cycle or reset your Meerkat<sup>®</sup>, the connman applet should be running and visible on the upper right of your screen on your next power up.

When the board comes back up, click on the Applet in the upper and select **Preferences**, then select your wireless network and click **Connect** on the right-hand side of the menu. Note that **Connect** does not look like a button, but text.

If you network requires additional configuration for security, the applet will prompt you for your authentication information.

## Console Image Networking

The console image ships with a network configuration that automatically connects to open (unsecure) networks that it finds. If successful, you will see the board retrieve an IP address via DHCP and will be able to ping to an IP address from the command line.

If your network requires additional configuration for security, you will need to provide the credentials for your network. This is accomplished from the Meerkat<sup>®</sup> console with the **wpa_passphrase** tool as follows:
```
wpa_passphrase YOURNET yourpassphrase  >> /etc/wpa_supplicant.conf
```
which will append an entry similar to the following to your /etc/wpa_supplicant.conf file:
```
network={
        ssid="YOURNET"
        #psk="yourpassphrase"
        psk=0d0992b62e7ce466b47aef8ea26fcd77421f6498f225419b40364c1b4441d08d
}
```
*NOTE: Remember to replace **YOURNET*** *and **yourpassphrase*** *with the information specific to your network.*
