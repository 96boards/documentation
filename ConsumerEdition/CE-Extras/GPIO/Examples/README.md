---
title: Examples for CE Boards
permalink: /documentation/ConsumerEdition/CE-Extras/GPIO/Examples/
redirect_from: /documentation/ConsumerEdition/CE-Extras/GPIO/Examples/README.md/
---
# Examples - Sample Code

## Contents

- GPIO Examples
- I2C Examples
- SPI Examples

***

## GPIO Examples

- [Example #1 - Through the shell](GPIO_Examples/Example_1.md)
   - This is the first and simplest example one could execute on a 96Boards. For this example you will access and manipulate the GPIOs via command line using the built in terminal application on your 96Boards. For this example you WILL NOT need any particular library, however, low-speed expansion header pins/GPIOs naming conventions can be significantly simplified by installing the **libsoc** library beforehand.
- [Example #2 - Triple library LED push button](GPIO_Examples/Example_2.md)
   - This repository, created by Linaro's David Mandala, demonstrates the use of three different libraries using three different scripts. Instructions on how to compile and execute the code can be found in the README.md file which is included in the repository download. Simply clone the repoistory onto your 96Boards and follow README.md instructions.
- [Example #3 - Sensor, sensors, and more sensors](GPIO_Examples/Example_3.md)
   - This public instruction set was created by Barry Byford, a DragonBoard 410c enthusiast from the UK. The code provided for these examples are simple and still being developed. Instructions for setting up the libsoc_zero library can be found on his website along side his sample code and examples.

***

## I2C Examples

- [Example #1 - Grove RGB backlit LCD module](I2C_Examples/Example_1.md)
   - This example provides sample code for accessing and using the grove RGB backlit LCD module. The example includes library installation instructions, code breakdown and download, build, run instructions. This sample has been tested on all libmraa and libupm enabled 96Boards.

***

## SPI Examples

Coming Soon...
