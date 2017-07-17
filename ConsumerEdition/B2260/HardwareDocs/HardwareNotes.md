---
title: Hardware Notes for B2260
permalink: /documentation/ConsumerEdition/B2260/HardwareDocs/HardwareNotes.md/
---
# Hardware Notes


### CPU Load

The current supplied Linux 4.6-based kernel supports the thermal protection framework and DVFS. If the thermal setpoint of the SoC is reached, the 2*A9/1.5GHz will reduce the core frequencies intelligently or shut down to reduce the power consumption. In an extreme case thermal shutoff will occur if DVFS has not been effective at reducing the SoC temperature to an acceptable level.

Higher performance may be obtained by using forced air (fan) cooling on the B2260 Development Board.

### HDMI Port

The HDMI port on B2260 Development Board supports TVs and Monitors with an HDMI interface 1.4b at display resolutions up to 1080p60. Note that interlaced display modes are not currently supported.

### USB Ports

There are multiple USB ports on the B2260 Development Board:
- One microUSB port on the front edge of the board,
- Two Type A USB 2.0 host ports on the front edge of the board,
- One USB 2.0 host port on the high-speed expansion bus.

Restriction: B2260 doesn't support USB OTG.

### UART Ports

B2260 Development Board supports an UART Port used for debugging over the low-speed expansion bus, the Baud Rate for this interface should be set to 115200.

### Known Issues

None

### Report a Bug

To report new issues with the B2260 Development Board, please send an email to your ST contact.
