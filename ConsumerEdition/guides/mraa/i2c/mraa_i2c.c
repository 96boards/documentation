/* 
 * i2c example in c using mraa
 *
 * Author: Manivannan Sadhasivam <manivannan.sadhasivam@linaro.org>
 *
 * Usage: Checks for MPU6050 sensor at I2C bus 0
 *
 * Compilation: gcc mraa_i2c.c -o bin -lmraa
 * 
 */

/* standard headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* mraa header */
#include "mraa/i2c.h"

/* i2c bus */
#define I2C_BUS 0

/* sensor address */
#define MPU6050_ADDR 0x68

/* WHO_AM_I register address */
#define MPU6050_REG_WHO_AM_I 0x75

int main(void)
{
	uint8_t data;
	mraa_result_t status = MRAA_SUCCESS;
	
	/* initialize i2c bus */
	mraa_i2c_context i2c = mraa_i2c_init(I2C_BUS);
	if (i2c == NULL)
		goto err_exit;

	/* set slave address */	
	status = mraa_i2c_address(i2c, MPU6050_ADDR);
	if (status != MRAA_SUCCESS)
		goto err_exit;

	/* read WHO_AM_I register and compare its value */	
	data = mraa_i2c_read_byte_data(i2c, MPU6050_REG_WHO_AM_I);
	if (data & 0x7E != MPU6050_ADDR) {
		fprintf(stderr, "Device not found!\n");
		goto err_exit;
	}

	fprintf(stdout, "MPU6050 found at: 0x%02x\n", data & 0x7E);

err_exit:
	mraa_i2c_stop(i2c);
	return status;
}
