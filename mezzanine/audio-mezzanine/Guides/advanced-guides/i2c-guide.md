---
title: Audio Mezzanine I2C Guide
permalink: /documentation/mezzanine/audio-mezzanine/Guides/advanced-guides/i2c-guide.md.html
---

# Hello World with the RGB LCD
This is an example of how to display text on the Grove RGB LCD module and change the color of the backlight. The example is written in C++, but could easily be implemented using Python or Java.

# Table of Contents
- [1) Hardware](#1-hardware)
  - [1.1) Hardware Requirements](#11-hardware-requirements)
  - [1.2) Hardware Setup](#12-hardware-setup)
- [2) Software](#2-software)
  - [2.1) Software Setup](#21-software-setup)
  - [2.2 Write build and run the code](#22-write-build-and-run-the-code)

# 1) Hardware

## 1.1) Hardware Requirements
- DragonBoard-410c
- Audio Mezzanine
- [Grove - LCD RGB Backlight](http://wiki.seeed.cc/Grove-LCD_RGB_Backlight/)

> Note: We are using Grove Sensors for this example, but the same can be reproduced using regular sensors and the Level Shifted Low Speed Header.  If you want to refer pin numbering take a look at: https://www.96boards.org/pinout/

## 1.2) Hardware Setup
- Make sure SW2 is set to 5v
- Connect the relay to the i2c0 Grove connector

# 2) Software

## 2.1) Software Setup
- Make sure you are on the latest Debian build for DragonBoard-410c: https://www.96boards.org/documentation/ConsumerEdition/DragonBoard-410c/Installation/
- Make sure to follow [this guide](https://www.96boards.org/blog/install-96boardgpio-libsoc-libmraa-new-image/) to install MRAA and UPM Packages.

## 2.2) Write build and run the Code
- Save the following code as ```rgb_lcd_demo.cpp```

```shell
#include <string>
#include "upm/jhd1313m1.hpp"

#define I2C_BUS  0
#define RGB_WHT 0xff,0xff,0xff
#define RGB_RED 0xff,0x00,0x00
#define RGB_GRN 0x00,0xff,0x00
#define RGB_BLU 0x00,0x00,0xff
#define SLEEP_TIME 2

using namespace std;
upm::Jhd1313m1* lcd;

void display(string str1, string str2, int red, int green, int blue)
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
	string str1 = "96Boards!";
	string str2 = "Grove Sensors!";
	string str3 = "Linaro!";

	lcd = new upm::Jhd1313m1(I2C_BUS, 0x3e, 0x62);

	if ((argc >= 2) && (argv[1] != NULL))
		str1 = argv[1];
	if ((argc >= 3) && (argv[2] != NULL))
		str2 = argv[2];
	if ((argc >= 4) && (argv[3] != NULL))
		str3 = argv[3];

	while (true) {
		display(str1, "Red", RGB_RED);
		display(str2, "Green", RGB_GRN);
		display(str3, "Blue", RGB_BLU);
	}
	delete lcd;
	return 0;
}
```
- Build the Code
```shell $ g++ rgb_lcd_demo.cpp -o rgb_lcd_demo -g -Wall -lupm-i2clcd```

- Run the demo
```shell  sudo ./rgb_lcd_demo```

The LCD will show some sample messages and the backlight will cycle between red, blue and green.

[Source](https://github.com/96boards/documentation/tree/master/mezzanine/sensors-mezzanine#example-project---hello-world-with-the-rgb-lcd)
