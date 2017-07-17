---
title: System LEDs Guide for HiKey
permalink: /documentation/ConsumerEdition/HiKey/Guides/SystemLEDs.md/
---
# System LEDs

Each board led has a directory in /sys/class/leds. By default the LEDs use the following triggers:

LED | Trigger
--- | -------
wifi_active | phy0tx (WiFi Tx)
bt_active | hci0tx (Bluetooth Tx)
user_led1 | heartbeat
user_led2 | mmc0 (disk access, eMMC)
user_led3 | mmc1 (disk access, microSD card)
user_led4 | CPU core 0 active(not used)

To change a user LED you can do the following as a root user:
```
# echo heartbeat > /sys/class/leds/<led_dir>/trigger      make a LED flash
# cat /sys/class/leds/<led_dir>/trigger                   show triggers
# echo none > /sys/class/leds/<led_dir>/trigger           remove triggers    
# echo 1 > /sys/class/leds/<led_dir>/brightness           turn LED on
# echo 0 > /sys/class/leds/<led_dir>/brightness           turn LED off
```
