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
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
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

/**************************************************************************
 * 						APIs supported by this driver
 * 		For more information about the APIs check the function definitions
 **************************************************************************/

/*Peripheral Clock setup*/
void GPIO_PeriClockControl(void);	//

/*Init and De-init*/
void GPIO_Init(void);				//позже решим что должно принимать и что возвращать
void GPIO_DeInit(void);				//сбрасывает порт в исходное состояние

/*Date read and write*/
void GPIO_ReadFromInputPin(void);	//
void GPIO_ReadFromInputPort(void);	//

void GPIO_WriteToOutPin(void);		//
void GPIO_WriteToOutPort(void);		//

/*IRQ Configuration and ISR handling*/
void GPIO_ToggleOutPin(void);		//
void GPIO_IRQConfig(void);			//
void GPIO_IRQHandling(void);		//




#endif /* INC_STM32F446XX_GPIO_DRIVER_H_ */
