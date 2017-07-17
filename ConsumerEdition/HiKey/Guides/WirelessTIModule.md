---
title: Configuring the wireless TI module (Debian) Guide for HiKey
permalink: /documentation/ConsumerEdition/HiKey/Guides/WirelessTIModule.md/
---
# Configuring the wireless TI module (Debian)

Using the right WiFi (TI wl1835mod) module config for HiKey (avoid bugs like https://bugs.96boards.org/show_bug.cgi?id=202)

```shell
root@linaro-alip:~# configure-device.sh

Please provide the following information.

Are you using a TI module? [y/n] : y
What is the chip flavor? [1801/1805/1807/1831/1835/1837 or 0 for unknown] : 1835
How many 2.4GHz antennas are fitted? [1/2] : 1
Should SISO40 support be applied? [y/n] : n

The device has been successfully configured.
TI Module: y
Chip Flavor: 1835
Number of 2.4GHz antennas fitted: 1
Number of 5GHz antennas fitted: 0
Diversity Support: n
SISO40 Support: n
Japanese standards applied: n
```

Reboot your HiKey and the wireless module should now use the right configuration.

# Wireless Network

The HiKey board includes built in [2.4GHz IEEE802.11 b/g/n WiFi networking](http://www.ti.com/product/WL1835MOD). The board does not support the 5GHz band. To use the wireless LAN interface for the first time (or to switch wireless networks) you should click on the wireless LAN icon on the bottom right of the desktop display. The yellow LED between the microUSB and the Type A USB on the front board edge indicates wireless network activity.

You can configure the network from UI, or manually from console:

```
$ sudo nmtui
```

Select 'Activate a connection', Choose your WiFi access point (SSID) and fill the relevant information (password, etc...)

You can check network status by issuing this command.
```
$ sudo nmcli dev wifi
```
