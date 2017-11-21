---
title: Examples on how to use I2C using mraa library
permalink: /documentation/ConsumerEdition/guides/mraa/i2c/README.md.html
---
# Examples on how to use I2C using mraa library


Following examples are provided to use I2C using MRAA library.

1. mraa_i2c.c
2. mraa_i2c.cpp
3. mraa_i2c.py

**Usage:**

> Prerequisite: Debian running on 96Boards CE with libmraa installed

* Copy the examples to 96Boards CE
* Build the C/C++ examples:
```shell
$ gcc mraa_i2c.c -o i2c_c
$ g++ mraa_i2c.cpp -o i2c_c++
```
* Execute the examples:
```shell
$ sudo ./i2c_c
$ sudo ./i2c_c++
$ sudo python mraa_i2c.py
```

**Expected Behaviour:**

Checks for MPU6050 sensor at I2C bus 0. 
