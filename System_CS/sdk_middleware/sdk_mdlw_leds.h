/*! @file : sdk_mdlw_leds.h
 * @author  Alexander Huertas Sanchez
 * @version 1.0.0
 * @date    16/02/2021
 * @brief   Driver para 
 * @details
 *
 */
#ifndef SDK_MDLW_LEDS_H_
#define SDK_MDLW_LEDS_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "sdk_hal_gpio.h"

/*!
 * @addtogroup MIDDLEWARE
 * @{
 */
/*!
 * @addtogroup LEDS
 * @{
 */
/*******************************************************************************
 * Public Definitions
 ******************************************************************************/
#define LED_ROJO_PIN	KPTB6
#define LED_VERDE_PIN	KPTB7
#define LED_AZUL_PIN	KPTB10

/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Public vars
 ******************************************************************************/

/*******************************************************************************
 * Public Prototypes
 ******************************************************************************/

static inline void encenderLedRojo(void) {
	gpioPutValue(LED_ROJO_PIN, 0);
}

static inline void apagarLedRojo(void) {
	gpioPutValue(LED_ROJO_PIN, 1);
}

static inline void toggleLedRojo(void){
	gpioPutToggle(LED_ROJO_PIN);
}

static inline void encenderLedVerde(void) {
	gpioPutValue(LED_VERDE_PIN, 0);
}

static inline void apagarLedVerde(void) {
	gpioPutValue(LED_VERDE_PIN, 1);
}

static inline void toggleLedVerde(void){
	gpioPutToggle(LED_VERDE_PIN);
}

static inline void encenderLedAzul(void) {
	gpioPutValue(LED_AZUL_PIN, 0);
}

static inline void apagarLedAzul(void) {
	gpioPutValue(LED_AZUL_PIN, 1);
}

static inline void toggleLedAzul(void){
	gpioPutToggle(LED_AZUL_PIN);
}

/** @} */ // end of LEDS group
/** @} */ // end of MIDDLEWARE group

#endif /* SDK_MDLW_LEDS_H_ */
