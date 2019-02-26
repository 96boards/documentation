---
title: DMIC Setup Guide for DragonBoard 845c
permalink: /documentation/consumer/dragonboard/dragonboard845c/guides/dmic.md.html
---

# Set up Quad DMICs

- **The board has four DMICs. Use dmic-ctl to perform separate DMIC enable, disable, and record operations**

- **The following example is for DMIC1 (dmic id 0), the same can be used for DMIC2 (dmic id 1), DMIC3 (dmic id 2) and DMIC4 (dmic id 3)**
    - Enable DMIC1: `dmic-ctl 0 enable`
    - Record from DMIC1: `arecord /data/dmic0_test.wav -f S16_LE -c 1 -r 48000 -d 10`
        - The command parameter setting only records for 10 seconds. After 10 seconds, the recording stops.
        - Move the recording file to the PC for playback verification or use a tool like Audacity to view the waveform.
    - Disable DMIC1: `dmic-ctl 0 disable`