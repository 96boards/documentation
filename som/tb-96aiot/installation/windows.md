---
title: Windows Host Installation for TB-96AIoT
permalink: /documentation/som/tb-96aiot/installation/windows.md.html
---

## Windows Host

### Download Tools and Images

**Download the following tools from the [Downloads Page](../downloads/):**
- Rockchip Download/Upgrade tool for Windows and Linux Hosts
- Rockchip Flash Download Driver for Windows
- PreBuilt Linux Images

### Install Rockchip Flash Download Driver on Host machine

- Double click DriverAssitant_v4.8\DriverInstall.exe, then automatically install rockchip flash download driver in your host windows machine.

### Bring the board into maskrom or rockusb loader mode
- Use type c usb cable to connect TB-96AIOT 96Boards and Host PC.
- Then put your TB-96AIOT 96Boards to download mode(maskrom or rockusb loader mode).
	- Press reset key of the developing board, and then long press recovery key around 3-4 seconds to enter.

### Start the rockchip flash download tool on the HostPC
- Run AndroidTool.exe

### Flash the Image

- Open the tool, and click “Download Image” menu.
- Single click every line end as marked with red arrow, it will pop out file selection box and then choose the img file path of the corresponding partition.
- Set all the img file paths successively.
- After configuration, click “Run”.
- The right information box will display the relative information.


### Reboot and enjoy!

**Once the download of the images is complete, follow these steps:**
- Disconnect the USB cable
- Press the reset button
- After the reboot you should see linux startup
