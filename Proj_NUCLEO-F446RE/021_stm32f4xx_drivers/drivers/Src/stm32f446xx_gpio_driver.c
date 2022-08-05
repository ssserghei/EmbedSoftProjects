/*
 * stm32f446xx_gpio_driver.c
 *
 *  Created on: 25 июл. 2022 г.
 *      Author: Serghei
 */

#include "stm32f446xx_gpio_driver.h"

/*Peripheral Clock setup*/
/*********************************
 * @fn					- GPIO_PeriClockControl
 *
 *@brief				- This function enables or disables peripheral clock for given GPIO port
 *
 *@param[in]			- base address of the GPIO peripheral
 *@param[in]			- ENALE or DISABLE macros
 *@param[in]			-
 *
 *@return				- none
 *
 *@Note					- none
 *
 * */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t ENorDI)	//
{
	if (ENorDI==ENABLE)
	{
		if		(pGPIOx==GPIOA)
		{
			GPIOA_PCLK_EN();
		}else if(pGPIOx==GPIOB)
		{
			GPIOB_PCLK_EN();
		}else if(pGPIOx==GPIOC)
		{
			GPIOC_PCLK_EN();
		}else if(pGPIOx==GPIOD)
		{
			GPIOD_PCLK_EN();
		}else if(pGPIOx==GPIOE)
		{
			GPIOE_PCLK_EN();
		}else if(pGPIOx==GPIOF)
		{
			GPIOF_PCLK_EN();
		}else if(pGPIOx==GPIOG)
		{
			GPIOG_PCLK_EN();
		}else if(pGPIOx==GPIOH)
		{
			GPIOH_PCLK_EN();
		}

	}else
	{
		if		(pGPIOx==GPIOA)
				{
					GPIOA_PCLK_DI();
				}else if(pGPIOx==GPIOB)
				{
					GPIOB_PCLK_DI();
				}else if(pGPIOx==GPIOC)
				{
					GPIOC_PCLK_DI();
				}else if(pGPIOx==GPIOD)
				{
					GPIOD_PCLK_DI();
				}else if(pGPIOx==GPIOE)
				{
					GPIOE_PCLK_DI();
				}else if(pGPIOx==GPIOF)
				{
					GPIOF_PCLK_DI();
				}else if(pGPIOx==GPIOG)
				{
					GPIOG_PCLK_DI();
				}else if(pGPIOx==GPIOH)
				{
					GPIOH_PCLK_DI();
				}
	}
}//END GPIO_PeriClockControl

/*Init and De-init*/
/*********************************
 * @fn					- GPIO_Init
 *
 *@brief				-
 *
 *@param[in]			-
 *@param[in]			-
 *@param[in]			-
 *
 *@return				-
 *
 *@Note					-
 *
 * */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)					//позже решим что должно принимать и что возвращать
{

}

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)						//сбрасывает порт в исходное состояние
{

}

/*Date read and write*/
uint8_t  GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)	//возвращает булевое значение
{

}

uint16_t  GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)						//
{

}

void GPIO_WriteToOutPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)		//
{

}

void GPIO_WriteToOutPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)							//
{

}

void GPIO_ToggleOutPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)						//
{

}

/*IRQ Configuration and ISR handling*/
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t ENorDI)				//
{

}

void GPIO_IRQHandling(uint8_t PinNumber)												//
{

}




//

/*Peripheral Clock setup*/
/*********************************
 * @fn					-
 *
 *@brief				-
 *
 *@param[in]			-
 *@param[in]			-
 *@param[in]			-
 *
 *@return				-
 *
 *@Note					-
 *
 * */
