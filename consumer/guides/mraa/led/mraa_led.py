#!/usr/bin/env python

# led example in python using mraa
#
# Author: Manivannan Sadhasivam <manivannan.sadhasivam@linaro.org>
#
# Usage: reads maximum brightness value for user1 led and turns it
# 	 on/off depending on current state. Then sets led trigger to heartbeat
#
# Execution: sudo python mraa_led.py

import mraa
import time

# initialize user1 led
led_1 = mraa.Led("user1")

# read maximum brightness
val = led_1.readMaxBrightness()

print("maximum brightness value for user1 led is: %d" % val);

if (val >= 1):
	val = 0
else:
	val = 1

# turn led on/off depending on max_brightness value
led_1.setBrightness(val)

# sleep for 5 seconds
time.sleep(5)

led_1.trigger("heartbeat")

print("led trigger set to: heartbeat")
