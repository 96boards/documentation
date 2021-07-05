---
title: TB-96AIoT-1126CE Board Recovery
permalink: /documentation/consumer/tb-96aiot-1126ce/installation/board-recovery.md.html
---

# For Linux Based Host OS

**1. Bring the board into maskrom or rockusb loader mode**
-  Use typec usb cable to connect RV1126 CE Boards and Host PC. Then put your RV1126 CE Boards enter download mode(maskrom or rockusb loader mode). The method of download mode as follows: Firstly press reset key of the developing board, and then long press recovery key around 3-4 seconds to enter.


**2. (Debian)  Flash debian images**
```
sudo ./upgrade_tool ul rv1126-debian/MiniLoaderAll.bin
sudo ./upgrade_tool di -p rv1126-debian/parameter.txt
sudo ./upgrade_tool di -u rv1126-debian/uboot.img
sudo ./upgrade_tool di -misc rv1126-debian/misc.img
sudo ./upgrade_tool di -b rv1126-debian/boot.img
sudo ./upgrade_tool di -recovery rv1126-debian/recovery.img
sudo ./upgrade_tool di -oem rv1126-debian/oem.img
sudo ./upgrade_tool di -rootfs rv1126-debian/rootfs.img
sudo ./upgrade_tool di -userdata rv1126-debian/userdata.img
sudo ./upgrade_tool rd
```

**2. (Buildroot) Flash buildroot images**
```
sudo ./upgrade_tool ul rv1126-buildroot/MiniLoaderAll.bin
sudo ./upgrade_tool di -p rv1126-buildroot/parameter.txt
sudo ./upgrade_tool di -u rv1126-buildroot/uboot.img
sudo ./upgrade_tool di -misc rv1126-buildroot/misc.img
sudo ./upgrade_tool di -b rv1126-buildroot/boot.img
sudo ./upgrade_tool di -recovery rv1126-buildroot/recovery.img
sudo ./upgrade_tool di -oem rv1126-buildroot/oem.img
sudo ./upgrade_tool di -rootfs rv1126-buildroot/rootfs.img
sudo ./upgrade_tool di -userdata rv1126-buildroot/userdata.img
sudo ./upgrade_tool rd
```

**3. Reboot and enjoy!**
- Once the download of the images is complete, follow these steps:
    - Disconnect the USB cable
    - Press the reset button
- If you flash buildroot images,after the reboot you should see buildroot startup.
- If you flash debian images,after the reboot you should see debian startup.

***

# For Windows Based Host OS

**1. Install Rockchip Flash Download Driver in Host machine**
- In the network disk tools Directory: tools\windows\DriverAssitant_v5.0.zip Double click DriverAssitant_v5.0\ DriverInstall.exe,then automatically install rockchip flash download driver in your host windows machine.

**2. Bring the board into maskrom or rockusb loader mode**
- Use typec usb cable to connect RV1126 CE Boards and Host PC. Then put your RV1126 CE Boards enter download mode(maskrom or rockusb loader mode). The method of download mode as follows: Firstly press reset key of the developing board, and then long press recovery key around 3-4 seconds to enter.

**3. Flash images**
- In the network disk tools Directory: tools\windows\RKDevTool_Release.zip Double click RKDevTool_Release\RKDevTool.exe.
- Flash images ass instructed in the GUI

**4. Reboot and enjoy!**
- Once the download of the images is complete, follow these steps:
    - Disconnect the USB cable
    - Press the reset button
- If you flash buildroot images,after the reboot you should see buildroot startup.
- If you flash debian images,after the reboot you should see debian startup.