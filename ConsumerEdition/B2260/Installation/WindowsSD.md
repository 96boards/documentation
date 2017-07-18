---
title: Windows SD for B2260
permalink: /documentation/ConsumerEdition/B2260/Installation/WindowsSD.md/
---
## Windows Host

This section show how to install an operating system to your B2260 using the SD Card method on a Windows host computer.
***

- **Step 1**: Prepare MicroSD card
- **Step 2**: Recall Download Location
- **Step 3**: Unzip _SD Card Install Image_
- **Step 4**: Download the Win32DiskImager tool
- **Step 5**: Use Win32DiskImager tool to flash image onto SD Card
- **Step 6**: Prepare B2260 with SD card

***

####**Step 1**: Prepare MicroSD card


- Ensure data from mircoSD card is backed up
- Everything on microSD card will be lost by the end of this procedure.

####**Step 2**: Recall Download Location

- Locate SD card install file from Downloads page.
- This file will be needed for the next step.

####**Step 3**: Unzip _SD Card Install Image_

- When unzipped, this download will be a file
   - Install Image (.img)

####**Step 4**: Download the Win32DiskImager tool

- Win32DiskImager tool ([Direct Download](https://sourceforge.net/projects/win32diskimager/files/latest/download) / <a href="http://sourceforge.net/projects/win32diskimager/" target="_blank">Go to Site</a>)

####**Step 5**: Use Win32DiskImager tool to flash image onto SD Card

- Open Win32DiskImager tool
- Click the folder icon in the top right
- Find your way to the appropriate `.img` file (This is why you need to remember the location of your extracted image.)

- Insert your microSD card (through a USB SD card-reader, if necessary)
- Select the correct device and click "write" There may be a warning about corrupting the device. Click "Yes" to proceed.
- This process may take a few minutes, be patient and wait for a completion notice.
- Upon completion you should see the following pop-up:

<img src="http://i.imgur.com/HzYujlw.png" data-canonical-src="http://i.imgur.com/HzYujlw.png" width="150" height="100"/>

- Eject SD Card and proceed to next **Step**

####**Step 6**: Prepare B2260 with SD card

- Make sure B2260 is unplugged from power
- Connect an HDMI monitor to the B2260 with an HDMI cable, and power on the monitor
- Plug a USB keyboard and mouse into the two USB connectors on the B2260
- Insert the microSD card into the B2260
- Plug power adaptor into B2260, wait for board to boot up.

**Congratulations! You are now booting your newly installed operating system directly from SDCard on the B2260!**
