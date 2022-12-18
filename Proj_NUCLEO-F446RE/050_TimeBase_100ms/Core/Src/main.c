/*
 *
 * */

#include <string.h>
#include "stm32f4xx_hal.h"
#include "main.h"

#define TRUE 	1U
#define FALSE 	0U

void SystemClockConfig(void);
void Error_handler(void);
void IMER6_Init(void);

TIM_HandleTypeDef htimer6;


/*************************MAIN************************************/
int main (void){

	HAL_Init();
	SystemClockConfig();

	TIMER6_Init();


	while(1);
	return 0;
}//END MAIN

void SystemClockConfig(void)
{

}

void TIMER6_Init (void)
{
	htimer6.Instance=TIM6;
	htimer6.Init
}

void Error_handler(void)
{
	while(1);
}
