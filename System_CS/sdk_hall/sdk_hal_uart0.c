/*! @file : sdk_hal_uart0.c
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
#include "sdk_hal_uart0.h"
#include "fsl_lpsci.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief Define nombre interno de funcion para gestionar interrupción por dato UART */
#define UART0_IRQ_FUNCTION 	UART0_IRQHandler

/*! @brief Define nombre interno de funcion para gestionar interrupción por dato UART */
#define UART_IRQ_INDEX 		UART0_IRQn

/*******************************************************************************
 * Private Prototypes
 ******************************************************************************/


/*******************************************************************************
 * External vars
 ******************************************************************************/


/*******************************************************************************
 * Local vars
 ******************************************************************************/
uint8_t uart0_buffer_circular[LONGITUD_BUFFER_CIRCULAR];
volatile uint16_t txIndex; /* Index of the data to send out. */
volatile uint16_t rxIndex; /* Index of the memory to save new arrived data. */

/*******************************************************************************
 * Private Source Code
 ******************************************************************************/
/*--------------------------------------------*/
/*!
 * @brief Funcion que gestiona IRQ por UART0
 */
void UART0_IRQ_FUNCTION(void)
{
    uint8_t data;

    if ((kLPSCI_RxDataRegFullFlag)&LPSCI_GetStatusFlags(UART0))
    {
        data = LPSCI_ReadByte(UART0);

        if (((rxIndex + 1) % LONGITUD_BUFFER_CIRCULAR) != txIndex)
        {
            uart0_buffer_circular[rxIndex] = data;
            rxIndex++;
            rxIndex %= LONGITUD_BUFFER_CIRCULAR;
        }
    }
}
/*--------------------------------------------*/
/*******************************************************************************
 * Public Source Code
 ******************************************************************************/
/*--------------------------------------------*/
status_t uart0Inicializar(uint32_t baud_rate) {
	lpsci_config_t config;
	status_t status;

	LPSCI_GetDefaultConfig(&config);
	config.baudRate_Bps = baud_rate;
	config.enableTx = true;
	config.enableRx = true;

	status=LPSCI_Init(UART0, &config, CLOCK_GetFreq(kCLOCK_McgFllClk));
	if (status != kStatus_Success)
		return (status);

	LPSCI_EnableInterrupts(UART0, kLPSCI_RxDataRegFullInterruptEnable);

	status=EnableIRQ(UART_IRQ_INDEX);

	return(status);
}
/*--------------------------------------------*/
uint16_t uart0CuantosDatosHayEnBuffer(void) {
	return ((uint16_t) (rxIndex - txIndex));
}
/*--------------------------------------------*/
status_t uart0LeerByteDesdeBuffer(uint8_t *nuevo_byte) {
	if ((kLPSCI_TxDataRegEmptyFlag & LPSCI_GetStatusFlags(UART0)) && (rxIndex != txIndex)) {
		*nuevo_byte = uart0_buffer_circular[txIndex];
		txIndex++;
		txIndex %= LONGITUD_BUFFER_CIRCULAR;
		return (kStatus_Success);
	} else {
		return (kStatus_Fail);
	}
}
