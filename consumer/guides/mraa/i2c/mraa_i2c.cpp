/* 
 * i2c example in c++ using mraa
 *
 * Author: Manivannan Sadhasivam <manivannan.sadhasivam@linaro.org>
 *
 * Usage: Checks for MPU6050 sensor at I2C bus 0
 *
 * Compilation: g++ mraa_i2c.cpp -o bin -lmraa
 * 
 */

/* standard headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* mraa header */
#include "mraa/i2c.hpp"

/* i2c bus */
#define I2C_BUS 0

/* sensor address */
#define MPU6050_ADDR 0x68

/* WHO_AM_I register address */
#define MPU6050_REG_WHO_AM_I 0x75

using namespace mraa;

int main(void)
{
	uint8_t data;

	/* initialize i2c bus */	
	I2c i2c(I2C_BUS);
	
	/* set slave address */
	i2c.address(MPU6050_ADDR);
	
	/* read WHO_AM_I register and compare its value */
	data = i2c.readReg(MPU6050_REG_WHO_AM_I);
	if (data & 0x7E != MPU6050_ADDR) {
		fprintf(stderr, "Device not found!\n");
		return -1;
	}

	fprintf(stdout, "MPU6050 found at: 0x%02x\n", data & 0x7E);

	return 0;
}
