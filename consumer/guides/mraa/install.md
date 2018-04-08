---
title: Guides
permalink: /documentation/consumer/guides/mraa/install.md.html
redirect_from: /documentation/ConsumerEdition/guides/mraa/install.md.html

---

# Installation guide for MRAA library on 96Boards CE

Following instructions provides information about installing the MRAA library as a package and building from source.

## MRAA Overview
**[MRAA](https://iotdk.intel.com/docs/master/mraa/)** (libmraa) is a C/C++ low level skeleton library for communication on GNU/Linux platforms.
It binds to Python, Javascript and Java to interface with the I/O on ARM platforms such as the DragonBoard 820c.
It has a structured and sane API where port names/numbering matches the board that you are on.
Use of libmraa does not tie you to specific hardware with board detection done at runtime you can create portable code that will work across the supported platforms.
MRAA make it easier for developers and sensor manufacturers to map their sensors & actuators on top of supported hardware and to allow control of low level communication protocol by high level languages & constructs.

Recent addition to the MRAA library by **[Manivannan Sadhasivam](https://twitter.com/mani_sadhasivam)** and **[Ivan Farkas](https://twitter.com/ifarkas)** enabled and extended MRAA for the DragonBoard 820c.

## Update 96Boards system

The image on your board might be out of date. This is possible even when using the stock image (the operating system your board was shipped with), or a newly flashed version from the 96Boards.org website.

A few useful commands will help us make sure everything on the board is current:

- **apt-get update**: Downloads package lists from online repositories and "updates" them to get information on the newest versions of packages and their dependencies.
- **apt-get upgrade**: Fetches and installs newest package versions which currently exist on the system. APT must know about these new versions by way of 'apt-get update'
- **apt-get dist-upgrade**: In addition to performing the function of upgrade, this option also intelligently handles changing dependencies with new versions of packages

**Commands:**

```shell
$ sudo apt update && \
  sudo apt upgrade -y && \
  sudo apt dist-upgrade -u -y && \
  sudo apt-get clean && \
  sudo apt autoremove -y
```

## Install as a package

The following command installs MRAA library as a package.

```shell
$ sudo apt-get install -y libmraa-dev
```

## Build from source

Following sections specifies installing MRAA library from source. We build and install dependencies first.
If you want to use legacy nodejs you can skip nodejs and SWIG sections and just get them from their packages.
If you want to be current, than do alls teps as outlined below.

**Install extra tool packages**

```shell
sudo apt-get install -y arduino-mk arduino git build-essential cmake bison doxygen graphviz python-sphinx python3-sphinx libudev-dev libgtest-dev libjson-c-dev autoconf libtool python-dev pkg-config libpcre3-dev
sudo apt-get clean
sudo apt autoremove -y
```

**We install all repos into the git directory to stay organized**

```shell
mkdir git && cd git
```

**Install node and npm**

```shell
curl -sL https://deb.nodesource.com/setup_9.x | sudo bash -
sudo apt-get install -y nodejs
sudo npm i -g npm yuidocjs
sudo npm cache clear --force
sudo apt-get clean
sudo apt autoremove -y
```

**Test**

```shell
node -v
```

**Output**

```shell
v9.11.1
```

**Test**

```shell
npm -v
```

**Output**

```shell
5.8.0
```

## Install Java 9

```shell
sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys C2518248EEA14886
sudo add-apt-repository ppa:webupd8team/java
sudo apt-get update
sudo apt-cache search openjdk-9-*
sudo apt-get install -y openjdk-9-jdk openjdk-9-jdk-headless openjdk-9-jre openjdk-9-jre-headless
```

**Configure Java**

```shell
sudo echo 'export JAVA_HOME=/usr/lib/jvm/java-9-openjdk-arm64' | sudo tee /etc/profile.d/java.sh
sudo echo 'export PATH=$PATH:$JAVA_HOME/bin' | sudo tee -a /etc/profile.d/java.sh
sudo echo '' >> ~/.bashrc
sudo echo '# C, C++ include' >> ~/.bashrc
sudo echo 'export C_INCLUDE_PATH=$C_INCLUDE_PATH:/usr/local/include:/usr/local/include/upm:/usr/local/include/mraa:/usr/lib/jvm/java-9-openjdk-arm64/include:/usr/lib/jvm/java-9-openjdk-arm64/include/linux' >> ~/.bashrc
sudo echo 'export CPLUS_INCLUDE_PATH=$CPLUS_INCLUDE_PATH:/usr/local/include:/usr/local/include/upm:/usr/local/include/mraa:/usr/lib/jvm/java-9-openjdk-arm64/include:/usr/lib/jvm/java-9-openjdk-arm64/include/linux' >> ~/.bashrc
sudo echo 'export LIBRARY_PATH=$LIBRARY_PATH:/usr/lib:/usr/local/lib' >> ~/.bashrc
sudo echo 'export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/lib:/usr/local/lib' >> ~/.bashrc
```

**Reboot**

```shell
sudo reboot
```

**Test**

```shell
java -version
```

**Output**

```shell
Picked up JAVA_TOOL_OPTIONS: -Dgnu.io.rxtx.SerialPorts=/dev/tty96B0
openjdk version "9.0.4"
OpenJDK Runtime Environment (build 9.0.4+12-Debian-4)
OpenJDK 64-Bit Server VM (build 9.0.4+12-Debian-4, mixed mode)
```

## Install and build SWIG library
**[SWIG](http://swig.org/)** is typically used to parse C/C++ interfaces and generate the 'glue code' required for the target languages like C# to call into the C/C++ code.
This will be important to call MRAA and UPM libraries from a .NET Core 2.1 C# program.
 
The current Github version works only with legacy nodejs. We need to apply a patch to bring it up-to-date. 

Remove previous swig package

```shell
sudo apt-get purge -y swig
```

**Get swig from GitHub**

```shell
cd ~/git
git clone --recurse-submodules https://github.com/swig/swig.git
```

**Backup files before applying Node 7.x aka V8-5.2 patch**

```shell
cd swig/Lib/javascript/v8/
cp javascriptcode.swg javascriptcode.swg.bak
cp javascripthelpers.swg javascripthelpers.swg.bak
cp javascriptinit.swg javascriptinit.swg.bak
cp javascriptrun.swg javascriptrun.swg.bak
cd ~/git/swig
```

**swig patch - Add Node 7.x aka V8-5.2 support**

```shell
wget https://git.yoctoproject.org/cgit.cgi/poky/plain/meta/recipes-devtools/swig/swig/0001-Add-Node-7.x-aka-V8-5.2-support.patch
git apply --check 0001-Add-Node-7.x-aka-V8-5.2-support.patch
git apply --index 0001-Add-Node-7.x-aka-V8-5.2-support.patch
git apply --stat 0001-Add-Node-7.x-aka-V8-5.2-support.patch
git commit -m "Add Node 7.x aka V8-5.2 support"
```

**Build**

```shell
./autogen.sh
./configure
make -j 4 && sudo make install
sudo ldconfig /usr/local/lib
sudo ln -s /usr/local/bin/swig4.0 /usr/local/bin/swig
```

**Test**

```shell
swig -version
```

**Output**

```shell
SWIG Version 4.0.0
Compiled with g++ [aarch64-unknown-linux-gnu]
Configured options: +pcre
```

## Install and build Google test library

```shell
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make -j 4
```

**Copy or symlink libgtest.a and libgtest_main.a to your /usr/local/lib folder**

```shell
sudo cp *.a /usr/local/lib
```

**Make sure CMake works**

```shell
sudo su
sed -i '1s/^/\n/' /usr/share/cmake-3.10/Modules/GoogleTest.cmake
sed -i '1s/^/cmake_policy(SET CMP0057 NEW)\n/' /usr/share/cmake-3.10/Modules/GoogleTest.cmake
sed -i '1s/^/cmake_minimum_required (VERSION 3.10)\n/' /usr/share/cmake-3.10/Modules/GoogleTest.cmake
exit
```

**Reboot**

```shell
sudo reboot
```

## Install and build MRAA library

**Get MRAA from GitHub**

```shell
cd ~/git
git clone --recurse-submodules https://github.com/intel-iot-devkit/mraa.git
```

**Setup doxygen2jsdoc**

```shell
cd mraa/doxygen2jsdoc
npm install
```

**Setup doxyport**

```shell
cd ../doxyport
sudo pip install virtualenv
make setup
cd ..
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
 -DBUILDSWIGJAVA=ON \
 -DBUILDSWIGNODE=ON \
 -DBUILDSWIGPYTHON=OFF \
 ..
```

**Build**

```shell
make -j 4 && sudo make install
sudo ldconfig /usr/local/lib
sudo ln -s /usr/lib/python2.7/site-packages/* /usr/lib/python2.7/dist-packages
sudo ln -s /usr/local/lib/python3.6/site-packages/* /usr/lib/python3.6/dist-packages
```
