# Qt Cross-Compile Setup for DragonBoard 410C

If you're curious, I came up with this process by following these sources:

https://wiki.qt.io/RaspberryPi2EGLFS

http://wiki.qt.io/Building_Qt_5_from_Git

This tutorial uses Ubuntu 18.04 as the Host PC operating system, and is designed to configure Qt cross compiling for the Linaro Debian OS on DragonBoard 410C. The following process was conducted using the developer version of Linaro Debian (non-desktop version), but these steps should work on the desktop version too. At the time of this tutorial, Qt 5.11 is the most recent version and that's the one we'll be using.

**[Host PC]**
= Run command on host PC

**[DragonBoard]**
= Run command on DragonBoard

## Set Up DragonBoard
**[DragonBoard]**
First off, get your board updated to latest packages. The "apt-mark hold" is there because I have found bugs when not holding the kernel before upgrading. Replace "4.14.0" with your version of the kernel.
```
sudo apt-mark hold linux-image-4.14.0-qcomlt-arm64
sudo apt-get update -y
sudo apt-get upgrade -y
sudo apt-get dist-upgrade -y
```
Install Qt dependencies on DragonBoard:
```
sudo apt-get build-dep -y qt4-x11
sudo apt-get build-dep -y libqt5gui5
sudo apt-get install -y libudev-dev libinput-dev libts-dev libxcb-xinerama0-dev libxcb-xinerama0
sudo mkdir /usr/local/qt5dragon
sudo chown linaro:linaro /usr/local/qt5dragon
```
## Set Up Host PC
**[Host PC]**
First, make a directory that we'll be working in, I called mine "linaro".
```
mkdir linaro
cd linaro
```
### Setting up the Sysroot
**[Host PC]**
Make a sysroot directory and pull the /lib and /usr directories that we need from the DragonBoard. My DragonBoard's IP address is 10.42.0.61, but replace that with yours.
```
mkdir sysroot sysroot/usr
rsync -avz linaro@10.42.0.61:/lib sysroot
rsync -avz linaro@10.42.0.61:/usr/include sysroot/usr
rsync -avz linaro@10.42.0.61:/usr/lib sysroot/usr
```
We need to make the symlinks in the sysroot to be relative. Download this script and run it with the "sysroot" directory as the argument.
```
wget https://raw.githubusercontent.com/riscv/riscv-poky/priv-1.10/scripts/sysroot-relativelinks.py
chmod +x sysroot-relativelinks.py
./sysroot-relativelinks.py sysroot
```
### Download Cross Compiler
**[Host PC]**
Download the Linaro cross-compile toolchain
```
wget https://releases.linaro.org/components/toolchain/binaries/latest/aarch64-linux-gnu/gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu.tar.xz
tar -xf gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu.tar.xz
```
### Download Qt5
**[Host PC]**
We are going to clone the Qt5 super module and download the modules we need (you can download other modules if you want).
```
git clone https://code.qt.io/qt/qt5.git
cd qt5
./init-repository -f --module-subset=default,-qtwebkit,-qtwebkit-examples,-qtwebengine
```
### Custom mkspec
**[Host PC]**
Qt uses device "mkspecs" to configure qmake to your hardware. The DragonBoard does not have a built-in mkspec, so we have to make our own. The mkspec defines what compiler to use, where to find the OpenGL and EGL graphics libraries, etc.


Here is a sample mkspec I made that works with the DragonBoard. First, we need to make a mkspec folder.
```
mkdir linux-dragonboard/
cd linux-dragonboard
```
Make a "qmake.conf" file inside the "linux-dragonboard" directory with the following contents:
```
nano qmake.conf
```
qmake.conf:

**IMPORTANT: Change the SYSROOT variable to your sysroot path, i.e. "/your-path-to-linaro/sysroot"**
```
# qmake configuration for the Dragonboard 410C

MAKEFILE_GENERATOR      = UNIX
CONFIG                 += incremental
QMAKE_INCREMENTAL_STYLE = sublib

include(../common/linux_device_pre.conf)

SYSROOT = /media/hdd/linaro/sysroot
LIB_PATH = $${SYSROOT}/usr/lib/aarch64-linux-gnu

QMAKE_LFLAGS+=-fuse-ld=gold
QMAKE_LFLAGS           += -Wl,-rpath-link,$${SYSROOT}/usr/lib/aarch64-linux-gnu
QMAKE_LFLAGS           += -Wl,-rpath-link,$${SYSROOT}/usr/lib
QMAKE_LFLAGS           += -Wl,-rpath-link,$${SYSROOT}/lib/aarch64-linux-gnu

QMAKE_LIBDIR_EGL        = $${LIB_PATH}
QMAKE_LIBDIR_OPENVG     = $${LIB_PATH}

QMAKE_INCDIR_OPENGL = $${SYSROOT}/usr/include/GLES2
QMAKE_LIBDIR_OPENGL = $${LIB_PATH}
QMAKE_INCDIR_EGL        = $${SYSROOT}/usr/include/EGL

QMAKE_LIBS_EGL          = -lEGL -lGLESv2

include(../common/linux_device_post.conf)

load(qt_config)
```
Make a "qplatformdefs.h" inside "linux-dragonboard" with the following contents:
```
nano qplatformdefs.h
```
qplatformdefs.h:
```
/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the qmake spec of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "../../linux-g++/qplatformdefs.h"
```

