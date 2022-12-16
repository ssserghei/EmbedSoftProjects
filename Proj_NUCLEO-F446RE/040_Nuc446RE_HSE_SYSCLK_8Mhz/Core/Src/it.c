/*
 * it.c
 *
 *  Created on: Dec 4, 2022
 *      Author: Serghei
 */

#include "main.h"



void SysTick_Handler (void){
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();

}
