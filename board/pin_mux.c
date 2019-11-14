/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v5.0
processor: MKE18F512xxx16
package_id: MKE18F512VLH16
mcu_data: ksdk2_0
processor_version: 5.0.0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '31', peripheral: LPSPI0, signal: SIN, pin_signal: ADC0_SE7/PTB3/FTM1_CH1/LPSPI0_SIN/FTM1_QD_PHA/TRGMUX_IN2}
  - {pin_num: '18', peripheral: LPSPI0, signal: PCS1_HREQ, pin_signal: PTB5/FTM0_CH5/LPSPI0_PCS1/TRGMUX_IN0/ACMP1_OUT}
  - {pin_num: '32', peripheral: LPSPI0, signal: SCK, pin_signal: ADC0_SE6/PTB2/FTM1_CH0/LPSPI0_SCK/FTM1_QD_PHB/TRGMUX_IN3}
  - {pin_num: '19', peripheral: LPSPI0, signal: SOUT, pin_signal: ACMP1_IN2/PTB4/FTM0_CH4/LPSPI0_SOUT/TRGMUX_IN1}
  - {pin_num: '28', peripheral: GPIOC, signal: 'GPIO, 16', pin_signal: ADC0_SE14/PTC16/FTM1_FLT2/LPI2C1_SDAS}
  - {pin_num: '14', peripheral: GPIOD, signal: 'GPIO, 16', pin_signal: ACMP2_IN0/PTD16/FTM0_CH1}
  - {pin_num: '27', peripheral: GPIOC, signal: 'GPIO, 17', pin_signal: ADC0_SE15/PTC17/FTM1_FLT3/LPI2C1_SCLS}
  - {pin_num: '25', peripheral: GPIOC, signal: 'GPIO, 1', pin_signal: ADC0_SE9/ACMP1_IN3/PTC1/FTM0_CH1/FTM1_CH7}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void)
{
    /* Clock Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortB);
    /* Clock Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortC);
    /* Clock Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortD);

    /* PORTB2 (pin 32) is configured as LPSPI0_SCK */
    PORT_SetPinMux(PORTB, 2U, kPORT_MuxAlt3);

    /* PORTB3 (pin 31) is configured as LPSPI0_SIN */
    PORT_SetPinMux(PORTB, 3U, kPORT_MuxAlt3);

    /* PORTB4 (pin 19) is configured as LPSPI0_SOUT */
    PORT_SetPinMux(PORTB, 4U, kPORT_MuxAlt3);

    /* PORTB5 (pin 18) is configured as LPSPI0_PCS1 */
    PORT_SetPinMux(PORTB, 5U, kPORT_MuxAlt3);

    /* PORTC1 (pin 25) is configured as PTC1 */
    PORT_SetPinMux(PORTC, 1U, kPORT_MuxAsGpio);

    /* PORTC16 (pin 28) is configured as PTC16 */
    PORT_SetPinMux(PORTC, 16U, kPORT_MuxAsGpio);

    /* PORTC17 (pin 27) is configured as PTC17 */
    PORT_SetPinMux(PORTC, 17U, kPORT_MuxAsGpio);

    /* PORTD16 (pin 14) is configured as PTD16 */
    PORT_SetPinMux(PORTD, 16U, kPORT_MuxAsGpio);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
