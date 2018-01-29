---
title: Examples on how to use on board LED using mraa library
permalink: /documentation/consumer/guides/mraa/led/
redirect_from: /documentation/ConsumerEdition/guides/mraa/led/
---
# Examples on how to use on board LED using mraa library

Following examples are provided to use LED using MRAA library.

1. mraa_led.c
2. mraa_led.cpp
3. mraa_led.py

**Usage:**

> Prerequisite: Debian running on 96Boards CE with libmraa installed

* Copy the examples to 96Boards CE
* Build the C/C++ examples:
```shell
$ gcc mraa_led.c -o led_c
$ g++ mraa_led.cpp -o led_c++
```
* Execute the examples:
```shell
$ sudo ./led_c
$ sudo ./led_c++
$ sudo python mraa_led.py
```

**Expected Behaviour:**

1. Reads maximum brightness value for USER1 led and turns it
ON/OFF depending on current state.
2. Finally sets led trigger to heartbeat.
