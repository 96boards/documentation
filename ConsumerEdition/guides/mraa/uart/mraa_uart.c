/* 
 * uart example in c using mraa
 *
 * Author: Manivannan Sadhasivam <manivannan.sadhasivam@linaro.org>
 *
 * Usage: sends "Hello Mraa" string through tty96B0 uart port
 *
 * Compilation: gcc mraa_uart.c -o bin -lmraa
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
#include "mraa/uart.h"

#ifndef FALSE
#define FALSE 0
#define TRUE (!FALSE)
#endif

#define DEV_PATH "/dev/tty96B0"

int
main(int argc, char** argv)
{
	mraa_uart_context uart;
	mraa_result_t status = MRAA_SUCCESS;
	char buffer[] = "Hello Mraa!";
	
    	int baudrate = 9600, stopbits = 1, databits = 8;
        mraa_uart_parity_t parity = MRAA_UART_PARITY_NONE;
    	unsigned int ctsrts = FALSE, xonxoff = FALSE;
        const char *name = NULL, *dev_path = "/dev/ttyACM0";

	/* initialize uart tty96B0 */
	uart = mraa_uart_init_raw(dev_path);

	if (uart == NULL) {
		fprintf(stderr, "Failed to initialize uart\n");
		return -1;
	}

	/* set serial port parameters */
	status = mraa_uart_settings(-1, &dev_path, &name, &baudrate, &databits, 
			&stopbits, &parity, &ctsrts, &xonxoff);
        if (status != MRAA_SUCCESS) {
		fprintf(stderr, "Failed to setup uart\n");
		return -1;
	}

	/* send data through uart */
	mraa_uart_write(uart, buffer, sizeof(buffer));

	/* stop uart */
	mraa_uart_stop(uart);

	mraa_deinit();

	return 0;
}
