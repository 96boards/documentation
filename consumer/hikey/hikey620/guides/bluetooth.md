---
title: Bluetooth Guide for HiKey
permalink: /documentation/consumer/hikey/hikey620/guides/bluetooth.md.html
redirect_from:
- /documentation/ConsumerEdition/HiKey/Guides/Bluetooth.md.html
---
# Bluetooth

The HiKey board includes built-in _Bluetooth_® wireless technology 4.0 LE support.

To setup a Bluetooth device open the Bluetooth Manager from the Preferences menu. If a “Bluetooth Turned Off” popup appears then select “Enable Bluetooth”. Click on "Search" to search for devices. Try with your Bluetooth audio and Bluetooth keyboard/mouse. If you make the device trusted then this should operate over a reboot of the board.

The blue LED between the microUSB and the Type A USB on the front board edge indicates Bluetooth activity.

### Audio Device

Bluetooth audio devices are supported on HiKey. Follow normal procedures of connecting a Bluetooth device to connect to your board.

Once Bluetooth sound sink is connected, you can open the LXMusic player from the Sound & Video menu. Create a playlist from your music files. Supported audio formats are .mp3 and .ogg. You should now be able to play from the LXMusic player.

**NOTE:** LXmusic uses xmms2 as the player backend, you may need to install xmms2 and related plugins if they are not installed, otherwise music may cannot be played.

```
$ sudo apt-get install xmms2 xmms2-plugin-*
```
