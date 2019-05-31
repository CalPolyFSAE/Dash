/*
 * WarningLEDs.cpp
 *
 *  Created on: Feb 20, 2019
 *      Author: mugetronblue
 */
#include "gpio.h"

using namespace BSP;

void initLEDs() {
	gpio::GPIO::ConstructStatic();
	gpio::GPIO& gpio = gpio::GPIO::StaticClass();
	gpio.clear(gpio::PortD,7);
	gpio.clear(gpio::PortD,6);
	gpio.clear(gpio::PortD,5);
	gpio.clear(gpio::PortB,4);
	//idk which pin port and pin to set for the third led.
}

/*void toggleLED1(GPIO_port port, uint8_t pin) {
	gpio::GPIO::StaticClass().toggle(port,pin);
}*/
void toggleLED1() {
	//gpio::GPIO::StaticClass().set(gpio::PortD,7);
	gpio::GPIO::StaticClass().toggle(gpio::PortD,7);
}
void toggleLED2() {
	gpio::GPIO::StaticClass().toggle(gpio::PortD,6);
}
void toggleLED3() {
	gpio::GPIO::StaticClass().toggle(gpio::PortD,5);
}
void toggleLED4() {
	gpio::GPIO::StaticClass().toggle(gpio::PortB,4);
}

// Create a function for each pin to toggle.
void setLED1() {
	gpio::GPIO::StaticClass().set(gpio::PortD,7);
}
void setLED2() {
	gpio::GPIO::StaticClass().set(gpio::PortD,7);
}
void setLED3() {
	gpio::GPIO::StaticClass().set(gpio::PortD,7);
}
void setLED4() {
	gpio::GPIO::StaticClass().set(gpio::PortD,7);
}

void clearLED1() {
	gpio::GPIO::StaticClass().clear(gpio::PortD,7);
}
void clearLED2() {
	gpio::GPIO::StaticClass().clear(gpio::PortD,7);
}
void clearLED3() {
	gpio::GPIO::StaticClass().clear(gpio::PortD,7);
}
void clearLED4() {
	gpio::GPIO::StaticClass().clear(gpio::PortD,7);
}
