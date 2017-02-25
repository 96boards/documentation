## Install and build 96BoardsGPIO

This library requires libsoc to be installed first.

**Commands:**

```shell
$ git clone https://github.com/96boards/96BoardsGPIO.git<Enter>
$ cd 96BoardsGPIO<Enter>
$ ./autogen.sh<Enter>
$ ./configure<Enter>
$ make && sudo make install<Enter>
$ sudo ldconfig /usr/local/lib<Enter>
```
Once you have successfully built the library you can either reset the system to pick up all of the changes, or proceed to building another library and reset the system once you are finished.

**Commands:** Reset the system

```shell
$ sudo reboot<Enter>
```

***

When you have you have finished installing and building your library, please proceed to the [Examples - Sample code](../../Examples/README.md) page to begin programming.
