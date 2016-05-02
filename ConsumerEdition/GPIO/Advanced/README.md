# Advanced Guide

In this guide you will learn where to acquire, and how to build the various 96Boards enabled libraries such as 96BoardsGPIO, libsoc, mraa, and UPM. Users who are interested in building their own libraries should be comfortable with building from source, and should already be familiar with the 96Boards hardware.

Before jumping to the library installation sections, you must first set up your 96Boards device with an up-to-date package list, the appropriate package dependencies, and configuration files. 

***

## Contents

- [Update 96Boards system](update-96boards-system)
- [Install package dependencies](install-package-dependencies)
- [Install 96Boards configuration files](install-96boards-configuration-files)
- [Install Libraries](install-libraries)
- [Examples - Sample code](examples---sample-code)


***

## Update 96Boards system

The image on your board might be out of date. This is possible even when using the stock image (the operating system your board was shipped with), or a newly flashed version from the 96Boards.org website. 

A few useful commands will help us make sure everything on the board is current:

- **apt-get update**: Downloads package lists from online repositories and "updates" them to get information on the newest versions of packages and their dependencies.
- **apt-get upgrade**: Fetches and installs newest package versions which currently exist on the system. APT must know about these new versions by way of 'apt-get update'
- **apt-get dist-upgrade**: In addition to performing the function of upgrade, this option also intelligently handles changing dependencies with new versions of packages

**Commands:**

```shell
$ sudo apt-get update: 
$ sudo apt-get upgrade
$ sudo apt-get dist-upgrade
```

Note: If at any point during this process you are prompted with a 'Y/N', select Y and press <Enter>.

***

## Install package dependencies

***

## Install 96Boards configuration files

***

## Install Libraries

This sections will show you how to install and build each library individually. Simple choose the library you wish to learn about and follow the instructions provided.

Note: 96BoardsGPIO is dependent on the libsoc library, UPM is depended on the MRAA library.

- [libsoc]()
   - 
- [96BoardsGPIO]()
   -
- [MRAA]()
   -
- [UPM]()
   -

***

## Examples

In progress..

***
