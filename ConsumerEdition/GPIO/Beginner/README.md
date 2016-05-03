# Beginner Guide

96Boards enabled pre-built libraries are easy to get, and in some cases might already be included in your current build image. This beginner's guide will show you how to set up, and use your libraries to program the various GPIO interfaces located on the low-speed expansion header of your 96Boards.

Before jumping into this guide, it is recommended to go through the [Low-Speed Expansion Header](../LSExpansionHeader/README.md) document. Readers can use this document to become more familiar with the physical locations of various GPIO interfaces.

***

## Contents

- [Update 96Boards system](#update-96boards-system)
- [Install package dependencies](#install-package-dependencies)
- [Install 96Boards configuration files](#install-96boards-configuration-files)
- [Install Libraries](#install-libraries)

***

## Update 96Boards system

The image on your board might be out of date. This is possible even when using the stock image (the operating system your board was shipped with), or a newly flashed version from the 96Boards.org website. 

A few useful commands will help us make sure everything on the board is current:

- **apt-get update**: Downloads package lists from online repositories and "updates" them to get information on the newest versions of packages and their dependencies.
- **apt-get upgrade**: Fetches and installs newest package versions which currently exist on the system. APT must know about these new versions by way of 'apt-get update'
- **apt-get dist-upgrade**: In addition to performing the function of upgrade, this option also intelligently handles changing dependencies with new versions of packages

**Commands:**

```shell
$ sudo apt-get update

$ sudo apt-get upgrade

$ sudo apt-get dist-upgrade
```

Note: If at any point during this process you are prompted with a 'Y/N', select Y and press Enter.

***

## Install package dependencies

Building the GPIO libraries is easy as long all the necessary tools are present. Installing all the package dependencies is a crucial step which will ensure our libraries build properly

**Package dependencies list:**

- **git**: A version control system which is widely used for software development and other version control tasks
- **build-essential**: This package contains an informational list of packages which are considered essential for building Debian packages
- **autoconf**: A tool for producing shell scripts which automatically configure software source code packages to adapt to many kinds of Posix-like systems
- **automake**: A programming tool to automate parts of the compilation process
- **libtool**: An important portability utility. It gives a common interface to the mechanics of building, debugging and maintaining static and dynamic libraries on most computer systems in use
- **swig3.0**: A software development tool that connects programs written in C and C++ with a variety of high-level programming languages
- **python-dev**: Contains the header files you need to build Python extensions
- **nodejs-dev**: A JavaScript runtime built on Chrome's V8 JavaScript engine
- **cmake**: A Makefile generator
- **pkg-config**: A computer program that provides a unified interface for querying installed libraries for the purpose of compiling software from its source code
- **libpcre3-dev**: This is a library of functions to support regular expressions whose syntax and semantics are as close as possible to those of the Perl 5 language

**Commands:**

```shell
$ sudo apt-get install git build-essential autoconf automake libtool swig3.0 python-dev nodejs-dev cmake pkg-config libpcre3-dev

$ sudo apt-get clean
```

Note: If at any point during this process you are prompted with a 'Y/N', select Y and press Enter.

***

## Install 96Boards configuration files

As root and using your favorite text editor edit /etc/profile.d/96boards-sensors.sh and add/update the following lines (This example uses “vi” text editor):


**Step 1:** Using git, clone the 96Boards-tools repository to your device and copy the respective files to your '/etc/udev/' directory

```shell
$ git clone https://github.com/96boards/96boards-tools.git

$ sudo cp 96board-tools/70-96boards-common.rules /etc/udev/rules.d/
```

**Step 2:** As root, and using your favorite text editor, edit /etc/profile.d/96boards-sensors.sh and add the following lines (This example uses “vi” text editor):

```shell
#EDIT THIS FILE
$ sudo vi /etc/profile.d/96boards-sensors.sh
```

```shell
#ADD THESE LINES
export JAVA_TOOL_OPTIONS=”-Dgnu.io.rxtx.SerialPorts=/dev/tty96B0”
export MONITOR_PORT=/dev/tty96B0
export PYTHONPATH=”$PYTHONPATH:/usr/local/lib/python2.7/site-packages”
```

```shell
#COPY FILE TO NEW LOCATION
$ sudo cp /etc/profile.d/96boards-sensors.sh /etc/X11/Xsession.d/96boards-sensors
```

***

## Install Libraries

This sections will show you how to install each library individually. Simple choose the library you wish install and execute the appropriate command

**libsoc**:

```shell
$ sudo apt-get install libsoc
```

**MRAA**:

```shell
$ sudo apt-get install mraa
```

**UPM**:

```shell
$ sudo apt-get install upm
```
