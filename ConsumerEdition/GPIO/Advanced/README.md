# Advanced Guide

In progres...

***

## Update system

The image on your board might be out of date. This is possible even when using the stock image (the operating system your board was shipped with), or a newly flashed version from the 96Boards.org website. 

A few usefull commands will help us make sure all on-board software is current:

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

## Libraries

In progress...

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

In progress...

- [libsoc]()
   - 
- [96BoardsGPIO]()
   -
- [MRAA]()
   -
- [UPM]()
   -


***
