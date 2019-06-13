/*
 * CAN.cpp
 *
 *  Created on: Apr 5, 2019
 *      Author: mugetronblue
 */
#include "canlight.h"
#include "gears.h"
#include "WarningLEDs.h"

using namespace BSP;

uint8_t buffer[8];
volatile uint32_t id;

void genCallBack()
{
	can::CANlight& can = can::CANlight::StaticClass();
	can::CANlight::frame frame = can.readrx(0);
	memcpy(buffer, frame.data, sizeof(frame.data));
	id = frame.id;
}
/* pin 6 = can hi
 * pin 7 = can low
 */
void setupCAN()
{
	id = 0;
	can::canlight_config c;
	can::CANlight::ConstructStatic(&c);
	can::CANlight& can = can::CANlight::StaticClass();
	can::CANlight::canx_config cx;
	cx.baudRate = 1000000;
	cx.callback = genCallBack;
	can.init(0, &cx);
}

void toggleWarningLeds(uint8_t data)
{
	if (data  & 0x1) {
		setLED1();
	}
	else {
		clearLED1();
	}
	if (data & 0x2) {
		setLED2();
	}
	else {
		clearLED2();
	}
	if (data & 0x4) {
		setLED3();
	}
	else {
		clearLED3();
	}
	if (data & 0x8) {
		setLED4();
	}
	else {
		clearLED4();
	}
}

/* inplement 2 bytes from buffer, one byte for the left steering
 * wheel button and rotary pot and one byte for right steering
 * button and rotary pot.
 * LSB is button.
 * rotary pot has 12 positions so requires a nibble 4 bits.
 */

/* buttons are for lap timer and DRS? maybe? or other one will be a flag*/

/* gear indicators are at data 1 and warning leds are at data 0*/
/* 400 for c car and 401 for e car*/
void read()
{
	can::CANlight& can = can::CANlight::StaticClass();
	while(1)
	{
		/*while (can.unread0 == 0);
		can::CANlight::frame frame = can.readrx(0);*/

		if(id == 0x400)
	    {
	        shift(buffer[1]);
	        toggleWarningLeds(buffer[0]);

	    }
	    else if(id == 0x401)
	    {
	        shift(buffer[1]);
	        toggleWarningLeds(buffer[0]);

	    }
	}
}

