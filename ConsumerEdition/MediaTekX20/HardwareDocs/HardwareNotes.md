---
title: Hardware Notes for MediaTek X20
permalink: /documentation/ConsumerEdition/MediaTekX20/HardwareDocs/HardwareNotes.md/
---
# Hardware Notes


### CPU Load

The current supplied Linux 3.18-based kernel supports the thermal protection framework and DVFS. If the thermal setpoint of the SoC is reached, the 2*A72/2.5GHz will reduce the core frequencies intelligently or shut down to reduce the power consumption. In an extreme case thermal shutoff will occur if DVFS has not been effective at reducing the SoC temperature to an acceptable level.

Higher performance may be obtained by using forced air (fan) cooling on the MediaTek X20 Development Board.

### HDMI Port

The HDMI port on MediaTek X20 Development Board supports TVs and Monitors with an HDMI interface at display resolutions of 1920*1080 pixels down to 640*480 pixels. Note that interlaced display modes are not currently supported. The mobile SoC used on the MediaTek X20 Development Board does not have sufficiently flexible clocking arrangements to support allpossible HDMI timings specified by monitors.

Note also that these modes are preferred and will be tried (in this order) first if they exist in EDID:

|   Resolution    |    Ratio    |    Usually on    |
|:------------------------|:-----------------------|:-----------------------|
| 1920*1080            | 16:9           | TV           |           
| 1280*720            | 16:9           | TV           |           
| 720*480         | 4:3           | Monitor           |           

### USB Ports

There are multiple USB ports on the MediaTek X20 Development Board:
   - One microUSB OTG port on the front edge of the board
   - Two Type A USB 2.0 host ports on the front edge of the board
   - One USB 2.0 host port on the high-speed expansion bus

Please read the document MediaTek X20 Development Board-Hardware Manual.pdf for more information on the following hardware restrictions:
   - The microUSB OTG port may be used (in host or slave mode) or the Type A host ports may be used. They may not both be used simultaneously. If a cable is inserted into the OTG port then the Type A ports and the expansion bus port will be automatically disabled.
   - For the microUSB OTG port a single Low Speed (1.5Mbit/sec), Full Speed (12Mbit/sec) or High Speed (480Mbit/sec) device is supported.
   - For the USB host ports all attached USB devices must be one of the following two options:
     - Low Speed (1.5Mbit/sec) and Full Speed (12Mbit/sec) devices, or
     - High Speed devices (480Mbit/sec)

If a mixture of High Speed and Low/Full speed devices are attached the devices will not operate correctly. This also applies if any hubs are attached to the ports.
The reason for this limitation is that USB 2.0 split transfers are not supported by the mobile-targeted SoC hardware USB implementation.

In order to address this limitation the USB ports are by default configured into Low/Full speed operation.

A switch is provided to change between USB 2.0 and USB Hub.

### UART Ports

MediaTek X20 supports a UART Port used for debugging, the Baud Rate for this interface should be set to 921600.

## Known Issues

The following are known issues on the current release.

1. **Not Yet Supported**
   - Expansion bus audio. (At present Bluetooth audio and HDMI are supported)
   - Some video formats are not decoded in Android, and will not be played with the current release.
   - HDMI display sometimes goes off when in AOSP.
2. **Apple Bluetooth Keyboards/Mice/Trackpads do not work.**
   - This is under the current investigation.
3. **Hot plugging an SD card may not work on some UHS class 1 SD cards on AOSP build.**
4. **Display sleep may not always work on AOSP build.**


***

## Report a Bug

To report new issues with the MediaTek please use the [96Boards Bug Tracker](https://bugs.96boards.org).

To view the open bugs, click [here](https://bugs.96boards.org/buglist.cgi?bug_status=__open__&list_id=144&order=Importance&product=HiKey&query_format=specific).  Alternatively go to the [site](https://bugs.96boards.org/), click on the Search menu item, select MediaTek X20 in the product dropdown list and click the search button.

To add a new bug, click [here](https://bugs.96boards.org/enter_bug.cgi?product=HiKey) and fill in the form.  Alternatively go to the [site](https://bugs.96boards.org/), click on the New menu item, then click on Consumer Edition Boards, then click on MediaTek X20, and finally fill in the form.

***
