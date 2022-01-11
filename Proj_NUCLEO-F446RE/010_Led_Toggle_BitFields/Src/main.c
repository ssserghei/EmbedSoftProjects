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
/*LED connected on PA5
 *BUT is connected on PC13
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include<stdint.h>
#include "main.h" //este un fiesier antet definit de user deaceia il scriem cu ""

int main(void)
{

	/*
	GPIOx_MODER_t *pGPIOa_MODER;
	*pGPIOa_MODER =(GPIOx_MODER_t*) 0x40020000;
	pGPIOa_MODER->moder5=1;
*/

	pClkCtrlReg->gpioA_en=1;	//for LED EN CLK on GPIOA

	pPortAModeReg->moder5=1;	//for LED


	pPortAOutReg->odr5=1;


	/* Loop forever */
	for(;;);
}
