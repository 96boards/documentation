## Windows Host

This section shows how to install a new operating system to your HiKey using the SD Card method on a Windows host computer.
***

- **Step 1**: Prepare MicroSD card
- **Step 2**: Recall Download Location
- **Step 3**: Unzip _SD Card Install Image_
- **Step 4**: Download the Win32DiskImager tool
- **Step 5**: Use Win32DiskImager tool to flash image onto SD Card
- **Step 6**: Prepare HiKey with SD card
- **Step 7**: Install image onto HiKey

***

####**Step 1**: Prepare MicroSD card

- Ensure data from mircoSD card is backed up
- Everything on microSD card will be lost by the end of this procedure.

####**Step 3**: Recall Download Location

- Locate SD card install file from Downloads page.
- This file will be needed for the next step.

####**Step 3**: Unzip _SD Card Install Image_

- When unzipped, this download will be a folder with the falling contents
   - Install Image (.img)
   - Readme

####**Step 4**: Download the Win32DiskImager tool

- Win32DiskImager tool ([Direct Download](https://sourceforge.net/projects/win32diskimager/files/latest/download) / <a href="http://sourceforge.net/projects/win32diskimager/" target="_blank">Go to Site</a>)

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

####**Step 6**: Prepare HiKey with SD card

- Make sure HiKey is unplugged from power
- Connect an HDMI monitor to the HiKey with an HDMI cable, and power on the monitor
- Plug a USB keyboard and/or mouse into either of the two USB connectors on the HiKey
- Insert the microSD card into the HiKey
- Plug power adaptor into HiKey, wait for board to boot up.

####**Step 7**: Install image onto HiKey

<img src="http://i.imgur.com/F18wlgU.png" data-canonical-src="http://i.imgur.com/F18wlgU.png" width="400" height="250"/>

- If **Steps 1 - 6** were followed correctly, the above screen should be visible from your HiKey
- Select the image to install and click “Install” (or type “i”). OS will be installed into the eMMC memory
- This process can take a few minutes to complete
- Upon completion, “Flashing has completed and OS has installed successfully....” message will appear.

Before clicking "OK":

- Remove the SD Card
- Now click "OK" button and allow HiKey to reboot.

**Congratulations! You are now booting your newly installed operating system directly from eMMC on the HiKey!**
