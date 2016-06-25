# Configuring the wireless TI module (Debian)

Using the right WiFi (TI wl1835mod) module config for HiKey (avoid bugs like https://bugs.96boards.org/show_bug.cgi?id=202)

```shell
root@linaro-alip:~# configure-device.sh 

Please provide the following information.

Are you using a TI module? [y/n] : y
What is the chip flavor? [1801/1805/1807/1831/1835/1837 or 0 for unknown] : 1835
How many 2.4GHz antennas are fitted? [1/2] : 1
Should SISO40 support be applied? [y/n] : n

The device has been successfully configured.
TI Module: y
Chip Flavor: 1835
Number of 2.4GHz antennas fitted: 1
Number of 5GHz antennas fitted: 0
Diversity Support: n
SISO40 Support: n
Japanese standards applied: n
```

Reboot your HiKey and the wireless module should now use the right configuration.
