## Install and build libsoc

In Progress...

**Commands:**

$ git clone https://github.com/jackmitch/libsoc.git<Enter>
$ cd libsoc<Enter>
$ ./autogen.sh<Enter>
$ ./configure --enable-python2 --enable-board=<your board><Enter>
Where <your board> is dragonboard410c or hikey or another supported board in the future.
$ make && sudo make install<Enter>
$ sudo ldconfig /usr/local/lib<Enter>
