/**
 * @file MKE18F512xxx16_Project.cpp
 * @author Hunter Borlik
 * @date 2019-12-16
 */
#include <string>

#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKE18F16.h"

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

/* lcd */
//#include <nhd_12232az_lcd.h>

#include <spi.h>

/* The software timer period. */
#define SW_TIMER_PERIOD_MS (1000 / portTICK_PERIOD_MS)

/* The callback function. */
static void SwTimerCallback(TimerHandle_t xTimer);

using namespace bsp;

/*
 * @brief   Application entry point.
 */
int main(void) {
  	/* Init board hardware. */
    BOARD_BootClockRUN();
    BOARD_InitBootPins();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();

    // freertos needs irq to have a lower priority than configMAX_SYSCALL_INTERRUPT_PRIORITY
    NVIC_SetPriority(LPSPI0_IRQn, 3);

    spi::SPIManager::constructInstance();
    spi::SPIManager& spimanager = spi::SPIManager::getInstance();
    spi::SPIConfig spi_config{0};
    spi_config.masterConfig.pinCfg = kLPSPI_SdoInSdoOut;
    spi_config.masterConfig.pcsActiveHighOrLow = kLPSPI_PcsActiveHigh;
    spimanager.setConfig(0, spi_config);

    TimerHandle_t SwTimerHandle = NULL;
    SwTimerHandle = xTimerCreate("ScreenUpdate",    /* Text name. */
                                80 / portTICK_PERIOD_MS,/* Timer period. */
                                pdTRUE,             /* Enable auto reload. */
                                0,                  /* ID is not used. */
                                SwTimerCallback);   /* The callback function. */

    /* Start timer. */
    xTimerStart(SwTimerHandle, 0);
    /* Start scheduling. */
    vTaskStartScheduler();

    /* Force the counter to be placed into memory. */
    volatile static int i = 0 ;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {
        i++ ;
    }
    return 0 ;
}

void spi_cmd(uint8_t cmd, const uint32_t delay = 52) {
    spi::SPIManager& spimanager = spi::SPIManager::getInstance();
    uint8_t tx[3];
    tx[0] = 0xF8;
    tx[1] = 0xF0 & cmd;
    tx[2] = 0xF0 & (cmd << 4);
    spimanager.transfer(0, tx, nullptr, 3);
    delay_us(delay);
}

void spi_data(uint8_t data, const uint32_t delay = 72) {
    spi::SPIManager& spimanager = spi::SPIManager::getInstance();
    uint8_t tx[3];
    tx[0] = 0xFA;
    tx[1] = 0xF0 & data;
    tx[2] = 0xF0 & (data << 4);
    spimanager.transfer(0, tx, nullptr, 3);
    delay_us(delay);
}

void ram_address(uint8_t addr) {
    addr &= ~(0xC0); // clamp address
    spi_cmd(0x80 | addr);
}

/**
 * @brief set vertical scroll address: range [0, 2^6-1]
 * 
 * @param addr 
 */
void scroll_address(uint8_t addr) {
    addr &= ~(0xC0); // clamp address
    spi_cmd(0x40 | addr);
}

void clear_gdram() {
    for(uint8_t y = 0; y < 64; y++) {
        if(y < 32) {
            ram_address(y);
            ram_address(0x00);
        } else {
            ram_address((y-32));
            ram_address(0x08);
        }
        for(uint8_t x = 0; x < 16; x++) {
            spi_data(0x00);
        }
    }
}

void write_string(const std::string& str) {
    for(uint32_t i = 0; i < str.length(); i++) {
        spi_data(str.data()[i]);
    }
}

/*!
 * @brief Software timer callback.
 */
static void SwTimerCallback(TimerHandle_t xTimer) {
    spi_cmd(0x38);
    spi_cmd(0x38);
    spi_cmd(0x38);
    spi_cmd(0x38);
    spi_cmd(0x08); // display off, cursor off, character blink off

    spi_cmd(0x01, 1600); // clear display

    spi_cmd(0x06); // entry mode move cursor right, display shift off    

    spi_cmd(0x22); // disable extended instructions
    spi_cmd(0x20); // disable extended instructions, disable graphic display

    ram_address(0x00); // set DDRAM address to 0

    std::string s;
    static uint32_t val = 0;
    val++;
    s = "abc: " + std::to_string(val);
    write_string(s);

    spi_cmd(0x24); // enable extended instructions
    spi_cmd(0x26); // enable extended instructions, enable graphic display

    static bool initfl = false;
    if(!initfl) {
        clear_gdram();
        initfl = true;
    }

    spi_cmd(0x0c); // display on, cursor off, character blink off
}