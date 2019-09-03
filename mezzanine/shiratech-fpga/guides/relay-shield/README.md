---
title: Interfacing with Relay Shield
permalink: /documentation/mezzanine/shiratech-fpga/guides/relay/
---

# Hardware
## Hardware Requierments

- **[Any 96Boards CE Board](/products/ce/)**
- **Shiratech FPGA Mezzanine**
- **I2C Shield or Sensor**
  - For the Purpose of this guide I will be using:
    - [Relay Shield for Arduino](https://www.amazon.com/HiLetgo-Relay-Shield-Channel-Arduino/dp/B07F7Y55Z7)

## HArdware Setup

- Connect the Shiratech Mezzanine to the 96Boards CE Development Board
- Connect the Relay shield on the FPGA Mezzanine's Arduino Header

## Software setup

- **[Install MRAA on 96Boards CE](https://youtu.be/c8b6pcc6H2c)**
- **[Download FPGA Mezzanine Library](fpga-mezzanine-library/)**
- Paste the following code into a file named relay.c
```C
/*
// Title: relay.c
// Author: Sahaj Sarup
// Copyright (c) 2019 Linaro Limited
*/

#include <stdio.h>
#include <stdlib.h>

/* mraa header */
#include "mraa/i2c.h"
#include "fpga_mezz.h"

int main()
{
    /*Initialise MRAA I2C*/
    mraa_result_t status = MRAA_SUCCESS;
    mraa_i2c_context i2c;
    mraa_init();


    i2c = mraa_i2c_init(I2C_BUS);

    /*Use I2C Bus0 for FPGA Mezzzanine*/
    int input, ver;

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
        /* Sequentially toggle each relay on and off. */
        digitalWrite(7,LOW,i2c);
        sleep(1);
        digitalWrite(7,HIGH,i2c);
        sleep(1);
        digitalWrite(6,LOW,i2c);
        sleep(1);
        digitalWrite(6,HIGH,i2c);
        sleep(1);
        digitalWrite(5,LOW,i2c);
        sleep(1);
        digitalWrite(5,HIGH,i2c);
        sleep(1);
        digitalWrite(4,LOW,i2c);
        sleep(1);
        digitalWrite(4,HIGH,i2c);
        sleep(1);
    }
}

```
- Compile using: `gcc relay.c <path-to-fpga_mezz_lib>/src/fpga_mezz.c -o relay -I<path-to-fpga_mezz_lib>/include/`
- Run using: `sudo ./relay`
    - All four relays should turn on and off, one at a time.
