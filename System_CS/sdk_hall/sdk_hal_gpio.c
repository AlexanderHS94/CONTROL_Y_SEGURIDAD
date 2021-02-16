/*! @file : sdk_hal_gpio.c
 * @author  Alexander Huertas Sanchez
 * @version 1.0.0
 * @date    16/02/2021
 * @brief   Driver para 
 * @details
 *
*/
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "sdk_hal_gpio.h"
#include "fsl_gpio.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Private Prototypes
 ******************************************************************************/


/*******************************************************************************
 * External vars
 ******************************************************************************/


/*******************************************************************************
 * Local vars
 ******************************************************************************/


/*******************************************************************************
 * Private Source Code
 ******************************************************************************/


/*******************************************************************************
 * Public Source Code
 ******************************************************************************/
/*--------------------------------------------*/
status_t gpioPutHigh(uint16_t pin_to_change) {

	uint16_t gpio_port_name;
	uint32_t gpio_pin_number;

	//Take 8MSB bits of pin_name for GPIOx PORT NAME
	gpio_port_name = pin_to_change & 0xFF00;
	gpio_port_name >>= 8;

	//Take 8LSB bits of pin_name for GPIOx PIN NUMBER
	gpio_pin_number = pin_to_change & 0x00FF;

	//only is available numbers for range (0-31)
	if (gpio_pin_number > 31)
		return (kStatus_Fail);

	//pin mask is calculated
	gpio_pin_number = 1 << (gpio_pin_number);

	//Call NXP_SDK_STACK to perform pin change
	switch (gpio_port_name) {
	case KGPIOA:
		GPIO_PortSet(GPIOA, gpio_pin_number);
		break;

	case KGPIOB:
		GPIO_PortSet(GPIOB, gpio_pin_number);
		break;

	default:
		return (kStatus_Fail);
		break;
	}

	return (kStatus_Success);
}
 /*--------------------------------------------*/
status_t gpioPutLow(uint16_t pin_to_change) {
	uint16_t gpio_port_name;
	uint32_t gpio_pin_number;

	//Take 8MSB bits of pin_name for GPIOx PORT NAME
	gpio_port_name = pin_to_change & 0xFF00;
	gpio_port_name >>= 8;

	//Take 8LSB bits of pin_name for GPIOx PIN NUMBER
	gpio_pin_number = pin_to_change & 0x00FF;

	//only is available numbers for range (0-31)
	if (gpio_pin_number > 31)
		return (kStatus_Fail);

	//pin mask is calculated
	gpio_pin_number = 1 << (gpio_pin_number);

	//Call NXP_SDK_STACK to perform pin change
	switch (gpio_port_name) {
	case KGPIOA:
		GPIO_PortClear(GPIOA, gpio_pin_number);
		break;

	case KGPIOB:
		GPIO_PortClear(GPIOB, gpio_pin_number);
		break;

	default:
		return (kStatus_Fail);
		break;
	}

	return (kStatus_Success);
}
 /*--------------------------------------------*/
status_t gpioPutValue(uint16_t pin_to_change, uint8_t new_value) {
	uint16_t gpio_port_name;
	uint32_t gpio_pin_number;

	//Take 8MSB bits of pin_name for GPIOx PORT NAME
	gpio_port_name = pin_to_change & 0xFF00;
	gpio_port_name >>= 8;

	//Take 8LSB bits of pin_name for GPIOx PIN NUMBER
	gpio_pin_number = pin_to_change & 0x00FF;

	//only is available numbers for range (0-31)
	if (gpio_pin_number > 31)
		return (kStatus_Fail);

	//Call NXP_SDK_STACK to perform pin change
	switch (gpio_port_name) {
	case KGPIOA:
		GPIO_PinWrite(GPIOA, gpio_pin_number,new_value);
		break;

	case KGPIOB:
		GPIO_PinWrite(GPIOB, gpio_pin_number,new_value);
		break;

	default:
		return (kStatus_Fail);
		break;
	}

	return (kStatus_Success);
}
 /*--------------------------------------------*/
status_t gpioPutToggle(uint16_t pin_to_change) {
	uint16_t gpio_port_name;
	uint32_t gpio_pin_number;

	//Take 8MSB bits of pin_name for GPIOx PORT NAME
	gpio_port_name = pin_to_change & 0xFF00;
	gpio_port_name >>= 8;

	//Take 8LSB bits of pin_name for GPIOx PIN NUMBER
	gpio_pin_number = pin_to_change & 0x00FF;

	//only is available numbers for range (0-31)
	if (gpio_pin_number > 31)
		return (kStatus_Fail);

	//pin mask is calculated
	gpio_pin_number = 1 << (gpio_pin_number);

	//Call NXP_SDK_STACK to perform pin change
	switch (gpio_port_name) {
	case KGPIOA:
		GPIO_PortToggle(GPIOA, gpio_pin_number);
		break;

	case KGPIOB:
		GPIO_PortToggle(GPIOB, gpio_pin_number);
		break;

	default:
		return (kStatus_Fail);
		break;
	}

	return (kStatus_Success);
}
