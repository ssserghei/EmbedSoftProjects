/*
 * main.h
 *
 *  Created on: 02-Jun-2018
 *      Author: kiran
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "stm32f4xx_hal.h"

#define SYS_CLOCK_FREQ_50_MHZ 50
#define SYS_CLOCK_FREQ_84_MHZ 84
#define SYS_CLOCK_FREQ_120_MHZ 120

#define TRUE 1
#define FALSE 0


/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA

#define Motor1A_Pin GPIO_PIN_4
#define Motor1A_GPIO_Port GPIOA

#define Motor1B_Pin GPIO_PIN_0
#define Motor1B_GPIO_Port GPIOB


#define Motor2A_Pin GPIO_PIN_1
#define Motor2A_GPIO_Port GPIOC

#define Motor2B_Pin GPIO_PIN_0
#define Motor2B_GPIO_Port GPIOC


#define Motor3A_Pin GPIO_PIN_4
#define Motor3A_GPIO_Port GPIOB

#define Motor3B_Pin GPIO_PIN_5
#define Motor3B_GPIO_Port GPIOB


#define Motor4A_Pin GPIO_PIN_1
#define Motor4A_GPIO_Port GPIOB

#define Motor4B_Pin GPIO_PIN_15
#define Motor4B_GPIO_Port GPIOB


#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA

#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB



#endif /* MAIN_H_ */
