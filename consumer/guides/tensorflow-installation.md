---
title: Tensorflow Installation Guide
permalink: /documentation/consumer/guides/tensorflow-installation.md.html
redirect_from: /documentation/ConsumerEdition/guides/tensorflow-installation.md.html
---
# Tensorflow Installation Guide

Tensorflow is an open source software library used for computation of data flow graphs, with applications in deep neural networks research and machine learning.
There are many interesting applications for Tensorflow including: [searching and filtering](https://github.com/agermanidis/thingscoop), [art creation](https://github.com/cysmith/neural-style-tf) ,[reinforcement learning](http://www.danielslater.net/2016/03/deep-q-learning-pong-with-tensorflow.html) , and [many more](https://github.com/jtoy/awesome-tensorflow).

This tutorial will describe two ways of installing Tensorflow: By installing and using Bazel (currently only on devices > 2GB), or through the Tensorflow static libraries.
If Tensorflow is installed through the static libraries then Tensorflows Python wrapper will not be included so it cannot be used through Python.

# Table of Contents

- [1) Tensorflow with Bazel](#1-tensorflow-with-bazel)
   - [1.1) Hardware requirements](#11-hardware-requirements)
   - [1.2) Description](#12-description)
   - [1.3) Software Dependencies](#13-software-dependencies)
   - [1.4) Installing Bazel](#14-installing-bazel)
   - [1.5) Tensorflow Installtion](#15-tensorflow-installtion)
- [2) Tensorflow with Static Libraries](#2-tensorflow-with-static-libraries)   
   - [2.1) Hardware Requirements](#21-hardware-requirements)
   - [2.2) Description](#22-description)   
   - [2.3) Software Dependencies](#23-software-dependencies)
   - [2.4) Building Protobuf](#24-building-protobuf)
   - [2.5) Building Tensorflow](#25-building-tensorflow)
- [3) Benchmark Test](#3-benchmark-test)
- [4) Cleaning](#4-cleaning)

***

# 1) Tensorflow with Bazel

## 1.1 Hardware requirements

- Aarch64 bit device > 2GB

## 1.2 Description
To install Tensorflow with the Python wrapper included it is necessary to install the binaries through the use of bazel-0.4.5 or higher. Currently Bazel cannot be installed on 2GB (or less) devices such as the Hikey, Hikey LeMaker addition or DragonBoard, as the compilation will crash due to lack of memory. If you are using an aarch64 bit platform with limited RAM or processing power it may be necessary to compile the core C++ runtime into a static library, as described later in this tutorial.

Bazel is not currently supported for aarch64 bit platforms, so to make it compatible the source file needs to be modified. In order to get Bazel and Tensorflow installed this [tutorial](http://zhiyisun.github.io/2017/02/15/Running-Google-Machine-Learning-Library-Tensorflow-On-ARM-64-bit-Platform.html) describing how to modify the Bazel source file was used, with a slight modification: changing Bazel version 0.4.4 to 0.4.5.

## 1.3 Software Dependencies

```shell
$ sudo apt-get update
$ sudo apt-get upgrade
```

In order to install bazel, JDK 8 is needed. For Ubuntu 15.10 or higher, OpenJDK 8 can be installed; however, for Ubuntu 14.04 or lower install Oracle JDK 8. To install OpenJDK 8 as well as other required tools and libraries run the following:

```shell
$ sudo apt-get install openjdk-8-jdk
$ sudo apt-get install pkg-config zip g++ zlib1g-dev unzip
```

## 1.4 Installing Bazel

First download the Bazel release package

```shell
$ wget https://github.com/bazelbuild/bazel/releases/download/0.4.5/bazel-0.4.5-dist.zip
$ mkdir bazel-0.4.5
$ unzip bazel-0.4.5-dist.zip -d bazel-0.4.5
$ cd bazel-0.4.5
```

Next you must modify the bazel source file to be compatible with aarch64. This [tutorial](http://zhiyisun.github.io/2017/02/15/Running-Google-Machine-Learning-Library-Tensorflow-On-ARM-64-bit-Platform.html) describes the step by step the modifications which must be made to the source code.

After Bazel is installed, you may either continue following the instructions from the Bazel tutorial for installing Tensorflow, or go to the [tensorflow website]( https://www.tensorflow.org/install/install_sources#ConfigureInstallation) and install tensorflow from source.

# 2) Tensorflow With Static Libraries

(no Python bindings)
(Compiled on 96boards Hikey LeMaker edition)

## 2.1 Hardware Requirements

- [Hikey LeMaker Edition 2GB](https://www.96boards.org/product/hikey/)
or
- Aarch64 bit device >= 2GB
- [96Boards Compliant Power Supply](http://www.96boards.org/product/power/)

## 2.2 Description

If you’re installing Tensorflow onto a platform that does not support the installation of Bazel, you can install the core C++ Tensorflow runtimes into a static library.
It is important to note that this static library will not contain Python or other language bindings, and will also not contain GPU support. This guide will allow you to compile Tensorflow and Protobuf libraries which can be linked to other external applications.

The work below is based on the Raspberry Pi installation on the [Static installation guide]( https://github.com/tensorflow/tensorflow/tree/master/tensorflow/contrib/makefile) from github, and it will include details on issues I ran into as well as a benchmark test provided by the above guide.

## 2.3 Software Dependencies

First, clone the Tensorflow repository
```shell
$ git clone https://github.com/tensorflow/tensorflow.git
```

Next you will need to download all of Tensorflow’s dependencies. A script that downloads these dependencies has been provided in the Tensorflow repository which you have downloaded. Run this script from the root of the tensorflow repository.

```shell
$ cd tensorflow
$ tensorflow/contrib/makefile/download_dependencies.sh
```

You should only need to do this step once, and all required libraries will be installed in the tensorflow/contrib/makefile/downloads folder.

You should also download the example graph which is provided by the static installation guide from: https://storage.googleapis.com/download.tensorflow.org/models/inception5h.zip
This graph will be used after Tensorflow has been built in order to verify your installation.

```shell
$ wget https://storage.googleapis.com/download.tensorflow.org/models/inception5h.zip
```

## 2.4 Building Protobuf

In order to build the tensorflow libraries you must install protobuf, this may take a couple hours if running on a 96boards platform. It is useful to note that as long as the green LED904 LED is blinking in heartbeat mode, the program is still running. If at any point the LED has gone solid green or off the program has crashed, and you may need to clean and rebuild.

```shell
$ sudo apt-get install -y autoconf automake libtool gcc-4.8 g++-4.8
$ cd tensorflow/contrib/makefile/downloads/protobuf/
$ ./autogen.sh
$ ./configure
$ make
$ sudo make install
```

Once that is done, and both protobuf and the tensorflow dependencies have been installed, the Tensorflow libraries can be built. The make step may take a few hours if running on a 96boards platform.

## 2.5 Building Tensorflow

```shell
$ sudo ldconfig
$ cd ../../../../..
$ make -f tensorflow/contrib/makefile/Makefile HOST_OS=PI TARGET=PI \
OPTFLAGS="-Os -funsafe-math-optimizations -ftree-vectorize" CXX=g++-4.8
```

# 3) Benchmark Test

In order to run the benchmark and verify that your installation of the Tensorflow C++ static libraries works correctly, you can run the benchmark which is based on the previously downloaded graph.

```shell
$ tensorflow/contrib/makefile/gen/bin/benchmark \
--graph=$HOME/graphs/inception/tensorflow_inception_graph.pb
```

# 4) Cleaning

If you make any changes in the dependencies or wish to install a different version of tensorflow it is important to clean the makefile, as header dependencies are not automatically tracked. To do so run the following command, and then recompile:

```shell
$ make -f tensorflow/contrib/makefile/Makefile clean
```
