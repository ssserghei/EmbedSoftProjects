/*
 * main.h
 *
 *  Created on: Jun 27, 2022
 *      Author: Serghei
 */

#ifndef MAIN_H_
#define MAIN_H_


/*******************************************************************
CLOCK_EN
Table 2. STM32L41xxx/42xxx/43xxx/44xxx/45xxx/46xxx memory map and peripheral register
boundary addresses
6.4.16 AHB2 peripheral clock enable register (RCC_AHB2ENR)
*/

typedef struct{
	uint32_t gpioA_en		:1;
	uint32_t gpioB_en		:1;
	uint32_t gpioC_en		:1;
	uint32_t gpioD_en		:1;
	uint32_t gpioE_en		:1;

	uint32_t reserved1		:2;
	uint32_t gpioH_en		:1;
	uint32_t reserved2		:5;
	uint32_t ADC_en			:1;
	uint32_t AES_en			:1;
	uint32_t reserved3		:1;
	uint32_t RNG_en			:1;
	uint32_t reserved4		:13;
}RCC_AHB1ENR_t;
	RCC_AHB1ENR_t volatile *pClkCtrlReg=(RCC_AHB1ENR_t*) (0x40021000+0x4C);

/*******************************************************************
PORT_MODER	//GPIOx_MODER
8.4.1 GPIO port mode register (GPIOx_MODER) (x =A to E and H)
Address offset:0x00
*/
typedef struct{
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

//														base address + ofset
GPIOx_MODER_t volatile *pPortAModeReg=(GPIOx_MODER_t*) (0x48000000+0x00);
GPIOx_MODER_t volatile *pPortBModeReg=(GPIOx_MODER_t*) (0x48000400+0x00);
GPIOx_MODER_t volatile *pPortCModeReg=(GPIOx_MODER_t*) (0x48000800+0x00);
GPIOx_MODER_t volatile *pPortDModeReg=(GPIOx_MODER_t*) (0x48000C00+0x00);
GPIOx_MODER_t volatile *pPortEModeReg=(GPIOx_MODER_t*) (0x48001000+0x00);
	//pPortAModeReg->moder5=1;	//output
	//pPortAModeReg->moder5=0;	//input


/*******************************************************************
PORT_OUT	//GPIO_OUT
8.4.2 GPIO port output type register (GPIOx_OTYPER) (x = A to E and H)
Address offset: 0x04
*/
typedef struct{
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
GPIOx_ODR_t volatile *pPortAOutReg=(GPIOx_ODR_t*) (0x48000000+0x14);
GPIOx_ODR_t volatile *pPortBOutReg=(GPIOx_ODR_t*) (0x48000400+0x14);
GPIOx_ODR_t volatile *pPortCOutReg=(GPIOx_ODR_t*) (0x48000800+0x14);
GPIOx_ODR_t volatile *pPortDOutReg=(GPIOx_ODR_t*) (0x48000C00+0x14);
GPIOx_ODR_t volatile *pPortEOutReg=(GPIOx_ODR_t*) (0x48001000+0x14);

/*******************************************************************
GPIOx_IDR
8.4.5 GPIO port input data register (GPIOx_IDR) (x = A to E and H)
Address offset: 0x10
*/
typedef struct{
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
GPIOx_IDR_t volatile *pPortAIntReg=(GPIOx_IDR_t*) (0x48000000+0x10);
GPIOx_IDR_t volatile *pPortBIntReg=(GPIOx_IDR_t*) (0x48000400+0x10);
GPIOx_IDR_t volatile *pPortCIntReg=(GPIOx_IDR_t*) (0x48000800+0x10);
GPIOx_IDR_t volatile *pPortDIntReg=(GPIOx_IDR_t*) (0x48000C00+0x10);
GPIOx_IDR_t volatile *pPortEIntReg=(GPIOx_IDR_t*) (0x48001000+0x10);

/*******************************************************************
GPIOx_PUPDR
8.4.4 GPIO port pull-up/pull-down register (GPIOx_PUPDR)Address offset: 0x10
Address offset: 0x0C
These bits are written by software to configure the I/O pull-up or pull-down
00: No pull-up, pull-down
01: Pull-up
10: Pull-down
11: Reserved
*/
typedef struct{
	uint32_t pupdr0		:2;
	uint32_t pupdr1		:2;
	uint32_t pupdr2		:2;
	uint32_t pupdr3		:2;
	uint32_t pupdr4		:2;
	uint32_t pupdr5		:2;
	uint32_t pupdr6		:2;
	uint32_t pupdr7		:2;
	uint32_t pupdr8		:2;
	uint32_t pupdr9		:2;
	uint32_t pupdr10	:2;
	uint32_t pupdr11	:2;
	uint32_t pupdr12	:2;
	uint32_t pupdr13	:2;
	uint32_t pupdr14	:2;
	uint32_t pupdr15	:2;
}GPIOx_PUPDR_t;
// 												  base address + ofset
GPIOx_PUPDR_t volatile *pPortAPuPdReg=(GPIOx_PUPDR_t*) (0x48000000+0x0C);
GPIOx_PUPDR_t volatile *pPortBPuPdReg=(GPIOx_PUPDR_t*) (0x48000400+0x0C);
GPIOx_PUPDR_t volatile *pPortCPuPdReg=(GPIOx_PUPDR_t*) (0x48000800+0x0C);
GPIOx_PUPDR_t volatile *pPortDPuPdReg=(GPIOx_PUPDR_t*) (0x48000C00+0x0C);
GPIOx_PUPDR_t volatile *pPortEPuPdReg=(GPIOx_PUPDR_t*) (0x48001000+0x0C);


//pPortAPuPdReg->pupdr12=1;	//pull-up connected
//pPortAPuPdReg->pupdr12=2;	//Pull-down connected
//pPortAPuPdReg->pupdr12=0;	//No pull-up, pull-down

#endif /* MAIN_H_ */
