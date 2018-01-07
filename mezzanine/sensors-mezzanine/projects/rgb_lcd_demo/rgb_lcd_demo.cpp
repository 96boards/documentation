/*
 * Author: Akira Tsukamoto
 * Copyright (c) 2016 Linaro Ltd.
 * All rights reserved.
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <string>
#include "upm/jhd1313m1.hpp"

#define I2C_BUS  0
#define RGB_WHT 0xff,0xff,0xff
#define RGB_RED 0xff,0x00,0x00
#define RGB_GRN 0x00,0xff,0x00
#define RGB_BLU 0x00,0x00,0xff
#define SLEEP_TIME 2

using namespace std;
upm::Jhd1313m1* lcd;

void display(string str1, string str2, int red, int green, int blue)
{
	lcd->clear();
	lcd->setColor(red, green, blue);
	lcd->setCursor(0,0); /* first row */
	lcd->write(str1);
	lcd->setCursor(1,2); /* second row */
	lcd->write(str2);
	sleep(SLEEP_TIME);
}

int main(int argc, char* argv[])
{
	string str1 = "96Boards!";
	string str2 = "Grove Sensors!";
	string str3 = "Linaro!";
	
	lcd = new upm::Jhd1313m1(I2C_BUS, 0x3e, 0x62);

	if ((argc >= 2) && (argv[1] != NULL))
		str1 = argv[1];
	if ((argc >= 3) && (argv[2] != NULL))
		str2 = argv[2];
	if ((argc >= 4) && (argv[3] != NULL))
		str3 = argv[3];

	while (true) {
		display(str1, "Red", RGB_RED);
		display(str2, "Green", RGB_GRN);
		display(str3, "Blue", RGB_BLU);
	}
	delete lcd;
	return 0;
}

