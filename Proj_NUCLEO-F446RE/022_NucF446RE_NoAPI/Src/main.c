/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */


/*D:\Udemy courcies\Master Microcontroller and Embedded Driver Development(MCU1)\1. Notes and Information\MasteringMCU-master\MasteringMCU-master\Resources\Source_code\Workspace\stm32f4xx_drivers
 * PC13 Button, Pressed=LOW
 * PA5 	LED    ONN=High
 * Код рабочий, при нажатии на кнопку светодиод переключается
 * Является наследником проекта 021_stm32f4xx_drivers только без API.
 * Создан для более детального изучения принципов работы API*/

#include<stdint.h>
#include<string.h>
#include "main.h"


#define HIGH 1
#define LOW 0
#define BTN_PRESSED LOW

void delay(void){
	// this will introduce ~200ms delay when system clock is 16MHz
	for(uint32_t i = 0 ; i < 50000 ; i ++);
}

int main(void){

	GPIO_Handle_t GpioLed, GPIOBtn;

	memset(&GpioLed,0,sizeof(GpioLed));
	memset(&GPIOBtn,0,sizeof(GpioLed));

	//this is led gpio configuration
	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

//	GPIO_PeriClockControl(GPIOA,ENABLE);
	GPIOA_PCLK_EN();

	//GPIO_Handle_t *pGPIOHandle;

//	GPIO_Init(&GpioLed);
	uint32_t temp=0; 		//temp. register
	//1. configure the mode of gpio pin
	//the non interrupt mode.
	temp=(GpioLed.GPIO_PinConfig.GPIO_PinMode<<(2*GpioLed.GPIO_PinConfig.GPIO_PinNumber));
	GpioLed.pGPIOx->MODER &=~(0x3<<(2*GpioLed.GPIO_PinConfig.GPIO_PinNumber));		//clearing
	GpioLed.pGPIOx->MODER |=temp;		//setting
	temp=0;
	//2.configure the speed
	temp=(GpioLed.GPIO_PinConfig.GPIO_PinSpeed<<(2*GpioLed.GPIO_PinConfig.GPIO_PinNumber));
	GpioLed.pGPIOx->OSPEEDR &=~(0x3<<GpioLed.GPIO_PinConfig.GPIO_PinNumber);		//clearing
	GpioLed.pGPIOx->OSPEEDR |=temp;
	temp=0;
	//3.configure the pudp setting
	temp=(GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl<<(2*GpioLed.GPIO_PinConfig.GPIO_PinNumber));
	GpioLed.pGPIOx->PUPDR &=~(0x3<<GpioLed.GPIO_PinConfig.GPIO_PinNumber);		//clearing
	GpioLed.pGPIOx->PUPDR |=temp;
	temp=0;
	//4. configure the optype
	temp=(GpioLed.GPIO_PinConfig.GPIO_PinOPType<<GpioLed.GPIO_PinConfig.GPIO_PinNumber);
	GpioLed.pGPIOx->OTYPER &=~(0x1<<GpioLed.GPIO_PinConfig.GPIO_PinNumber);		//clearing
	GpioLed.pGPIOx->OTYPER |=temp;
	temp=0;


	//this is btn gpio configuration
	GPIOBtn.pGPIOx = GPIOC;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	//	GPIO_PeriClockControl(GPIOC,ENABLE);
	GPIOC_PCLK_EN();

//	GPIO_Init(&GPIOBtn);
//	uint32_t temp=0; 		//temp. register
	temp=0;

	//Interrupt mode
	//1.configure the FTSR
	EXTI->FTSR |=(1<< GPIOBtn.GPIO_PinConfig.GPIO_PinNumber);
	//Clear the corresponding RTSR bit
	EXTI->RTSR &=~(1<< GPIOBtn.GPIO_PinConfig.GPIO_PinNumber);

	//2. configure GPIO port selection in SYSCFG_EXTICR
	//Будем расчитывать позицию EXTIx в регистрах
	/*Всего 4 регистра SYSCFG_EXTICR2 из каждого регистра используются первые 16 бит. Каждый регистр отвечает за 4 линии EXTI
	* К каждой линии EXTI можно подключить путем записи 4 битного числа только один пин порта под номером соответствующему номеру линии EXTI
	*Пример: к линии EXTI5 можно подключить PA5 либо PB5 либо... PE5*/
	uint8_t	temp1=GPIOBtn.GPIO_PinConfig.GPIO_PinNumber/4;
	uint8_t	temp2=GPIOBtn.GPIO_PinConfig.GPIO_PinNumber%4;
	uint8_t portcode=GPIO_BASEADDR_TO_CODE(GPIOBtn.pGPIOx);
	SYSCFG_PCLK_EN();
	SYSCFG->EXTICR[temp1]=portcode <<(temp2*4);

	//3. enable the exti interrupt delivery using IMR
	EXTI->IMR |=(1<< GPIOBtn.GPIO_PinConfig.GPIO_PinNumber);

	//2.configure the speed
	temp=(GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed<<(2*GPIOBtn.GPIO_PinConfig.GPIO_PinNumber));
	GPIOBtn.pGPIOx->OSPEEDR &=~(0x3<<GPIOBtn.GPIO_PinConfig.GPIO_PinNumber);		//clearing
	GPIOBtn.pGPIOx->OSPEEDR |=temp;
	temp=0;
	//3.configure the pudp setting
	temp=(GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl<<(2*GPIOBtn.GPIO_PinConfig.GPIO_PinNumber));
	GPIOBtn.pGPIOx->PUPDR &=~(0x3<<GPIOBtn.GPIO_PinConfig.GPIO_PinNumber);		//clearing
	GPIOBtn.pGPIOx->PUPDR |=temp;
	temp=0;
	//4. configure the optype
	temp=(GPIOBtn.GPIO_PinConfig.GPIO_PinOPType<<GPIOBtn.GPIO_PinConfig.GPIO_PinNumber);
	GPIOBtn.pGPIOx->OTYPER &=~(0x1<<GPIOBtn.GPIO_PinConfig.GPIO_PinNumber);		//clearing
	GPIOBtn.pGPIOx->OTYPER |=temp;



//	GPIO_WriteToOutPin(GPIOA,GPIO_PIN_NO_5,GPIO_PIN_RESET);//GPIO_PIN_SET//GPIO_PIN_RESET

	//write 1 to the output data register at the bit field corresponding to the pin number
	GPIOBtn.pGPIOx->ODR &= ~( 1 << GPIO_PIN_NO_13);


	//IRQ configurations
//	GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10,NVIC_IRQ_PRI15);
	//1. first lets find out the ipr register
	uint8_t iprx=IRQ_NO_EXTI15_10/4;				//выесняем какой регистр IPRX
	uint8_t iprx_section=IRQ_NO_EXTI15_10 %4;		//выесняем какиая из 4 секций
	uint8_t shift_ammount=(8*iprx_section)+(8-NO_PR_BITS_IMPLEMENTED);
	*(NVIC_PR_BASE_ADDR +iprx) |= (NVIC_IRQ_PRI15 <<shift_ammount);	/*(8*iprx_section)	 не умножаем на 4 так как арифметика указателей
	не работает так как мы задумали на 4 потому что следуюший адрес регистра находится через 4 адреса */


//	GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10,ENABLE);
	//program ISER0 resgister
	*NVIC_ISER1 |=(1<<(IRQ_NO_EXTI15_10 %32));

	while(1);
}//END MAIN

void EXTI15_10_IRQHandler(void){
   /// delay(); //200ms . wait till button de-bouncing gets over
	GPIO_IRQHandling(GPIO_PIN_NO_13); //clear the pending event from exti line
	GPIO_ToggleOutPin(GPIOA,GPIO_PIN_NO_5);
	delay();
}//EXTI15_10_IRQHandler         			/* EXTI Line[15:10] interrupts

void GPIO_IRQHandling(uint8_t PinNumber){
	//clear the exti pr register corresponding to the pin number
	if (EXTI->PR &(1<<PinNumber)){
		//clear the pending register bit
		EXTI->PR |=(1<<PinNumber);
	}
}

void GPIO_ToggleOutPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR  ^= ( 1 << PinNumber);
}

