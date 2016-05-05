# Low-Speed Expansion Header

The low-speed expansion header is where all of your GPIO interfaces are located. This particular header is 2x20, 2.0mm pitch, with female pins. This guide will go over the expansion header in as much detail as possible, while providing safe practices when accessing the necessary hardware for GPIO use. 

***

## Contents

- Closer look at the Low-Speed Expansion header
- Safe Practices
- GPIO interfaces


***

## Closer look at the Low-Speed Expansion header

This section will help you locate the low-speed expansion header on your 96Boards.

<a href="" align="left" target="_blank"><img src="http://i.imgur.com/48NCYil.png" data-canonical-src="http://i.imgur.com/48NCYil.png" width="180" height="240" /></a>

<a href="" align="right" target="_blank"><img src="http://i.imgur.com/zo44YPE.jpg" data-canonical-src="http://i.imgur.com/zo44YPE.jpg" width="280" height="220" /></a>

***

## Safe Practices


***

## GPIO Interfaces

**GPIO Defined**

General purpose Input/Output pins or GPIO are pins that go generally unused by default and are said to have no defined special purpose. This means the user maintains decisive control over the GPIO pins and their actions. That being said, these GPIO are capable of performing a variety of user driven actions, most of which will be necessary for this course. Below is a list of potential capabilities of the GPIO pins as seen on
https://en.wikipedia.org/wiki/General-purpose_input/output

- GPIO capabilities may include:
- GPIO pins can be configured to be input or output
- GPIO pins can be enabled/disabled
- Input values are readable (typically high=1, low=0)
- Output values are writable/readable
- Input values can often be used as IRQs (Interrupt), typically for wakeup events

Here it is important to note that the GPIO pins are configurable, and can be set as an input or output. With that, we see values can be written onto, or read from these interfaces (GPIO), typically as discrete values of 0 and 1 (High or Low). Being able to read and write values to these pins allows simple and quick communication with peripheral devices. These devices in turn help the DragonBoard™ 410c to interpret and communicate with the environment or other devices. All microcontrollers are not the same, and will usually differ in many ways. The DragonBoard™ 410c has 12 GPIO pins, one of which is multi-purpose.

**I2C**

The Inter-integrated Circuit (I2C) is essentially a serial computer bus (a bus is something that communicates/transfers data between components) which allows lower speed peripheral ICs to be connected with processors and microcontrollers. They permit multiple synchronized master-slave connections to be formed. It is used in short distance communications within a single device. Although it is slower, it can be used for many devices. Requires two signal wires to transfer information. 

**SPI**

The serial peripheral interface (SPI) is a bus that is used for fast, short distance communication between two systems in a master-slave fashion. The master device will contain the original signals which can be processed in the slave. The main difference between SPI and I2C is that SPI is a 4 wire interface while I2C is a two wire interface. SPI is used for guaranteed data transmission while I2C is easier to link multiple devices for it has a built in addressing scheme. 

**UART**

A UART is a microchip that controls the interface between a computer and its attached serial devices. It translates data between parallel and serial. It can talk to, and exchange information between modems and other serial devices. It is asynchronous (requiring a form of computer control timing protocol). The main difference between UART and SPI is in their protocols and speed. SPI typically operates at up to 50 Mbps while the UART operates between 0.5 Kbps and 1 Mbps. Therefore, SPI is excellent for high-bandwidth applications, such as audio and video. UARTs is better for sensor type applications. 

**PCM**

Pulse-code modulation (PCM) is used to sample analog signals and convert it to a digital signal. The analog signal is, in effect, compressed into a digital signal (not perfect analog representation but close) which means that the data is easier to work with (storing, reading, less noise).

***

