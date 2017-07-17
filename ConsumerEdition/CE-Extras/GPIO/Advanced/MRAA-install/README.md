---
title: Install and build MRAA
permalink: /documentation/ConsumerEdition/CE-Extras/GPIO/Advanced/MRAA-install/
redirect_from: /documentation/ConsumerEdition/CE-Extras/GPIO/Advanced/MRAA-install/README.md/
---
## Install and build MRAA

```shell
$ git clone https://github.com/intel-iot-devkit/mraa.git<Enter>
$ mkdir -p mraa/build<Enter>
$ cd mraa/build<Enter>
$ cmake ..<Enter>
$ make <Enter>
$ sudo make install<Enter>
$ sudo ldconfig /usr/local/lib<Enter>
```

Once you have successfully built the library you can either reset the system to pick up all of the changes, or proceed to building another library and reset the system once you are finished.

**Commands:** Reset the system

```shell
$ sudo reboot<Enter>
```

***

When you have you have finished installing and building your library, please proceed to the [Examples - Sample code](../../Examples/) page to begin programming.
