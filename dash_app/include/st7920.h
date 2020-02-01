/**
 * @file ST7920.h
 * @date 2019-12-14
 */
#pragma once
#ifndef DASH_ST7920_H
#define DASH_ST7920_H

#include <stdint.h>

#include <string>

class ST7920 {
public:
    /**
     * @brief Construct a new ST7920 object
     * 
     * @param lpspi_ind index of LPSPI controller to use [0, 1]
     * @param command_delay approximate microsecond delay between consecutive SPI commands to ST7920
     */
    ST7920(uint32_t lpspi_ind = 0, uint32_t command_delay = 72);
    ~ST7920();

    static constexpr uint8_t CommandHeader  = 0xF8;

    static constexpr uint8_t ReadHeader     = 0xFA;
    static constexpr uint8_t ReadDataMask   = 0xFF;

    static constexpr uint8_t WriteHeader    = 0xFB;
    static constexpr uint8_t WriteDataMask  = 0xFF;

    static constexpr uint8_t BasicClearCommand          = 0x01;

    static constexpr uint8_t BasicHomeCommand           = 0x02;

    static constexpr uint8_t BasicEntryModeCommand      = 0x04;
    static constexpr uint8_t BasicEntryModeIDMask       = 0x02; // address counter control, 1: increase, 0: decrease
    static constexpr uint8_t BasicEntryModeSMask        = 0x01; // display shift enable

    static constexpr uint8_t BasicDisplayControlCommand = 0x08;
    static constexpr uint8_t BasicDisplayControlDENMask = 0x04; // display on
    static constexpr uint8_t BasicDisplayControlCMask   = 0x02; // cursor on 
    static constexpr uint8_t BasicDisplayControlBMask   = 0x01; // character blink on

    static constexpr uint8_t BasicCDShiftControlCommand = 0x10; // Cursor/Display Shift Control
    static constexpr uint8_t BasicCDShiftControlSCMask  = 0x08; // enable display shifting
    static constexpr uint8_t BasicCDShiftControlRLMask  = 0x04;

    static constexpr uint8_t FunctionSetCommand         = 0x20;
    static constexpr uint8_t FunctionSetDLMask          = 0x10; // parallel interface mode
    static constexpr uint8_t FunctionSetREMask          = 0x04; // use extended function set
    static constexpr uint8_t ExtendedFunctionSetGMask   = 0x02; // graphic display on

    static constexpr uint8_t SetRAMCommand              = 0x80;
    static constexpr uint8_t BasicSetDDRAMAddressMask   = 0x7F;
    static constexpr uint8_t ExtendedSetGRAMAddressMask = 0x3F;

    static constexpr uint32_t Width         = 128;
    static constexpr uint32_t Height        = 64;
    static constexpr uint32_t VRAMLength    = Width * Height / sizeof(uint8_t);

    /**
     * @brief configure and reset display
     * 
     * @return true 
     * @return false 
     */
    bool initDisplay();

    /**
     * @brief Write a string into DDRAM to display on screen
     * 
     * @param line line number can be [1,4]
     * @param str string to write
     */
    void displayString(uint8_t line, const std::string& str);

    /**
     * @brief Write the ST7920 GRAM data starting at upper left of screen
     */
    void writeGRAM(const uint8_t* data, uint32_t len);

    /**
     * @brief Write all zeros to GRAM
     */
    void clearGRAM();

    /**
     * @brief Write all spaces to ST7920 DDRAM, clearing it. DDRAM address is also set to 0
     */
    inline void clearDDRAM() {
        extendedCommandMode(false);
        command(BasicClearCommand);
    }

    /**
     * @brief Enable or disable LCD display
     * 
     * @param enabled 
     */
    void display(bool enabled) {
        extendedCommandMode(false);
        command(BasicDisplayControlCommand | (enabled ? BasicDisplayControlDENMask : 0));
    }

    /**
     * @brief Enable or disable display of graphic memory
     * 
     * @param enabled true to enable
     */
    inline void graphicDisplay(bool enabled) {
        extendedCommandMode(true);
        command(FunctionSetCommand | (enabled ? ExtendedFunctionSetGMask : 0));
    }

private:
    bool extendedMode = false;

    const uint32_t CommandDelay;
    const uint32_t LPSPI_Ind;

    /**
     * @brief set ddram address for read or write
     * 
     * @param addr 
     */
    inline void ddramAddress(uint8_t addr) {
        addr = std::min(addr, BasicSetDDRAMAddressMask); // clamp address
        command(SetRAMCommand | addr);
    }

    /**
     * @brief Set GRAM address for read or write
     * 
     * @param addr 
     */
    inline void gramAddress(uint8_t addr) {
        addr = std::min(addr, ExtendedSetGRAMAddressMask); // clamp address
        command(SetRAMCommand | addr);
    }

    /**
     * @brief Set the Extended Command Mode. Must be actve to use graphic mode
     * 
     * @param enabled true to enable
     */
    inline void extendedCommandMode(bool enabled) {
        if(extendedMode != enabled) {
            command(FunctionSetCommand | (enabled ? FunctionSetREMask : 0));
            extendedMode = enabled;
        }
    }

    /**
     * @brief Set GRAM address
     * 
     * @param y y pixel (vertical address)
     * @param col column
     */
    void setGRAMWritePosition(uint8_t y, uint8_t col);

    /**
     * @brief send command over SPI and wait delay microseconds
     * 
     * @param cmd 
     * @param delay microseconds to wait after command sends
     */
    void command(uint8_t cmd, uint32_t delay);

    /**
     * @brief send write command over SPI and wait delay microseconds
     * 
     * @param data 
     * @param delay microseconds to wait after command sends
     */
    void write(uint8_t data, uint32_t delay);

    void command(uint8_t cmd) { command(cmd, CommandDelay); }
    void write(uint8_t data) { write(data, CommandDelay); }
};

#endif // DASH_ST7920_H