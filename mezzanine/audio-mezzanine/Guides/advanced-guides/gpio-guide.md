---
title: Audio Mezzanine GPIO Guide
permalink: /documentation/mezzanine/audio-mezzanine/Guides/advanced-guides/gpio-guide.md.html
---

# Touch Sensor and Relay
Build a system that toggles a relay on and off when the touch sensor is tapped using Linux GPIO IO.

The pins on connectors I/H and F/E are connected to GPIO pins on the baseboard and can be directly controlled from Linux. In this project, the application reads the state of the touch sensor from GPIO-H on connector I/H, and toggles the relay by driving GPIO-E on connector F/E. Each time the touch sensors is tapped, the relay will toggle between on and off.

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
- [5v Grove Relay](http://wiki.seeed.cc/Grove-Relay/)
- [5v Grove Touch Sensor](http://wiki.seeed.cc/Grove-Touch_Sensor/)

> Note: We are using Grove Sensors for this example, but the same can be reproduced using regular sensors and the Level Shifted Low Speed Header. If you want to refer pin numbering take a look at: https://www.96boards.org/pinout/

## 1.2) Hardware Setup
- Make sure SW2 is set to 5v
- Connect the relay to the E/F Grove connector
- Connect the touch sensor to I/H Grove connector

# 2) Software

## 2.1) Software Setup
- Make sure you are on the latest Debian build for DragonBoard-410c: https://www.96boards.org/documentation/ConsumerEdition/DragonBoard-410c/Installation/
- Make sure to follow [this guide](https://www.96boards.org/blog/install-96boardgpio-libsoc-libmraa-new-image/) to install MRAA and UPM Packages.

## 2.2) Write build and run the Code
- Save the following code as ```touch_switch.cpp```

```shell
#include <signal.h>
#include <unistd.h>
#include "mraa.hpp"

bool running = true;
bool relay_state = false;
int last_touch;

void sig_handler(int signo)
{
    if (signo == SIGINT)
        running = false;
}
int main(int argc, char* argv[])
{
    mraa::Gpio* touch_gpio = new mraa::Gpio(30);
    mraa::Gpio* relay_gpio = new mraa::Gpio(27);
    mraa::Result response;
    int touch;

    signal(SIGINT, sig_handler);

    response = touch_gpio->dir(mraa::DIR_IN);
    if (response != mraa::SUCCESS)
        return 1;
    response = relay_gpio->dir(mraa::DIR_OUT);
    if (response != mraa::SUCCESS)
        return 1;

    relay_gpio->write(relay_state);

    while (running) {
        touch = touch_gpio->read();
        if (touch == 1 && last_touch == 0) {
            relay_state = !relay_state;
            response = relay_gpio->write(relay_state);
            usleep(100000);
        }
        last_touch = touch;
    }
    delete relay_gpio;
    delete touch_gpio;
    return response;
}
```
- Build the Code
```shell $ g++ touch_switch.cpp -o touch_switch -g -Wall -lmraa```

- Run the demo
```shell  sudo ./touch_relay```


[Source](https://github.com/96boards/documentation/blob/master/mezzanine/sensors-mezzanine/README.md#example-project---touch-sensor-and-relay)
