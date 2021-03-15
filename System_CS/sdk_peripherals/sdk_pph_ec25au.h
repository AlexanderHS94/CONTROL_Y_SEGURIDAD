/*! @file : sdk_pph_ec25au.h
 * @author  Alexander Huertas Sanchez
 * @version 1.0.0
 * @date    16/02/2021
 * @brief   Driver para 
 * @details
 *
 */
#ifndef SDK_PPH_EC25AU_H_
#define SDK_PPH_EC25AU_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "sdk_hal_uart0.h"

/*!
 * @addtogroup PPH
 * @{
 */
/*!
 * @addtogroup EC25AU
 * @{
 */
/*******************************************************************************
 * Public Definitions
 ******************************************************************************/
enum _ec25_lista_comandos_at {
kAT = 0,
kATI,
kAT_CPIN,
kAT_QCFG_CONFIG1,
kAT_QCFG_CONFIG2,
kAT_QCSQ,
kAT_CREG,
kAT_CGREG,
kAT_CEREG,
kAT_CGDCONT,
kAT_QIACT_1,
kAT_QIACT,
kAT_QMTOPEN,
kAT_QMTCONN,
kAT_QMTPUB_T,
kAT_MQTT_MSJ_T,
kAT_CFUN_0,
kAT_CFUN_1,
kAT_CSQ,
kAT_QLTS_2,
};

enum _fsm_ec25_state{
kFSM_INICIO=0,
kFSM_ENVIANDO_AT,
kFSM_ENVIANDO_ATI,
kFSM_ENVIANDO_CPIN,
kFSM_ENVIANDO_QCFG_CONFIG1,
kFSM_ENVIANDO_QCFG_CONFIG2,
kFSM_ENVIANDO_QCSQ,
kFSM_ENVIANDO_CREG,
kFSM_ENVIANDO_CGREG,
kFSM_ENVIANDO_CEREG,
kFSM_ENVIANDO_CGDCONT,
kFSM_ENVIANDO_QIACT_1,
kFSM_ENVIANDO_QIACT,
kFSM_ENVIANDO_QMTOPEN,
kFSM_ENVIANDO_QMTCONN,
kFSM_ENVIANDO_QMTPUB_T,
kFSM_ENVIANDO_MQTT_MSJ_T,
kFSM_ENVIANDO_CFUN_0,
kFSM_ENVIANDO_CFUN_1,
kFSM_ENVIANDO_CSQ,
kFSM_ESPERANDO_RESPUESTA,
kFSM_RESULTADO_ERROR,
kFSM_RESULTADO_EXITOSO,
kFSM_PROCESANDO_RESPUESTA,
kFSM_RESULTADO_ERROR_RSSI,
kFSM_RESULTADO_ERROR_QMTOPEN,
kFSM_RESULTADO_ERROR_QIACT_1,
kFSM_RESULTADO_ERROR_QMTPUB_T,
};

#define EC25_TIEMPO_MAXIMO_ESPERA	3		//Tiempo maximo que espera modem por respuesta
#define EC25_RSSI_MINIMO_ACEPTADO	20		//RSSI minimo aceptado segun tabla de fabricante
/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Public vars
 ******************************************************************************/

/*******************************************************************************
 * Public Prototypes
 ******************************************************************************/
status_t ec25Inicializacion(void);
status_t ec25EnviarMensajeDeTexto(uint8_t *mensaje, uint8_t size_mensaje );
uint8_t ec25Polling(void);
status_t lm35sensor(float adc_dato);
/** @} */ // end of X group
/** @} */ // end of X group

#endif /* SDK_PPH_EC25AU_H_ */
