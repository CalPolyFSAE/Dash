/**
 * @file spi.cpp
 * @version 0.1
 * @date 2019-12-14
 */

#include <spi.h>

using namespace bsp::spi;

bool SPIManager::setConfig(uint32_t base, const SPIConfig& config) noexcept {
    return LPSPI_RTOS_Init(&handle[base], SPIBases[base], &(config.masterConfig), config.srcClock_Hz) == kStatus_Success;
}

void SPIManager::reset(uint32_t base) noexcept {
    LPSPI_Reset(SPIBases[base]);
}

bool SPIManager::transfer(uint32_t base, uint8_t* txbuffer, uint8_t* rxbuffer, size_t size, _lpspi_transfer_config_flag_for_master flags) noexcept {
    lpspi_transfer_t transfer_data{};
    transfer_data.txData = txbuffer;
    transfer_data.rxData = rxbuffer;
    transfer_data.dataSize = size;
    transfer_data.configFlags = flags;
    return LPSPI_RTOS_Transfer(&handle[base], &transfer_data) == kStatus_Success;
}

SPIManager::SPIManager() noexcept {

}

SPIManager::~SPIManager() {
    if(handle[0].async_status != 0)
        LPSPI_RTOS_Deinit(&handle[0]);
    if(handle[1].async_status != 0)
        LPSPI_RTOS_Deinit(&handle[1]);
}

