# General Purpose Input/Output

In order for your 96Boards to interact with the world, there has to be an interface between them. This is where the GPIO comes in handy. Using this       interface you will teach your board to sense and interact with the environment.

General Purpose Input/Output pins are accessable through the low-speed expansion header found on your 96Boards device. It is important to first locate and safely gain physical access to these interfaces(pins) before you begin coding.

This page will walk you through the entire process. Once a greater understanding of the GPIO is achieved you will learn to toggle them manually via command prompt and programmatically using one or more libraries included in your 96Boards operating systems.

## Start Here

- [Beginner](96BoardsGPIO.README.md)
   - These guides are intended for users who wish to utilize the GPIO libraries which are included in our pre-built images
- [Advanced](Libsoc/README.md)
   - Advanced users can learn where to aquire, and how to build the various 96Boards enabled libraries such as 96BoardsGPIO, libsoc, mraa, and UPM. These users should already be familiar with the 96Boards hardware.