#!/usr/bin/env python

# uart example in python using mraa
#
# Author: Manivannan Sadhasivam <manivannan.sadhasivam@linaro.org>
#
# Usage: sends "Hello Mraa" string through tty96B0 uart port
#
# Execution: sudo python mraa_uart.py

import mraa
import time
import sys

# serial port
port = "/dev/tty96B0"
data = 'Hello Mraa!'

# initialize uart tty96B0
uart = mraa.Uart(port)

# send data through uart
uart.write(bytearray(data, 'utf-8'))
