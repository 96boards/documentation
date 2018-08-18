---
title: Install UPM
permalink: /documentation/consumer/guides/install_upm.md.html
redirect_from:

---

# Installation guide for UPM library on 96Boards CE

Following instructions provides information about installing the UPM library as a package and building from source.

## UPM (Useful Packages & Modules) Overview
**[UPM](https://iotdk.intel.com/docs/master/upm/)** is a high level repository for sensors that use [MRAA](https://iotdk.intel.com/docs/master/mraa/).
Each sensor links to MRAA and are not meant to be interlinked although some groups of sensors may be.
Each sensor contains a header which allows to interface with it.
Typically a sensor is represented as a class and instantiated.
The constructor is expected to initialize the sensor and parameters may be used to provide identification/pin location on the board.
Typically an update() function will be called in order to get new data from the sensor in order to reduce load when doing multiple reads to sensor data.

## Prerequisites
[Installation guide for MRAA library on 96Boards CE](mraa/install.md)

## Install and build modbus library

```shell
cd ~/git
cd ~/git/libmodbus
git clone --recurse-submodules git://github.com/stephane/libmodbus
cd libmodbus
./autogen.sh
./configure
make -j 4 && sudo make install
sudo ldconfig /usr/local/lib
```

## Install and build libbacnet library

```shell
cd ~/git
wget https://sourceforge.net/projects/bacnet/files/bacnet-stack/bacnet-stack-0.8.5/bacnet-stack-0.8.5.zip
unzip bacnet-stack-0.8.5.zip
rm bacnet-stack-0.8.5.zip
cd bacnet-stack-0.8.5
BACDL_DEFINE=-DBACDL_MSTP=1 MAKE_DEFINE=-fPIC make clean all
echo "prefix=/usr/local" > libbacnet.pc
echo "exec_prefix=${prefix}" >> libbacnet.pc
echo "libdir=${exec_prefix}/lib" >> libbacnet.pc
echo "includedir=${prefix}/include" >> libbacnet.pc
echo "Name: bacnet" >> libbacnet.pc
echo "Description: BACnet library" >> libbacnet.pc
echo "Version: 0.8.5" >> libbacnet.pc
echo "Libs: -L${libdir} -lbacnet" >> libbacnet.pc
echo "Cflags: -I${includedir}/bacnet" >> libbacnet.pc
sudo cp libbacnet.pc /usr/local/lib/pkgconfig/libbacnet.pc
sudo cp lib/libbacnet.a /usr/local/lib/libbacnet.a
sudo mkdir /usr/local/include/bacnet
sudo cp include/* /usr/local/include/bacnet/
sudo ldconfig /usr/local/lib
```

## Install and build libopenzwave library
```shell
cd ~/git
git clone --recurse-submodules https://github.com/OpenZWave/open-zwave.git
cd open-zwave
make -j 4 && sudo make install
sudo ldconfig /usr/local/lib
```

## Install and build UPM library

**Get swig from GitHub**

```shell
cd ~/git
git clone --recurse-submodules https://github.com/intel-iot-devkit/upm.git
```

**Setup doxygen2jsdoc**

```shell
cd upm/doxy/doxygen2jsdoc
npm install
```

**Setup doxyport**

```shell
cd ../../doxy/doxyport
sudo pip install virtualenv
make setup
cd ../../
```

**Configure**
Add optional ```-DCMAKE_BUILD_TYPE=DEBUG``` parameter if you want to make a debug build.

```shell
mkdir -p build
cd build
cmake \
 -DCMAKE_INSTALL_PREFIX:PATH=/usr/local \
 -DCMAKE_BUILD_TYPE=DEBUG \
 -DCMAKE_C_COMPILER=/usr/bin/clang-6.0 \
 -DCMAKE_CXX_COMPILER=/usr/bin/clang++-6.0 \
 -DBUILDDOC=ON \
 -DBUILDTESTS=ON \
 -DBUILDSWIGJAVA=ON \
 -DBUILDSWIGNODE=ON \
 -DBUILDSWIGPYTHON=ON \
 ..
```

**Build**

```shell
make -j 4 && sudo make install
sudo ldconfig /usr/local/lib
sudo ln -s /usr/local/lib/python2.7/site-packages/* /usr/lib/python2.7/dist-packages
```
