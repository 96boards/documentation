---
title: Description of LED’s and Connectors
permalink: /documentation/consumer/dragonboard410c/guides/led-connectors.md.html
redirect_from:
- /db410c-getting-started/Guides/led-connectors.md/
- /documentation/ConsumerEdition/DragonBoard-410c/Guides/led-connectors.md.html
---
# Description of LED’s and Connectors

Throughout this document, references are made to certain board
connectors, headers and switches.  There are also six activity LEDs on
the board. These items are described further in this section

### Connectors / Switch

```
+----------------------+----------------------+--------------------------+
| Board Identifier     | Description          | Behavior                 |
+----------------------+----------------------+--------------------------+
| J8                   | Low Speed Connector  | This connector contains  |
|                      |                      | low speed peripheral     |
|                      |                      | signals just as UART and |
|                      |                      | GPIO. In context of      |
|                      |                      | this document, we use it |
|                      |                      | for connecting the UART. |
+----------------------+----------------------+--------------------------+
| S6                   | 4 channel Dip Switch | Located on the back of   |
|                      |                      | the board, this Switch   |
|                      |                      | provides some manual     |
|                      |                      | configuration settings.  |
|                      |                      | In context of this       |
|                      |                      | document, it is used to  |
|                      |                      | select boot order (SD    |
|                      |                      | Card first or eMMC       |
|                      |                      | first) OTG modes.        |
|                      |                      |                          |
+----------------------+----------------------+--------------------------+
```

### LEDs

Located by the USB ports are a series of LEDs used to provide
information to the user. Their usage is defined as follows:

#### Debian Images
When Debian-based images are installed, the following table defines the LED usage/behaviors.
```
+----------------------+----------------------+--------------------------+
| LED Board Identifier | Description          | Behavior                 |
+----------------------+----------------------+--------------------------+
| User LED 1           | Heartbeat            | Green: This LED is       |
|                      |                      | should always be         |
|                      |                      | blinking about once a    |
|                      |                      | second. If solid off or  |
|                      |                      | solid on, the board is   |
|                      |                      | not executing correctly  |
+----------------------+----------------------+--------------------------+
| User LED 2           | eMMC                 | Green: This LED blinks   |
|                      |                      | during accesses to eMMC  |
+----------------------+----------------------+--------------------------+
| User LED 3           | SD                   | Green: This LED blinks   |
|                      |                      | during accesses to SD    |
|                      |                      | Card                     |
+----------------------+----------------------+--------------------------+
| User LED 4           | currently unassigned | N/A                      |
+----------------------+----------------------+--------------------------+
| Wifi                 | Wifi                 | Yellow: This LED blinks  |
|                      |                      | during network accesses  |
|                      |                      | over Wifi                |
+----------------------+----------------------+--------------------------+
| BT                   | Bluetooth            | Yellow: This LED blinks  |
|                      |                      | when Bluetooth is being  |
|                      |                      | used                     |
+----------------------+----------------------+--------------------------+
```

#### Android Images
When Android-based images are installed, the following table defines the LED usage/behaviors.

```
+----------------------+----------------------+--------------------------+
| LED Board Identifier | Description          | Behavior                 |
+----------------------+----------------------+--------------------------+
| User LED 1           | currently unassigned | Green:                   |
+----------------------+----------------------+--------------------------+
| User LED 2           | currently unassigned | Green:                   |
|                      |                      |                          |
+----------------------+----------------------+--------------------------+
| User LED 3           | currently unassigned | Green:                   |
|                      |                      |                          |
|                      |                      |                          |
+----------------------+----------------------+--------------------------+
| User LED 4           | Boot                 | This LED illuminates at  |
|                      |                      | at the start of boot     |
|                      |                      | and turns of after       |
|                      |                      | completion of boot.      |
+----------------------+----------------------+--------------------------+
| Wifi                 | Wifi                 | Yellow: TDB              |
+----------------------+----------------------+--------------------------+
| BT                   | Bluetooth            | Yellow: TBD              |
+----------------------+----------------------+--------------------------+
```
