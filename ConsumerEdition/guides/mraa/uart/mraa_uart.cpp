/* 
 * uart example in c++ using mraa
 *
 * Author: Manivannan Sadhasivam <manivannan.sadhasivam@linaro.org>
 *
 * Usage: sends "Hello Mraa" string through tty96B0 uart port
 *
 * Compilation: g++ mraa_uart.cpp -o bin -lmraa
 * 
 */

/* standard headers */
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* mraa header */
#include "mraa/uart.hpp"

/* serial port */
#define DEV_PATH "/dev/tty96B0"

using namespace mraa;

int
main(int argc, char** argv)
{
	char buffer[] = "Hello Mraa!";
	
	/* initialize uart tty96B0 */
	Uart uart(DEV_PATH);
	
	/* send data through uart */
	uart.write(buffer, sizeof(buffer));

	return 0;
}
