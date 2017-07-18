---
title: Compare Consumer Edition(CE) 96Boards
permalink: /documentation/ConsumerEdition/CE-Extras/Compare96BoardsCE.md/
---
# Compare Consumer Edition(CE) 96Boards

### Quick Comparison - CPU, GPU, and Memory

<table align="center">
<thead>
	<tr>
		<td></td>
		<td><b></td>
		<td colspan="3"><b>CPU</td>
		<td><b></td>
		<td colspan="4"><b>RAM</td>
	</tr>
</thead>
<tbody>
	<tr>
		<td><img src="http://i.imgur.com/mKjYKTH.png" data-canonical-src="http://i.imgur.com/mKjYKTH.png" width="135" height="40" /></td>
		<td><a href="https://en.wikipedia.org/wiki/System_on_a_chip"><b>SoC</a></td>
		<td><a href="https://en.wikipedia.org/wiki/ARM_architecture"><b>Architecture&shy;</a></td>
		<td><a href="https://en.wikipedia.org/wiki/Multi-core_processor"><b>Cores</a></td>
		<td><a href=""><b>Frequency&shy;</a></td>
		<td><a href="https://en.wikipedia.org/wiki/Graphics_processing_unit"><b>GPU</a></td>
		<td><a href="https://en.wikipedia.org/wiki/Random-access_memory"><b>Size&shy;</a></td>
		<td><a href="https://en.wikipedia.org/wiki/Random-access_memory"><b>Data rate</a></td>
		<td><a href="https://en.wikipedia.org/wiki/Random-access_memory"><b>Type</a></td>
	</tr>
	<tr>
		<td> <img src="http://i.imgur.com/0e7lsoO.png" data-canonical-src="http://i.imgur.com/0e7lsoO.png" width="70" height="50" /> <br> HiKey</td>
		<td>HiSilicon<br>Kirin 620</td>
		<td>ARM Cortex-A53</td>
		<td>8</td>
		<td>1.2 GHz</td>
		<td>Mali-450 MP4</td>
		<td>1 GB or 2 GB</td>
		<td>1600</td>
		<td>LPDDR3</td>
	</tr>
	<tr>
		<td><img src="http://i.imgur.com/4a5GXRd.png" data-canonical-src="http://i.imgur.com/4a5GXRd.png" width="70" height="50" /> <br> DragonBoard™ 410c</td>
		<td>Qualcomm<br>Snapdragon 410</td>
		<td>ARM Cortex-A53</td>
		<td>4</td>
		<td>1.2 GHz</td>
		<td>Qualcomm<br>Adreno 306</td>
		<td>1 GB</td>
		<td>1066</td>
		<td>LPDDR3</td>
	</tr>
	<tr>
		<td> <img src="http://i.imgur.com/ykySoFc.png" data-canonical-src="http://i.imgur.com/ykySoFc.png" width="70" height="50" /> <br> Bubblegum-96</td>
		<td>Actions<br>s900</td>
		<td>ARM Cortex-A53</td>
		<td>4</td>
		<td>1.8 GHz</td>
		<td>PowerVR G6230</td>
		<td>2 GB</td>
		<td>2400</td>
		<td>LPDDR3</td>
	</tr>
	<tr>
		<td> <img src="http://i.imgur.com/kSjTguX.png" data-canonical-src="http://i.imgur.com/kSjTguX.png" width="70" height="50" /> <br> Mediatek X20</td>
		<td>Application Processor<br>Helio X20</td>
		<td>2xARM Cortex-A72<br>4xARM Cortex-A53<br>4xARM Cortex-A53</td>
		<td>10</td>
		<td>2.3 GHz<br>1.95 GHz<br>1.4 GHz</td>
		<td>Mali-T880</td>
		<td>2 GB</td>
		<td>?</td>
		<td>LPDDR3</td>
	</tr>
	<tr>
	<td> <img src="https://github.com/96boards/documentation/blob/master/ConsumerEdition/MediaTekX20Pro/AdditionalDocs/Images/Images_Board/MediaTek%20X20-Front-SD.jpg?raw=true" data-canonical-src="https://github.com/96boards/documentation/blob/master/ConsumerEdition/MediaTekX20Pro/AdditionalDocs/Images/Images_Board/MediaTek%20X20-Front-SD.jpg?raw=true" width="70" height="50" /> <br> Mediatek X20 Pro</td>
	<td>Application Processor<br>Helio X20</td>
	<td>2xARM Cortex-A72<br>4xARM Cortex-A53<br>4xARM Cortex-A53</td>
	<td>10</td>
	<td>2.3 GHz<br>1.95 GHz<br>1.4 GHz</td>
	<td>Mali-T880</td>
	<td>2 GB</td>
	<td>?</td>
	<td>LPDDR3</td>
	</tr>
