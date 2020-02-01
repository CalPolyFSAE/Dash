/**
 * @file spi.h
 * @brief FreeRTOS spi library wrapper
 * @version 0.1
 * @date 2019-12-14
 */
#pragma once
#ifndef BSP_SPI_H
#define BSP_SPI_H

#include <MKE18F16.h>
#include <fsl_lpspi_freertos.h>
#include <fsl_clock.h>

#include <static_instance.h>

namespace bsp {
namespace spi {

LPSPI_Type* const SPIBases[2] = {LPSPI0, LPSPI1};
const clock_ip_name_t SPIIpClockNames[2] = {kCLOCK_Lpspi0, kCLOCK_Lpspi1};

struct SPIConfig {
    SPIConfig(uint32_t base) {
        srcClock_Hz = CLOCK_GetIpFreq(SPIIpClockNames[base]);
        LPSPI_MasterGetDefaultConfig(&masterConfig);
    }
    ~SPIConfig() {}

    uint32_t srcClock_Hz;
    lpspi_master_config_t masterConfig;
};

class SPIManager : public util::StaticInstance<SPIManager> {
public:
    SPIManager(const SPIManager&) = delete;
    SPIManager(SPIManager&&) = delete;

    SPIManager& operator=(const SPIManager&) = delete;
    SPIManager& operator=(SPIManager&&) = delete;

    /**
     * @brief Set the Config
     * 
     * @param base LPSPI hardware base index
     * @param config 
     * @return true 
     * @return false 
     */
    bool setConfig(uint32_t base, const SPIConfig& config) noexcept;

    /**
     * @brief Performs a SPI transfer
     * 
     * @param txbuffer pointer to tx buffer
     * @param rxbuffer pointer to rx bffer
     * @param size length of the buffers
     * @param flags transfer flags, defaults to CS0 with no byte swap
     * @return true 
     * @return false 
     */
    bool transfer(uint32_t base, uint8_t* txbuffer, uint8_t* rxbuffer, size_t size, _lpspi_transfer_config_flag_for_master flags = kLPSPI_MasterPcs0) noexcept;

    /**
     * @brief reset LPSPI hardware
     * 
     * @param base LPSPI hardware base index
     */
    void reset(uint32_t base) noexcept;

private:
    friend util::StaticInstance<SPIManager>;
    SPIManager() noexcept;
    ~SPIManager();

    lpspi_rtos_handle_t handle[2]{};
};

} // spi
} // bsp

#endif // BSP_SPI_H