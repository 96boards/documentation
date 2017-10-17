#!/usr/bin/env python

# i2c example in python using mraa
#
# Author: Manivannan Sadhasivam <manivannan.sadhasivam@linaro.org>
#
# Usage: Checks for MPU6050 sensor at I2C bus 0
#
# Execution: sudo python mraa_i2c.py

import mraa
import time

# initialize i2c bus
i2c = mraa.I2c(0)

# set slave address
i2c.address(0x68)

# read WHO_AM_I register and compare its value
if ((i2c.readReg(0x75) & 0x7E) != 0x68):
	print("Device not found!")

print("MPU6050 found at: 0x68")
