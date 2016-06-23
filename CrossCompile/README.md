# How to Cross Compile files on X86 Linux System for 96Boards & libsoc

**Step 1:** Install Ubuntu 16.04 and make sure it’s fully up to date.

**apt-get update:** Downloads package lists from online repositories and "updates" them to get information on the newest versions of packages and their dependencies.
**apt-get upgrade:** Fetches and installs newest package versions which currently exist on the system. APT must know about these new versions by way of 'apt-get update'
**apt-get dist-upgrade:** In addition to performing the function of upgrade, this option also intelligently handles changing dependencies with new versions of packages

**Commands:**

```shell
$ sudo apt-get update
$ sudo apt-get upgrade
$ sudo apt-get dist-upgrade
```

**Step 2:** Install cross compilers

- For ARM 32bit toolchain
   - `$ sudo apt-get install gcc-arm-linux-gnueabihf g++-arm-linux-gnueabihf`
- For ARM 64bit toolchain
   - `$ sudo apt-get install gcc-aarch64-linux-gnu g++-aarch64-linux-gnu`

**Step 3:** Install Dependencies

$ sudo apt-get install build-essential autoconf libtool cmake pkg-config git python-dev swig3.0 libpcre3-dev nodejs-dev

**Step 4:** Create a workspace

**Commands:**

```shell
mkdir hacking
cd hacking
```

**Step 5:** Create a helloworld.c file with your favorite editor and put this in it

```shell
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	puts(“!!!Hello World!!!”);
	return(EXIT_SUCCESS);
}
```

**Step 6:** Compile to x86 file from the command line

`$ gcc helloworld.c -o helloworld.x86`

**Step 7:** Test x86 file

`$ file helloworld.x86`

> Printout should show a X86 binary file

**Step 8:** Run x86 file

`$ ./helloworld.x86`

> Printout should read `!!!Hello World!!!`

**Step 9:** Cross compile to ARM file from the command line

`$ aarch64-linux-gnu-gcc helloworld.c -o helloworld.arm`

**Step 10:** Test ARM file
 
`$ file helloworld.arm`

> Printout should show a aarch64 ARM file

**Step 11:** Copy aarch64 ARM file to a 96Board and run it from Terminal command line, printout should read `!!!Hello World!!!`

**If you got this far congratulations basic cross compiling is working, now let's make it more complex and add a shared library.
For the purpose of the rest of this document we will assume you have installed libsoc and mraa libraries on your 96Board and they are ready to use.**

***

Install libsoc, this will take a bit of doing, as we have to cross compile this library and then manually install it so it does not collide with X86 libraries.

`$ git clone https://github.com/JackMitch/libsoc.git`
`$ cd libsoc`

`$ autoreconf -i`
`$ ./configure --build i686-pc-linux-gnu --host aarch64-linux-gnu --enable-board=dragonboard410c --with-board-configs`
`$ make`

`$ sudo make DESTDIR=/tmp/stage install`
`$ sudo mkdir /usr/local/aarch64-linux-gnu`

`$ sudo mv /tmp/stage/usr/local/* /usr/local/aarch64-linux-gnu/.`

`$ cd test`
`$ cp board_test.c compile_test.c`

`$ aarch64-linux-gnu-gcc -I /usr/local/aarch64-linux-gnu/include/ -L /usr/local/aarch64-linux-gnu/lib/ compile_test.c -o compile_test.arm -lsoc`

Now test it: file compile_test.arm you should see it’s an aarch64 ARM file

Now copy it to a 96board and run it.  It should run.

If you got this far you have command line cross compiling with shared library support installed and working, congratulations.

