/**
 * @file display.h
 * @brief 
 * @version 0.1
 * @date 2020-02-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#pragma once
#ifndef DASH_DISPLAY_H
#define DASH_DISPLAY_H

#include <vector>
#include <cstdint>
#include <memory>

#include <FreeRTOS.h>
#include <semphr.h>

class Display {
public:
    Display(uint32_t rows, uint32_t cols);
    ~Display();

    /**
     * @brief Swap the front and back buffers. Will block until frame update
     * thread unlocks the front buffer. 
     */
    void swap();
private:
    std::unique_ptr<std::vector<uint8_t>> fb_front{};
    std::unique_ptr<std::vector<uint8_t>> fb_back{};
    /**
     * @brief simple mutual exclusion over buffer resource
     * frame writing thread will lock front buffer while updating screen.
     */
    SemaphoreHandle_t fb_front_lock = nullptr;
};

#endif // DASH_DISPLAY_H