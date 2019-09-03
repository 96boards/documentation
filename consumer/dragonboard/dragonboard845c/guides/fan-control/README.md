---
title: Fan Control Guide for DragonBoard 845c
permalink: /documentation/consumer/dragonboard/dragonboard845c/guides/fan-control/
---

# Fan Control

This guide will show how to control the fan connected to the on board header.

**Enable Fan**

```Shell
echo 1 > /sys/kernel/fan/speed # Minimum Speed
echo 2 > /sys/kernel/fan/speed # Medium Speed
echo 3 > /sys/kernel/fan/speed # Maximum Speed
```

**Disable Fan**

```Shell
echo 0 > /sys/kernel/fan/speed
```
