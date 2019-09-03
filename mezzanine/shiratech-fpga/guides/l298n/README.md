---
title: Interfacing with L298n Motor Controler
permalink: /documentation/mezzanine/shiratech-fpga/guides/l298n/
---

# Hardware
## Hardware Requierments

- **[Any 96Boards CE Board](/products/ce/)**
- **Shiratech FPGA Mezzanine**
- **I2C Shield or Sensor**
  - For the Purpose of this guide I will be using:
    - [L298n Motor Controller Module](https://www.amazon.com/Qunqi-Controller-Module-Stepper-Arduino/dp/B014KMHSW6/)
    - [2x 12v 300rpm Motors](https://www.amazon.com/uxcell-300RPM-Micro-Reduction-Engine/dp/B07N1FJSXY/)

## HArdware Setup

- Connect the Shiratech Mezzanine to the 96Boards CE Development Board
- Wire the L298n Modukle to the Arduino Header in the following manner:

| FPGA Mezzanine Ardiono Header | L298n Motor Controller Module |
|:-----------------------------:|:-----------------------------:|
| 7                             | IN1                           |
| 6                             | IN2                           |
| 5                             | IN3                           |
| 4                             | IN4                           |

## Software setup

- **[Install MRAA on 96Boards CE](https://youtu.be/c8b6pcc6H2c)**
- **[Download FPGA Mezzanine Library](fpga-mezzanine-library/)**
- Paste the following code into a file named l298n.c
```C
/*
// Title: l298n.c
// Author: Sahaj Sarup
// Copyright (c) 2019 Linaro Limited
*/

#include <stdio.h>
#include <stdlib.h>

/* mraa header */
#include "mraa/i2c.h"

#include "fpga_mezz.h"

/*Turn Both Motors Clockwise*/
int front(mraa_i2c_context i2c)
{
    digitalWrite(7, HIGH, i2c);
    digitalWrite(6, LOW, i2c);
    digitalWrite(5, HIGH, i2c);
    digitalWrite(4, LOW, i2c);
}

/*Stop Both Motors*/
int stop(mraa_i2c_context i2c)
{
    digitalWrite(7,LOW,i2c);
    digitalWrite(4,LOW,i2c);
    digitalWrite(6,LOW,i2c);
    digitalWrite(5,LOW,i2c);
}

/*Turn Both Motors Anticlockwise*/
int back(mraa_i2c_context i2c)
{
    digitalWrite(7, LOW, i2c);
    digitalWrite(6, HIGH, i2c);
    digitalWrite(5, LOW, i2c);
    digitalWrite(4, HIGH, i2c);
}

/*Turn Both Motors in Opposite Directions*/
int rot_l(mraa_i2c_context i2c)
{
    digitalWrite(7, LOW, i2c);
    digitalWrite(6, HIGH, i2c);
    digitalWrite(5, HIGH, i2c);
    digitalWrite(4, LOW, i2c);
}

/*Turn Both Motors in Opposite Directions*/
int rot_r(mraa_i2c_context i2c)
{
    digitalWrite(7, HIGH, i2c);
    digitalWrite(6, LOW, i2c);
    digitalWrite(5, LOW, i2c);
    digitalWrite(4, HIGH, i2c);
}

int main()
{
    /*Initialise MRAA I2C*/
    mraa_result_t status = MRAA_SUCCESS;
    mraa_i2c_context i2c;
    mraa_init();

    /*Use I2C Bus0 for FPGA Mezzzanine*/
    i2c = mraa_i2c_init(I2C_BUS);

    int ver;

    if (i2c == NULL) {
        fprintf(stderr, "Failed to initialize I2C\n");
        mraa_deinit();
        return EXIT_FAILURE;
    }

    /* set slave address */
    status = mraa_i2c_address(i2c, FPGA_MEZZI_ADDR);
    if (status != MRAA_SUCCESS) {
    }

    /* Simple Test function to test the I2C Communication */
    if(test(i2c)==0)
    {
        printf("Test Passed\n");
    }
    else
    {
      printf("Test Failed\n");
      return 1;
    }

    /* Check Firmware Revision of the FPGA Mezzanine */
    ver = check_version(i2c);
    if(ver == -1)
    {
      printf("Version Check Error\n");
      return 1;
    }
    else
    {
      printf("Version %d\n",&ver);
    }

    /* Set Pins 7,6,5 and 4 as output */
    pinMode(7,OUTPUT,i2c);
    pinMode(6,OUTPUT,i2c);
    pinMode(5,OUTPUT,i2c);
    pinMode(4,OUTPUT,i2c);


    while(1)
    {
        /* Turn the motors in a set pattern */
        front(i2c);
        sleep(2);
        back(i2c);
        sleep(2);
        rot_l(i2c);
        sleep(2);
        rot_r(i2c);
        sleep(2);
        stop(i2c);
        sleep(5);
    }
}

```
- Compile using: `gcc l298n.c <path-to-fpga_mezz_lib>/src/fpga_mezz.c -o l298n -I<path-to-fpga_mezz_lib>/include/`
- Run using: `sudo ./l298n`
    - Both the motors should turn in one direction, and the opposite directions and repeat the motion.
