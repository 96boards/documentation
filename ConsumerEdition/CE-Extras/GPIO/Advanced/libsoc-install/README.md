## Install and build libsoc

**Commands:**

```shell
$ git clone https://github.com/jackmitch/libsoc.git<Enter>
$ cd libsoc<Enter>
$ autoreconf -i<Enter>
$ ./configure --enable-python2 --enable-board=<your board><Enter>
#Where <your board> is dragonboard410c or hikey or another supported board in the future.
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
