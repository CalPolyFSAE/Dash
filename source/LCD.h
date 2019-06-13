/*
 * LCD.h
 *
 *  Created on: Apr 17, 2019
 *      Author: mugetronblue
 */

#ifndef LCD_H_
#define LCD_H_

//for datasheet, note we are using 6800 mode for the control signals.
#define RS_PIN 10
#define RS_PORT PortD
//RS=0 is command, RS=1 is data
#define CS_L_PIN 0
#define CS_L_PORT PortD
#define CS_R_PIN 11
#define CS_R_PORT PortE
//both CS active low
#define CLK_PIN 2
#define CLK_PORT PortD
//2kHz
#define EN_PIN 5
#define EN_PORT PortC
//EN is active-high
#define RW_PIN 0
#define RW_PORT PortE
//RW=1 is Read, RW=0 is Write
#define DATA0_PIN 1
#define DATA0_PORT PortE
#define DATA1_PIN 11
#define DATA1_PORT PortA
#define DATA2_PIN 12
#define DATA2_PORT PortA
#define DATA3_PIN 13
#define DATA3_PORT PortA
#define DATA4_PIN 2
#define DATA4_PORT PortE
#define DATA5_PIN 6
#define DATA5_PORT PortE
#define DATA6_PIN 6
#define DATA6_PORT PortC
#define DATA7_PIN 7
#define DATA7_PORT PortC

#define RST_PIN 1
#define RST_PORT PortD
//Negative Reset. (active-low)

void LCDinit();
void LCDcommand(char str);
void LCDchar(char str);
void LCDwrite(char* str);
char* getLapTime_str();
char* getLastLapTime_str();
char* getLapCount_str();
void Writeleft(char i);
void Writeright(char i);
void Comleft(char i);
void Comright(char i);
void bothSides(char i);
void LCDchar(char chr);

#endif
