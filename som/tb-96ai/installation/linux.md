---
title: Linux Host Installation for TB-96AI
permalink: /documentation/som/tb-96ai/installation/linux.md.html
---

## Linux Host

### Download Tools and Images

**Download the following tools from the [Downloads Page](../downloads/):**
- Rockchip Download/Upgrade tool for Windows and Linux Hosts
- PreBuilt Linux Images  (ANDROID and FEDORA)

### Bring the board into maskrom or rockusb loader mode
- Use type c usb cable to connect TB-96AI 96Boards and Host PC.
- Then put your TB-96AI 96Boards to download mode(maskrom or rockusb loader mode).
	- Press reset key of the developing board, and then long press recovery key around 3-4 seconds to enter.


### Flash the Image

**1. Flash dual system images(android&fedora)**
- Flash all image:
`sudo python flash.py -d all`
- Flash uboot.img and trust.img:
`sudo python flash.py -d uboot`
- Flash boot.img and boot_linux.img:
`sudo python flash.py -d boot`
- Flash system.img:
`sudo python flash.py -d system`
- Flash rootfs.img:
`sudo python flash.py -d rootfs`

**2. Flash android images**
- Flash all image:
`sudo python flash.py -a all`
- Flash uboot.img and trust.img:
`sudo python flash.py -a uboot`
- Flash boot.img:
`sudo python flash.py -a boot`
- Flash system.img:
`sudo python flash.py -a system`

**3. Flash fedora images**
- Flash all image:
`sudo python flash.py -l all`
- Flash uboot.img and trust.img:
`sudo python flash.py -l uboot`
- Flash boot_linux.img;
`sudo python flash.py -l boot`
- Flash rootfs.img:
`sudo python flash.py -l rootfs`

### Reboot and enjoy!

**Once the download of the images is complete, follow these steps:**
- Disconnect the USB cable
- Press the reset button
- After the reboot you should see linux startup

> NOTE: If you flash android images,after the reboot you should see android startup. If you
flash fedora images,after the reboot you should see fedora startup. If you flash dual
images,after the reboot you should see android startup or after pressing 'KEY2' key
reboot you should see fedora startup.
