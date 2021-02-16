/*! @file : sdk_hal_i2c0.h
 * @author  Alexander Huertas Sanchez
 * @version 1.0.0
 * @date    16/02/2021
 * @brief   Driver para 
 * @details
 *
 */
#ifndef SDK_HAL_I2C0_H_
#define SDK_HAL_I2C0_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "fsl_common.h"


/*!
 * @addtogroup HAL
 * @{
 */
/*!
 * @addtogroup I2C
 * @{
 */
/*******************************************************************************
 * Public Definitions
 ******************************************************************************/

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
 * @brief Perform a I2C0 initialization
 *
 * @param baud_rate   baudrate (bps) for I2C module
 * @return            status for process
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t i2c0MasterInit(uint32_t baud_rate);
/*--------------------------------------------*/
/*!
 * @brief Read byte from I2C0 devide
 *
 * @param data				memory adderess pointer
 * @param bytes_to_read		number of byte to read form i2c device
 * @param device_address	I2C address
 * @return            resultado de la ejecución
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t i2c0MasterReadByte(uint8_t *data, uint8_t bytes_to_read, uint8_t device_address, int8_t memory_address);
/*--------------------------------------------*/
/*!
 * @brief Write byte to I2C0 devide
 *
 * @param data				memory adderess pointer
 * @param bytes_to_read		number of byte to write on i2c device
 * @param device_address	I2C address
 * @return            resultado de la ejecución
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t i2c0MasterWriteByte(uint8_t *data, uint8_t bytes_to_write, uint8_t device_address, int8_t memory_address);



/** @} */ // end of I2C0 group
/** @} */ // end of HAL group

#endif /* SDK_HAL_I2C0_H_ */
