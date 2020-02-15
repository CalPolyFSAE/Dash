#include "MKE18F16.h"
#include "pin_mux.h"
#include "clock_config.h"

#include "gpio.h"
#include "can.h"

using namespace BSP;


int main(void) {
    BOARD_InitBootPins();
    BOARD_InitBootClocks();


    SysTick_Config(60000);
    
    while (1);
    return 0;
}

extern "C" {
    void SysTick_Handler(void){
    static uint64_t time = 0;
    time++;
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    int flag4 = 0;

    

    if(!(time % 3000) && flag1 == 0)
    {
        gpio::GPIO::set(gpio::PortD, 0); // LED
        flag1 = 1;
    }

    if(!(time % 6000) && flag2 == 0)
    {
        gpio::GPIO::set(gpio::PortD, 1); // LED
        flag2 = 1;
    }

    if(!(time % 9000) && flag3 == 0)
    {
        gpio::GPIO::set(gpio::PortE, 10); // LED
        flag3 = 1;
    }

    if(!(time % 12000) && flag4 == 0)
    {
        gpio::GPIO::set(gpio::PortE, 11); // LED
        flag4 = 1;
    }

   if(!(time % 15000))
    {
        gpio::GPIO::clear(gpio::PortE, 11); // LED
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
}