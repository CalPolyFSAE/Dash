/**
 * @file display.cpp
 * @date 2019-12-14
 */
#include <st7920.h>

#include <spi.h>
#include <util.h>

using namespace bsp;

ST7920::ST7920(uint32_t lpspi_ind, uint32_t command_delay) : 
    CommandDelay{command_delay}, LPSPI_Ind{lpspi_ind} {

}

ST7920::~ST7920() {

}

bool ST7920::initDisplay() {

}

void ST7920::displayString(uint8_t line, const std::string& str) {
    for(uint32_t i = 0; i < str.length(); i++) {
        write(str.data()[i]);
    }
}

void ST7920::writeGRAM(const uint8_t* data, uint32_t len) {
    uint32_t count = 0;
    for(uint8_t y = 0; y < 64 && count < len; y++) {
        if(y < 32) {
            gramAddress(y);
            gramAddress(0x00);
        } else {
            gramAddress((y-32));
            gramAddress(0x08);
        }
        for(uint8_t x = 0; x < 16 && count < len; x++, count++) {
            write(data[count]);
        }
    }
    gramAddress(0x00);
    gramAddress(0x00);
}

void ST7920::clearGRAM() {
    for(uint8_t y = 0; y < 64; y++) {
        if(y < 32) {
            gramAddress(y);
            gramAddress(0x00);
        } else {
            gramAddress((y-32));
            gramAddress(0x08);
        }
        for(uint8_t x = 0; x < 16; x++) {
            write(0x00);
        }
    }
    gramAddress(0x00);
    gramAddress(0x00);
}

void ST7920::command(uint8_t cmd, const uint32_t delay) {
    spi::SPIManager& spimanager = spi::SPIManager::getInstance();
    uint8_t tx[3];
    tx[0] = CommandHeader;
    tx[1] = 0xF0 & cmd;
    tx[2] = 0xF0 & (cmd << 4);
    spimanager.transfer(LPSPI_Ind, tx, nullptr, 3);
    dash_util::delay_us(delay);
}

void ST7920::write(uint8_t data, uint32_t delay) {
    spi::SPIManager& spimanager = spi::SPIManager::getInstance();
    uint8_t tx[3];
    tx[0] = WriteHeader;
    tx[1] = 0xF0 & data;
    tx[2] = 0xF0 & (data << 4);
    spimanager.transfer(LPSPI_Ind, tx, nullptr, 3);
    dash_util::delay_us(delay);
}