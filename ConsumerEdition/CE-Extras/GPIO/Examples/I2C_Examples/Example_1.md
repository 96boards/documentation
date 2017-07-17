---
title: Example 1 - Grove RGB backlight LCD module
permalink: /documentation/ConsumerEdition/CE-Extras/GPIO/Examples/I2C_Examples/Example_1.md/
---
# Example 1 - Grove RGB backlight LCD module

## Update 96Boards system

The image on your board might be out of date. This is possible even when using the stock image (the operating system your board was shipped with), or a newly flashed version from the 96Boards.org website.

A few useful commands will help us make sure everything on the board is current:

- **apt-get update**: Downloads package lists from online repositories and "updates" them to get information on the newest versions of packages and their dependencies.
- **apt-get upgrade**: Fetches and installs newest package versions which currently exist on the system. APT must know about these new versions by way of 'apt-get update'
- **apt-get dist-upgrade**: In addition to performing the function of upgrade, this option also intelligently handles changing dependencies with new versions of packages

**Commands:**

```shell
$ sudo apt-get update

$ sudo apt-get upgrade

$ sudo apt-get dist-upgrade
```

Note: If at any point during this process you are prompted with a 'Y/N', select Y and press Enter.

## Install Libraries

**Commands:**

`$ sudo apt-get install libmraa-dev libupm-dev`

The command above will install the following four packages:

- libmraa0: contains only libraa run-time library
- libmraa-dev: includes header files to compile program using libmraa
- libupm0: contains only libupm run-time library
- libupm-de: includes header files to compile program using libupm

## Setting up hardware - Connecting Grove RGB backlight LCD

<a href="" align="left" target="_blank"><img src="http://i.imgur.com/ZTatUeB.png" data-canonical-src="http://i.imgur.com/ZTatUeB.png" width="350" height="330" /></a>

##  Download, build and run sample program:

**Commands:**

```shell
$ git clone https://github.com/96boards/Starter_Kit_for_96Boards

$ cd Starter_Kit_for_96Boards

$ cd rgb_lcd_demo

$ make

$ sudo ./rgb_lcd_demo
```

## Extra - Inside the sample program

Below you will see the insides of the sample program you just ran. It is written in C++. There is no immediate need to write you own code for controlling the LCD display, reading this code over should give you a good start to designing your own I2C programs.
This can be accessed through the terminal using your favorite text editor. Make sure you are in the right directory and simply open the rgb-lcd-demo.cpp file.

**Example using vim text editor:**

`$ vim rgb-lcd-demo.cpp`

—— rgb-lcd-demo.cpp —–

```shell
/*
 * Author: Akira Tsukamoto
 * Copyright (c) 2016 Linaro Ltd.
 * All rights reserved.
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include
#include "upm/jhd1313m1.h"

/* Note:
        LCD_I2C_ADDRESS 0x7C>>1 62 0x3E
        RGB_I2C_ADDRESS 0xC4>>1 98 0x62
*/

#define I2C_BUS  0
#define RGB_WHT 0xff,0xff,0xff
#define RGB_RED 0xff,0x00,0x00
#define RGB_GRN 0x00,0xff,0x00
#define RGB_BLU 0x00,0x00,0xff
#define SLEEP_TIME 2

using namespace std;

void display(upm::Jhd1313m1* lcd, string str1, string str2, int red, int green,
        int blue)
{
    lcd->clear();
    lcd->setColor(red, green, blue);
    lcd->setCursor(0,0); /* first row */
    lcd->write(str1);
    lcd->setCursor(1,2); /* second row */
    lcd->write(str2);
    sleep(SLEEP_TIME);
}

int main(int argc, char* argv[])
{
    upm::Jhd1313m1* lcd;

    string str1 = "96Boards!";
    string str2 = "Sensors!";
    string str3 = "Linaro!";

    string red = "fantastic :)";
    string grn = "nice :)";
    string blu = "great :)";

    lcd = new upm::Jhd1313m1(I2C_BUS, 0x3e, 0x62);

    while (true) {
            display(lcd, str1, red, RGB_RED);
            display(lcd, str2, grn, RGB_GRN);
            display(lcd, str3, blu, RGB_BLU);
    }

    delete lcd;

    return 0;
}
```

###### Compiling

For those of you who wish to compile the program manually please use the following command. This is important for those who wish to try other sensors, you will need to find the linking library before compilation.

**Commands:**

`$ g++ rgb-lcd-demo.cpp -o rgb-lcd-demo -g -Wall -lupm-i2clcd`

You can find the linking library [here](http://iotdk.intel.com/docs/master/upm/classupm_1_1_jhd1313m1.html#details)

###### Running

Once you have successfully written your code and compiled your program, you are ready to run it. This is the fun part.

**Commands:**

`$ sudo ./rgb-lcd-demo`
