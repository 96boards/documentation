---
title: CAN Bus Guide for DragonBoard 845c
permalink: /documentation/consumer/dragonboard/dragonboard845c/guides/can/
---

# CAN

This guide will show how to control the CAN bus on the LS2 Header.

**Connect CAN_L and CAN_H for loopback test.**
- CAN_H is Pin 2 and CAN_L in Pin 4 on the LS2 Header

**Configure the CAN device:**
```Shell
ip link set can0 down
// Disable CAN
ip link set can0 up type can bitrate 800000
// Enable CAN;
```
**Perform the data loopback test.**
- Receive data:
```Shell
candump can0
interface = can0, family = 29, type = 3, proto = 1
```

- Send Data:
```Shell
candump can0 interface = can0, family = 29, type = 3, proto = 1
```
