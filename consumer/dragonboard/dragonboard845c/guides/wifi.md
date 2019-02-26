---
title: Wi-Fi Setup Guide for DragonBoard 845c
permalink: /documentation/consumer/dragonboard/dragonboard845c/guides/wifi.md.html
---

# Set up WiFi

## Connect to a WiFi AP

- Edit `wpa_supplicant.conf` using: `vi /data/misc/wifi/wpa_supplicant.conf`
- Fill in the ssid and psk of wifi as follows:
```Shell
update_config=1
eapol_version=1
ap_scan=1
fast_reauth=1
pmf=1
p2p_add_cli_chan=1
network={
    ssid=”wifissid1”
    psk=”wifipsk1”
}
Network={
    ssid=”wifissid2”
    psk=”wifipsk2”
}
```
- Restart the device and connect to wifi.
- Run the following commands to confirm that the device is connected to wifi:
```Shell
ifconfig wlan0
wlan0     Link encap:Ethernet  HWaddr 00:0A:F5:83:66:EF
          inet addr:192.168.43.92  Bcast:192.168.43.255  Mask:255.255.255.0
          inet6 addr: fe80::20a:f5ff:fe83:66ef%1736140884/64 Scope:LinkUP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:15 errors:0 dropped:0 overruns:0 frame:0
          TX packets:18 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:3000
          RX bytes:1864 (1.8 KiB)  TX bytes:1828 (1.7 KiB)
          
ping www.qualcomm.com
PING www.qualcomm.com (23.59.93.51): 56 data bytes
64 bytes from 23.59.93.51: seq=0 ttl=48 time=171.722 ms
64 bytes from 23.59.93.51: seq=1 ttl=48 time=163.070 ms
64 bytes from 23.59.93.51: seq=2 ttl=48 time=244.932 ms
64 bytes from 23.59.93.51: seq=3 ttl=48 time=166.135 ms
```