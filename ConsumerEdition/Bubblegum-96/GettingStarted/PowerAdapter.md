---
title: Power Adapter for Bubblegum-96
permalink: /documentation/ConsumerEdition/Bubblegum-96/GettingStarted/PowerAdapter.md/
---
## Power Adapter

The 96Boards Consumer Edition boards require a 8-18V 2A power supply.

We recommend a 12V, 2A adapter with a DC plug which has a 4.75 mm outer diameter with 1.7mm center pin (EIAJ-3 Compliant).

Easiest way to prepare your AC adapter for 96Boards is to have the following:

(1) AC adapter which has 12V 2A DC output with DC plug has 5,5 diameter and 2.1 mm center pin. (Center pin positive)

(2) DC plug converter from 5,5 diameter with 2.1 mm center pin to 4.75mm diameter with 1.7mm center pin.

***

Many low cost boards use the ubiquitous microUSB cable to deliver 5V power. However, this limits the power capability to only 500mA at 5V by original official USB specification, which is less than 3W (https://en.wikipedia.org/wiki/USB#Power). As more powerful SoCs become available, peak power requirements for the SoC alone can easily exceed 5W.

We therefore require an external power supply. In order to minimize the board height profile while maximizing the power available we specified to use an EIAJ-3 compliant DC plug available up to 2A, which is 4.75 mm outer diameter with 1.7mm center pin (4.75/1.7), for the power supply (https://en.wikipedia.org/wiki/EIAJ_connector). For an embedded product, power can alternatively be provided over the low speed expansion bus. (Note: this paragraph has been extracted from the 96Boards Specification.)

Other types of DC plug commonly used have a 5.5 mm outer diameter with 2.1mm center pin (5.5/2.1).

This page lists out powers supplies with both 4.75/1.7 and 5.5/2.1 connectors plus some 5.5/2.1 to 4.75/1.7 converters that are required if you have a 5.5/2.1 power supply.

The below is more detailed information about selecting the correct DC plug and jack for 96Boards.

There are three commonly used DC plug/jack in most consumer products.

Outer diameter 5.5mm and a 2.1mm center barrel (5.5/2.1)
Outer diameter 5.5mm and a 2.5mm center barrel (5.5/2.5)
Outer diameter 4.75mm and a 1.7mm center barrel (4.75/1.7 EIAJ-3 compliant)
And also there are two type of each, (a) center pin positive and (b) center pin negative. The center negative is commonly considered not a good practice but some products uses outer shield for 5V or 12V and the center pin for ground, while most of the AC adapters are opposite, the outer shield is ground and the center pin is 5V or 12V. If you plug the AC adapter with center negative which has outer positive to the 96boards, it will burn out the 96boards products.

There is an EIAJ-2 plug that has an outer diameter of 4.75mm and a 1.7mm center barrel (4.0/1.7). The 4.0/1.7 EIAJ-2 plug is able to insert into 4.75/1.7 EIAJ-3, but it will cause the outer shield to have weak connection and make the board unstable.

Also, the 5.5/2.5 DC plug is able to insert to 5.5/2.1 jack on 5.5/2.1 to 4.75/1.7 converters but it will have weak center pin connection and make the 96Boards unstable.

In the 96boards specification, it uses 4.75/1.7 EIAJ-3 and center pin positive.

We strongly advise to check your plug is correct as follows:

Use DC plug has 4.75/1.7 EIAJ-3.
Or use plug converter from 5.5/2.1 to 4.75/1.7 EIAJ-3 plug.
Make sure the polarity is center pin positive.
