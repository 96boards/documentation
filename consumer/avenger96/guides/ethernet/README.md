---
title: Ethernet Configuration Guide for Avenger96
permalink: /documentation/consumer/avenger96/guides/ethernet/
---

# Configuring Ethernet

When an ethernet cable is plugged into the RJ45 connector, auto-negotiation will start automatically and the network service will try to get IP address over DHCP.

The progress of network card configuration can be checked by executing: `ifconfig eth0`

When eth0 has already received IP address the network connection can be tested by: `ping google.com`
