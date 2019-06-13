/*
 * LCD.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: mugetronblue
 */
#include "gpio.h"
#include "LCD.h"

using namespace BSP;

extern void
	delay(uint32_t usec);

void LCDinit()
{
	gpio::GPIO::ConstructStatic();
	gpio::GPIO& gpio = gpio::GPIO::StaticClass();
	gpio.clear(gpio::DATA0_PORT,DATA0_PIN);
	gpio.clear(gpio::DATA1_PORT,DATA1_PIN);
	gpio.clear(gpio::DATA2_PORT,DATA2_PIN);
	gpio.clear(gpio::DATA3_PORT,DATA3_PIN);
	gpio.clear(gpio::DATA4_PORT,DATA4_PIN);
	gpio.clear(gpio::DATA5_PORT,DATA5_PIN);
	gpio.clear(gpio::DATA6_PORT,DATA6_PIN);
	gpio.clear(gpio::DATA7_PORT,DATA7_PIN);
	gpio.clear(gpio::CS_L_PORT,CS_L_PIN);
	gpio.clear(gpio::CS_R_PORT,CS_R_PIN);
	gpio.clear(gpio::RST_PORT,RST_PIN);
	delay(2);
	gpio.set(gpio::RST_PORT,RST_PIN);
	delay(10);
	gpio.clear(gpio::RS_PORT,RS_PIN);
	gpio.set(gpio::EN_PORT,EN_PIN);
	gpio.set(gpio::RW_PORT, RW_PIN);

	bothSides(0xE2);
	/*delay(10);
	bothSides(0xA4);
	bothSides(0xA9);
	bothSides(0xA0);
	bothSides(0xEE);
	bothSides(0xC0);
	bothSides(0xAF);
	*/
}

void writeLeft(char i)
{
	gpio::GPIO& gpio = gpio::GPIO::StaticClass();
	gpio.toggle(gpio::CS_L_PORT,CS_L_PIN);
	//iterates through bits of i and sets them to data pins
	if (i & 0x01)
	{
		gpio.set(gpio::DATA0_PORT,DATA0_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA0_PORT,DATA0_PIN);
	}
	if (i & 0x02)
	{
		gpio.set(gpio::DATA1_PORT,DATA1_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA1_PORT,DATA1_PIN);
	}
	if (i & 0x04)
	{
		gpio.set(gpio::DATA2_PORT,DATA2_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA2_PORT,DATA2_PIN);
	}
	if (i & 0x08)
	{
		gpio.set(gpio::DATA3_PORT,DATA3_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA3_PORT,DATA3_PIN);
	}
	if (i & 0x10)
	{
		gpio.set(gpio::DATA4_PORT,DATA4_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA4_PORT,DATA4_PIN);
	}
	if (i & 0x20)
	{
		gpio.set(gpio::DATA5_PORT,DATA5_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA5_PORT,DATA5_PIN);
	}
	if (i & 0x40)
	{
		gpio.set(gpio::DATA6_PORT,DATA6_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA6_PORT,DATA6_PIN);
	}
	if (i & 0x80)
	{
		gpio.set(gpio::DATA7_PORT,DATA7_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA7_PORT,DATA7_PIN);
	}

	gpio.clear(gpio::RW_PORT, RW_PIN );
	gpio.set(gpio::RS_PORT,RS_PIN);
	gpio.set(gpio::EN_PORT,EN_PIN);
	delay(2);
	gpio.clear(gpio::EN_PORT,EN_PIN);
	gpio.toggle(gpio::CS_L_PORT,CS_L_PIN);
}

void writeRight(char i)
{
	gpio::GPIO& gpio = gpio::GPIO::StaticClass();
	gpio.toggle(gpio::CS_R_PORT,CS_R_PIN);
	//iterates through bits of i and sets them to data pins
	if (i & 0x01)
	{
		gpio.set(gpio::DATA0_PORT,DATA0_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA0_PORT,DATA0_PIN);
	}
	if (i & 0x02)
	{
		gpio.set(gpio::DATA1_PORT,DATA1_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA1_PORT,DATA1_PIN);
	}
	if (i & 0x04)
	{
		gpio.set(gpio::DATA2_PORT,DATA2_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA2_PORT,DATA2_PIN);
	}
	if (i & 0x08)
	{
		gpio.set(gpio::DATA3_PORT,DATA3_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA3_PORT,DATA3_PIN);
	}
	if (i & 0x10)
	{
		gpio.set(gpio::DATA4_PORT,DATA4_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA4_PORT,DATA4_PIN);
	}
	if (i & 0x20)
	{
		gpio.set(gpio::DATA5_PORT,DATA5_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA5_PORT,DATA5_PIN);
	}
	if (i & 0x40)
	{
		gpio.set(gpio::DATA6_PORT,DATA6_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA6_PORT,DATA6_PIN);
	}
	if (i & 0x80)
	{
		gpio.set(gpio::DATA7_PORT,DATA7_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA7_PORT,DATA7_PIN);
	}
	gpio.clear(gpio::RW_PORT, RW_PIN );
	gpio.set(gpio::RS_PORT,RS_PIN);
	gpio.set(gpio::EN_PORT,EN_PIN);
	delay(2); //needs a delay function
	gpio.clear(gpio::EN_PORT,EN_PIN);
	gpio.toggle(gpio::CS_R_PORT,CS_R_PIN);
}

