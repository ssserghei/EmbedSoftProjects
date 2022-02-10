/*
 * main.h
 *
 *  Created on: 5 февр. 2022 г.
 *      Author: Maxim
 */
#ifndef MAIN_H_
#define MAIN_H_

/******************************************************************************
CLOCK_EN
6.3.8 AHB peripheral clock enable register (RCC_AHBENR)
Address offset: 0x1C *
*/
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
	RCC_AHB1ENR_t volatile *pClkCtrlReg=(RCC_AHB1ENR_t*) (0x40023800+0x1C);


/******************************************************************************
 * PORT_MODER	//GPIOx_MODER
 7.4.1 GPIO port mode register (GPIOx_MODER) (x = A..H)
 * Address offset: 0x00
 * These bits are written by software to configure the I/O direction mode.
 * 00: Input (reset state)
 * 01: General purpose output mode
 * 10: Alternate function mode
 * 11: Analog mode
 * */
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
	// 												  		base address + ofset
	GPIOx_MODER_t volatile *pPortAModeReg=(GPIOx_MODER_t*) (0x40020000+0x00);
	GPIOx_MODER_t volatile *pPortBModeReg=(GPIOx_MODER_t*) (0x40020400+0x00);
	GPIOx_MODER_t volatile *pPortCModeReg=(GPIOx_MODER_t*) (0x40020800+0x00);
	GPIOx_MODER_t volatile *pPortDModeReg=(GPIOx_MODER_t*) (0x40020C00+0x00);
	GPIOx_MODER_t volatile *pPortEModeReg=(GPIOx_MODER_t*) (0x40021000+0x00);
	GPIOx_MODER_t volatile *pPortHModeReg=(GPIOx_MODER_t*) (0x40021400+0x00);
	GPIOx_MODER_t volatile *pPortFModeReg=(GPIOx_MODER_t*) (0x40021800+0x00);
	GPIOx_MODER_t volatile *pPortGModeReg=(GPIOx_MODER_t*) (0x40021C00+0x00);

	//pPortA3eModeReg->moder5=1;	//output
	//pPortA3eModeReg->moder5=0;	//input


/*******************************************************************************
//PORT_OUT	//GPIO_OUT
7.4.6 GPIO port output data register (GPIOx_ODR) (x = A..H) * Address offset: 0x14
 */
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
	//
	GPIOx_ODR_t volatile *pPortAOutReg=(GPIOx_ODR_t*) (0x40020000+0x14);
	GPIOx_ODR_t volatile *pPortBOutReg=(GPIOx_ODR_t*) (0x40020400+0x14);
	GPIOx_ODR_t volatile *pPortCOutReg=(GPIOx_ODR_t*) (0x40020800+0x14);
	GPIOx_ODR_t volatile *pPortDOutReg=(GPIOx_ODR_t*) (0x40020C00+0x14);
	GPIOx_ODR_t volatile *pPortEOutReg=(GPIOx_ODR_t*) (0x40021000+0x14);
	GPIOx_ODR_t volatile *pPortHOutReg=(GPIOx_ODR_t*) (0x40021400+0x14);
	GPIOx_ODR_t volatile *pPortFOutReg=(GPIOx_ODR_t*) (0x40021180+0x14);
	GPIOx_ODR_t volatile *pPortGOutReg=(GPIOx_ODR_t*) (0x40021C00+0x14);

/*******************************************************************************
 * 7.4.5 GPIO port input data register (GPIOx_IDR) (x = A..H)
 * Address offset: 0x10
 */
typedef struct
{
	uint16_t idr0		:1;
	uint16_t idr1		:1;
	uint16_t idr2		:1;
	uint16_t idr3		:1;
	uint16_t idr		:1;
	uint16_t idr5		:1;
	uint16_t idr6		:1;
	uint16_t idr7		:1;
	uint16_t idr8		:1;
	uint16_t idr9		:1;
	uint16_t idr10		:1;
	uint16_t idr11		:1;
	uint16_t idr12		:1;
	uint16_t idr13		:1;
	uint16_t idr14		:1;
	uint16_t idr15		:1;
}GPIOx_IDR_t;
	// 												  base address + ofset
	GPIOx_IDR_t volatile *pPortAIntReg=(GPIOx_IDR_t*) (0x40020000+0x10);
	GPIOx_IDR_t volatile *pPortBIntReg=(GPIOx_IDR_t*) (0x40020400+0x10);
	GPIOx_IDR_t volatile *pPortCIntReg=(GPIOx_IDR_t*) (0x40020800+0x10);
	GPIOx_IDR_t volatile *pPortDIntReg=(GPIOx_IDR_t*) (0x40020C00+0x10);
	GPIOx_IDR_t volatile *pPortEIntReg=(GPIOx_IDR_t*) (0x40021000+0x10);
	GPIOx_IDR_t volatile *pPortHIntReg=(GPIOx_IDR_t*) (0x40021400+0x10);
	GPIOx_IDR_t volatile *pPortFIntReg=(GPIOx_IDR_t*) (0x40021800+0x10);
	GPIOx_IDR_t volatile *pPortGIntReg=(GPIOx_IDR_t*) (0x40021C00+0x10);

#endif /* MAIN_H_ */
