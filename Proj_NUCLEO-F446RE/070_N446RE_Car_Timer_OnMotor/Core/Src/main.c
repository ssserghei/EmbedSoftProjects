/*
 * main.c
 *
 *  Created on: 02-Jun-2018
 *      Author: kiran
 */
/*Lucreaza/
cu ajutorul PWM dirijez cu 4 motoare

 * */

#include <string.h>
#include "stm32f4xx_hal.h"
#include "main.h"


//void GPIO_Init(void);
void MX_GPIO_Init(void);
void Error_handler(void);
void TIMER2_Init(void);
void UART2_Init(void);
void SystemClock_Config_HSE(uint8_t clock_freq);

void Forward (void);
void Back (void);
void Left (void);
void Right (void);
void Stop (void);

TIM_HandleTypeDef htimer2;
UART_HandleTypeDef huart2;

/*************************************MAIN******************************/
int main(void)
{

	HAL_Init();


	SystemClock_Config_HSE(SYS_CLOCK_FREQ_50_MHZ);

//	GPIO_Init();
	MX_GPIO_Init();

	UART2_Init();

	TIMER2_Init();

	if ( HAL_TIM_PWM_Start(&htimer2,TIM_CHANNEL_1) != HAL_OK)
	{
		Error_handler();
	}
	if ( HAL_TIM_PWM_Start(&htimer2,TIM_CHANNEL_2) != HAL_OK)
	{
		Error_handler();
	}
	if ( HAL_TIM_PWM_Start(&htimer2,TIM_CHANNEL_3) != HAL_OK)
	{
		Error_handler();
	}
	if ( HAL_TIM_PWM_Start(&htimer2,TIM_CHANNEL_4) != HAL_OK)
	{
		Error_handler();
	}
	while(1)
	{

		Forward ();
		HAL_Delay(1500); //

		Left ();
		HAL_Delay(1000);

		Back ();
		HAL_Delay(2000);

		Forward ();
		HAL_Delay(1500);

		Right ();
		HAL_Delay(1000);

//		Stop ();

	}//END While(1)


/*
#define Motor1Out_Pin GPIO_PIN_4
#define Motor1Out_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define Motor2Out_Pin GPIO_PIN_0
#define Motor2Out_GPIO_Port GPIOB
#define Motor4Out_Pin GPIO_PIN_1
#define Motor4Out_GPIO_Port GPIOB
#define Motor3Out_Pin GPIO_PIN_8
#define Motor3Out_GPIO_Port GPIOA

 * */


	return 0;
}//END MAIN



