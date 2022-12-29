/*
 * main.c
 *
 *  Created on: Dec 4, 2022
 *      Author: Serghei
 */

/*lucreaza
 *tot ce primeste prin uart intoarce inapoi dar cu majuscule
 * */
#include <string.h>
#include "stm32f3xx_hal.h"
#include "main.h"

#define TRUE 	1U
#define FALSE 	0U

void SystemClockConfig(void);
void UART1_Init(void);
void Error_handler(void);

uint8_t convert_to_capital (uint8_t);

UART_HandleTypeDef huart1;

char *user_data="The application is running\r\n";

/*************************MAIN************************************/
uint8_t data_buffer[100];
uint8_t recvd_data;
uint8_t count=0;
uint8_t reception_complete=FALSE;
int main (void){

	HAL_Init();
	SystemClockConfig();
	UART1_Init();

	uint16_t len_of_data=strlen(user_data);
	HAL_UART_Transmit(&huart1, (uint8_t*)user_data, len_of_data, HAL_MAX_DELAY);



	return 0;
}//END MAIN



void SystemClockConfig(void){

}

void UART1_Init(void){

	huart1.Instance=USART1;						//
	huart1.Init.BaudRate=115200;				//
	huart1.Init.WordLength=UART_WORDLENGTH_8B;	//
	huart1.Init.StopBits=UART_STOPBITS_1;		//
	huart1.Init.Parity=UART_PARITY_NONE;		//
	huart1.Init.HwFlowCtl=UART_HWCONTROL_NONE;	//
	huart1.Init.Mode=UART_MODE_TX_RX;			//
	if (HAL_UART_Init(&huart1) !=HAL_OK){
		//There is a problem
		Error_handler();
	}
}


void Error_handler(void){
	while(1);
}
