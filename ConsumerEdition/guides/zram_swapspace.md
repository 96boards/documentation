---
title: Create Swap Space using ZRAM or RAM Compression
permalink: /documentation/ConsumerEdition/guides/zram_swapspace.md.html
---
# Create Swap Space using ZRAM or RAM Compression

ZRAM enable us to create extra swap space but without the cons of slower speeds due to Hard Drive or SD Card limitations.
It is not as fast as actual RAM, but it is close enough for the speed degradation to not be noticable.

## Hardware

- 96Boards Consumer Edition board (tested with DragonBoard410c)

## Software

- Linaro Debian Operating system snapshot Builds (http://builds.96boards.org/snapshots/)
- If you are not using the DragonBoard410c, you will need to rebuild the kernel using ```CONFIG_ZRAM=m``` and ```CONFIG_ZSMALLOC=m``` Kconfig option.

## Steps

### Create swap script

Feel free to use the text editor of your choice, I'll be using 'nano' fot the rest of this guide.
```shell
sudo nano /usr/bin/zram.sh
```

Now enter the following text, this will create a swap space 3 times that of actual usable memory
```shell
#!/bin/bash
modprobe zram num_devices=4

totalmem=`free | grep -e "^Mem:" | awk '{print $2}'`
mem=$(( ($totalmem)* 1024 * 3))

echo $mem > /sys/block/zram0/disksize

mkswap /dev/zram0

swapon -p 5 /dev/zram0
```

Press 'ctrl+x' to exit and 'y' to save the file.
You can change the amout of zram swap by modifying ```mem=$(( ($totalmem)* 1024 * 3))```


### Next, to make sure the script runs on every boot:

First, Make it executable
```shell
sudo chmod +x /usr/bin/zram.sh
```

Next add it to the rc.local script
```shell
sudo nano /etc/rc.local
```

Add the following line just above ```exit 0```
```shell
/usr/bin/zram.sh &
```
### Reboot

```shell
sudo reboot
```

### That's It!
Enjoy a faster swap, go ahead and try opening multiple chrome tabs and compiling something with ```make -j4``` !!!
