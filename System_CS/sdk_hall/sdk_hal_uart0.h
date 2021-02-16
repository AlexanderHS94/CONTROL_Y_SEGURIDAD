/*! @file : sdk_hal_uart0.h
 * @author  Alexander Huertas Sanchez
 * @version 1.0.0
 * @date    16/02/2021
 * @brief   Driver para 
 * @details
 *
 */
#ifndef SDK_HAL_UART0_H_
#define SDK_HAL_UART0_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "fsl_common.h"

/*!
 * @addtogroup HAL
 * @{
 */
/*!
 * @addtogroup UART0
 * @{
 */
/*******************************************************************************
 * Public Definitions
 ******************************************************************************/
/*! @brief Tamaño de buffer circular para recibir datos por UART (Unit: Byte). */
#define LONGITUD_BUFFER_CIRCULAR 	100

/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Public vars
 ******************************************************************************/

/*******************************************************************************
 * Public Prototypes
 ******************************************************************************/
/*--------------------------------------------*/
/*!
 * @brief Inicializa UART0 al baudrate especificado
 *
 * @param baud_rate   baudrate (bps) que se quiere configurado en UART0
 * @return            estado de la ejecución
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * 		kStatus_ReadOnly
 * 		kStatus_OutOfRange
 * 		kStatus_InvalidArgument
 * 		kStatus_Timeout
 * 		kStatus_NoTransferInProgress
 * @endcode
 */
status_t uart0Inicializar(uint32_t baud_rate);
/*--------------------------------------------*/
/*!
 * @brief Calcula el numero de datos nuevos que hay en el buffer circular
 *
 * @return	numero de bytes que estan pendientes por ser procesados
 * @endcode
 */
uint16_t uart0CuantosDatosHayEnBuffer(void);
/*--------------------------------------------*/
/*!
 * @brief Obtiene 1 byte desde buffer circular
 *
 * @param nuevo_byte	apuntador de memoria donde almacenar nuevo byte
 * @return	estado de la ejecución
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t uart0LeerByteDesdeBuffer(uint8_t *nuevo_byte);

/** @} */ // end of UART0 group
/** @} */ // end of HAL group

#endif /* SDK_HAL_UART0_H_ */
