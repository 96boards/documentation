---
title: WisTrio Installation for Windows
permalink: /documentation/iot/wistrio/installation/windows.md.html
---

# Windows

Following instructions specifies how to flash the firmware onto WisTrio board
from a Windows host machine:

Make sure to download the following from the [Downloads Page](../downloads/):
- CP210x Windows Driver
- STM32 Flasher aka Demonstrator

1. Install the “CP210x_windows_Drivers” driver
  - Unzip the CP210x Driver file, and run the installer
  - Connect the WisTrio Board, Windows should now look for the correct drivers and install them.
  - Note down the COM port, In most cases it should be COM3
2. Install the STM32 Flash Loader Demonstrator
3. Connect the BOOT jumper:
  - The bootpin of the board needs to be raised to 3.3V when upgrading, so
you need to connect the BOOT0 and VDD pin of J12 by using a jumper.
  - Also, make sure that the RX pin of J25 is connected to the RXCP pin.
4. Start Upgrading the Firmware
  - Open the STM32 Flash Demonstrator Program
    - Select the COM Port
    - Set BaudRate to 115200
    - Click Next
  - Press reset button on the WisTrio Board
    - You should see the traffic light turn green
    - Click Next
  - Select "STM32L1_Cat2-128K" as Target
    - Click Next
  - Select “Download to device” then navigate to location of bin file.
    - Click “Next”
    - This will start the download process
5. Reset:
  - After finishing the download, close the Demonstrator program, disconnect the
RAK5205 and remove the jumper of J12.
