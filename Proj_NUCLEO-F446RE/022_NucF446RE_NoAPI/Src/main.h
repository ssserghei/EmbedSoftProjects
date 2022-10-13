/*
 * main.h
 *
 *  Created on: Oct 13, 2022
 *      Author: SergheiSGarage
 */

#include <stdint.h>
#include <stddef.h>

#ifndef MAIN_H_
#define MAIN_H_

#define __vo volatile
#define __weak __attribute__((weak))

/****************************** START: Processor Specific Details******************************/

/*AHBx and APBx Bus Peripheral base addresses*/
//Table 1. STM32F446xx register boundary addresses
//#define PERIPH_BASEADDR			0x40000000U					/*Первый адрес начала APB1 //TIM2*/
//#define APB1PERIPH_BASEADDR		PERIPH_BASEADDR				//
//#define APB2PERIPH_BASEADDR		0x40010000U					/*TIM1*/
#define AHB1PERIPH_BASEADDR		0x40020000U					//
//#define AHB2PERIPH_BASEADDR		0x50000000U					//

/*Base addresses of peripherals which are hanging on AHB1 bus*/
#define GPIOA_BASEADDR 			(AHB1PERIPH_BASEADDR+0x0000)		//0x4002 0000 - 0x4002 03FF GPIOA
#define GPIOB_BASEADDR 			(AHB1PERIPH_BASEADDR+0x0400)		//0x4002 0400 - 0x4002 07FF GPIOB
#define GPIOC_BASEADDR 			(AHB1PERIPH_BASEADDR+0x0800)		//0x4002 0800 - 0x4002 0BFF GPIOC
#define GPIOD_BASEADDR 			(AHB1PERIPH_BASEADDR+0x0C00)		//0x4002 0C00 - 0x4002 0FFF GPIOD
#define GPIOE_BASEADDR 			(AHB1PERIPH_BASEADDR+0x1000)		//0x4002 1000 - 0x4002 13FF GPIOE
#define GPIOF_BASEADDR 			(AHB1PERIPH_BASEADDR+0x1400)		//0x4002 1400 - 0x4002 17FF GPIOF
#define GPIOG_BASEADDR 			(AHB1PERIPH_BASEADDR+0x1800)		//0x4002 1800 - 0x4002 1BFF GPIOG
#define GPIOH_BASEADDR 			(AHB1PERIPH_BASEADDR+0x1C00)		//0x4002 1C00 - 0x4002 1FFF GPIOH

#define RCC_BASEADDR			(AHB1PERIPH_BASEADDR+0x3800)

/******************************Peripheral Register Definition Structures******************************/

/*Note: Register of a peripheral are specific to MCU
*e.g: Number of Register of SPI peripheral of STM32F4x family of MCUs may be different(more or less)
* Compared to number of registers of SPI peripheral of STM32Lx or STM32F0x family of MCUs
* Please check your Device RM*/

/*7.4.11 GPIO register map
 * 7.1 GPIO introduction*/
typedef struct{	//7.4.11 GPIO register map
	__vo uint32_t MODER;	/*!< GPIO port mode register,	Address offset: 0x00*/
	__vo uint32_t OTYPER;	/*!<	     					Address offset: 0x04*/
	__vo uint32_t OSPEEDR;	/*!< Possible OSPEEDER							0x08*/
	__vo uint32_t PUPDR;	/*												0x0C*/
	__vo uint32_t IDR;		/*												0x10*/
	__vo uint32_t ODR;		/*												0x14*/
	__vo uint32_t BSRR;		/*												0x18*/
//	__vo uint32_t LCKR;		/*												0x1C*/
	__vo uint32_t AFR[2];	/*!< AFR[0] : GPIO alternate function low register, AF[1] : GPIO alternate function high register    		Address offset: 0x20-0x24 */
}GPIO_RegDef_t;				//

/*peripheral register definition structure for RCC
 * 6.3.28 RCC register map
 * Table 21. RCC register map and reset values*/
