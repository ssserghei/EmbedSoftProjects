/*
 * main.h
 *
 *  Created on: 23 авг. 2020 г.
 *      Author: SSS_notebok
 */

#ifndef MAIN_H_
#define MAIN_H_

/*******************************************************************************/
//CLOCK_EN
//6.3.10 RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
typedef struct
{
	uint32_t gpioA_en		:1;
	uint32_t gpioB_en		:1;
	uint32_t gpioC_en		:1;
	uint32_t gpioD_en		:1;
	uint32_t gpioE_en		:1;
	uint32_t gpioF_en		:1;
	uint32_t gpioG_en		:1;
	uint32_t gpioH_en		:1;

	uint32_t reserved1		:4;
	uint32_t crc_en			:1;
	uint32_t reserved2		:5;
	uint32_t ckpsram_en		:1;
	uint32_t reserved3		:2;
	uint32_t dma1_en		:1;
	uint32_t dma2_en		:1;
	uint32_t reserved4		:6;
	uint32_t otghs_en		:1;
	uint32_t otghsulpi_en	:1;
	uint32_t reserved5		:1;
}RCC_AHB1ENR_t;

/*******************************************************************************/
// PORT_MODER	//GPIOx_MODER
//7.4.1 GPIO port mode register (GPIOx_MODER) (x = A..H)
//These bits are written by software to configure the I/O direction mode.
//00: Input (reset state)
//01: General purpose output mode
//10: Alternate function mode
//11: Analog mode
typedef struct
{
	uint32_t moder0		:2;
	uint32_t moder1		:2;
	uint32_t moder2		:2;
	uint32_t moder3		:2;
	uint32_t moder4		:2;
	uint32_t moder5		:2;
	uint32_t moder6		:2;
	uint32_t moder7		:2;
	uint32_t moder8		:2;
	uint32_t moder9		:2;
	uint32_t moder10	:2;
	uint32_t moder11	:2;
	uint32_t moder12	:2;
	uint32_t moder13	:2;
	uint32_t moder14	:2;
	uint32_t moder15	:2;
}GPIOx_MODER_t;


/*******************************************************************************/
//PORT_OUT	//GPIO_OUT
//7.4.6 GPIO port output data register (GPIOx_ODR) (x = A..H)
typedef struct
{
	uint16_t odr0		:1;
	uint16_t odr1		:1;
	uint16_t odr2		:1;
	uint16_t odr3		:1;
	uint16_t odr4		:1;
	uint16_t odr5		:1;
	uint16_t odr6		:1;
	uint16_t odr7		:1;
	uint16_t odr8		:1;
	uint16_t odr9		:1;
	uint16_t odr10		:1;
	uint16_t odr11		:1;
	uint16_t odr12		:1;
	uint16_t odr13		:1;
	uint16_t odr14		:1;
	uint16_t odr15		:1;
}GPIOx_ODR_t;
	GPIOx_ODR_t volatile *pPortAOutReg=(GPIOx_ODR_t*) 0x40020014;


#endif /* MAIN_H_ */
