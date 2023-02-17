/*
 * 006_SPI_TX_testing.c
 *
 *  Created on: 12 февр. 2023 г.
 *      Author: Serghei
 */

/*SPI2 pins
 *	AF5
 * SPI2_SCK		PA9		PB10	PB13	PC7		PD3
 * SPI2_NSS		PB4		PB12	PD1		PB4		PB9
 * SPI2_MISO	PB14	PC2
 * SPI2_MOSI	PB15	PC3		PC1
 * */

/*PB14 as SPI2_MISO
 *PB15 as SPI2_MOSI
 *PB13 as SPI2_SCK
 *PB12 as SPI2_NSS
 *Alt func mode :AF5
 * */
#include <string.h>
#include "stm32f446xx.h"

void SPI2_GPIOInits(void)
{
	GPIO_Handle_t SPIPins;

	SPIPins.pGPIOx=GPIOB;

	SPIPins.GPIO_PinConfig.GPIO_PinMode=GPIO_MODE_ALTFN;
	SPIPins.GPIO_PinConfig.GPIO_PinAltFunMode=5;
	SPIPins.GPIO_PinConfig.GPIO_PinOPType=GPIO_OP_TYPE_PP;
	SPIPins.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_NO_PUPD;
	SPIPins.GPIO_PinConfig.GPIO_PinSpeed=GPIO_SPEED_FAST;

	//SCK
	SPIPins.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_13;
	GPIO_Init(&SPIPins);

	//MOSI
	SPIPins.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_15;
	GPIO_Init(&SPIPins);

	//MISO
	//SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	//GPIO_Init(&SPIPins);

	//NSS
	SPIPins.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_12;
	GPIO_Init(&SPIPins);

}

void SPI2_Inits(void)
{
	SPI_Handle_t SPI2handle;

	SPI2handle.pSPIx=SPI2;
	SPI2handle.SPIConfig.SPI_BusConfig=SPI_BUS_CONFIG_FD;
	SPI2handle.SPIConfig.SPI_DeviceMode=SPI_DEVICE_MODE_MASTER;	//MTSR
	SPI2handle.SPIConfig.SPI_SclkSpeed=SPI_SCLK_SPEED_DIV32;		//generates SCLK of 8MHz
	SPI2handle.SPIConfig.SPI_DFF=SPI_DFF_8BITS;
	SPI2handle.SPIConfig.SPI_CPOL=SPI_CPOL_HIGH;
	SPI2handle.SPIConfig.SPI_CPHA=SPI_CPHA_LOW;
	SPI2handle.SPIConfig.SPI_SSM=SPI_SSM_DI;		//software slave management enable for NSS pin

	SPI_Init(&SPI2handle);
}

int main (void)
{
	char user_data[]="Hello worls";

	//initialize the GPIO pins te behave as SPI2 pins
	SPI2_GPIOInits();

	//initialize the SPI2 peripheral parameters
	SPI2_Inits();

	//this make NSS signal internaly high and
	SPI_SSIConfig(SPI2, ENABLE);

	//enable the SPI peripheral
	SPI_PeripheralControl(SPI2, ENABLE);

	//to send data
	SPI_SendData(SPI2,(uint8_t*)user_data, strlen(user_data));

	while(1);


	return 0;
}




