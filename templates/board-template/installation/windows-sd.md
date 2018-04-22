<!---
---
title: Linux Host Installation for boardname
permalink: /documentation/consumer/boardname/installation/windows-sd.md.html
---
-->

## Windows Host

This section show how to install an operating system to your Board-X using the SD Card method on a Windows host computer.

< Example below - MediaTek X20 >
***

- **Step 1**: Prepare MicroSD card
- **Step 2**: Recall Download Location
- **Step 3**: Unzip _SD Card Install Image_
- **Step 4**: Download the Win32DiskImager tool
- **Step 5**: Use Win32DiskImager tool to flash image onto SD Card Card
- **Step 6**: Prepare Helio X20 with SD card
- **Step 7**: Install image onto Helio X20

***

####**Step 1**: Prepare MicroSD card

- Ensure data from mircoSD card is backed up
- Everything on microSD card will be lost by the end of this procedure.

####**Step 2**: Recall Download Location

- Locate SD card install file from Downloads page.
- This file will be needed for the next step.

####**Step 3**: Unzip _SD Card Install Image_

- When unzipped, this download will be a folder with the falling contents
   - Install Image (.img)
   - Readme

####**Step 4**: Download the Win32DiskImager tool

- Win32DiskImager tool ([Direct Download](https://sourceforge.net/projects/win32diskimager/files/latest/download))

####**Step 5**: Use Win32DiskImager tool to flash image onto SD Card

- Open Win32DiskImager tool
- Click the folder icon in the top right
- Find your way to the appropriate `.img` file (This is why you need to remember the location of your extracted image.)

<img src="http://i.imgur.com/cqk6LhL.png" data-canonical-src="http://i.imgur.com/cqk6LhL.png" width="300" height="150"/>

- Insert your microSD card (through a USB SD card-reader, if necessary)
- Select the correct device and click "write" There may be a warning about corrupting the device. Click "Yes" to proceed.
- This process may take a few minutes, be patient and wait for a completion notice.
- Upon completion you should see the following pop-up:

<img src="http://i.imgur.com/HzYujlw.png" data-canonical-src="http://i.imgur.com/HzYujlw.png" width="150" height="100"/>

- Eject SD Card and proceed to next **Step**

####**Step 6**: Prepare Helio X20 with SD card

- Make sure Helio X20 is unplugged from power
- Set S6 switch on Helio X20 to `0-1-0-0`, "SD Boot switch" should be set to "ON".
   - Please see "1.1 Board Overview" on page 7 from [Helio X20 Hardware Manual]() if you cannot find S6
- Connect an HDMI monitor to the Helio X20 with an HDMI cable, and power on the monitor
- Plug a USB keyboard and/or mouse into either of the two USB connectors on the Helio X20
- Insert the microSD card into the Helio X20
- Plug power adaptor into Helio X20, wait for board to boot up.

####**Step 7**: Install image onto Helio X20

<img src="http://i.imgur.com/F18wlgU.png" data-canonical-src="http://i.imgur.com/F18wlgU.png" width="400" height="250"/>

- If **Steps 1 - 6** were followed correctly, the above screen should be visible from your Helio X20
- Select the image to install and click “Install” (or type “i”). OS will be installed into the eMMC memory
- This process can take a few minutes to complete
- Upon completion, “Flashing has completed and OS has installed successfully....” message will appear.

Before clicking "OK":

- Remove the SD Card
- Set S6 switch on Helio X20 to `0-0-0-0`, all switches should be set to "OFF"
- Now click "OK" button and allow Helio X20 to reboot.

**Congratulations! You are now booting your newly installed operating system directly from eMMC on the Helio X20!**