</tbody>
</table>

***

## HiKey

The HiKey board was the first board to be certified 96Boards Consumer Edition compatible. Two versions of this board are available: the original from CircuitCo and a new version in 1GB and 2GB variants from LeMaker. The board is based around the HiSilicon Kirin 620 eight-core ARM® Cortex-A53 64-bit SoC running at 1.2GHz and delivering over 10,000 Dhrystone VAX MIPS total performance. The SoC also delivers high performance 3D graphics support with its ARM Mali-450-MP4 GPU.

800MHz LPDDR3 DRAM (1GB in the CircuitCo version and a choice of 1GB or 2GB from LeMaker), 8GB eMMC Flash Storage and the standard 96Boards microSD v3.0 socket provide high performance. Flexible storage options and connectivity are available through 802.11b/g/n WiFi, Bluetooth® 4.0 LE, three high speed USB 2.0 ports (1 OTG), an HDMI 1.3 1080p video output with audio, and Maker, DSI display and CSI camera interfaces. The board is the standard 96Boards credit-card form factor powered by an 8-18V DC 2A power supply.

***

## DragonBoard™ 410c

The DragonBoard™ 410c by Arrow Electronics is the first development board based on a mid-tier Qualcomm® Snapdragon™ 400 series processor. The board is designed to build a software ecosystem around the Snapdragon™ 410 processor, as well as offering uses in education, prototyping, and commercial embedded computing products. Featuring the 64-bit capable Snapdragon 410 quad-core ARM® Cortex® A53 processor, the DragonBoard™ 410c supports Android 5.1, Linux based on Debian and Windows 10. It offers advanced processing power, integrated WiFi, Bluetooth®, and GPS, all packed into a board the size of a credit card. The board supports feature-rich functionality, including multimedia, with the Adreno™ 306 GPU for PC-class graphics, integrated ISP with up to 13 MP camera support, and 1080p HD video playback and capture with H.264 (AVC).

The DragonBoard™ 410c is an ideal foundation for prototyping and includes 1GB 533MHz LPDDR3 memory, 8GB eMMC 4.5 storage and a micro SD card slot, as well as one 40-pin low speed and one 60-pin high speed expansion connector, and the footprint for an optional analog expansion connector for stereo headset/line-out, speakers and analog line-in. The board can be made compatible with Arduino using an add-on mezzanine board.

The DragonBoard™ 410c has the rich feature set and mid-tier accessibility to enable wide-ranging embedded and Internet of Everything (IoE) applications, including the next generation of robotics, cameras, medical devices, vending machines, smart buildings, digital signage, casino gaming consoles, and much more.

***

## Bubblegum-96

The Bubblegum-96 board was first shown in mid 2015 at trade shows in Asia. Since then,  Actions has been working with Linaro to finalize the software support and ensure the best possible performance. Sporting an optimized Actions s900 Quad-core ARM® 64-bit Cortex-A53 processor running at 1.8GHz and 600MHz PowerVR G6230 high-quality graphics with 2GB of DRAM and USB 3.0 support, this board is expected to deliver top of the line performance and superior gaming.
In addition to standard 96Boards features, the board will offer integrated HDMI with Ultra 4K output, Full HD video capture (1080P@60fps H.264) and ARM® TrustZone® security support.

***

## Mediatek X20 and X20 Professional

The Mediatek X20 Development Board is a 96Boards compliant community board based on the MediaTek X20 series of SoCs. X20 is a highly integrated application processor that includes Dual-core ARM Cortex-A72 processors operating at up to 2.3GHz, Quad-core ARM Cortex-A53 processors operating at up to 1.95GHz, Quad-core ARM Cortex-A53 processors operating at up to 1.4GHz and a Mali-T880 GPU operating at up to 800MHz. In addition, an extensive set of interfaces and connectivity peripherals are included to interface to cameras, touch-screen displays and MMC/SD cards. It also fully supports wireless communication, including WLAN, Bluetooth and GPS.
