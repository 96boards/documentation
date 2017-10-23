#!/usr/bin/env python

# gpio example in python using mraa
#
# Author: Manivannan Sadhasivam <manivannan.sadhasivam@linaro.org>
#
# Usage: Toggles GPIO 23 and 24
#
# Execution: sudo python mraa_gpio.py

import mraa
import time

# initialize gpio 23
gpio_1 = mraa.Gpio(23)

# initialize gpio 24
gpio_2 = mraa.Gpio(24)

# set gpio 23 to output
gpio_1.dir(mraa.DIR_OUT)

# set gpio 24 to output
gpio_2.dir(mraa.DIR_OUT)

while True:
	# toggle both gpio's
	gpio_1.write(1)
	gpio_2.write(0)

	time.sleep(1)

	gpio_1.write(0)
	gpio_2.write(1)

	time.sleep(1)