void comLeft(char i)
{
	gpio::GPIO& gpio = gpio::GPIO::StaticClass();
	gpio.toggle(gpio::CS_L_PORT,CS_L_PIN);
	//iterates through bits of i and sets them to data pins
	if (i & 0x01)
	{
		gpio.set(gpio::DATA0_PORT,DATA0_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA0_PORT,DATA0_PIN);
	}
	if (i & 0x02)
	{
		gpio.set(gpio::DATA1_PORT,DATA1_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA1_PORT,DATA1_PIN);
	}
	if (i & 0x04)
	{
		gpio.set(gpio::DATA2_PORT,DATA2_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA2_PORT,DATA2_PIN);
	}
	if (i & 0x08)
	{
		gpio.set(gpio::DATA3_PORT,DATA3_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA3_PORT,DATA3_PIN);
	}
	if (i & 0x10)
	{
		gpio.set(gpio::DATA4_PORT,DATA4_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA4_PORT,DATA4_PIN);
	}
	if (i & 0x20)
	{
		gpio.set(gpio::DATA5_PORT,DATA5_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA5_PORT,DATA5_PIN);
	}
	if (i & 0x40)
	{
		gpio.set(gpio::DATA6_PORT,DATA6_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA6_PORT,DATA6_PIN);
	}
	if (i & 0x80)
	{
		gpio.set(gpio::DATA7_PORT,DATA7_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA7_PORT,DATA7_PIN);
	}

	gpio.clear(gpio::RW_PORT, RW_PIN );
	gpio.clear(gpio::RS_PORT,RS_PIN);
	gpio.set(gpio::EN_PORT,EN_PIN);
	delay(2); //needs a delay function
	gpio.clear(gpio::EN_PORT,EN_PIN);
	gpio.toggle(gpio::CS_L_PORT,CS_L_PIN);
}

void comRight(char i)
{
	gpio::GPIO& gpio = gpio::GPIO::StaticClass();
	gpio.toggle(gpio::CS_R_PORT,CS_R_PIN);
	//iterates through bits of i and sets them to data pins
	if (i & 0x01)
	{
		gpio.set(gpio::DATA0_PORT,DATA0_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA0_PORT,DATA0_PIN);
	}
	if (i & 0x02)
	{
		gpio.set(gpio::DATA1_PORT,DATA1_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA1_PORT,DATA1_PIN);
	}
	if (i & 0x04)
	{
		gpio.set(gpio::DATA2_PORT,DATA2_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA2_PORT,DATA2_PIN);
	}
	if (i & 0x08)
	{
		gpio.set(gpio::DATA3_PORT,DATA3_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA3_PORT,DATA3_PIN);
	}
	if (i & 0x10)
	{
		gpio.set(gpio::DATA4_PORT,DATA4_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA4_PORT,DATA4_PIN);
	}
	if (i & 0x20)
	{
		gpio.set(gpio::DATA5_PORT,DATA5_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA5_PORT,DATA5_PIN);
	}
	if (i & 0x40)
	{
		gpio.set(gpio::DATA6_PORT,DATA6_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA6_PORT,DATA6_PIN);
	}
	if (i & 0x80)
	{
		gpio.set(gpio::DATA7_PORT,DATA7_PIN);
	}
	else
	{
		gpio.clear(gpio::DATA7_PORT,DATA7_PIN);
	}

	gpio.clear(gpio::RW_PORT, RW_PIN );
	gpio.clear(gpio::RS_PORT,RS_PIN);
	gpio.set(gpio::EN_PORT,EN_PIN);
	delay(2); //needs a delay function
	gpio.clear(gpio::EN_PORT,EN_PIN);
	gpio.toggle(gpio::CS_R_PORT,CS_R_PIN);
}

void bothSides(char i)
{
	comLeft(i);
	comRight(i);
}

void writeBothSides(char i)
{
	writeLeft(i);
	writeRight(i);
}

void LCDcommand(char str)
{

}

void LCDchar(char chr)
{
	writeBothSides(chr);
}

void LCDwrite(char* str)
{
	int i=0;
	while(str[i] != '\0')
	{
		LCDchar(str[i]);
		i++;
	}
}

/*extern "C" {
void SysTick_Handler(){
	blocked = 0;
}
}*/
