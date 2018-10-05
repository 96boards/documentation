---
title: Serial Console
permalink: /documentation/enterprise/ficus/guides/serial-console.md.html
---

ROCK960 exports a dedicated serial console, which can access the low level debug message.

## Requirement

 * ROCK960
 * 12V/2A DC 4.0 power adapter
 * [USB to TTL serial cable](https://store.vamrs.com/products/usb-to-ttl-cable)
 * Host PC with Windows or Linux


**Note**:

* The default baudrate of ROCK960 is 1500000(1.5Mbps), please check if your USB to TTL cable support 1.5Mbps baudrate. Some model of [CP210X](https://www.silabs.com/products/interface/usb-bridges) and [PL2303x](http://www.prolific.com.tw/US/ShowProduct.aspx?pcid=41) has baudrate limitation, please check the specified model. We also tested that some cheap PL2303x based cable does not work well. Make sure choose a high quality one. The instructions below use a [FT232RL](http://www.ftdichip.com/Products/ICs/FT232R.htm) based cable.

* It seems the serial tool on macOS platform can not support custom baudrate such as 1.5Mbps due to driver restriction, if you know how to set custom baudrate on macOS, please send pull requrest to update the documents.

    `/bin/stty -f /dev/cu.usbserial-14430   1500000`

    `stty: tcsetattr: Invalid argument`



## Connect

Connect the USB to TTL serial cable as below:

    RX     <---->    GREEN
    TX     <---->    WHITE
    GND    <---->    BLACK

<img src="../additional-docs/images/images-guides/serial-connection.jpg" data-canonical-src="" width="600" />

**Warn**:
*Don't connect the red wire.*

## Serial setting on host PC

The default serial setting for ROCK960 u-boot and kernel console is:

    baudrate: 1500000
    data bit: 8
    stop bit: 1
    parity  : none
    flow control: none

### Linux

Minicom is a the serial tool that supports wide range baud rate.

Install minicom:

    sudo apt install minicom

Plug in the USB to TTL cable, kernel `dmesg | tail` should show the following device:

	[  244.443685] usbserial: USB Serial support registered for FTDI USB Serial Device
    [  244.443729] ftdi_sio 3-2:1.0: FTDI USB Serial Device converter detected
    [  244.443782] usb 3-2: Detected FT232BM
    [  244.445317] usb 3-2: FTDI USB Serial Device converter now attached to ttyUSB0


**/dev/ttyUSB0** is our device here.

Run

    sudo minicom -D /dev/ttyUSB0

<pre>

Welcome to minicom 2.7

OPTIONS: I18n
Compiled on Feb  7 2016, 13:37:27.
Port /dev/ttyUSB0, 08:13:38

Press CTRL-A Z for help on special keys

            +-----[configuration]------+
            | Filenames and paths      |
            | File transfer protocols  |
            | Serial port setup        |
            | Modem and dialing        |
            | Screen and keyboard      |
            | Save setup as dfl        |
            | Save setup as..          |
            | Exit                     |
            +--------------------------+



CTRL-A Z for help | 1500000 8N1 | NOR | Minicom 2.7 | VT102 | Offline | ttyUSB0

</pre>

Press `Ctrl+A` and then `O`(press Ctrl key and A key at the same time and release, then press O key) to open the configuration menu. Choose **Serial port setup**, and change the setting as following:

<pre>

Welcome to minicom 2.7

OPTI+-----------------------------------------------------------------------+
Comp| A -    Serial Device      : /dev/ttyUSB0                              |
Port| B - Lockfile Location     : /var/lock                                 |
    | C -   Callin Program      :                                           |
Pres| D -  Callout Program      :                                           |
    | E -    Bps/Par/Bits       : 1500000 8N1                               |
    | F - Hardware Flow Control : No                                        |
    | G - Software Flow Control : No                                        |
    |                                                                       |
    |    Change which setting?                                              |
    +-----------------------------------------------------------------------+
            | Screen and keyboard      |
            | Save setup as dfl        |
            | Save setup as..          |
            | Exit                     |
            +--------------------------+




CTRL-A Z for help | 1500000 8N1 | NOR | Minicom 2.7 | VT102 | Offline | ttyUSB0

</pre>

Please note the **E - Bps/Par/Bits** setting, you should use A and B key to find the right baud rate **1500000**.


<pre>

Welcome to minicom 2.7

OPTI+-----------------+---------[Comm Parameters]----------+----------------+
Comp| A -    Serial De|                                    |                |
Port| B - Lockfile Loc|     Current: 1500000 8N1           |                |
    | C -   Callin Pro| Speed            Parity      Data  |                |
Pres| D -  Callout Pro| A: <next>        L: None     S: 5  |                |
    | E -    Bps/Par/B| B: <prev>        M: Even     T: 6  |                |
    | F - Hardware Flo| C:   9600        N: Odd      U: 7  |                |
    | G - Software Flo| D:  38400        O: Mark     V: 8  |                |
    |                 | E: 115200        P: Space          |                |
    |    Change which |                                    |                |
    +-----------------| Stopbits                           |----------------+
            | Screen a| W: 1             Q: 8-N-1          |
            | Save set| X: 2             R: 7-E-1          |
            | Save set|                                    |
            | Exit    |                                    |
            +---------| Choice, or <Enter> to exit?        |
                      +------------------------------------+



CTRL-A Z for help | 1500000 8N1 | NOR | Minicom 2.7 | VT102 | Offline | ttyUSB0

</pre>

#### Recapitulation

<a href="https://asciinema.org/a/164637" target="_blank"><img src="https://asciinema.org/a/164637.png" /></a>
<script src="https://asciinema.org/a/164637.js" id="asciicast-164637" async></script>

### macOS



### Windows
