/*! @file : sdk_hal_adc.c
 * @author  Maria Alejandra Pabon
 * @version 2.0.0
 * @date    25/02/2021
 * @brief   Driver para 
 * @details
 *
*/
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "sdk_hal_adc.h"
#include "fsl_adc16.h"

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
status_t adcInit(void) {
	adc16_config_t adc16ConfigStruct;	//Variable para almacenar tarjeta
	ADC16_GetDefaultConfig(&adc16ConfigStruct);	//Obtiene configuracion por defecto
	ADC16_Init(ADC0, &adc16ConfigStruct);//inicializa ADC con la configuración previa
	ADC16_EnableHardwareTrigger(ADC0, false); //configura tipo de inicio conversión "manual"
	return (kStatus_Success);
}
/*--------------------------------------------*/
status_t adcTomarCaptura(uint8_t canal_adc, uint32_t *resultado_adc) {
	adc16_channel_config_t adc16ChannelConfigStruct;

	adc16ChannelConfigStruct.channelNumber = canal_adc; //Selecciona canal ADC a utilizar
	adc16ChannelConfigStruct.enableInterruptOnConversionCompleted = false;//Deshabilita IRQ por ADC
	ADC16_SetChannelConfig(ADC0, 0U,&adc16ChannelConfigStruct);	//establece canal e inicia lectura ADC

	//Espera a terminar proceso de conversor ADC
	while (0U	== (kADC16_ChannelConversionDoneFlag & ADC16_GetChannelStatusFlags(ADC0,0))) {
	}

	*resultado_adc = ADC16_GetChannelConversionValue(ADC0, 0);

	return (kStatus_Success);
}
