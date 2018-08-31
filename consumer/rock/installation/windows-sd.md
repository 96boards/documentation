---
title: Linux Host Installation for ROCK960
permalink: /documentation/consumer/rock/installation/windows-sd.md.html
redirect_from: /documentation/consumer/rock960/installation/windows-sd.md.html
---

## Windows Host

This section show how to install an operating system to your ROCK960 using the SD Card method on a Windows host computer.
***

- **Step 1**: Prepare MicroSD card
- **Step 2**: Recall Download Location
- **Step 3**: Unzip _SD Card Install Image_
- **Step 4**: Download the Win32DiskImager tool
- **Step 5**: Use Win32DiskImager tool to flash image onto SD Card Card
- **Step 6**: Prepare ROCK960 with SD card

***

####**Step 1**: Prepare MicroSD card

- Ensure data from mircoSD card is backed up
- Everything on microSD card will be lost by the end of this procedure.

####**Step 2**: Recall Download Location

- Locate SD card install file from Downloads page.
- This file will be needed for the next step.

####**Step 3**: Unzip _SD Card Install Image_

- When unzipped, this download will be a folder with the falling contents
   - Loader (rk3399_loader_v1.08.106.bin) we don't need it for SD card writing here.
   - Install Image (system.img)
   - readme.md

####**Step 4**: Download the Win32DiskImager tool

- Win32DiskImager tool ([Direct Download](https://sourceforge.net/projects/win32diskimager/files/latest/download) / <a href="http://sourceforge.net/projects/win32diskimager/" target="_blank">Go to Site</a>)

####**Step 5**: Use Win32DiskImager tool to flash image onto SD Card

- Open Win32DiskImager tool
- Click the folder icon in the top right
- Find your way to the appropriate `.img` file (This is why you need to remember the location of your extracted image.)

<img src="../rock960/additional-docs/images/images-install/win32imagewriter.png" data-canonical-src="" width="250" height="160" />


- Insert your microSD card (through a USB SD card-reader, if necessary)
- Select the correct device and click "write" There may be a warning about corrupting the device. Click "Yes" to proceed.
- This process may take a few minutes, be patient and wait for a completion notice.
- Upon completion you should see the success dialog pop-up:


- Eject SD Card and proceed to next **Step**

####**Step 6**: Prepare ROCK960 with SD card

- Make sure ROCK960 is unplugged from power
- Connect an HDMI monitor to the ROCK960 with an HDMI cable, and power on the monitor
- Plug a USB keyboard and/or mouse into either of the two USB connectors on the ROCK960
- Insert the microSD card into the ROCK960
- Plug power adaptor into ROCK960, wait for board to boot up.

**Congratulations! You are now booting your newly installed operating system directly on SD card on the ROCK960!**
