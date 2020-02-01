/**
 * @file display.cpp
 * @brief 
 * @version 0.1
 * @date 2020-02-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <display.h>
#include <util.h>

Display::Display(uint32_t rows, uint32_t cols) : 
    fb_front{std::make_unique<std::vector<uint8_t>>(rows*cols)},
    fb_back{std::make_unique<std::vector<uint8_t>>(rows*cols)},
    fb_front_lock{xSemaphoreCreateMutex()} {
    
    configASSERT(fb_front_lock != nullptr);
}

Display::~Display() {
    // TODO: wait for draw thread to stop
    vSemaphoreDelete(fb_front_lock);
}

void Display::swap() {
    configASSERT(xSemaphoreTake(fb_front_lock, 10) == pdTRUE);
    std::swap(fb_front, fb_back);
    xSemaphoreGive(fb_front_lock);
}