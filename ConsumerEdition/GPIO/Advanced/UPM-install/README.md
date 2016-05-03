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
