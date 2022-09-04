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
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDI)	//
{
	if (EnorDI==ENABLE)
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
void GPIO_Init(GPIO_Handle_t *pGPIOHandle){					//позже решим что должно принимать и что возвращать
	uint32_t temp=0; 		//temp. register

	//enable the peripheral clock
	GPIO_PeriClockControl(pGPIOHandle->pGPIOx, ENABLE);

	//1. configure the mode of gpio pin
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode<=GPIO_MODE_ANALOG){
		//the non interrupt mode.
		temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode<<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER &=~(0x3<<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));		//clearing
		pGPIOHandle->pGPIOx->MODER |=temp;		//setting
		temp=0;
	}else{	//Interrupt mode
		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode<=GPIO_MODE_IT_FT){
			//1.configure the FTSR
			EXTI->FTSR |=(1<< pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			//Clear the corresponding RTSR bit
			EXTI->RTSR &=~(1<< pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}else if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode<=GPIO_MODE_IT_RT){
			//1.configure the RTSR
			EXTI->RTSR |=(1<< pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			//Clear the corresponding RTSR bit
			EXTI->FTSR &=~(1<< pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}else if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode<=GPIO_MODE_IT_RFT){
			//1.configure both FTSR and RTSR
			EXTI->RTSR |=(1<< pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			//Clear the corresponding RTSR bit
			EXTI->FTSR |=(1<< pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}
		//2. configure GPIO port selection in SYSCFG_EXTICR
		//Будем расчитывать позицию EXTIx в регистрах
		/*Всего 4 регистра SYSCFG_EXTICR2 из каждого регистра используются первые 16 бит. Каждый регистр отвечает за 4 линии EXTI
		 * К каждой линии EXTI можно подключить путем записи 4 битного числа только один пин порта под номером соответствующему номеру линии EXTI
		 *Пример: к линии EXTI5 можно подключить PA5 либо PB5 либо... PE5*/
		uint8_t	temp1=pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber/4;
		uint8_t	temp2=pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber%4;
		uint8_t portcode=GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);
		SYSCFG_PCLK_EN();
		SYSCFG->EXTICR[temp1]=portcode <<(temp2*4);

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

/*********************************************************************
 * @fn      		  - GPIO_DeInit
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -
 */
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){						//сбрасывает порт в исходное состояние
	if(pGPIOx == GPIOA){
			GPIOA_REG_RESET();
		}else if (pGPIOx == GPIOB){
			GPIOB_REG_RESET();
		}else if (pGPIOx == GPIOC){
			GPIOC_REG_RESET();
		}else if (pGPIOx == GPIOD){
			GPIOD_REG_RESET();
		}else if (pGPIOx == GPIOE){
			GPIOE_REG_RESET();
		}else if (pGPIOx == GPIOF){
			GPIOF_REG_RESET();
		}else if (pGPIOx == GPIOG){
			GPIOG_REG_RESET();
		}else if (pGPIOx == GPIOH){
			GPIOH_REG_RESET();
		}
}

/*Date read and write*/

/*********************************************************************
 * @fn      		  - GPIO_ReadFromInputPin
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -   0 or 1
 *
 * @Note              -

 */
uint8_t  GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){	//возвращает булевое значение
	uint8_t value;

	value = (uint8_t )((pGPIOx->IDR  >> PinNumber) & 0x00000001 ) ;

	return value;
}

/*********************************************************************
 * @fn      		  - GPIO_ReadFromInputPort
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
uint16_t  GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){
	uint16_t value;

	value = (uint16_t)pGPIOx->IDR;

	return value;
}

/*********************************************************************
 * @fn      		  - GPIO_WriteToOutputPin
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_WriteToOutPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value){		//
	if(Value == GPIO_PIN_SET){
			//write 1 to the output data register at the bit field corresponding to the pin number
			pGPIOx->ODR |= ( 1 << PinNumber);
		}else{
			//write 0
			pGPIOx->ODR &= ~( 1 << PinNumber);
		}
}

/*********************************************************************
 * @fn      		  - GPIO_WriteToOutputPort
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_WriteToOutPort(GPIO_RegDef_t *pGPIOx, uint16_t Value){							//
	pGPIOx->ODR  = Value;
}

/*********************************************************************
 * @fn      		  - GPIO_ToggleOutputPin
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_ToggleOutPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){						//
	pGPIOx->ODR  ^= ( 1 << PinNumber);
}


/*IRQ Configuration and ISR handling*/


/*********************************************************************
 * @fn      		  - GPIO_IRQConfig
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_IRQInnterruptConfig(uint8_t IRQNumber, uint8_t EnorDI){
	if(EnorDI ==ENABLE){
		if(IRQNumber <=31){
			//program ISER0 resgister
			*NVIC_ISER0 |=(1<<IRQNumber);
		}else if(IRQNumber >31 && IRQNumber <64){	//32 to 63
			//program ISER1 register
			*NVIC_ISER1 |=(1<<(IRQNumber %32));
		}
		else if(IRQNumber >=64 && IRQNumber <96){
			//program ISER2 register
			*NVIC_ISER2 |=(1<<(IRQNumber %64));		//64 to 95
		}
	}else{
		if(IRQNumber <=31){
			//program ICER0 register
			*NVIC_ICER0 |=(1<<IRQNumber);
		}else if(IRQNumber >31 && IRQNumber <64){
			//program ICER1 register
			*NVIC_ICER1 |=(1<<(IRQNumber %32));
		}else if(IRQNumber >=64 && IRQNumber <96){
			//program ICER2 register
			*NVIC_ICER2 |=(1<<(IRQNumber %64));
		}
	}
}//END GPIO_IRQInnteruptConfig



/*********************************
 * @fn					- GPIO_IRQPriorityConfig
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
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority){
	//1. first lets find out the ipr register
	uint8_t iprx=IRQNumber/4;				//выесняем какой регистр IPRX
	uint8_t iprx_section=IRQNumber %4;		//выесняем какиая из 4 секций
	uint8_t shift_ammount=(8*iprx_section)+(8-NO_PR_BITS_IMPLEMENTED);
	*(NVIC_PR_BASE_ADDR+(iprx*4)) |= (IRQPriority <<shift_ammount);	//(8*iprx_section)	//умножаем на 4 потому что следуюший адрес регистра находится через 4 адреса

}//END GPIO_IRQPriorityConfig



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
void GPIO_IRQHandling(uint8_t PinNumber){
	//clear the exti pr register corresponding to the pin number
	if (EXTI->PR &(1<<PinNumber)){
		//clear the pending register bit
		EXTI->PR |=(1<<PinNumber);
	}
}
