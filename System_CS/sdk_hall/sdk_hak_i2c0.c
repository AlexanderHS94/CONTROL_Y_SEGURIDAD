/*! @file : sdk_hak_i2c0.c
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
#include "sdk_hal_i2c0.h"
#include "fsl_i2c.h"
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
status_t i2c0MasterInit(uint32_t baud_rate) {
	i2c_master_config_t masterConfig;

	I2C_MasterGetDefaultConfig(&masterConfig);
    masterConfig.baudRate_Bps = baud_rate;

    I2C_MasterInit(I2C0, &masterConfig, CLOCK_GetFreq(I2C0_CLK_SRC));
	return(kStatus_Success);
}
/*--------------------------------------------*/
status_t i2c0MasterReadByte(uint8_t *data, uint8_t bytes_to_read, uint8_t device_address, int8_t memory_address) {
	i2c_master_transfer_t masterXfer;
	status_t status;

    masterXfer.slaveAddress = device_address;
    masterXfer.direction = kI2C_Read;
    masterXfer.subaddress = (uint32_t)memory_address;
    masterXfer.subaddressSize = 1;
    masterXfer.data = data;
    masterXfer.dataSize = bytes_to_read;
    masterXfer.flags = kI2C_TransferDefaultFlag;

    status=I2C_MasterTransferBlocking(I2C0, &masterXfer);

    return(status);
}
/*--------------------------------------------*/
status_t i2c0MasterWriteByte(uint8_t *data, uint8_t bytes_to_write, uint8_t device_address, int8_t memory_address) {
	i2c_master_transfer_t masterXfer;
	status_t status;

    masterXfer.slaveAddress = device_address;
    masterXfer.direction = kI2C_Write;
    masterXfer.subaddress = (uint32_t)memory_address;
    masterXfer.subaddressSize = 1;
    masterXfer.data = data;
    masterXfer.dataSize = bytes_to_write;
    masterXfer.flags = kI2C_TransferDefaultFlag;

    status=I2C_MasterTransferBlocking(I2C0, &masterXfer);

    return(status);
}
