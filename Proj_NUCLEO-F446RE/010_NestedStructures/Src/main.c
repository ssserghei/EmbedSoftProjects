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
/* PA5 	LED    ONN=High
 * */

#include <stdint.h>


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "main.h" //este un fiesier antet definit de user deaceia il scriem cu ""

int main(void)
{
	pClkCtrlReg->gpioA_en=1;	//LED EN CLK on GPIOA
	pPortAModeReg->moder5=1;	//LED Set pin as OUT

//	pClkCtrlReg->gpioC_en=1;	//BUT EN CLK on PC13
//	pPortCModeReg->moder13=0;	//BUT Set pin as IN

#define HIGH 1
#define LOW	0

//#define GPIOA		((GPIOx_ODR_t*) (0x40020000+0x14))	//

typedef struct{
	 uint8_t state0 :1;
	 uint8_t state1 :1;
	 uint8_t state2 :1;
	 uint8_t state3 :1;
	 uint8_t state4 :1;
	 uint8_t state5 :1;
}OutputSettings;

typedef struct{
	GPIOx_ODR_t *dev;
	OutputSettings setiings;
}Output;

Output GpioLed;

GpioLed.dev=GPIOA;
GpioLed.setiings.state4=HIGH;
GpioLed.setiings.state5=HIGH;


pPortAOutReg->odr4=GpioLed.setiings.state4;
pPortAOutReg->odr5=GpioLed.setiings.state5;


/*
	while(1){
	uint8_t ButState=!pPortCIntReg->idr13;
		if(!ButState){
			//turn on LED
			pPortAOutReg->odr5=1;
			for(uint32_t i=0; i<100000; i++);
			//turn off the LED
			pPortAOutReg->odr5=0;
			for(uint32_t i=0; i<100000; i++);
		}//end if
	}//end while
*/

}//end main