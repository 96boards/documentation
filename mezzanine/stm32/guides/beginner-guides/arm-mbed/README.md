---
title: STM32 Sensor Mezzanine Getting Started With Arm mbed
permalink: /documentation/mezzanine/stm32/guides/beginner-guides/arm-mbed/
---

# Programming the STM32 Mezzanine with Arm mbed online

1. Make sure to properly setup the hardware and software as directed in the [Getting Started Guide](getting-started.md)
2. Power on you board, the ST-LINK LED should turn on Red
3. Once the board is booted to Desktop, remove the jumper (Labeled JP5) right next to the micro-usb port.
  - The ST-LINK LED should turn green
  - A USB storage device with a label similar to "B96B-F446VE" should show up with a capacity of around 532Kb
4. Open Up a browser and navigate to ["https://os.mbed.com/compiler"](https://os.mbed.com/compiler)
  - Login if you already have an id, or;
  - Sign-up for a new one
5. Once the IDE Open Up, on the Top-Right corner, click on "ST Platforms"
6. Select Add Board
7. From the list select "B96B-F446VE"
8. Select "Add to your Mbed Compiler"
10. Go Back to the Compiler Tab
11. On the Top-Right corner, click on "ST Platforms"
12. Select "B96B-F446VE" and then Select "Select Platform"
13. Create a New Project by clicking the "New" button on the Top-Left corner
14. Make sure the Following things are selected and click OK:
  - Platform: "B96B-F446VE"
  - Template: "Blinky LED Test for the ST Nucleo Boards"
  - Name: any name of your choice
15. Enter Ctrl+D:
  - IDE should start Compiling
  - A .bin file should be downloaded
16. Copy the .bin file to the USB storage device labeled "B96B-F446VE"
  - This will flash the .bin file to the Mezzanine Automatically
17. You should see the ST-LINK LED flash Green and Red for a few seconds and the LED Labeled D2 would start blinking
18. Try out with other examples
