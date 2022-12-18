/*
 * main.c
 *
 *  Created on: Dec 4, 2022
 *      Author: Serghei
 */

/*Exercise
 * Using HSE Configure the SYSCLK as 8MHz.
 * AHB	as 4MHZ (HCLK)
 * APB1	as 2MHz	(PCLK1)
 * APB2	as 2MHz	(PCLK2)*/


#include <string.h>
#include "stm32f4xx_hal.h"
#include "main.h"

#define TRUE 	1U
#define FALSE 	0U

void UART2_Init(void);
void Error_handler(void);

UART_HandleTypeDef huart2;

/*************************MAIN************************************/
int main (void){

	RCC_OscInitTypeDef osc_init;
	RCC_ClkInitTypeDef clk_init;
	char msg[100];


	HAL_Init();
	UART2_Init();

	memset (&osc_init, 0, sizeof(osc_init));

	osc_init.OscillatorType=RCC_OSCILLATORTYPE_HSE;
	osc_init.HSEState=RCC_HSE_BYPASS;
	if (HAL_RCC_OscConfig(&osc_init) !=HAL_OK)
	{
		Error_handler();
	}

	clk_init.ClockType=RCC_CLOCKTYPE_SYSCLK |RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	clk_init.SYSCLKSource=RCC_SYSCLKSOURCE_HSE;
	clk_init.AHBCLKDivider=RCC_SYSCLK_DIV2;
	clk_init.APB1CLKDivider=RCC_HCLK_DIV2;
	clk_init.APB2CLKDivider=RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&clk_init,FLASH_ACR_LATENCY_0WS)  !=HAL_OK)
	{
		//There is a problem
		Error_handler();
	}

/***********************************After this line SYSCLK is SOURCED BY HSE**************/

	__HAL_RCC_HSI_DISABLE();	//save some current

	/*Lets redo the SYSTICK configuration*/
	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

	UART2_Init();	//initiam UARTul iarasi deoarece a fost initializat cu alta freqventa

	memset(msg,0,sizeof(msg));
	sprintf(msg, "SYSCLK : %ld Hz\r\n", HAL_RCC_GetSysClockFreq());
	HAL_UART_Transmit(&huart2,(uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	memset(msg,0,sizeof(msg));
	sprintf(msg, "HCLK : %ld Hz\r\n", HAL_RCC_GetHCLKFreq());
	HAL_UART_Transmit(&huart2,(uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	memset(msg,0,sizeof(msg));
	sprintf(msg, "PCLK1 : %ld Hz\r\n", HAL_RCC_GetPCLK1Freq());
	HAL_UART_Transmit(&huart2,(uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	memset(msg,0,sizeof(msg));
	sprintf(msg, "PCLK2 : %ld Hz\r\n", HAL_RCC_GetPCLK2Freq());
	HAL_UART_Transmit(&huart2,(uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	while(1);

	return 0;
}//END MAIN


void UART2_Init(void)
{

	huart2.Instance=USART2;						//
	huart2.Init.BaudRate=115200;				//
	huart2.Init.WordLength=UART_WORDLENGTH_8B;	//
	huart2.Init.StopBits=UART_STOPBITS_1;		//
	huart2.Init.Parity=UART_PARITY_NONE;		//
	huart2.Init.HwFlowCtl=UART_HWCONTROL_NONE;	//
	huart2.Init.Mode=UART_MODE_TX_RX;			//
	if (HAL_UART_Init(&huart2) !=HAL_OK)
	{
		//There is a problem
		Error_handler();
	}
}



void Error_handler(void)
{
	while(1);
}
