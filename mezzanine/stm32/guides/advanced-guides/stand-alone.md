---
title: STM32 Sensor Mezzanine as a Stand Alone Dev Board
permalink: /documentation/mezzanine/stm32/guides/advanced-guides/stand-alone.md.html
---

# Instruction to use the Mezzanine as a Stand Alone Dev Board

These instructions will allow you to use the STM32 Sensor Mezzanine as a Stand alone Development Platform and program it using a regular PC and the micro-usb ST-LINK Programming Port.

1. Make sure the Mezzanine is powered off and not attached to any Board.
2. Locate Jumper JP4
  - Back side of the Mezzanine
  - Below the High Speed Header
  - Below JP71-JP81
3. Close Jumper JP4 using Solder
4. Make sure JP5, right next to the ST-LINK micro-usb port is also closed
5. Connect the micro-usb to your PC
  - A USB storage device with a label similar to "B96B-F446VE" should show up with a capacity of around 532Kb
6. Follow our [Arm mbed Guide](/mezzanine/stm32/guides/beginner-guides/arm-mbed.md) from Step 4 and start Programming!
