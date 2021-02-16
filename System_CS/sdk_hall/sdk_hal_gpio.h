/*! @file : sdk_hal_gpio.h
 * @author  Alexander Huertas Sanchez
 * @version 1.0.0
 * @date    16/02/2021
 * @brief   Driver para 
 * @details
 *
 */
#ifndef SDK_HAL_GPIO_H_
#define SDK_HAL_GPIO_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "fsl_common.h"

/*!
 * @addtogroup HAL
 * @{
 */
/*!
 * @addtogroup GPIO
 * @{
 */
/*******************************************************************************
 * Public Definitions
 ******************************************************************************/
/*!
 * @brief list  of gpio port available on KL02Z microcontrollers.
 */
enum _gpio_port_list_available
{
	KGPIOA=0X00,
	KGPIOB
};

/*!
 * @brief list  of gpio pin available on KL02Z microcontrollers.
 */
enum _gpio_pin_list_available
{
	/*!< GPIOA*/
	KPTA0 = 0x0000,	/*!< PTA0/IRQ_0/SWD_CLK ADC0_SE12/CMP0_IN2/TPM1_CH0*/
	KPTA1,	/*!< PTA1/IRQ_1/LPTMR0_ALT1/RESET_b*/
	KPTA2,	/*!< PTA2/SWD_DIO/CMP0_OUT*/
	KPTA3,	/*!< PTA3/EXTAL0/I2C0_SCL/I2C1_SDA*/
	KPTA4,	/*!< PTA4/XTAL0/I2C0_SDA/I2C1_SCL*/
	KPTA5,	/*!< PTA5/TPM0_CH1/SPI0_SS_b*/
	KPTA6,	/*!< PTA6/TPM0_CH0/SPI0_MISO*/
	KPTA7,	/*!< PTA7/IRQ_4/ADC0_SE7/SPI0_MISO/SPI0_MOSI*/
	KPTA8,	/*!< PTA8/ADC0_SE3/I2C1_SCL*/
	KPTA9,	/*!< PTA9/ADC0_SE2/I2C1_SDA*/
	KPTA10,	/*!< PTA10/IRQ_8*/
	KPTA11,	/*!< PTA11/IRQ_9*/
	KPTA12,	/*!< PTA12/IRQ_13/LPTMR0_ALT2/ADC0_SE0/CMP0_IN0/TPM1_CH0/TPM_CLKIN0*/
	KPTA13,	/*!< PTA13*/
	KPTA14,	/*!< Not available*/
	KPTA15,	/*!< Not available*/

	/*!< GPIOB*/
	KPTB0 = 0x0100,	/*!< PTB0/IRQ_5/ADC0_SE6/EXTRG_IN/SPI0_SCK*/
	KPTB1,	/*!< PTB1/IRQ_6/ADC0_SE5/CMP0_IN3/UART0_TX/UART0_RX*/
	KPTB2,	/*!< PTB2/IRQ_7/ADC0_SE4/UART0_RX/UART0_TX*/
	KPTB3,	/*!< PTB3/IRQ_10/I2C0_SCL/UART0_TX*/
	KPTB4,	/*!< PTB4/IRQ_11/I2C0_SDA UART0_RX*/
	KPTB5,	/*!< PTB5/IRQ_12/NMI_b/ADC0_SE1/CMP0_IN1/TPM1_CH1*/
	KPTB6,	/*!< PTB6/IRQ_2/LPTMR0_ALT3/TPM1_CH1/TPM_CLKIN1*/
	KPTB7,	/*!< PTB7/IRQ_3/TPM1_CH0*/
	KPTB8,	/*!< PTB8/ADC0_SE11*/
	KPTB9,	/*!< PTB9/ADC0_SE10*/
	KPTB10,	/*!< PTB10/ADC0_SE9/TPM0_CH1*/
	KPTB11,	/*!< PTB11/ADC0_SE8/TPM0_CH0*/
	KPTB12,	/*!< PTB12*/
	KPTB13,	/*!< PTB13/ADC0_SE13/TPM1_CH1*/
	KPTB14,	/*!< Not available*/
	KPTB15,	/*!< Not available*/
};
/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Public vars
 ******************************************************************************/

/*******************************************************************************
 * Public Prototypes
 ******************************************************************************/
/*!
 * @brief Set specific pin to high value
 *
 * @param pin_to_change	pin name code
 * @see	_gpio_pin_list_available
 * @return	execution error code
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t gpioPutHigh(uint16_t pin_to_change);
/*!
 * @brief Set specific pin to low value
 *
 * @param pin_to_change	pin name code
 * @see	_gpio_pin_list_available
 * @return	execution error code
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t gpioPutLow(uint16_t pin_to_change);
/*!
 * @brief Set specific pin to new specific value
 *
 * @param pin_to_change	pin name code
 * @see	_gpio_pin_list_available
 * @param new_value new value to be pushed on specific pin
 * @return	execution error code
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t gpioPutValue(uint16_t pin_to_change, uint8_t new_value);
/*!
 * @brief Set toggle on specific pin
 *
 * @param pin_to_change	pin name code
 * @see	_gpio_pin_list_available
 * @return	execution error code
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t gpioPutToggle(uint16_t pin_to_change);

/** @} */ // end of GPIO group
/** @} */ // end of HAL group

#endif /* SDK_HAL_GPIO_H_ */
