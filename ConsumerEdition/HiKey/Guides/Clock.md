---
title: Clock Guide for HiKey
permalink: /documentation/ConsumerEdition/HiKey/Guides/Clock.md/
---
# Clock

The HiKey board does not support a battery powered RTC. System time will be obtained from the network if available. If you are not connecting to a network you will need to manually set the date on each power up or use fake-hwclock:
```
$ sudo apt-get install fake-hwclock
```
