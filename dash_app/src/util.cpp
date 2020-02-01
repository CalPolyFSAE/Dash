/**
 * @file util.cpp
 * @author Hunter Borlik
 * @version 0.1
 * @date 2019-12-17
 */

#include <util.h>

#include <fsl_clock.h>

#include <FreeRTOS.h>

using namespace dash_util;

uint32_t dash_util::get_clock_cycle_count() {
    return DWT->CYCCNT;
}

void dash_util::delay_us(uint32_t us) {
    portENTER_CRITICAL();
    const uint32_t start_count = get_clock_cycle_count();
    const uint32_t cycles_per_us = SystemCoreClock / 1000000;
    const uint32_t cycles_to_wait = cycles_per_us * us;
    uint32_t cycles = 0;
    uint32_t counter;
    while(cycles < cycles_to_wait) {
        counter = DWT->CYCCNT;
        if(counter < start_count) { // overflow
            cycles = ~(0u) - start_count + DWT->CYCCNT;
        } else
            cycles = DWT->CYCCNT - start_count;        
    }
    portEXIT_CRITICAL();
}