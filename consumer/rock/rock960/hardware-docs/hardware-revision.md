---
title: Hardware Revision for ROCK960
permalink: /documentation/consumer/rock/rock960/hardware-docs/hardware-revision.md.html
redirect_from: /documentation/consumer/rock960/hardware-docs/hardware-revision.md.html
---

# Hardware Revision

Like the software update, the ROCK960 hardware design and production has been updated either to fix minor bugs or improve the hardware performance.

## V1.0

The first hardware revisoin, only few samples are made. The most on board interfaces of this verison are working. The main issue is SYR838 and SYR838 are swapped by mistake.

## V1.1

V1.1 is the test production. 50pcs are produced, most of them are sent to developers and for internal testing purpose. The main issue for this revision is the HDMI connector footprint mismatch since we change to the short HDMI connector.

Change list:

* swap SYR837 and SYR838
* power key and recovery key change to reset key and maskrom key
* debug uart position changed
* HDMI connector changes to short one
* route ethernet mac signal to pcie connector
* change MIPI channel on HS connector

## V1.2

V1.2 is the first production run and first public available batch. We fixed some specification mismatch according to the "96Boards New compliance Self-assessment table".

Some improvements are:

* fix HDMI connector footprint
* optimize heat dispatching
* optimize GPU power routing
* optimize pcie equal length routing
* add pull-up for NC pin in HS connector
* add power measurement resistor
* wifi antenna changed to Rainsun
