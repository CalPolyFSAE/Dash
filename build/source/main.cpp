#include "MKE18F16.h"
#include "pin_mux.h"
#include "clock_config.h"




#include "gpio.h"
#include "can.h"

using namespace BSP;


uint8_t counter;

void cb(void){
	can::CANlight::frame f = can::CANlight::StaticClass().readrx(0);
    if (f.id == 0x123)
    {
        if(f.data[0] == 0x00)
        {
            gpio::GPIO::set(gpio::PortA, 7); // SSEG
            gpio::GPIO::set(gpio::PortC, 8); // SSEG   
            gpio::GPIO::set(gpio::PortD, 3); // SSEG
            gpio::GPIO::set(gpio::PortD, 4); // SSEG
            gpio::GPIO::set(gpio::PortC, 9); // SSEG
            gpio::GPIO::set(gpio::PortC, 0); // SSEG
            gpio::GPIO::set(gpio::PortC, 17); // SSEG Decimal

        }
        if (f.data[1] == 0x05)
        {
            gpio::GPIO::set(gpio::PortD, 0); // LED


        }
        if (f.data[2] == 0x04)
        {
            gpio::GPIO::set(gpio::PortD, 1); // LED

        }
        if (f.data[3] == 0x06)
        {
            gpio::GPIO::set(gpio::PortE, 10); 
        }
        if (f.data[4] == 0x07)
        {
            gpio::GPIO::set(gpio::PortE, 11);
        }
        // if (f.data[5] == 0x08)
        // {
            
        // }
        // if (f.data[6] == 0x09)
        // {
            
        // }
        // if (f.data[7] == 0x04)
        // {
            
        // }
        // if (f.data[8] == 0xff)
        // {
            
        // }
    }
}


void testingLEDS(void)
{
    static uint64_t time = 0;
    time++;
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    int flag4 = 0;


    if(!(time % 3000) && flag1 == 0)
    {
        gpio::GPIO::set(gpio::PortD, 0); // LED
        gpio::GPIO::set(gpio::PortA, 7); // SSEG
        gpio::GPIO::set(gpio::PortC, 8); // SSEG        
    
        flag1 = 1;
    }

    if(!(time % 6000) && flag2 == 0)
    {
        gpio::GPIO::set(gpio::PortD, 1); // LED
        gpio::GPIO::set(gpio::PortD, 3); // SSEG
        gpio::GPIO::set(gpio::PortD, 4); // SSEG
        flag2 = 1;
    }

    if(!(time % 9000) && flag3 == 0)
    {
        gpio::GPIO::set(gpio::PortE, 10); // LED
        gpio::GPIO::set(gpio::PortC, 9); // SSEG
        gpio::GPIO::set(gpio::PortC, 0); // SSEG
        flag3 = 1;
    }

    if(!(time % 12000) && flag4 == 0)
    {
        gpio::GPIO::set(gpio::PortE, 11); // LED
        gpio::GPIO::set(gpio::PortC, 1); // SSEG        

        flag4 = 1;
    }

   if(!(time % 15000))
    {
        gpio::GPIO::clear(gpio::PortE, 11); // LED
        gpio::GPIO::set(gpio::PortC, 17); // SSEG        

    }

    if(!(time % 18000))
    {
        gpio::GPIO::clear(gpio::PortE, 10); // LED
    }

    if(!(time % 21000))
    {
        gpio::GPIO::clear(gpio::PortD, 1); // LED
    }

    if(!(time % 24000))
    {
        gpio::GPIO::clear(gpio::PortD, 0); // LED
        flag1 = 0;
        flag2 = 0;
        flag3 = 0;
        flag4 = 0;
    }

}

int main(void) {
    BOARD_InitBootPins();
    BOARD_InitBootClocks();

	can::can_config c;
	can::CANlight::ConstructStatic(&c);
	can::CANlight& can = can::CANlight::StaticClass();

	can::CANlight::canx_config cx;
	cx.callback = cb;
	can.init(0, &cx);

    // SysTick_Config(60000);
    
    while (1);
    return 0;
}

extern "C" {


    
    void SysTick_Handler(void){
   
        // testingLEDS();
        // cb();

    }
}