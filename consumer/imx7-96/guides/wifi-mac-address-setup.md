---
title: Setting Wi-Fi MAC Address on DragonBoard 410c
permalink: /documentation/consumer/dragonboard410c/guides/WIFIMacAddressSetup.md.html
redirect_from:
- /db410c-getting-started/Guides/WIFIMacAddressSetup.md/
- /documentation/ConsumerEdition/DragonBoard-410c/Guides/WIFIMacAddressSetup.md.html
---
# Setting Wi-Fi MAC Address on DragonBoard 410c

This document shows users how to program a unique MAC address into a DragonBoard 410c
board. If at any point the board’s flash memory is rewritten (changing between operating systems,
etc.) the MAC address will once again need to be reprogrammed.

***

## Introduction

All internet connected devices have a globally unique address used for Media Access Control.
This “MAC” address, sometimes referred to as the physical address, serves as your device’s
unique identity when accessing a network. The MAC address can be used for internet packet
routing, this allows messages to be moved through the network to a specific device. If multiple
devices share the same MAC address, packets may be directed to the wrong device.

Just like a serial number, **DragonBoard 410c** devices are also given a unique MAC address
during production. This 12-digit address is printed on a sticker, and can be found below the
analog expansion header on the reverse side of your board.

### Acronyms, abbreviations, and terms

|       Term          |                     Definition                                   |
|:--------------------|:-----------------------------------------------------------------|
| MAC                 | Media Access Control                                             |
| OTA                 | Over The Air                                                     |
| WLAN                | Wireless Local Area Network                                      |

***

## WiFi MAC Address Programming

This Wi-Fi MAC address programming section describes how to write the MAC address to the
DragonBoard 410c device manually in order to have a unique MAC address.

### Android - Setting the Wi-Fi MAC address on DragonBoard 410c

Each board needs a unique MAC address so the network can talk to a specific board. You need to
set the MAC address for your board. You can find the MAC address on a sticker on the back of
the board. The MAC address will be 12 characters long, where the characters are from `0-9` and `AF`.
There may be colon `:` characters between pairs of characters.

**To set the Wi-Fi MAX address:**

##### Step 1: Turn the board "ON", turn the Wi-Fi "OFF".
##### Step 2: Connect the host computer to the DragonBoard 410c using a USB to MicroUSB cable, and run the following commands:

```shell
adb devices
adb root
adb remount
adb pull /data/misc/wifi/WCNSS_qcom_cfg.ini
```

##### Step 3: With a local editor, edit the file WCNSS_qcom_cfg.ini and change the MAC address:

```shell
# Each byte of MAC address is represented in Hex format as XX
Intf0MacAddress=8CFDF00123EA
Intf1MacAddress=8CFDF00123E9
Intf2MacAddress=8CFDF00123E8
Intf3MacAddress=8CFDF00123E7
```

> NOTE: The `Intf0MacAddress` should match the address printed on your board (all uppercase letters,
with the colons removed). The last character of the remaining addresses should each be one letter
or digit smaller that the preceding one.

##### Step 4: Write the MAC address back to the board and reboot

```shell
adb push WCNSS_qcom_cfg.ini /data/misc/wifi/
adb reboot
```

##### Step 5: Use one of the following methods to confirm the MAC address has been changed (you have
the option to check via the DragonBoard 410c connected display or through your host
computer command line).

- **Option 1:** On the board, look at the Wi-Fi advanced settings and ensure that your MAC
address is correct (as seen on the sticker).

<img src="https://i.imgur.com/ba1mIqK.png" data-canonical-src="https://i.imgur.com/ba1mIqK.png" width="850" height="480" />

- **Option 2**: This method allows you to continue working in the shell (through the host
computer) without needing to hook up a display or mouse to confirm the changed MAC
address.
   - Ensure the DragonBoard 410c device Wi-Fi is connected.
   - From Android shell run: netcfg.

netcfg provides information on the current status of a specific WLAN/Ethernet
interface. The output will include information such as:

`$ wlan0 UP [IP] [NETMASK] [MAC], etc.`

<img src="https://i.imgur.com/9Pk0swl.png" data-canonical-src="https://i.imgur.com/9Pk0swl.png" width="850" height="150" />

***

### Linux - Setting the Wi-Fi MAC address on DragonBoard 410c

If you are running Linux based Ubuntu release 15.07 or newer, your board should already be
equipped with a unique MAC address. Therefore, you should not experience a random MAC
address issue, as with prior releases. Instructions below are only relevant for those who wish to
use the DragonBoard 410c assigned MAC address. You can find the DragonBoard 410c MAC
address on a sticker on the back of your board. The MAC address will be 12 characters long,
where the characters are from 0-9 and A-F. There may be colon ':' characters between pairs of
characters.

To set the Wi-Fi MAC Address

##### Step 1: From a command prompt, run the following command (MAC address is in lowercase):

```shell
sudo su
echo "8d:fd:f0:01:22:d7" > /lib/firmware/wlan/macaddr0
```

Run the ‘echo’ command once, using the MAC address from the sticker on the DragonBoard
410c device.

##### Step 2: Reboot the device.
##### Step 3: Validate the MAC address across reboots by entering the following command:

`root@linaro-developer:~$ ifconfig wlan0`

Observe the print out and confirm the MAC address.

```shell
wlan0     Link encap:Ethernet WHaddr 8d:fd:f0:01:22:d7
          inet addr:A:B:C:D Bcast:E:F:G:H Mask:I:J:K:H
          inet6 addr: fe00::8efd:f0ff:fe01:7a5b/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST MTU:1500 Metric:1
          RX packets:22 errors:0 dropped:0 overruns:0 frame:0
          TX packets:22 errors:0 dropped:0 overruns:0 carrier:0
          Collisions:0 txqueuelen:1000
          RX bytes:8264 (8.2 KB) TX bytes:8145 (8.1 KB)
```

> NOTE: If you are unable to follow this procedure, re-image your DragonBoard 410c device and repeat
this section.

For Linux based Ubuntu 15.07 and newer, if this procedure is not followed, onboard software
will generate a MAC address for you. This MAC address is expected to be unique and should not
cause any issues.

For Linux based Ubuntu older than 15.07, if this procedure is not followed, onboard software
will recognize that the MAC address has not yet been set. A temporary MAC address will be
generated, which is not guaranteed to be globally unique. The use of this address may cause
unexpected behaviors when accessing a network
