/* 
 * gpio example in c++ using mraa
 *
 * Author: Manivannan Sadhasivam <manivannan.sadhasivam@linaro.org>
 *
 * Usage: Toggles GPIO 23 and 24
 *
 * Compilation: g++ mraa_gpio.cpp -o bin -lmraa
 * 
 */

/* standard headers */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* mraa header */
#include "mraa.hpp"

/* gpio starts from 23 as per LS header pinout */
#define GPIO_1 23
#define GPIO_2 24

int flag = 1;

using namespace mraa;

void sig_handler(int signum)
{
	if (signum == SIGINT) {
		fprintf(stdout, "Program interrupted\n");
		flag = 0;
	}
}

int main(void)
{
	Result res;

	/* install signal handler */
	signal(SIGINT, sig_handler);

	/* initialize gpio 23 */
	Gpio gpio_1(GPIO_1);

        /* initialize gpio 24 */
        Gpio gpio_2(GPIO_2);
	
	/* set gpio 23 to output */
	res = gpio_1.dir(DIR_OUT);
	if (res != SUCCESS) {
		printError(res);
        	return -1;
	}

        /* set gpio 24 to output */
        res = gpio_2.dir(DIR_OUT);
        if (res != SUCCESS) {
                printError(res);
                return -1;
        }

	/* toggle both gpio's */
	while (flag) {
		res = gpio_1.write(1);
		res = gpio_2.write(0);

		sleep(1);

		res = gpio_1.write(0);
		res = gpio_2.write(1);

		sleep(1);
	}

	return res;
}