Copy mkspec directory to "qt5/qtbase/mkspecs/devices"
```
cp -r linux-dragonboard/ qt5/qtbase/mkspecs/devices/
```
### Build Qt
**[Host PC]**
Make out-of-source build folder in "linaro" directory. We do this to make it easy to restart the build if it fails.
```
mkdir qt5-build
cd qt5-build
```
Run configure script in out-of-source build folder:

**IMPORTANT: Change CROSS_COMPILE path to be the path to your "linaro" directory, i.e. change "/media/hdd/" to "/your-path-to-linaro/"**
```
../qt5/configure -release -opengl es2 -device linux-dragonboard \
-device-option CROSS_COMPILE=/media/hdd/linaro/gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu- \
-sysroot /media/hdd/linaro/sysroot -opensource \
-confirm-license -make libs -prefix /usr/local/qt5dragon \
-extprefix /media/hdd/linaro/qt5dragon \
-hostprefix /media/hdd/linaro/qt5-qmake -v -nomake examples -nomake tests
```
If the configure script runs without error, then compile and install. Replace the "8" in -j8 with however many threads your host PC has.
```
make -j8
make install
```
If you encounter any errors, you can delete everything in the "qt5-build" directory and try again. Make sure your paths are correct, that would be the most common error.

### Send Qt to DragonBoard
**[Host PC]**
Deploy compiled Qt files to DragonBoard.
```
rsync -avz qt5dragon linaro@10.42.0.61:/usr/local
```
**[DragonBoard]**
If you are running the developer version of Linaro Debian, you might want to install xorg so your Qt apps can actually communicate with the X server. If you are running the desktop version, this shouldn't be necessary.
```
sudo apt-get install -y xorg
```

### Test Out a Qt app
**[Host PC]**
Build an example app to try to run. As usual, replace "/media/hdd" with your path to the "linaro" directory. Change the "8" in -j8 to however many threads your host PC has.
```
cd qt5/qtbase/examples/opengl/qopenglwidget
/media/hdd/linaro/qt5-qmake/bin/qmake
make -j8

scp qopenglwidget linaro@10.42.0.61:/home/linaro
```

**[DragonBoard]**
Run the app on the DragonBoard. Make sure you have a display connected to HDMI, you can use ssh X forwarding instead if you want (ssh -X), I have tried it but the frame rate is very slow. If you're running the developer version of Linaro, you'll want to run "sudo startx" if X has not already started.
```
./qopenglwidget
```
## Set up Qt Creator
**[Host PC]**
You can set up Qt Creator to automatically deploy the app to the DragonBoard. I'm copying this process directly from the Qt Wiki.

**IMPORTANT: Change the paths to your actual path, i.e. change "/media/hdd" to "/your-path-to-linaro/"**

```
Go to Options -> Devices -> Devices
  Add
    Generic Linux Device
    Enter IP address, user & password
    Finish
```
```
Go to Options -> Kits -> Compilers
  Add
    GCC -> C
    Compiler path: /media/hdd/linaro/gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc
  Add
    GCC -> C++
    Compiler path: /media/hdd/linaro/gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++
```
```
Go to Options -> Kits -> Debuggers
  Add
    /media/hdd/linaro/gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gdb
```
```
Go to Options -> Kits -> Qt Versions
  Add
    /media/hdd/linaro/qt5-qmake/bin/qmake
```
```
Go to Options -> Kits -> Kits
  Add
    Generic Linux Device
    Device: the one we just created
    Sysroot: /media/hdd/linaro/sysroot
    Compiler: the one we just created
    Debugger: the one we just created
    Qt version: the one we just created
    Qt mkspec: leave empty
```
In your project .pro file, make sure to have the lines:
```
target.path = /home/linaro/
INSTALLS += target
```
Now when you choose your new Kit as the build option in Qt, and click Run, the executable will be transfered to the path on the DragonBoard specified by "target.path".
