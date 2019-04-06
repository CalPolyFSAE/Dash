/*
 * Gears.cpp
 *
 *  Created on: Feb 25, 2019
 *      Author: mugetronblue
 */
#include "gpio.h"

using namespace BSP;
//******** DO NOT USE DECIMAL POINT PORTE 9 ********//
//____Cathodes_on_is off__//
void initGears() {
	gpio::GPIO::ConstructStatic();
	gpio::GPIO& gpio = gpio::GPIO::StaticClass();
	gpio.set(gpio::PortB,7); //e   bottom left
	gpio.set(gpio::PortB,6); //d   bottom
	gpio.clear(gpio::PortE,3); //c   bottom right
	gpio.clear(gpio::PortD,3); //b   top right
	gpio.set(gpio::PortD,4); //a   top
	gpio.set(gpio::PortB,12); //f  top left
	gpio.set(gpio::PortB,13); //g  middle
}

void shift(int gear) {
	switch (gear) {
		case 1: gpio::GPIO::StaticClass().set(gpio::PortB,7); //e
				gpio::GPIO::StaticClass().set(gpio::PortB,6); //d
				gpio::GPIO::StaticClass().clear(gpio::PortE,3); //c
				gpio::GPIO::StaticClass().clear(gpio::PortD,3); //b
				gpio::GPIO::StaticClass().set(gpio::PortD,4); //a master en
				gpio::GPIO::StaticClass().set(gpio::PortB,12); //f
				gpio::GPIO::StaticClass().set(gpio::PortB,13); //g
				break;
		case 2: gpio::GPIO::StaticClass().clear(gpio::PortB,7); //e   bottom left
				gpio::GPIO::StaticClass().clear(gpio::PortB,6); //d   bottom
				gpio::GPIO::StaticClass().set(gpio::PortE,3); //c   bottom right
				gpio::GPIO::StaticClass().clear(gpio::PortD,3); //b   top right
				gpio::GPIO::StaticClass().clear(gpio::PortD,4); //a   top
				gpio::GPIO::StaticClass().set(gpio::PortB,12); //f  top left
				gpio::GPIO::StaticClass().clear(gpio::PortB,13); //g  middle
				break;
		case 3: gpio::GPIO::StaticClass().set(gpio::PortB,7); //e   bottom left
				gpio::GPIO::StaticClass().clear(gpio::PortB,6); //d   bottom
				gpio::GPIO::StaticClass().clear(gpio::PortE,3); //c   bottom right
				gpio::GPIO::StaticClass().clear(gpio::PortD,3); //b   top right
				gpio::GPIO::StaticClass().clear(gpio::PortD,4); //a   top
				gpio::GPIO::StaticClass().set(gpio::PortB,12); //f  top left
				gpio::GPIO::StaticClass().clear(gpio::PortB,13); //g  middle
				break;
		case 4: gpio::GPIO::StaticClass().set(gpio::PortB,7); //e   bottom left
				gpio::GPIO::StaticClass().set(gpio::PortB,6); //d   bottom
				gpio::GPIO::StaticClass().clear(gpio::PortE,3); //c   bottom right
				gpio::GPIO::StaticClass().clear(gpio::PortD,3); //b   top right
				gpio::GPIO::StaticClass().set(gpio::PortD,4); //a   top
				gpio::GPIO::StaticClass().clear(gpio::PortB,12); //f  top left
				gpio::GPIO::StaticClass().clear(gpio::PortB,13); //g  middle
				break;
		case 5: gpio::GPIO::StaticClass().set(gpio::PortB,7); //e   bottom left
				gpio::GPIO::StaticClass().clear(gpio::PortB,6); //d   bottom
				gpio::GPIO::StaticClass().clear(gpio::PortE,3); //c   bottom right
				gpio::GPIO::StaticClass().set(gpio::PortD,3); //b   top right
				gpio::GPIO::StaticClass().clear(gpio::PortD,4); //a   top
				gpio::GPIO::StaticClass().clear(gpio::PortB,12); //f  top left
				gpio::GPIO::StaticClass().clear(gpio::PortB,13); //g  middle
				break;
		case 6: gpio::GPIO::StaticClass().clear(gpio::PortB,7); //e   bottom left
				gpio::GPIO::StaticClass().clear(gpio::PortB,6); //d   bottom
				gpio::GPIO::StaticClass().clear(gpio::PortE,3); //c   bottom right
				gpio::GPIO::StaticClass().set(gpio::PortD,3); //b   top right
				gpio::GPIO::StaticClass().clear(gpio::PortD,4); //a   top
				gpio::GPIO::StaticClass().clear(gpio::PortB,12); //f  top left
				gpio::GPIO::StaticClass().clear(gpio::PortB,13); //g  middle
				break;

	}
}