typedef struct{
	__vo uint32_t CR;			/*!<	Adders offset	0x00		*/
	__vo uint32_t PLLCFGR[2];	/*!<	Adders offset	0x04-0x04	*/
	__vo uint32_t CIR;			/*!<	Adders offset	0x0C		*/
	__vo uint32_t AHB1RSTR;		/*!<	Adders offset	0x10		*/
	__vo uint32_t AHB2RSTR;		/*!<	Adders offset	0x14		*/
	__vo uint32_t AHB3RSTR;		/*!<	Adders offset	0x18		*/
		 uint32_t RESERVED0;	/*!<	Adders offset	0x1C		*/
	__vo uint32_t APB1RSTR;		/*!<	Adders offset	0x20		*/
	__vo uint32_t APB2RSTR;		/*!<	Adders offset	0x24		*/
		 uint32_t RESERVED1[2];	/*!<	Adders offset	0x28-0x2C	*/
	__vo uint32_t AHB1ENR;		/*!<	Adders offset	0x30		*/
	__vo uint32_t AHB2ENR;		/*!<	Adders offset	0x34		*/
	__vo uint32_t AHB3ENR;		/*!<	Adders offset	0x38		*/
	__vo uint32_t RESERVED2;	/*!<	Adders offset	0x3C		*/
	__vo uint32_t APB1ENR;		/*!<	Adders offset	0x40		*/
	__vo uint32_t APB2ENR;		/*!<	Adders offset	0x44		*/
		 uint32_t RESERVED3[2];	/*!<	Adders offset	0x48-0x4C	*/
	__vo uint32_t AHB1LPENR;	/*!<	Adders offset	0x50		*/
	__vo uint32_t AHB2LPENR;	/*!<	Adders offset	0x54		*/
	__vo uint32_t AHB3LPENR;	/*!<	Adders offset	0x58		*/
	__vo uint32_t RESERVED4;	/*!<	Adders offset	0x5C		*/
	__vo uint32_t APB1LPENR;	/*!<	Adders offset	0x60		*/
	__vo uint32_t APB2LPENR;	/*!<	Adders offset	0x64		*/
		 uint32_t RESERVED5[2];	/*!<	Adders offset	0x68-0x6C	*/
	__vo uint32_t BDCR;			/*!<	Adders offset	0x70		*/
	__vo uint32_t CSR;			/*!<	Adders offset	0x74		*/
		 uint32_t RESERVED9[2];	/*!<	Adders offset	0x78-0x7C	*/
	__vo uint32_t SSCGR;		/*!<	Adders offset	0x80		*/
	__vo uint32_t PLLI2SCFGR;	/*!<	Adders offset	0x84		*/
	__vo uint32_t PLLSAICFGR;	/*!<	Adders offset	0x88		*/
	__vo uint32_t DCKCFGR;		/*!<	Adders offset	0x8C		*/
	__vo uint32_t CKGATENR;		/*!<	Adders offset	0x90		*/
	__vo uint32_t DCKCFGR2;		/*!<	Adders offset	0x94		*/
}RCC_RegDef_t;


/***************************************************/
/*Clock Disable Macros for GPIOx peripherals*/
#define GPIOA_PCLK_DI()		(RCC->AHB1ENR &=~(1<<0))
#define GPIOB_PCLK_DI()		(RCC->AHB1ENR &=~(1<<1))
#define GPIOC_PCLK_DI()		(RCC->AHB1ENR &=~(1<<2))
#define GPIOD_PCLK_DI()		(RCC->AHB1ENR &=~(1<<3))
#define GPIOE_PCLK_DI()		(RCC->AHB1ENR &=~(1<<4))
#define GPIOF_PCLK_DI()		(RCC->AHB1ENR &=~(1<<5))
#define GPIOG_PCLK_DI()		(RCC->AHB1ENR &=~(1<<6))
#define GPIOH_PCLK_DI()		(RCC->AHB1ENR &=~(1<<7))


/*Clock Disable Macros for SPIx peripherals*/

/*Macros to reset GPIO peripherals*/
#define GPIOA_REG_RESET()	do{(RCC->AHB1RSTR |= (1<<0)); (RCC->AHB1RSTR &=~(1<<0));}while(0)
#define GPIOB_REG_RESET()	do{(RCC->AHB1RSTR |= (1<<1)); (RCC->AHB1RSTR &=~(1<<1));}while(0)
#define GPIOC_REG_RESET()	do{(RCC->AHB1RSTR |= (1<<2)); (RCC->AHB1RSTR &=~(1<<2));}while(0)
#define GPIOD_REG_RESET()	do{(RCC->AHB1RSTR |= (1<<3)); (RCC->AHB1RSTR &=~(1<<3));}while(0)
#define GPIOE_REG_RESET()	do{(RCC->AHB1RSTR |= (1<<4)); (RCC->AHB1RSTR &=~(1<<4));}while(0)
#define GPIOF_REG_RESET()	do{(RCC->AHB1RSTR |= (1<<5)); (RCC->AHB1RSTR &=~(1<<5));}while(0)
#define GPIOG_REG_RESET()	do{(RCC->AHB1RSTR |= (1<<6)); (RCC->AHB1RSTR &=~(1<<6));}while(0)
#define GPIOH_REG_RESET()	do{(RCC->AHB1RSTR |= (1<<7)); (RCC->AHB1RSTR &=~(1<<7));}while(0)

/*return port code for given GPIOx_base address*/
#define GPIO_BASEADDR_TO_CODE(x)  ( (x==GPIOA) ? 0:\
									(x==GPIOB) ? 1:\
									(x==GPIOC) ? 2:\
									(x==GPIOD) ? 3:\
									(x==GPIOE) ? 4:\
									(x==GPIOF) ? 5:\
									(x==GPIOG) ? 6:\
									(x==GPIOH) ? 7:0)



#endif /* MAIN_H_ */
