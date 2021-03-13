---
title: Linux Host Installation for TB-96AIoT
permalink: /documentation/som/tb-96aiot/installation/linux.md.html
---

## Linux Host

### Download Tools and Images

**Download the following tools from the [Downloads Page](../downloads/):**
- Rockchip Download/Upgrade tool for Windows and Linux Hosts
- PreBuilt Linux Images

### Bring the board into maskrom or rockusb loader mode
- Use type c usb cable to connect TB-96AIOT 96Boards and Host PC.
- Then put your TB-96AIOT 96Boards to download mode(maskrom or rockusb loader mode).
	- Press reset key of the developing board, and then long press recovery key around 3-4 seconds to enter.


### Flash the Image

**Run the upgrade_tool**
- `sudo ./upgrade_tool`
- Input the device number and press Enter
- Download loader: `ul MiniLoaderAll.bin`
- DI command:
	- burn partition imag(1) Parameter: `di –p parameter.txt`
	- Uboot: `di –u uboot.img`
	- Trust: `di –t turst.img`
	- Misc: `di –m misc.img`
	- Boot: `di –b boot.img`
	- Recovery: `di –r recovery.img`
	- Oem: `di –oem oem.img`
	- Rootfs: `di –rootfs rootfs.img`
	- Userdata: `di –userdata userdata.img`
	- Reboot: `rd`

### Reboot and enjoy!

**Once the download of the images is complete, follow these steps:**
- Disconnect the USB cable
- Press the reset button
- After the reboot you should see linux startup
