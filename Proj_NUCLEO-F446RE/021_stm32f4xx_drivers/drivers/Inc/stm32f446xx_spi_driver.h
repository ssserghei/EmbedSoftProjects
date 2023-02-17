/*
 * stm32f4xx_spi_driver.h
 *
 *  Created on: 4 февр. 2023 г.
 *      Author: Serghei
 */

#ifndef INC_STM32F4XX_SPI_DRIVER_H_
#define INC_STM32F4XX_SPI_DRIVER_H_

#include "stm32f446xx.h"

/*Configueration structure sor SPIx peripheral*/
//26.3.7 SPI configuration
typedef struct
{
	uint8_t SPI_DeviceMode;	// MSTR: Master selection 0: Slave configuration 1: Master configuration
	uint8_t SPI_BusConfig;	//
	uint8_t	SPI_SclkSpeed;	//
	uint8_t	SPI_DFF;		//		Bit 11 DFF: Data frame format
	uint8_t	SPI_CPOL;		//
	uint8_t SPI_CPHA;		//
	uint8_t	SPI_SSM;		//
}SPI_Config_t;

/*Handle structure for SPIx peripheral*/
typedef struct
{
	SPI_RegDef_t 	*pSPIx;		/*!<This hold base address of SPIx(x:0.1,2) peripheral*/
	SPI_Config_t	SPIConfig;
}SPI_Handle_t;

/*@SPI_DeviceMode*/							//Bit 2 MSTR: Master selection
#define SPI_DEVICE_MODE_MASTER		1		//1: Master configuration
#define SPI_DEVICE_MODE_SLAVE		0		//0: Slave configuration
/*@SPI_BusConfig*/
#define SPI_BUS_CONFIG_FD				1	//Full duplex	26.7.1 SPI control register 1 (SPI_CR1) (not used in I2S mode)
#define SPI_BUS_CONFIG_HD				2	//Half duplex
//#define SPI_BUS_CONFIG_SIMPLEX_TXONLY	3
#define SPI_BUS_CONFIG_SIMPLEX_RXONLY	3
/*@SPI_SclkSpeed*/		//BR[2:0]
#define SPI_SCLK_SPEED_DIV2		0
#define SPI_SCLK_SPEED_DIV4		1
#define SPI_SCLK_SPEED_DIV8		2
#define SPI_SCLK_SPEED_DIV16	3
#define SPI_SCLK_SPEED_DIV32	4
#define SPI_SCLK_SPEED_DIV64	5
#define SPI_SCLK_SPEED_DIV128	6
#define SPI_SCLK_SPEED_DIV256	7
/*@SPI_DFF*/
#define SPI_DFF_8BITS 			0		//0: 8-bit data frame format is selected for transmission/reception
#define SPI_DFF_16BITS 			1		//1: 16-bit data frame format is selected for transmission/reception
/*@SPI_CPOL*/
#define SPI_CPOL_HIGH			0		//0: CK to 0 when idle
#define SPI_CPOL_LOW			1		//
/*@SPI_CPHA*/
#define SPI_CPHA_HIGH			1		//
#define SPI_CPHA_LOW			0		//
/*@SPI_SSM*/
#define SPI_SSM_EN				1		//1: Software slave management enabled
#define SPI_SSM_DI				0		//0: Software slave management disabled

#define SPI_TXE_FLAG	(1<<SPI_SR_TXE)
#define SPI_RXNE_FLAG	(1<<SPI_SR_RXNE)
#define SPI_BUSY_FLAG	(1<<SPI_SR_BSY)


/*******************************************************************************************
 * 									APIs supported by this driver
 * 					for more information about this AOIs check the functions definitions
 *******************************************************************************************/

/*Peripheral Clock setup*/
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);

/*Init and De-init*/
void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_RegDef_t *pSPIx);

/*Data Send and Receive*/
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t len);
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t len);

/*IRQ Configuration ISR handling*/
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);		//
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);	//
void SPI_IRQHandling(SPI_Handle_t *pSPIHandle);


/*
 * Other Peripheral Control APIs
 */
void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t EnOrDi);
void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t EnOrDi);


#endif /* INC_STM32F4XX_SPI_DRIVER_H_ */
