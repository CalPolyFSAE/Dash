/*
 * Copyright 2016-2018 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    DashB.cpp
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "lpit.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKE18F16.h"
#include "fsl_debug_console.h"
#include "gpio.h"
#include "WarningLEDs.h"
#include "Gears.h"
#include "CAN.h"
#include "LCD.h"
#include "fsl_lpit.h"

using namespace BSP;

/*extern "C" {
	void LPIT0_Ch0_IRQHandler(void)
	{
		gpio::GPIO& gpio = gpio::GPIO::StaticClass();
		gpio.toggle(gpio::PortD,2);
	}
}*/

/*
extern "C" {

void LPIT0_Ch0_IRQHandler(){
	/*debug toggle*//*
	gpio::GPIO& gpio = gpio::GPIO::StaticClass();
	gpio.toggle(gpio::PortD,2);
}

void LPIT0_Ch1_IRQHandler(){

}

void LPIT0_Ch2_IRQHandler(){

}

void LPIT0_Ch3_IRQHandler(){

}

}


void LPIT_Handler(void)
{
	gpio::GPIO& gpio = gpio::GPIO::StaticClass();
	gpio.toggle(gpio::PortD,2);
}

volatile uint32_t counter;

void LPIT_DelayHandler(void)
{
	if (counter > 0)
	{
		counter--;
	}
}

void delay(uint32_t usec)
{
	counter = usec;
	while (counter != 0)
		;
}*/
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */
int main(void) {
	int i = 0x0;
	/*lpit_config_t LPIT_Config = {0};
	lpit_chnl_params_t Channel = {0} ;
	Channel.timerMode = kLPIT_PeriodicCounter;
	Channel.triggerSelect = kLPIT_Trigger_TimerChn0;
	Channel.triggerSource = kLPIT_TriggerSource_Internal;
	Channel.enableReloadOnTrigger = true;*/
	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
	BOARD_InitDebugConsole();



	/*LPIT_Init(LPIT0, &LPIT_Config);
	LPIT_SetupChannel(LPIT0, kLPIT_Chnl_0, &Channel);
	LPIT_SetTimerPeriod(LPIT0, kLPIT_Chnl_0, USEC_TO_COUNT(12500, 30000000));
	LPIT_EnableInterrupts(LPIT0, kLPIT_Channel0TimerInterruptEnable);
	EnableIRQ(LPIT0_Ch0_IRQn);
	LPIT_StartTimer(LPIT0, kLPIT_Chnl_0);*/

	gpio::GPIO::ConstructStatic();

	/*lpit::lpit_config lpit_conf;
	lpit_conf.clock = kCLOCK_IpSrcFircAsync;
	lpit_conf.interrupts = 1;
	lpit::LPIT::ConstructStatic(&lpit_conf);
	lpit::LPIT& lpitc = lpit::LPIT::StaticClass();
	lpitc.init(0, 7500, LPIT_Handler);
	lpitc.init(1, 30, LPIT_DelayHandler);
	*/

	initLEDs();
	initGears();
	LCDinit();
	setupCAN();

	delay(10);
	bothSides('C');
	delay(10);
	bothSides('P');
	delay(10);


	/*while(1){
		bothSides(i);
		LCDchar(i);
	}*/

	read();
	//SysTick_Config(0xfffff0);
	//_____________TEST GEARS_____________
	while(1) {}
    return 0 ;
}
