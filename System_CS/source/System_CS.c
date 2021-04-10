/*
 * Copyright 2016-2021 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    System_CS.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL02Z4.h"
#include "fsl_debug_console.h"

/* TODO: insert other include files here. */
/*******************************************************************************
 * Includes Librerias SDK_HALL
******************************************************************************/
#include "sdk_hal_gpio.h"
#include "sdk_hal_uart0.h"
#include "sdk_hal_i2c0.h"
#include "sdk_hal_adc.h"
/*******************************************************************************
 * Includes Librerias SDK para optimizacion de codigo
******************************************************************************/
#include "sdk_mdlw_leds.h"
#include "sdk_pph_ec25au.h"

/* TODO: insert other definitions and declarations here. */
/*******************************************************************************/
 #define HABILITAR_ENTRADA_ADC_PTB8	1

 /* Local vars
 ******************************************************************************/

uint8_t mensaje_de_texto[]="Hola desde EC25";



void waytTime(void) {
	uint32_t tiempo = 0xFFFFF;
	do {
		tiempo--;
	} while (tiempo != 0x0000);
}

/*
 * @brief   Application entry point.
 */
int main(void) {


	 uint32_t adc_dato2;
	 float SensorTemp;
	 uint32_t conv;
	 uint8_t adc_base_de_tiempos2=0;
	 uint8_t estado_actual_ec25;

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif


    //inicializa puerto UART0 y solo avanza si es exitoso el proceso
        if(uart0Inicializar(115200)!=kStatus_Success){	//115200bps
        	return 0 ;
        }

    //inicializa puerto I2C0 y solo avanza si es exitoso el proceso
        if(i2c0MasterInit(100000)!=kStatus_Success){	//100kbps
        	return 0 ;
        }
    //inicializa todas las funciones necesarias para trabajar con el modem EC25
    ec25Inicializacion();
    ec25InicializarMQTT();
    ec25EnviarMensajeDeTexto(&mensaje_de_texto[0], sizeof(mensaje_de_texto));

    /* Force the counter to be placed into memory. */
    /* Enter an infinite loop, just incrementing a counter. */

#if HABILITAR_ENTRADA_ADC_PTB8
    //Inicializa conversor analogo a digital
    //Se debe usar  PinsTools para configurar los pines que van a ser analogicos
    printf("Inicializa ADC \r\n");
    if(adcInit()!=kStatus_Success){
    	printf("Error");
    	return 0 ;
    }
    //printf("OK\r\n");
#endif


    while(1) {
    	waytTime();		//base de tiempo fija aproximadamente 200ms

#if HABILITAR_ENTRADA_ADC_PTB8
    	adc_base_de_tiempos2++;//incrementa base de tiempo para tomar una lectura ADC
    	if(adc_base_de_tiempos2>10){	// >10 equivale aproximadamente a 2s
    		adc_base_de_tiempos2=0;	//reinicia contador de tiempo
    		adc_dato2=0;
    		SensorTemp=0.0;
    		adcTomarCaptura(PTB8_ADC0_SE11_CH14, &adc_dato2);	//inicia lectura por ADC y guarda en variable adc_dato
    		//printf("ADC ->");
    		//printf("PTB8:%d ",adc_dato2);	//imprime resultado ADC
    		//printf("\r\n");	//Imprime cambio de linea
    		conv=(1.1*adc_dato2*100)/4096;
    		SensorTemp= 90-conv;
    		//printf("temp2C :%d ", adc_dato2);
    		//printf("temp2C :%d", SensorTemp);
    		//printf("\r\n");
    	}
#endif

    	estado_actual_ec25 = ec25Polling();	//actualiza maquina de estados encargada de avanzar en el proceso interno del MODEM

    	switch(estado_actual_ec25){

    	case kFSM_RESULTADO_ERROR:
    		toggleLedRojo();
    		apagarLedVerde();
    		apagarLedAzul();
    		break;

    	case kFSM_RESULTADO_EXITOSO:
    		apagarLedRojo();
    		//toggleLedVerde();
    		apagarLedAzul();
    		break;

    	case kFSM_RESULTADO_ERROR_RSSI:
    		toggleLedRojo();
    		//apagarLedVerde();
    		toggleLedAzul();
    		break;
    	case kFSM_ENVIANDO_MQTT_MSJ_T:
    		lm35sensor(SensorTemp);
    		break;

    	default:
    		apagarLedRojo();
    		//apagarLedVerde();
    		toggleLedAzul();
    		break;

    	}
    }
    return 0 ;
}

