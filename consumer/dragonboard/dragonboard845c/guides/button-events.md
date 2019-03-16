---
title: Button Events Guide for DragonBoard 845c
permalink: /documentation/consumer/dragonboard/dragonboard845c/guides/button-events.md.html
---

# Button Events

This guide will show how to get interrupt events from the on-board Buttons 

**Key Map table**
| Key    | Device Node       |
|:------:|:-----------------:|
| VOL +  | /dev/input/event2 |
| VOL -  | /dev/input/event0 |
| F_DL   | /dev/input/event2 |
| ON/OFF | /dev/input/event0 |

**Get Inturrupt Event**
```Shell
hexdump /dev/input/event0
```

**Press the “key -" button. The terminal displays the following information:**
```Shell
hexdump /dev/input/event0

 0000000 6a1d 5c2f 0000 0000 c499 000d 0000 0000
 0000010 0001 0072 0001 0000 6a1d 5c2f 0000 0000
 0000020 c499 000d 0000 0000 0000 0000 0000 0000
```