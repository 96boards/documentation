/* 
 * led example in c using mraa
 *
 * Author: Manivannan Sadhasivam <manivannan.sadhasivam@linaro.org>
 *
 * Usage: reads maximum brightness value for user1 led and turns it
 * on/off depending on current state. Then sets led trigger to heartbeat
 *
 * Compilation: gcc mraa_led.c -o bin -lmraa
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
#include "mraa/led.h"

#define USER_LED "user1"
#define LED_TRIGGER "heartbeat"

int main(void)
{
	mraa_led_context led;
	mraa_result_t res = MRAA_SUCCESS;
	int val;

	/* initialize user1 led */
	led = mraa_led_init(USER_LED);
	if (led == NULL) {
		fprintf(stderr, "Failed to initialize led: user1\n");
		exit(1);
	}

	/* read maximum brightness */
	val = mraa_led_read_max_brightness(led);
	fprintf(stdout, "maximum brightness value for user1 led is: %d\n", val);
	if (val >= 1)
		val = 0;
	else
		/* never reached mostly */
		val = 1;

	/* turn led on/off depending on max_brightness value */
	res = mraa_led_set_brightness(led, val);
	if (res != MRAA_SUCCESS) {
		fprintf(stderr, "unable to set led brightness\n");
		exit(1);
	}

	/* sleep for 5 seconds */
	usleep(5000000);

	/* set led trigger to heartbeat */
	res = mraa_led_set_trigger(led, LED_TRIGGER);
        if (res != MRAA_SUCCESS) {
                fprintf(stderr, "unable to set led trigger to: heartbeat\n");
                exit(1);
        }

	fprintf(stdout, "led trigger set to: heartbeat\n");

	return 0;
}
