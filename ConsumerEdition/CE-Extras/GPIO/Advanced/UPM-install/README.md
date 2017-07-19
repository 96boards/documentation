---
title: Install and build MRAA
permalink: /documentation/ConsumerEdition/CE-Extras/GPIO/Advanced/UPM-install/
redirect_from: /documentation/ConsumerEdition/CE-Extras/GPIO/Advanced/UPM-install/README.md/
---
## Install and build UPM

```shell
$ sudo ln -s /usr/bin/swig3.0 /usr/bin/swig
$ git clone https://github.com/intel-iot-devkit/upm.git<Enter>
$ mkdir -p upm/build<Enter>
$ cd upm/build<Enter>
$ cmake -DBUILDSWIGNODE=OFF ..<Enter>
$ make <Enter>
$ sudo make install<Enter>
$ sudo ldconfig /usr/local/lib/libump-*<Enter>
```
Once you have successfully built the library you can either reset the system to pick up all of the changes, or proceed to building another library and reset the system once you are finished.

**Commands:** Reset the system

```shell
$ sudo reboot<Enter>
```

***

When you have you have finished installing and building your library, please proceed to the [Examples - Sample code](../../Examples/) page to begin programming.
