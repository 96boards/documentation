---
title: WiFi Configuration Guide for Avenger96
permalink: /documentation/consumer/avenger96/guides/wifi/
---

# Configuring WiFi

**Before configuring WiFi it is best to shut down other interfaces:**
```Shell
ifconfig eth0 down
ifconfig usb0 down
```

**Now let’s start WiFi:**
```Shell
ifconfig wlan0 up
iw dev wlan0 scan | grep ssid -i
```

**The last command will list the WiFi hot spots in range. <br> If a WiFi network uses WPA authentication the following commands will connect to it:**
```Shell
cd
cp /etc/wpa_supplicant.conf .
wpa_passphrase [SSID] [passphrase] >> ./wpa_supplicant.conf
```

**Please insert the name of the WiFi network and the passphrase in the command above without quotes or the brackets. <br> Now connect to the WiFi network:** `wpa_supplicant -B -Dnl80211 -iwlan0 -cwpa_supplicant.conf`

**The connection can be checked by:** `iw dev wlan0 link`

**When connected to the network IP address can be requested by:** `dhclient wlan0`
