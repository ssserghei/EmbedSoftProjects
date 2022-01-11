
//этот проект не сохранился. но тут должно быть мигание светодиодом. оно было...
/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include<stdint.h>
#include "main.h" //este un fiesier antet definit de user deaceia il scriem cu ""

/*
	uint32_t *pClkCtrlReg=(uint32_t*)0x40023830;
	uint32_t *pPortAModeReg=(uint32_t*)0x40020000;
	uint32_t *pPortAOutReg=(uint32_t*)0x40020014;
*/
int main(void)
{
	/*
	GPIOx_MODER_t *pGPIOa_MODER;
	*pGPIOa_MODER =(GPIOx_MODER_t*) 0x40020000;
	pGPIOa_MODER->moder5=1;
*/
	RCC_AHB1ENR_t *pClkCtrlReg=(RCC_AHB1ENR_t*) 0x40023830;
	pClkCtrlReg->gpioA_en=1;

	GPIOx_MODER_t *pPortAModeReg=(GPIOx_MODER_t*) 0x40020000;
	pPortAModeReg->moder5=1;


	GPIOx_ODR_t *pPortAOutReg=(GPIOx_ODR_t*) 0x40020014;
	pPortAOutReg->odr5=1;

	/* Loop forever */
	for(;;);
}
