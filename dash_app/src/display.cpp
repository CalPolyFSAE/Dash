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

Display::Display() : 
    fb_front{std::make_unique<std::vector<uint8_t>>(100)},
    fb_front_lock{xSemaphoreCreateMutex()} {
    
}

Display::~Display() {
    // TODO: wait for draw thread to stop
    vSemaphoreDelete(fb_front_lock);
}