---
title: Examples on how to use GPIO using mraa library
permalink: /documentation/ConsumerEdition/guides/mraa/gpio/README.md.html
---
# Examples on how to use GPIO using mraa library

Following examples are provided in this repository to use GPIO using MRAA library.

1. mraa_gpio.c
2. mraa_gpio.cpp
3. mraa_gpio.py

**Usage:**

> Prerequisite: Debian running on 96Boards CE with libmraa installed

* Copy the examples to 96Boards CE
* Build the C/C++ examples:
```shell
$ gcc mraa_gpio.c -o gpio_c
$ g++ mraa_gpio.cpp -o gpio_c++
```
* Execute the examples:
```shell
$ sudo ./gpio_c
$ sudo ./gpio_c++
$ sudo python mraa_gpio.py
```

**Expected Behaviour:**

Toggles GPIO23 and GPIO24 on Low Speed expansion header.
 
