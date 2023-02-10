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
		}else{
			if	(pSPIx==SPI1){
				SPI1_PCLK_DI();
			}else if(pSPIx==SPI2){
				SPI2_PCLK_DI();
			}else if(pSPIx==SPI3){
				SPI3_PCLK_EDI();
			}else if(pSPIx==SPI4){
				SPI4_PCLK_DI();
			}
		}
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
//void SPI_DeInit(SPI_RegDef_t *pSPIx)
//{

//}

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
 *@Note					-
 *
 * */
//void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t len)
//{

//}

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
