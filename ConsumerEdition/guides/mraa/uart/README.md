---
title: Examples on how to use UART using mraa library
permalink: /documentation/ConsumerEdition/guides/mraa/uart/README.md.html
---
# Examples on how to use UART using mraa library

Following examples are provided to use UART using MRAA library.

1. mraa_uart.c
2. mraa_uart.cpp
3. mraa_uart.py

**Usage:**

> Prerequisite: Debian running on 96Boards CE with libmraa installed

* Copy the examples to 96Boards CE
* Build the C/C++ examples:
```shell
$ gcc mraa_uart.c -o uart_c
$ g++ mraa_uart.cpp -o uart_c++
```
* Execute the examples:
```shell
$ sudo ./uart_c
$ sudo ./uart_c++
$ sudo python mraa_uart.py
```

**Expected Behaviour:**

Sends "Hello Mraa" string to `/dev/tty96B0` uart port.
