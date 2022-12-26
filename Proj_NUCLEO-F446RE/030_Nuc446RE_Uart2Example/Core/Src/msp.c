/*
 * msp.c
 *
 *  Created on: Dec 4, 2022
 *      Author: Serghei
 */

#include "stm32f4xx_hal.h"

void HAL_MspInint(void){
	//Here will do low level processor specific inits.
		//1. Set up the priority grouping OF THE ARM CORTEX MX PROCESSOR
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4); //linii redundanta de cod. implicit e setarea asta

		//2. Enable the required system exeptions of the arm cortex mx processor
		//System Handler Control and State Register
	SCB->SHCSR |=0x7 << 16; //Ena MemFaul; BusFault; UsgFault
		//3. Configure the priority for system exections
	HAL_NVIC_SetPriority(MemoryManagement_IRQn,0,0);
	HAL_NVIC_SetPriority(BusFault_IRQn,0,0);
	HAL_NVIC_SetPriority(UsageFault_IRQn,0,0);

}


void HAL_UART_MspInit(UART_HandleTypeDef *huart){
	GPIO_InitTypeDef gpio_uart;
	//here we are going to do the low level inits. of the USART2 peripheral

	//1. enable the clock for the USART2 peripheral
	__HAL_RCC_USART2_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	//2. Do the pin muxing configurations
	gpio_uart.Pin=GPIO_PIN_2;
	gpio_uart.Mode=GPIO_MODE_AF_PP;
	gpio_uart.Pull=GPIO_PULLUP;
	gpio_uart.Speed=GPIO_SPEED_FREQ_LOW;
	gpio_uart.Alternate=GPIO_AF7_USART2;	//UART2_TX
	HAL_GPIO_Init(GPIOA,&gpio_uart);

	//nu trebuie de scrie restul setarilor dearece ele sint fixate in structura
	gpio_uart.Pin=GPIO_PIN_3;		//UART2_RX
	HAL_GPIO_Init(GPIOA,&gpio_uart);
	//3. Enable the IRQ and set up the priority (NVIC settings)
	HAL_NVIC_EnableIRQ(USART2_IRQn);
	HAL_NVIC_SetPriority(USART2_IRQn, 15, 0);
}
