/*
 * it.c
 *
 *  Created on: Dec 4, 2022
 *      Author: Serghei
 */

#include "main.h"

extern UART_HandleTypeDef huart1;

void SysTick_Handler (void){
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();

}


void USART1_IRQHandler (void){
	HAL_UART_IRQHandler(&huart1);
}