/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config_HSE(uint8_t clock_freq)
{
	RCC_OscInitTypeDef Osc_Init;
	RCC_ClkInitTypeDef Clock_Init;
    uint8_t flash_latency=0;

	Osc_Init.OscillatorType = RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_LSE | RCC_OSCILLATORTYPE_HSI ;
	Osc_Init.HSEState = RCC_HSE_ON;
	Osc_Init.LSEState = RCC_LSE_ON;
	Osc_Init.HSIState = RCC_HSI_ON;
	Osc_Init.PLL.PLLState = RCC_PLL_ON;
	Osc_Init.PLL.PLLSource = RCC_PLLSOURCE_HSE;

	switch(clock_freq)
	 {
	  case SYS_CLOCK_FREQ_50_MHZ:
		  Osc_Init.PLL.PLLM = 4;
		  Osc_Init.PLL.PLLN = 50;
		  Osc_Init.PLL.PLLP = RCC_PLLP_DIV2;
		  Osc_Init.PLL.PLLQ = 2;
		  Osc_Init.PLL.PLLR = 2;
		  Clock_Init.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
	                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
		  Clock_Init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
		  Clock_Init.AHBCLKDivider = RCC_SYSCLK_DIV1;
		  Clock_Init.APB1CLKDivider = RCC_HCLK_DIV2;
		  Clock_Init.APB2CLKDivider = RCC_HCLK_DIV1;
          flash_latency = 1;
	     break;

	  case SYS_CLOCK_FREQ_84_MHZ:
		  Osc_Init.PLL.PLLM = 4;
		  Osc_Init.PLL.PLLN = 84;
		  Osc_Init.PLL.PLLP = RCC_PLLP_DIV2;
		  Osc_Init.PLL.PLLQ = 2;
		  Osc_Init.PLL.PLLR = 2;
		  Clock_Init.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
	                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
		  Clock_Init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
		  Clock_Init.AHBCLKDivider = RCC_SYSCLK_DIV1;
		  Clock_Init.APB1CLKDivider = RCC_HCLK_DIV2;
		  Clock_Init.APB2CLKDivider = RCC_HCLK_DIV1;
          flash_latency = 2;
	     break;

	  case SYS_CLOCK_FREQ_120_MHZ:
		  Osc_Init.PLL.PLLM = 4;
		  Osc_Init.PLL.PLLN = 120;
		  Osc_Init.PLL.PLLP = RCC_PLLP_DIV2;
		  Osc_Init.PLL.PLLQ = 2;
		  Osc_Init.PLL.PLLR = 2;
		  Clock_Init.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
	                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
		  Clock_Init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
		  Clock_Init.AHBCLKDivider = RCC_SYSCLK_DIV1;
		  Clock_Init.APB1CLKDivider = RCC_HCLK_DIV4;
		  Clock_Init.APB2CLKDivider = RCC_HCLK_DIV2;
          flash_latency = 3;
	     break;

	  default:
	   return ;
	 }

		if (HAL_RCC_OscConfig(&Osc_Init) != HAL_OK)
	{
			Error_handler();
	}



	if (HAL_RCC_ClockConfig(&Clock_Init, flash_latency) != HAL_OK)
	{
		Error_handler();
	}


	/*Configure the systick timer interrupt frequency (for every 1 ms) */
	uint32_t hclk_freq = HAL_RCC_GetHCLKFreq();
	HAL_SYSTICK_Config(hclk_freq/1000);

	/**Configure the Systick
	*/
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

	/* SysTick_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
 }

/*
void GPIO_Init(void)
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef ledgpio;
	ledgpio.Pin = GPIO_PIN_5;
	ledgpio.Mode = GPIO_MODE_OUTPUT_PP;
	ledgpio.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA,&ledgpio);
}
*/

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, Motor2B_Pin|Motor2A_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(Motor1A_GPIO_Port, Motor1A_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, Motor1B_Pin|Motor4A_Pin|Motor4B_Pin|Motor3A_Pin
                          |Motor3B_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : Motor2B_Pin Motor2A_Pin */
  GPIO_InitStruct.Pin = Motor2B_Pin|Motor2A_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : Motor1A_Pin LD2_Pin */
  GPIO_InitStruct.Pin = Motor1A_Pin|LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : Motor1B_Pin Motor4A_Pin Motor4B_Pin Motor3A_Pin
                           Motor3B_Pin */
  GPIO_InitStruct.Pin = Motor1B_Pin|Motor4A_Pin|Motor4B_Pin|Motor3A_Pin
                          |Motor3B_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}


void UART2_Init(void)
{
	huart2.Instance = USART2;
	huart2.Init.BaudRate = 115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	if ( HAL_UART_Init(&huart2) != HAL_OK )
	{
		//There is a problem
		Error_handler();
	}
}


 void TIMER2_Init(void)
{
	 TIM_OC_InitTypeDef tim2PWM_Config;
	 htimer2.Instance = TIM2;
	 /*1kHz
	  * period 10-1
	  * Prescaler 4999
	  * or:
	  * 1kHz
	  * Period 10000-1
	  * Prescaler 4
	  * or
	  * Period 1000-1
	  * Prescaler 49
	  * */
	 htimer2.Init.Period = 1000-1;
	 htimer2.Init.Prescaler = 49;
	 if ( HAL_TIM_PWM_Init(&htimer2) != HAL_OK)
	 {
		 Error_handler();
	 }

	 memset(&tim2PWM_Config,0,sizeof(tim2PWM_Config));

	 tim2PWM_Config.OCMode = TIM_OCMODE_PWM1;
	 tim2PWM_Config.OCPolarity = TIM_OCPOLARITY_HIGH;


	tim2PWM_Config.Pulse =  (htimer2.Init.Period * 35 ) /100;		//25

	 if( HAL_TIM_PWM_ConfigChannel(&htimer2,&tim2PWM_Config,TIM_CHANNEL_1) != HAL_OK)
	 {
		 Error_handler();
	 }

	 tim2PWM_Config.Pulse =  (htimer2.Init.Period * 35 ) /100;		//45
	 if( HAL_TIM_PWM_ConfigChannel(&htimer2,&tim2PWM_Config,TIM_CHANNEL_2) != HAL_OK)
	 {
		 Error_handler();
	 }

	 tim2PWM_Config.Pulse =  (htimer2.Init.Period * 35 ) /100;		//75
	 if( HAL_TIM_PWM_ConfigChannel(&htimer2,&tim2PWM_Config,TIM_CHANNEL_3) != HAL_OK)
	 {
		 Error_handler();
	 }

	 tim2PWM_Config.Pulse =  (htimer2.Init.Period * 35 ) /100;		//95
	 if( HAL_TIM_PWM_ConfigChannel(&htimer2,&tim2PWM_Config,TIM_CHANNEL_4) != HAL_OK)
	 {
		 Error_handler();
	 }
}


void Error_handler(void)
{
	while(1);
}


void Forward (void)
{
	HAL_GPIO_WritePin(Motor1A_GPIO_Port, Motor1A_Pin, GPIO_PIN_SET);	//Motor1
	HAL_GPIO_WritePin(Motor1B_GPIO_Port, Motor1B_Pin, GPIO_PIN_RESET);	//Motor1

	HAL_GPIO_WritePin(Motor2A_GPIO_Port, Motor2A_Pin, GPIO_PIN_SET);	//Motor2
	HAL_GPIO_WritePin(Motor2B_GPIO_Port, Motor2B_Pin, GPIO_PIN_RESET);	//Motor2

	HAL_GPIO_WritePin(Motor3A_GPIO_Port, Motor3A_Pin, GPIO_PIN_SET);	//Motor3
	HAL_GPIO_WritePin(Motor3B_GPIO_Port, Motor3B_Pin, GPIO_PIN_RESET);	//Motor3

	HAL_GPIO_WritePin(Motor4A_GPIO_Port, Motor4A_Pin, GPIO_PIN_SET);	//Motor4
	HAL_GPIO_WritePin(Motor4B_GPIO_Port, Motor4B_Pin, GPIO_PIN_RESET);	//Motor4
}


void Back (void)
{
	HAL_GPIO_WritePin(Motor1A_GPIO_Port, Motor1A_Pin, GPIO_PIN_RESET);	//Motor1
	HAL_GPIO_WritePin(Motor1B_GPIO_Port, Motor1B_Pin, GPIO_PIN_SET);	//Motor1

	HAL_GPIO_WritePin(Motor2A_GPIO_Port, Motor2A_Pin, GPIO_PIN_RESET);	//Motor2
	HAL_GPIO_WritePin(Motor2B_GPIO_Port, Motor2B_Pin, GPIO_PIN_SET);	//Motor2

	HAL_GPIO_WritePin(Motor3A_GPIO_Port, Motor3A_Pin, GPIO_PIN_RESET);	//Motor3
	HAL_GPIO_WritePin(Motor3B_GPIO_Port, Motor3B_Pin, GPIO_PIN_SET);	//Motor3

	HAL_GPIO_WritePin(Motor4A_GPIO_Port, Motor4A_Pin, GPIO_PIN_RESET);	//Motor4
	HAL_GPIO_WritePin(Motor4B_GPIO_Port, Motor4B_Pin, GPIO_PIN_SET);	//Motor4
}

void Left (void)
{
	HAL_GPIO_WritePin(Motor1A_GPIO_Port, Motor1A_Pin, GPIO_PIN_RESET);	//Motor1
	HAL_GPIO_WritePin(Motor1B_GPIO_Port, Motor1B_Pin, GPIO_PIN_SET);	//Motor1

	HAL_GPIO_WritePin(Motor2A_GPIO_Port, Motor2A_Pin, GPIO_PIN_RESET);	//Motor2
	HAL_GPIO_WritePin(Motor2B_GPIO_Port, Motor2B_Pin, GPIO_PIN_SET);	//Motor2

	HAL_GPIO_WritePin(Motor3A_GPIO_Port, Motor3A_Pin, GPIO_PIN_SET);	//Motor3
	HAL_GPIO_WritePin(Motor3B_GPIO_Port, Motor3B_Pin, GPIO_PIN_RESET);	//Motor3

	HAL_GPIO_WritePin(Motor4A_GPIO_Port, Motor4A_Pin, GPIO_PIN_SET);	//Motor4
	HAL_GPIO_WritePin(Motor4B_GPIO_Port, Motor4B_Pin, GPIO_PIN_RESET);	//Motor4
}

void Right (void)
{
	HAL_GPIO_WritePin(Motor1A_GPIO_Port, Motor1A_Pin, GPIO_PIN_SET);	//Motor1
	HAL_GPIO_WritePin(Motor1B_GPIO_Port, Motor1B_Pin, GPIO_PIN_RESET);	//Motor1

	HAL_GPIO_WritePin(Motor2A_GPIO_Port, Motor2A_Pin, GPIO_PIN_SET);	//Motor2
	HAL_GPIO_WritePin(Motor2B_GPIO_Port, Motor2B_Pin, GPIO_PIN_RESET);	//Motor2

	HAL_GPIO_WritePin(Motor3A_GPIO_Port, Motor3A_Pin, GPIO_PIN_RESET);	//Motor3
	HAL_GPIO_WritePin(Motor3B_GPIO_Port, Motor3B_Pin, GPIO_PIN_SET);	//Motor3

	HAL_GPIO_WritePin(Motor4A_GPIO_Port, Motor4A_Pin, GPIO_PIN_RESET);	//Motor4
	HAL_GPIO_WritePin(Motor4B_GPIO_Port, Motor4B_Pin, GPIO_PIN_SET);	//Motor4
}

void Stop (void)
{
	HAL_GPIO_WritePin(Motor1A_GPIO_Port, Motor1A_Pin, GPIO_PIN_RESET);	//Motor1
	HAL_GPIO_WritePin(Motor1B_GPIO_Port, Motor1B_Pin, GPIO_PIN_RESET);	//Motor1

	HAL_GPIO_WritePin(Motor2A_GPIO_Port, Motor2A_Pin, GPIO_PIN_RESET);	//Motor2
	HAL_GPIO_WritePin(Motor2B_GPIO_Port, Motor2B_Pin, GPIO_PIN_RESET);	//Motor2

	HAL_GPIO_WritePin(Motor3A_GPIO_Port, Motor3A_Pin, GPIO_PIN_RESET);	//Motor3
	HAL_GPIO_WritePin(Motor3B_GPIO_Port, Motor3B_Pin, GPIO_PIN_RESET);	//Motor3

	HAL_GPIO_WritePin(Motor4A_GPIO_Port, Motor4A_Pin, GPIO_PIN_RESET);	//Motor4
	HAL_GPIO_WritePin(Motor4B_GPIO_Port, Motor4B_Pin, GPIO_PIN_RESET);	//Motor4
}