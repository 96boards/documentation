---
title: Using PMIC PWM on Dragonboard410c
permalink: /documentation/consumer/dragonboard/dragonboard410c/guides/pmic-pwm/
redirect_from:  /documentation/consumer/dragonboard410c/guides/pmic-pwm/
---

# Introduction

This document provides information on using the on-board PWM interface
present in PMIC PM8916 on Dragonboard410c running Linux.

# PWM

PWM is the Pulse Width Modulation, a technique used for producing the digital
signal to control devices such as motors, LEDs etc... PWM consists of two main
componenets:

1. Frequency - Number of cycles per second
2. Duty Cycle - Period at which the signal is ON

In Linux, hardware PWM peripheral is being managed by the PWM subsystem which
exposes control to userspace via sysfs.

# PMIC PM8916 PWM

The PMIC PM8916 on Dragonboard410c has one LPG (Light Pulse Generator)
module. It is used for generating the PWM signal for dimming control of
external WLED IC driver. But this interface can also be used to control
hobby servo motors which draws minimum current.

The PWM is exposed via **MPP_4** pin, which is pin **28** on the Low Speed
Expansion Connector. The driver implementing the PWM interface in Linux
kernel is **drivers/leds/leds-qcom-lpg.c** and it exposes a single channel
PWM interface for LPG module.

Following instructions are used to control the PWM output on pin **28**
from userspace in Linux.

## Prerequisite:

Flash the recent linaro debian build available [here](http://snapshots.linaro.org/96boards/dragonboard410c/linaro/debian/latest/).
Both the driver and its relevant devicetree entries are enabled by default.

## Controlling PWM from Userspace

```shell
# Export PWM 0
$ echo 0 | sudo tee /sys/class/pwm/pwmchip0/export

# Set frequency to 100KHz (value in nanoseconds)
$ echo 10000 | sudo tee /sys/class/pwm/pwmchip0/pwm0/period

# Set 50% duty cycle (value in nanoseconds)
$ echo 5000 | sudo tee /sys/class/pwm/pwmchip0/pwm0/duty_cycle

# Enable PWM 0
$ echo 1 | sudo tee /sys/class/pwm/pwmchip0/pwm0/enable
```

> Note: Both Frequency and Dutycycle should be specified in Nanoseconds.

Below is the script which can be used to sweep a hobby servo across its
useful range:

```shell
#!/bin/bash

echo sweep servo position at 50Hz nominal freq

# hobby servos want a pulse between 1ms (full CCW), 1.5ms (center) and 2ms (full CW) repeated every 20ms (50Hz)

PERIOD=20000000 #50Hz
MIN_DUTY=1000000 #1mS
MAX_DUTY=2000000 #2ms
DUTY=$MIN_DUTY  # initial duty cycle 1ms
INC=10000       # 1% 10uS

echo 0 | sudo tee /sys/class/pwm/pwmchip0/export
echo $PERIOD | sudo tee /sys/class/pwm/pwmchip0/pwm0/period >/dev/null
echo $DUTY | sudo tee /sys/class/pwm/pwmchip0/pwm0/duty_cycle >/dev/null
echo 1 | sudo tee /sys/class/pwm/pwmchip0/pwm0/enable >/dev/null

while [ $DUTY -lt $MAX_DUTY ]; do
        echo $DUTY | sudo tee /sys/class/pwm/pwmchip0/pwm0/duty_cycle >/dev/null
        let DUTY=DUTY+INC
        sleep 0.1
        printf %d\\r  $DUTY
done
```

> Note: Due to hardware limitation, the frequency might be little off and dutycycle
>       won't be available in exact steps.
