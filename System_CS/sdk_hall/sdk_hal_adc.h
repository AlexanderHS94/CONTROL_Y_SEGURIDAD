/*! @file : sdk_hal_adc.h
 * @author  Maria Alejandra Pabon
 * @version 2.0.0
 * @date    25/02/2021
 * @brief   Driver para 
 * @details
 *
*/
#ifndef SDK_HAL_ADC_H_
#define SDK_HAL_ADC_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "fsl_common.h"

/*!
 * @addtogroup HAL
 * @{
 */
/*!
 * @addtogroup ADC
 * @{
 */
/*******************************************************************************
 * Public Definitions
 ******************************************************************************/
/*!
 * @brief Lista de canales ADC y puertos a los que pertenece
 */
enum _adc_channel_list{
	PTA12_ADC0_SE0_CH0=0,
	PTB5_ADC0_SE1_CH1,
	PTA9_ADC0_SE2_CH2,
	PTA8_ADC0_SE3_Ch3,
	PTB2_ADC0_SE4_CH4,
	PTB1_ADC0_SE5_CH8=8,
	PTB0_ADC0_SE6_CH9,
	PTA7_ADC0_SE7_CH10,
	PTB11_ADC0_SE8_CH11,
	PTB10_ADC0_SE9_CH12,
	PTB9_ADC0_SE10__CH13,
	PTB8_ADC0_SE11_CH14,
	PTA0_ADC0_SE12_CH15,
	PTB13_ADC0_SE13_CH16,
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
 * @brief Inicializa modulo conversor analogico a digital
 *
 * @return	execution error code
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t adcInit(void);



/*!
 * @brief Toma una captura usando conversor analogico adigital
 *
 * @param canal_adc 			Canal ADC que será usado como entrada analogica
 * @param resultado_adc 		Apuntador de memoria donde será almacenado el resultado
 *
 * @return	execution error code
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t adcTomarCaptura(uint8_t canal_adc, uint32_t *resultado_adc);


/** @} */ // end of ADC group
/** @} */ // end of HAL group

#endif /* SDK_HAL_ADC_H_ */
