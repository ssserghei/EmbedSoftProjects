/*
 * stm32f4xx_spi_driver.c
 *
 *  Created on: 4 февр. 2023 г.
 *      Author: Serghei
 */

#include <stm32f446xx_spi_driver.h>

/*********************************************
 * @fn					- SPI_PeriClockControl
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
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
	if (EnorDi==ENABLE)
		{
			if	(pSPIx==SPI1){
				SPI1_PCLK_EN();
			}else if(pSPIx==SPI2){
				SPI2_PCLK_EN();
			}else if(pSPIx==SPI3){
				SPI3_PCLK_EN();
			}else if(pSPIx==SPI4){
				SPI4_PCLK_EN();
			}
		}
	else{/* TODO
			if	(pSPIx==SPI1){
				SPI1_PCLK_DI();
			}else if(pSPIx==SPI2){
				SPI2_PCLK_DI();
			}else if(pSPIx==SPI3){
				SPI3_PCLK_EDI();
			}else if(pSPIx==SPI4){
				SPI4_PCLK_DI();
			}
		*/}
}


/*********************************************
 * @fn					- SPI_Init
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
void SPI_Init(SPI_Handle_t *pSPIHandle)
{

	//peripheral clock control enable
	SPI_PeriClockControl(pSPIHandle->pSPIx, ENABLE);

	//first lets configure the SPI_CR1 register
	uint32_t tempreg=0;

	//1. configure the device mode
	tempreg|=pSPIHandle->SPIConfig.SPI_DeviceMode<<SPI_CR1_MSTR;		//Bit 2 MSTR: Master selection

	//2.configure the bus config
	if(pSPIHandle->SPIConfig.SPI_BusConfig==SPI_BUS_CONFIG_FD)
	{
		//bidi mode should be cleared
		tempreg &=~(1<<SPI_CR1_BIDIMODE);
	}else if (pSPIHandle->SPIConfig.SPI_BusConfig==SPI_BUS_CONFIG_HD)
	{
		//bidi mode should be set
		tempreg |=(1<<SPI_CR1_BIDIMODE);
	}else if(pSPIHandle->SPIConfig.SPI_BusConfig==SPI_BUS_CONFIG_SIMPLEX_RXONLY)
	{
		//BIDI mode should be cleared
		tempreg &=~(1<<SPI_CR1_BIDIMODE);
		//RXONLY bit must be set
		tempreg |=(1<<SPI_CR1_RXONLY);
	}
	//3.Configure the SOI serial clock speed (baud rate)
	tempreg|=pSPIHandle->SPIConfig.SPI_SclkSpeed<<SPI_CR1_BR;

	//4.configure the DFF
	tempreg|=pSPIHandle->SPIConfig.SPI_DFF<<SPI_CR1_DFF;

	//5.configure the CPOL
	tempreg|=pSPIHandle->SPIConfig.SPI_CPOL<<SPI_CR1_CPOL;

	//configurte the CPHA
	tempreg|=pSPIHandle->SPIConfig.SPI_CPHA<<SPI_CR1_CPHA;

	tempreg |= pSPIHandle->SPIConfig.SPI_SSM << SPI_CR1_SSM;

	pSPIHandle->pSPIx->CR1=tempreg;
}

/*********************************************
 * @fn					- SPI_DeInit
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
void SPI_DeInit(SPI_RegDef_t *pSPIx)
{
	//TODO
}

SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint32_t FlagName)
{
	if(pSPIx->SR & FlagName)
	{
		return FLAG_SET;
	}
	return FLAG_RESET;
}


/*********************************************
 * @fn					- SPI_SendData
 *
 *@brief				-
 *
 *@param[in]			-
 *@param[in]			-
 *@param[in]			-
 *
 *@return				-
 *
 *@Note					- This in blocking call
 *
 * */
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len)
{
	while(Len>0)
	{
		//1.wait until TXE is set
		//while(!(pSPIx-SR&(1<<1)));
		SPI_GetFlagStatus(pSPIx,SPI_TXE_FLAG)==FLAG_RESET;
		//2.checkthe DFF bit in CR1
		if((pSPIx->CR1&(1<<SPI_CR1_DFF)))
		{
			//16 bit DFF
			//1.Load the data in to trhe DR
			pSPIx->DR=*((uint16_t*)pTxBuffer);
			Len--;
			Len--;
			(uint16_t*)pTxBuffer++;
		}else
		{
			//8bit DFF
			pSPIx->DR=*pTxBuffer;
			Len--;
			pTxBuffer++;
		}
	}
}

/*********************************************
 * @fn					- SPI_ReceiveData
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
//void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t len)
//{

//}

/*********************************************************************
 * @fn      		  - SPI_PeripheralControl
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
void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t EnOrDi)
{
	if(EnOrDi == ENABLE)
	{
		pSPIx->CR1 |=  (1 << SPI_CR1_SPE);
	}else
	{
		pSPIx->CR1 &=  ~(1 << SPI_CR1_SPE);
	}
}

/*********************************************************************
 * @fn      		  - SPI_SSIConfig
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
void  SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t EnOrDi)
{
	if(EnOrDi == ENABLE)
	{
		pSPIx->CR1 |=  (1 << SPI_CR1_SSI);
	}else
	{
		pSPIx->CR1 &=  ~(1 << SPI_CR1_SSI);
	}


}

/*********************************************
 * @fn					- SPI_IRQInterruptConfig
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
//void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
//{

//}

/*********************************************
 * @fn					- SPI_IRQPriorityConfig
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
//void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority)
//{

//}

/*********************************************
 * @fn					- SPI_IRQHandling
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
//void SPI_IRQHandling(SPI_Handle_t *pHandle)

//{

//}
