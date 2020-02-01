/**
 * @file fontRenderer.h
 * @author Hunter Borlik
 * @brief Draw bitmap fonts to bitmap
 * @version 0.1
 * @date 2019-12-17
 */
#pragma once
#ifndef DASH_FONT_RENDERER_H
#define DASH_FONT_RENDERER_H

#include <string>

#include <stdint.h>

class FontRenderer {
public:
    FontRenderer(uint8_t* vram_ptr, uint32_t width, uint32_t height);
    ~FontRenderer();

    /**
     * @brief Draw font bitmap at coordinate in vram
     * 
     * @param x x pixel coordinate
     * @param y y pixel coordiante
     * @param c character to draw
     * @param trim enable trimming of extra blank space around character
     * @return uint8_t character width
     */
    uint8_t drawFontAt(uint8_t x, uint8_t y, char c, bool trim);

    /**
     * @brief 
     * 
     * @param x 
     * @param y 
     * @param str string to draw
     * @param spacing pixel spacing between consecutive characters
     * @param trim enable trimming of extra space in front of and behind character
     * @param wrap_w wrap line after width, 0 to disable 
     */
    void drawFontStringAt(uint8_t x, uint8_t y, const std::string& str, uint32_t spacing, bool trim, uint8_t wrap_w = 0);

private:
    const uint32_t Width, Height;
    uint8_t vram[];
};

#endif // DASH_FONT_RENDERER_H