#include "MKE18F16.h"
#include "clock_config.h"
#include "pin_mux.h"

#include "gpio.h"
#include "spi.h"

using namespace BSP;

#define p_min 50        // minimum period between edges
#define p_max 10000     // maximum period between edges

uint16_t count = 0;

void delay(uint16_t ms){
    count = ms * 10;
    while(count);
}

uint8_t tx[3];
uint8_t rx[3];

void spi_init(){
    spi::spi_config conf;
    spi::SPI::ConstructStatic(&conf);
    spi::SPI& spi = spi::SPI::StaticClass();

    spi::SPI::masterConfig mconf;
    // mode 0
    mconf.baudRate = 50000U;
    mconf.csport = gpio::PortD;
    mconf.cspin = 16;
    spi.initMaster(0, &mconf);
}

void spi_transmit(uint8_t instr){
    tx[0] = 0xf8;
    tx[1] = (instr & 0xf0);
    tx[2] = (instr & 0x0f) << 4;
    spi::SPI& spi = spi::SPI::StaticClass();
    spi.mastertx(0, tx, rx, 3);
    while(spi.xcvrs[0].transmitting);
}

void spi_data(uint8_t instr){
    tx[0] = 0xfa;
    tx[1] = (instr & 0xf0);
    tx[2] = (instr & 0x0f) << 4;
    spi::SPI& spi = spi::SPI::StaticClass();
    spi.mastertx(0, tx, rx, 3);
    while(spi.xcvrs[0].transmitting);
}

void display_clearscreen(){
    spi_transmit(0x01);
    delay(10);
}

void display_ddptr(uint8_t p){
    spi_transmit(0x80 | p);
    delay(1);
}

void display_string(char* c, uint8_t len){
    for(uint8_t i = 0; i < len; i++){
        spi_data(c[i]);
        delay(1);
    }
}

void display_init(){

    spi_transmit(0x30);
    spi_transmit(0x30);
    spi_transmit(0x30);
    spi_transmit(0x30);
    spi_transmit(0x0A);
    spi_transmit(0x01);
    spi_transmit(0x06);
    spi_transmit(0x0c);

}

uint16_t p; // tick counter
uint16_t edgetimer; // actual edge period

void edge(){
    if(p > p_max){
        p = 0;
    } else if(p > p_min){
        edgetimer = p;
        p = 0;
    }
	gpio::GPIO::StaticClass().ack_interrupt(gpio::PortC, 17);
}

uint8_t z = 0;
uint8_t y = 255;

void display_number(uint16_t x){
    char s[8];
    uint8_t len = 0;
    while(x){
        s[len] = (x % 10) + '0';
        x /= 10;
        len++;
    }
    while(len--){
        spi_data(s[len]);
        delay(1);
    }
}

uint8_t main() {
    p = 0;
    edgetimer = 0;
    // initialize board hardware
    BOARD_InitBootClocks();
    BOARD_InitBootPins();
    gpio::GPIO::ConstructStatic();
	gpio::GPIO& gpio = gpio::GPIO::StaticClass();
	gpio.config_function(gpio::PortC, edge);
	gpio.config_interrupt(gpio::PortC, 17, kPORT_InterruptRisingEdge);
    // do the reset
    gpio::GPIO::clear(gpio::PortC, 16);
    SysTick_Config(6000);
    delay(100);
    spi_init();
    // unreset
    gpio::GPIO::set(gpio::PortC, 16);
    display_init();
    display_clearscreen();
    char* s = "period";
    char* s2 = "00us";
    while(true){
        display_clearscreen();
        display_string(s, 6);
        display_ddptr(16);
        display_number(edgetimer);
        display_string(s2, 4);
        delay(1000);
    }

}

extern "C" {
void SysTick_Handler(void){
    z++;
    if(z == y){
        z = 0;
        gpio::GPIO::toggle(gpio::PortC, 1);
        y--;
    }
    p++;
    if(count) count--;
}
}
