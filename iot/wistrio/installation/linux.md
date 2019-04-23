---
title: WisTrio Installation for Linux
permalink: /documentation/iot/wistrio/installation/linux.md.html
---

# Linux

Following instructions specifies how to flash the firmware onto WisTrio board
from a Linux host machine:

1. Install `stm32flash` tool

```shell
$ git clone https://git.code.sf.net/p/stm32flash/code stm32flash-code
$ cd stm32flash-code
$ make
$ sudo make install
```
2. Download the firmware from [Git repo](https://github.com/RAKWireless/RAK5205-WisTrio-LoRa/tree/master/doc/Firmware) page.

3. Trigger ROM bootloader
   - Connect 96Boards WisTrio to your Linux PC using, USB-Micro to USB-A cable.
   - ROM bootloader can be triggered by the following pattern:
       - Connect BOOT0 to VDD (link pin 1 and 2 on J12)
       - Press and release the RST button

4. Flash the firmware onto WisTrio
```shell
$ sudo stm32flash -b 115200 -w ./Firmware/RAK811_HF_trackerboard_V2.0.0.6.bin -v -g 0x08000000 /dev/ttyUSB0
```

> Note: `/dev/ttyUSB0` is the serial port exposed by WisTrio

5. Once the firmware is flashed, unlink J12 and connect to the WisTrio serial port using minicom
```shell
$ sudo minicom -D /dev/ttyUSB0
```
> Note: For getting the AT command response, Local echo needs to be turned ON. On minicom,
>       this can be achieved by `Ctrl + A, E`. After entering the AT commands, press `Ctrl + J`.
