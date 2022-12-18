/*
 * */

#include "main.h"

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


