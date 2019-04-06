/*
 * LCD.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: mugetronblue
 */
#include "gpio.h"

using namespace BSP;
void initLCD() {
	gpio::GPIO::ConstructStatic();
	gpio::GPIO& gpio = gpio::GPIO::StaticClass();
	/* Set CL to clock with a 2kHz external clock signal.
	 * Register select signal. A0=0: Command, A0=1: Data
	 * choose between command and data.
	 * Active LOW Chip Select Signal for LEFT half of LCD
	 * Active LOW Chip Select Signal for RIGHT half of LCD
	 * So to turn them on, we should clear them.
	 * RESET -> Hardware RESET (edge-sensitive) and
	 * interface type selection: Positive
	 * Reset: 8080 mode
	 * Negative Reset: 6800 mode
	 * R/W -> 6800 Mode: Read/Write select signal.
	 * R/W=1: Read R/W: =0:
	 * Write 8080 Mode: Active LOW Write Signal
	 * EN-> 6800 Mode: Active HIGH Enable Signal
	 * 8080 Mode: Active LOW Read Signal
	 * D0-D7 are the 8 bit bidirectional data bus.
	 *
	 */
	//___Other pins____
	//gpio.clear(gpio::PortD,2) ; //CL = clock signal
	gpio.clear(gpio::PortE,10); //RS? A0
	gpio.clear(gpio::PortE,11); //CS2
	gpio.clear(gpio::PortD,0) ; //CS1
	gpio.clear(gpio::PortD,1) ; //RESET/IF
	gpio.clear(gpio::PortC,5) ; //EN? I think E/RD
	gpio.clear(gpio::PortE,0) ; //R/W

	//____DATA pins____
	gpio.clear(gpio::PortE,1) ; //D0
	gpio.clear(gpio::PortA,11); //D1
	gpio.clear(gpio::PortA,12); //D2
	gpio.clear(gpio::PortA,13); //D3
	gpio.clear(gpio::PortE,2) ; //D4
	gpio.clear(gpio::PortE,6) ; //D5
	gpio.clear(gpio::PortC,6) ; //D6
	gpio.clear(gpio::PortC,7) ; //D7

}



