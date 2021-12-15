/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include<stdio.h>
#include<stdint.h>

/* This function executes in THREAD MODE of the processor */
void generate_interrupt()
{
	uint32_t *pSTIR  = (uint32_t*)0xE000EF00;
	uint32_t *pISER0 = (uint32_t*)0xE000E100;

	//enable IRQ3 interrupt
	*pISER0 |= ( 1 << 3);

	//generate an interrupt from software for IRQ3
	*pSTIR = (3 & 0x1FF);

}

void change_access_level_unpriv(void)
{

	//read
	__asm volatile ("MRS R0,CONTROL");
	//modify
	__asm volatile ("ORR R0,R0,#0x01");
	//write
	__asm volatile ("MSR CONTROL,R0");

 }

/* This function executes in THREAD MODE+ PRIV ACCESS LEVEL of the processor */
int main(void)
{
	printf("In thread mode : before interrupt\n");

	change_access_level_unpriv();

	generate_interrupt();

	printf("In thread mode : after interrupt\n");

	for(;;);
}

/* This function(ISR) executes in HANDLER MODE of the processor */
void RTC_WKUP_IRQHandler(void)
{
	printf("In handler mode : ISR\n");
}

void HardFault_Handler(void)
{
	printf("Hard fault detected\n");
	while(1);
}
