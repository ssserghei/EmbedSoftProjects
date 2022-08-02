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
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t ENorDI);	//

/*Init and De-init*/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);								//позже решим что должно принимать и что возвращать
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);				//сбрасывает порт в исходное состояние


/*Date read and write*/
uint8_t  GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);	//возвращает булевое значение
uint16_t  GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);	//

void GPIO_WriteToOutPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);		//
void GPIO_WriteToOutPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);					//
void GPIO_ToggleOutPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);		//

/*IRQ Configuration and ISR handling*/
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t ENorDI);			//
void GPIO_IRQHandling(uint8_t PinNumber);		//




#endif /* INC_STM32F446XX_GPIO_DRIVER_H_ */
