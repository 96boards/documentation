/* 
 * led example in c++ using mraa
 *
 * Author: Manivannan Sadhasivam <manivannan.sadhasivam@linaro.org>
 *
 * Usage: reads maximum brightness value for user1 led and turns it
 * on/off depending on current state. Then sets led trigger to heartbeat
 *
 * Compilation: g++ mraa_led.cpp -o bin -lmraa
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
#include "mraa/led.hpp"

#define USER_LED "user1"
#define LED_TRIGGER "heartbeat"

using namespace mraa;

int main(void)
{
	Result res;
	int val;

	/* initialize user1 led */
	Led led_1(USER_LED);

	/* read maximum brightness */
	val = led_1.readMaxBrightness();
	fprintf(stdout, "maximum brightness value for user1 led is: %d\n", val);
	if (val >= 1)
		val = 0;
	else
		/* never reached mostly */
		val = 1;

	/* turn led on/off depending on max_brightness value */
	res = led_1.setBrightness(val);
	if (res != SUCCESS) {
		fprintf(stderr, "unable to set led brightness\n");
		exit(1);
	}

	/* sleep for 5 seconds */
	usleep(5000000);
	
	/* set led trigger to heartbeat */
	res = led_1.trigger(LED_TRIGGER);
        if (res != SUCCESS) {
                fprintf(stderr, "unable to set led trigger to: heartbeat\n");
                exit(1);
        }

	fprintf(stdout, "led trigger set to: heartbeat\n");

	return 0;
}
