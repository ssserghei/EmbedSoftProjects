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


	HAL_Init();
	UART2_Init();

	memset (&osc_init, 0, sizeof(osc_init));

	osc_init.OscillatorType=RCC_OSCILLATORTYPE_HSE;
	osc_init.HSEState=RCC_HSE_BYPASS;
	if (HAL_RCC_OscConfig(&osc_init) !=HAL_OK)
	{
		Error_handler();
	}

	while(1);

	return 0;
}//END MAIN



void UART2_Init(void){

	huart2.Instance=USART2;						//
	huart2.Init.BaudRate=115200;				//
	huart2.Init.WordLength=UART_WORDLENGTH_8B;	//
	huart2.Init.StopBits=UART_STOPBITS_1;		//
	huart2.Init.Parity=UART_PARITY_NONE;		//
	huart2.Init.HwFlowCtl=UART_HWCONTROL_NONE;	//
	huart2.Init.Mode=UART_MODE_TX_RX;			//
	if (HAL_UART_Init(&huart2) !=HAL_OK){
		//There is a problem
		Error_handler();
	}
}


void Error_handler(void){
	while(1);
}
