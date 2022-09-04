/*
 * stm32f446xx_gpio_driver.h
 *
 *  Created on: 25 июл. 2022 г.
 *      Author: Serghei
 */

#ifndef INC_STM32F446XX_GPIO_DRIVER_H_
#define INC_STM32F446XX_GPIO_DRIVER_H_

#include "stm32f446xx.h"


/*This is a Configuration structure for a GPIO pin*/
typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;			/*possible values from @GPIO_PIN_MODES*/
	uint8_t GPIO_PinSpeed;			/*possible values from @GPIO_PIN_SPEED*/
	uint8_t GPIO_PupdCopntrol;
	uint8_t GPIO_PinOPTupe;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;

/*This in a Handle structure for a GPIO pin*/
typedef struct
{
	GPIO_RegDef_t *pGPIOx;				/*This hold the base address of the GPIO port to which the pin belongs*/
	GPIO_PinConfig_t GPIO_PinConfig;	/*This holds GPIO pin configuration settings*/

}GPIO_Handle_t;

/*@GPIO_PIN_NUMBERS
 * GPIO pin numbers*/
#define GPIO_PIN_NO_0		0
#define GPIO_PIN_NO_1		1
#define GPIO_PIN_NO_2		2
#define GPIO_PIN_NO_3		3
#define GPIO_PIN_NO_4		4
#define GPIO_PIN_NO_5		5
#define GPIO_PIN_NO_6		6
#define GPIO_PIN_NO_7		7
#define GPIO_PIN_NO_8		8
#define GPIO_PIN_NO_9		9
#define GPIO_PIN_NO_10		10
#define GPIO_PIN_NO_11		11
#define GPIO_PIN_NO_12		12
#define GPIO_PIN_NO_13		13
#define GPIO_PIN_NO_14		14
#define GPIO_PIN_NO_15		15

/* @GPIO_PIN_MODES
 * GPIO pin possible modes*/
#define GPIO_MODE_IN 		0
#define GPIO_MODE_OUT 		1
#define GPIO_MODE_ALTFN 	2
#define GPIO_MODE_ANALOG 	3
#define GPIO_MODE_IT_FT		4	//Fooling interrupt mode
#define GPIO_MODE_IT_RT		5	//Rising interrupt mode
#define GPIO_MODE_IT_RFT	6	//both interrupt mode

/*GPIO pin possible output types*/
#define GPIO_OP_TYPE_PP		0	//push-pull
#define GPIO_OP_TYPE_OD		1	//open-drain

/*@GPIO_PIN_SPEED
 * GPIO pin possible output speeds*/
#define GPIO_LOW			0 	/*GPIO_SPEED_LOW*/
#define GPIO_MEDIUM			1
#define GPIO_FAST			2
#define GPIO_HIGH			3

/*GPIO pin pull up and pull down configuration macros */
#define GPIO_NO_PUDP		0
#define GPIO_PIN_OU			1
#define GPIO_PIN_PD			2

/**************************************************************************
 * 						APIs supported by this driver
 * 		For more information about the APIs check the function definitions
 **************************************************************************/

/*Peripheral Clock setup*/
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);	//

/*Init and De-init*/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);				//позже решим что должно принимать и что возвращать
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);				//сбрасывает порт в исходное состояние

/*Date read and write*/
uint8_t  GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);	//возвращает булевое значение
uint16_t  GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);					//

void GPIO_WriteToOutPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);	//
void GPIO_WriteToOutPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);					//
void GPIO_ToggleOutPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);					//

/*IRQ Configuration and ISR handling*/
void GPIO_IRQInnteruptConfig(uint8_t IRQNumber, uint8_t EnorDi);		//
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);	//
void GPIO_IRQHandling(uint8_t PinNumber);								//

#endif /* INC_STM32F446XX_GPIO_DRIVER_H_ */
