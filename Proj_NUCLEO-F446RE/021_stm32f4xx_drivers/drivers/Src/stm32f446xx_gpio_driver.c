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
	uint32_t temp=0; 		//temp. register

	//1. configure the mode of gpio pin
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode<=GPIO_MODE_ANALOG)
	{
		//the non interrupt mode.
	temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode<<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->MODER &=~(0x3<<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);		//clearing
	pGPIOHandle->pGPIOx->MODER |=temp;		//setting
	temp=0;
	}else
	{	//Interrupt mode
		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode<=GPIO_MODE_IT_FT)
		{	//1.configure the FTSR
			EXTI->FTSR |=(1<< pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			//Clear the corresponding RTSR bit
			EXTI->RTSR &=~(1<< pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}else if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode<=GPIO_MODE_IT_RT)
		{	//1.configure the RTSR
			EXTI->RTSR |=(1<< pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			//Clear the corresponding RTSR bit
			EXTI->FTSR &=~(1<< pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}else if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode<=GPIO_MODE_IT_RFT)
		{	//1.configure both FTSR and RTSR
			EXTI->RTSR |=(1<< pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			//Clear the corresponding RTSR bit
			EXTI->FTSR |=(1<< pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}
		//2. configure GPIO port selection in SYSCFG_EXTICR

		//3. enable the exti interrupt delivery using IMR
		EXTI->IMR |=(1<< pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	}

	temp=0;

	//2.configure the speed
	temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed<<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &=~(0x3<<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);		//clearing
	pGPIOHandle->pGPIOx->OSPEEDR |=temp;
	temp=0;

	//3.configure the pudp setting
	temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PupdCopntrol<<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &=~(0x3<<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);		//clearing
	pGPIOHandle->pGPIOx->PUPDR |=temp;
	temp=0;

	//4. configure the optype
	temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinOPTupe<<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER &=~(0x1<<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);		//clearing
	pGPIOHandle->pGPIOx->OTYPER |=temp;

	//5. configure the alt fuctionality
	if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode==GPIO_MODE_ALTFN)
	{
		//configure the alt function registers.
		uint8_t temp1, temp2;
		temp1=pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber /8;
		temp2=pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber %8;
		pGPIOHandle->pGPIOx->AFR[temp1] &=~(0xF<<(4*temp2));
		pGPIOHandle->pGPIOx->AFR[temp1] |=(pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode<<(4*temp2));
	}
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





/*********************************
 * @fn					- GPIO_IRQHandling
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
void GPIO_IRQHandling(uint8_t PinNumber)												//
{

}







