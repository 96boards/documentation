---
title: Hardware Revision for ROCK960
permalink: /documentation/consumer/rock/rock960c/hardware-docs/hardware-revision/
---

# Hardware Revision

Like the software update, the ROCK960 hardware design and production has been updated either to fix minor bugs or improve the hardware performance. ROCK960 model C is a completely re-design based on the ROCK960 model A/B. The version number starts from V2.0.

## V2.0

Re-design based on ROCK960 model A/B, the difference are:

* change LPDDR3 to LPDDR4, for longer availability and lower cost
* change USB type C connector to type A and USB 2.0 type A connector to micro B connector
* since USB 3.0 OTG is on type A connector, add a hardware switch for manually device/host switch
* wifi/bt module change to ap6255, still 802.11 ac/a/b/g/n, only 1xMIMO
* remove on board eMMC, adds an eMMC socket connector, compatible with Odroid eMMC connector
* all connectors are changed to SMT footprint, production friendly
* changed the MIPI singal on HS connector to fully compliant with 96boards spec

## V2.1

V2.1 had small fixes for V2.0, and it's the MP version, the changes/improvements are:

* change USB 2.0 host micro B connector to type C connector for model A/B alignment
* add another B2B connector for mechanical mounting of the eMMC module, more stable
* change the switch footprint for better component sourcing
* add a dedicated PCIE power, not shared with system 3.3V
