/*
 * stm32f446xx.h
 *
 *  Created on: Jul 18, 2022
 *      Author: Serghei
 *  D:\YandexDisk\Carti si reviste periodice\Микроконтроллеры\STM32\Dev Boards\NUCLEO-F446RE_STM32F446RET6\MCU STM32F446RE\DUI0553.pdf
 *  D:\YandexDisk\Carti si reviste periodice\Микроконтроллеры\STM32\Dev Boards\NUCLEO-F446RE_STM32F446RET6\MCU STM32F446RE\
erence manual RM0390 STM32F446xx.pdf
 */
#include <stdint.h>
#include <stddef.h>


#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_
#define __vo volatile
#define __weak __attribute__((weak))



/****************************** START: Processor Specific Details******************************/

/*ARM Cortex Mx Processor NVIC ISERx register Addresses
 * DUI0553
 * Table 4-2 NVIC register summary
 * The NVIC_ISER0-NVIC_ISER7 registers enable interrupts, and show which interrupts are
enabled.*/
#define NVIC_ISER0		((__vo uint32_t*)0xE000E100)	/*!< Interrupt Set-enable Registers on page 4-4*/
#define NVIC_ISER1		((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2		((__vo uint32_t*)0xE000E108)	/*!<*/
#define NVIC_ISER3		((__vo uint32_t*)0xE000E10C)	/*!<*/

/*ARM Cortex Mx Processor NVIC ICERx register Addresses
 *The NVIC_ICER0-NVIC_ICER7 registers disable interrupts, and show which interrupts are
enabled.*/
#define NVIC_ICER0		((__vo uint32_t*)0xE000E180)	/*!< Interrupt Clear-enable Registers on page 4-5*/
#define NVIC_ICER1		((__vo uint32_t*)0xE000E184)
#define NVIC_ICER2		((__vo uint32_t*)0xE000E188)
#define NVIC_ICER3		((__vo uint32_t*)0xE000E18C)

/*ARM Cortex Mx Processor Priority Register Address Calculation
 * The NVIC_IPR0-NVIC_IPR59 registers provide an 8-bit priority field for each interrupt and
each register holds four priority fields.*/
#define NVIC_PR_BASE_ADDR ((__vo uint32_t*)0xE000E400)	/*Interrupt Priority Registers on page 4-7*/

/*ARM Cortex Mx Processor number of priority bits implemented in Priority Register
 * */
#define NO_PR_BITS_IMPLEMENTED		4					/*Interrupt Priority Registers on page 4-7*/

/*base addresses of Flash and SRAM ,memories*/
#define FLASH_BASEADDR				0x08000000U				/*3.3 Embedded Flash memory*/
#define SRAM1_BASEADDR				0x20000000U				/*2.2.3 Embedded SRAM //Main internal SRAM1 (112 KB)*/
#define SRAM2_BASEADDR				0x2001C000U				/*0x20000000U+1C000U //+112*1024=114688=1C000(h) Auxiliary internal SRAM2 (16 KB)*/
#define ROM_BASEADDR				0x1FFF0000U				/*Table 4. Flash module organization // System memory	//30 Kbytes*/
#define SRAM						SRAM1_BASEADDR

/*AHBx and APBx Bus Peripheral base addresses*/
//Table 1. STM32F446xx register boundary addresses
#define PERIPH_BASEADDR			0x40000000U					/*Первый адрес начала APB1 //TIM2*/
#define APB1PERIPH_BASEADDR		PERIPH_BASEADDR				//
#define APB2PERIPH_BASEADDR		0x40010000U					/*TIM1*/
#define AHB1PERIPH_BASEADDR		0x40020000U					//
#define AHB2PERIPH_BASEADDR		0x50000000U					//

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

/*Base addresses of peripherals which are hanging on APB1 bus
 * Table 1. STM32F446xx register boundary addresses (continued)*/
#define	I2C1_BASEADDR			(AHB1PERIPH_BASEADDR+0x5400)		//0x4000 5400 - 0x4000 57FF I2C1
#define I2C2_BASEADDR			(APB1PERIPH_BASEADDR+0x5800)
#define I2C3_BASEADDR			(APB1PERIPH_BASEADDR+0x5C00)

#define SPI2_BASEADDR			(APB1PERIPH_BASEADDR+0x3800)		/*SPI2 / I2S2*/
#define SPI3_BASEADDR			(APB1PERIPH_BASEADDR+0x3C00)		/*SPI3 / I2S3*/

#define USART2_BASEADDR			(APB1PERIPH_BASEADDR+0x4400)
#define USART3_BASEADDR			(APB1PERIPH_BASEADDR+0x4800)
#define UART4_BASEADDR			(APB1PERIPH_BASEADDR+0x4C00)
#define UART5_BASEADDR			(APB1PERIPH_BASEADDR+0x5000)


/*Base addresses of peripherals which are hanging on APB2 bus*/
#define EXTI_BASEADDR			(APB2PERIPH_BASEADDR+0x3C00)		//0x4001 3C00 - 0x4001 3FFF EXTI
#define SPI1_BASEADDR			(APB2PERIPH_BASEADDR+0x3000)
#define SPI4_BASEADDR			(APB2PERIPH_BASEADDR+0x3400)		/*SPI4*/
#define SYSCFG_BASEADDR			(APB2PERIPH_BASEADDR+0x3800)
#define USART1_BASEADDR			(APB2PERIPH_BASEADDR+0x1000)
#define USART6_BASEADDR			(APB2PERIPH_BASEADDR+0x1400)



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
	__vo uint32_t PLLCFGR;      /*!< TODO,     						Address offset: 0x04 */
	__vo uint32_t CFGR;         /*!< TODO,     						Address offset: 0x08 */
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

/*peripheral definition structure for EXTI
 * 10.3.5 Software interrupt event register (EXTI_SWIER)
 * 10.3.7 EXTI register map*/
typedef struct{
	__vo uint32_t IMR; 				/*!<10.3.1 Interrupt mask register (EXTI_IMR)				//Address offset: 0x00*/
	__vo uint32_t EMR; 				/*!<10.3.2 Event mask register (EXTI_EMR),   				//Address offset: 0x04*/
	__vo uint32_t RTSR; 			/*!<10.3.3 Rising trigger selection register (EXTI_RTSR),  	//Address offset: 0x08*/
	__vo uint32_t FTSR; 			/*!<10.3.4 Falling trigger selection register (EXTI_FTSR), 	//Address offset: 0x0C*/
	__vo uint32_t SWIER; 			/*!<10.3.5 Software interrupt event register (EXTI_SWIER), 	//Address offset: 0x10*/
	__vo uint32_t PR; 				/*!<10.3.6 Pending register (EXTI_PR),  					//Address offset: 0x14*/
}EXTI_RegDef_t;

/*peripheral register definition structure for SPI
 * 26.7.10 SPI register map
 * */
typedef struct{
	__vo uint32_t CR1;        /*!< 26.7.1 SPI control register 1 (SPI_CR1) (not used in I2S mode),     										Address offset: 0x00 */
	__vo uint32_t CR2;        /*!< TODO,     										Address offset: 0x04 */
	__vo uint32_t SR;         /*!< TODO,     										Address offset: 0x08 */
	__vo uint32_t DR;         /*!< TODO,     										Address offset: 0x0C */
	__vo uint32_t CRCPR;      /*!< TODO,     										Address offset: 0x10 */
	__vo uint32_t RXCRCR;     /*!< TODO,     										Address offset: 0x14 */
	__vo uint32_t TXCRCR;     /*!< TODO,     										Address offset: 0x18 */
	__vo uint32_t I2SCFGR;    /*!< TODO,     										Address offset: 0x1C */
	__vo uint32_t I2SPR;      /*!< TODO,     										Address offset: 0x20 */
} SPI_RegDef_t;

/*peripheral register definition structure for SYSCFG
 * 8.2.9 SYSCFG register maps
 * Table 27. SYSCFG register map and reset values*/
typedef struct{
	__vo uint32_t MEMRMP;		/*!<Give a short description, 						Adress ofset: 0x00*/
	__vo uint32_t PMC;			/*!<TODO, 											Adress ofset: 0x04*/
	__vo uint32_t EXTICR[4];	/*!<SYSCFG external interrupt configuration registerAdress ofset: 0x08-0x14*/
		 uint32_t RESERVED1[2];	/*!<TODO, 											Adress ofset: 0x18-0x1C*/
	__vo uint32_t CMCPCR;		/*!<TODO, 											Adress ofset: 0x20*/
	 	 uint32_t RESERVED2[2];	/*!<TODO, 											Adress ofset: 0x24-0x28*/
	__vo uint32_t CFGR;			/*!<TODO, 											Adress ofset: 0x2C*/
}SYSCFG_RegDef_t;


/*peripheral register definition structure for I2C
 * 24.6.11 I2C register map*/
typedef struct{
  __vo uint32_t CR1;        /*!< 24.6.1 I2C Control register 1 (I2C_CR1)  					Address offset: 0x00 */
  __vo uint32_t CR2;        /*!< 24.6.2 I2C Control register 2 (I2C_CR2)    				Address offset: 0x04 */
  __vo uint32_t OAR1;       /*!< 24.6.3 I2C Own address register 1 (I2C_OAR1)    			Address offset: 0x08 */
  __vo uint32_t OAR2;       /*!< 24.6.4 I2C Own address register 2 (I2C_OAR2)     			Address offset: 0x0C */
  __vo uint32_t DR;         /*!< 24.6.5 I2C Data register (I2C_DR)    						Address offset: 0x10 */
  __vo uint32_t SR1;        /*!< 24.6.6 I2C Status register 1 (I2C_SR1)    					Address offset: 0x14 */
  __vo uint32_t SR2;        /*!< 24.6.7 I2C Status register 2 (I2C_SR2)     				Address offset: 0x18 */
  __vo uint32_t CCR;        /*!< 24.6.8 I2C Clock control register (I2C_CCR)     			Address offset: 0x1C */
  __vo uint32_t TRISE;      /*!< 24.6.9 I2C TRISE register (I2C_TRISE)     					Address offset: 0x20 */
  __vo uint32_t FLTR;       /*!< 24.6.10 I2C FLTR register (I2C_FLTR)     					Address offset: 0x24 */
}I2C_RegDef_t;

/*
 * peripheral register definition structure for USART
 * 25.6.8 USART register map*/
typedef struct{
	__vo uint32_t SR;         /*!< TODO,     						Address offset: 0x00 */
	__vo uint32_t DR;         /*!< TODO,     						Address offset: 0x04 */
	__vo uint32_t BRR;        /*!< TODO,     						Address offset: 0x08 */
	__vo uint32_t CR1;        /*!< TODO,     						Address offset: 0x0C */
	__vo uint32_t CR2;        /*!< TODO,     						Address offset: 0x10 */
	__vo uint32_t CR3;        /*!< TODO,     						Address offset: 0x14 */
	__vo uint32_t GTPR;       /*!< TODO,     						Address offset: 0x18 */
} USART_RegDef_t;


/**********************peripheral definition**********************/

/*(Peripheral base addresses typecasted to xxx_RegDef_t)
 * */
#define GPIOA		((GPIO_RegDef_t*)GPIOA_BASEADDR)	//
#define GPIOB		((GPIO_RegDef_t*)GPIOB_BASEADDR)	//
#define GPIOC		((GPIO_RegDef_t*)GPIOC_BASEADDR)	//
#define GPIOD		((GPIO_RegDef_t*)GPIOD_BASEADDR)	//
#define GPIOE		((GPIO_RegDef_t*)GPIOE_BASEADDR)	//
#define GPIOF		((GPIO_RegDef_t*)GPIOF_BASEADDR)	//
#define GPIOG		((GPIO_RegDef_t*)GPIOG_BASEADDR)	//
#define GPIOH		((GPIO_RegDef_t*)GPIOH_BASEADDR)	//

#define RCC			((RCC_RegDef_t*)RCC_BASEADDR)		//Table 21. RCC register map and reset values

#define EXTI		((EXTI_RegDef_t*)EXTI_BASEADDR)

#define SYSCFG		((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

#define SPI1  		((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2  		((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3  		((SPI_RegDef_t*)SPI3_BASEADDR)
#define SPI4  		((SPI_RegDef_t*)SPI4_BASEADDR)

#define I2C1  		((I2C_RegDef_t*)I2C1_BASEADDR)
#define I2C2  		((I2C_RegDef_t*)I2C2_BASEADDR)
#define I2C3  		((I2C_RegDef_t*)I2C3_BASEADDR)

#define USART1  	((USART_RegDef_t*)USART1_BASEADDR)
#define USART2  	((USART_RegDef_t*)USART2_BASEADDR)
#define USART3  	((USART_RegDef_t*)USART3_BASEADDR)
#define UART4  		((USART_RegDef_t*)UART4_BASEADDR)
#define UART5  		((USART_RegDef_t*)UART5_BASEADDR)
#define USART6  	((USART_RegDef_t*)USART6_BASEADDR)


/*************************************Clock Enable Macros*******************************************/

/*Clock Enable Macros for GPIOx peripherals*/
#define GPIOA_PCLK_EN()		(RCC->AHB1ENR |=(1<<0))
#define GPIOB_PCLK_EN()		(RCC->AHB1ENR |=(1<<1))
#define GPIOC_PCLK_EN()		(RCC->AHB1ENR |=(1<<2))
#define GPIOD_PCLK_EN()		(RCC->AHB1ENR |=(1<<3))
#define GPIOE_PCLK_EN()		(RCC->AHB1ENR |=(1<<4))
#define GPIOF_PCLK_EN()		(RCC->AHB1ENR |=(1<<5))
#define GPIOG_PCLK_EN()		(RCC->AHB1ENR |=(1<<6))
#define GPIOH_PCLK_EN()		(RCC->AHB1ENR |=(1<<7))

/*Clock Enable Macros for I2Cx peripherals
 * 6.3.13 RCC APB1 peripheral clock enable register (RCC_APB1ENR)*/
#define I2C1_PCLK_EN() (RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN() (RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN() (RCC->APB1ENR |= (1 << 23))

/*Clock Enable Macros for SPIx peripherals
 * 6.3.13 RCC APB1 peripheral clock enable register (RCC_APB1ENR)
 * 6.3.14 RCC APB2 peripheral clock enable register (RCC_APB2ENR)*/
#define SPI1_PCLK_EN()		(RCC->APB2ENR |=(1<<12))
#define SPI2_PCLK_EN()		(RCC->APB1ENR |=(1<<14))
#define SPI3_PCLK_EN()		(RCC->APB1ENR |=(1<<15))
#define SPI4_PCLK_EN()		(RCC->APB2ENR |=(1<<13))

#define I2C1_PCLK_EN() (RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN() (RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN() (RCC->APB1ENR |= (1 << 23))

/*Clock Enable Macros for USARTx peripherals*/
#define USART1_PCCK_EN() (RCC->APB2ENR |= (1 << 4))
#define USART2_PCCK_EN() (RCC->APB1ENR |= (1 << 17))
#define USART3_PCCK_EN() (RCC->APB1ENR |= (1 << 18))
#define UART4_PCCK_EN()  (RCC->APB1ENR |= (1 << 19))
#define UART5_PCCK_EN()  (RCC->APB1ENR |= (1 << 20))
#define USART6_PCCK_EN() (RCC->APB1ENR |= (1 << 5))

/*Clock Enable Macros for SYSCFG peripherals*/
#define SYSCFG_PCLK_EN() (RCC->APB2ENR |= (1 << 14))

/***************************************************/


/*Clock Disable Macros for I2Cx peripherals*/
#define I2C1_PCLK_EN() (RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN() (RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN() (RCC->APB1ENR |= (1 << 23))

/*
 * Clock Enable Macros for SPIx peripheralsbu
 */
#define SPI1_PCLK_EN() (RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN() (RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN() (RCC->APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN() (RCC->APB2ENR |= (1 << 13))

/*
 * Clock Enable Macros for USARTx peripherals
 */
#define USART1_PCCK_EN() (RCC->APB2ENR |= (1 << 4))
#define USART2_PCCK_EN() (RCC->APB1ENR |= (1 << 17))
#define USART3_PCCK_EN() (RCC->APB1ENR |= (1 << 18))
#define UART4_PCCK_EN()  (RCC->APB1ENR |= (1 << 19))
#define UART5_PCCK_EN()  (RCC->APB1ENR |= (1 << 20))
#define USART6_PCCK_EN() (RCC->APB1ENR |= (1 << 5))


/*
 * Clock Enable Macros for SYSCFG peripheral
 */
#define SYSCFG_PCLK_EN() (RCC->APB2ENR |= (1 << 14))


/*Clock Disable Macros for GPIOx peripherals*/
#define GPIOA_PCLK_DI()		(RCC->AHB1ENR &=~(1<<0))
#define GPIOB_PCLK_DI()		(RCC->AHB1ENR &=~(1<<1))
#define GPIOC_PCLK_DI()		(RCC->AHB1ENR &=~(1<<2))
#define GPIOD_PCLK_DI()		(RCC->AHB1ENR &=~(1<<3))
#define GPIOE_PCLK_DI()		(RCC->AHB1ENR &=~(1<<4))
#define GPIOF_PCLK_DI()		(RCC->AHB1ENR &=~(1<<5))
#define GPIOG_PCLK_DI()		(RCC->AHB1ENR &=~(1<<6))
#define GPIOH_PCLK_DI()		(RCC->AHB1ENR &=~(1<<7))

/*
 * Clock Disable Macros for SPIx peripherals
 */

/*
 * Clock Disable Macros for USARTx peripherals
 */


/*
 * Clock Disable Macros for SYSCFG peripheral
 */



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

/*IRQ(Interrupt Request) Number of STM32F407x MCU
 * Table 38. Vector table for STM32F446xx*/
#define IRQ_NO_EXTI0 		6
#define IRQ_NO_EXTI1 		7
#define IRQ_NO_EXTI2 		8
#define IRQ_NO_EXTI3 		9
#define IRQ_NO_EXTI4 		10
#define IRQ_NO_EXTI9_5 		23
#define IRQ_NO_EXTI15_10 	40

#define IRQ_NO_SPI1			35
#define IRQ_NO_SPI2         36
#define IRQ_NO_SPI3         51
#define IRQ_NO_SPI4
#define IRQ_NO_I2C1_EV     31
#define IRQ_NO_I2C1_ER     32
#define IRQ_NO_USART1	    37
#define IRQ_NO_USART2	    38
#define IRQ_NO_USART3	    39
#define IRQ_NO_UART4	    52
#define IRQ_NO_UART5	    53
#define IRQ_NO_USART6	    71

/*macros for all the possible priority levels*/
#define NVIC_IRQ_PRI0    0
#define NVIC_IRQ_PRI15    15

/*some generic macros*/
#define ENABLE			1
#define DISABLE			0
#define	SET				ENABLE
#define	RESET			DISABLE
#define GPIO_PIN_SET	SET
#define GPIO_PIN_RESET	RESET
#define FLAG_RESET      RESET
#define FLAG_SET 		SET

/******************************************************************
 * 						Bit position definition of SPI peripheral
 * ****************************************************************/
//используются для сдвигов в фукции void SPI_Init(SPI_Handle_t *pSPIHandle)
//26.7.1 SPI control register 1 (SPI_CR1) (not used in I2S mode)
#define SPI_CR1_CPHA		0
#define SPI_CR1_CPOL		1
#define SPI_CR1_MSTR		2
#define SPI_CR1_BR			3
#define SPI_CR1_SPE			6
#define SPI_CR1_LSB			7
#define SPI_CR1_SSI			8
#define SPI_CR1_SSM			9		//SSM: Software slave management When the SSM bit is set, the NSS pin input is replaced with the value from the SSI bit.
#define SPI_CR1_RXONLY		10
#define SPI_CR1_DFF			11
#define SPI_CR1_CRCNEXT		12
#define SPI_CR1_CRCEN		13
#define SPI_CR1_BIDIOE		14
#define SPI_CR1_BIDIMODE	15

//SPI control register 2 (SPI_CR2)
#define SPI_CR2_RXDMAEN		0
#define SPI_CR2_TXDMAEN		1
#define SPI_CR2_SSOE		2
#define SPI_CR2_FRF			4
#define SPI_CR2_ERRIE		5
#define SPI_CR2_RXNEIE		6
#define SPI_CR2_TXEIE		7

//26.7.3 SPI status register (SPI_SR)
#define SPI_SR_RXNE			0
#define SPI_SR_TXE			1
#define SPI_SR_CHSIDE		2
#define SPI_SR_UDR			3
#define SPI_SR_CRC_ERR		4
#define SPI_SR_MODF			5
#define SPI_SR_OVR			6
#define SPI_SR_BSY			7
#define SPI_SR_FRE			8

/******************************************************************************************
 *Bit position definitions of I2C peripheral
 ******************************************************************************************/
/*
 * Bit position definitions I2C_CR1
 */
#define I2C_CR1_PE						0		//Bit 0 PE: Peripheral enable	0: Peripheral disable 1: Peripheral enable
#define I2C_CR1_NOSTRETCH  				7		//Bit 7 NOSTRETCH: Clock stretching disable (Slave mode)	0: Clock stretching enabled	1: Clock stretching disabled
#define I2C_CR1_START 					8		//Bit 8 START: Start generation	0: No Start generation	1: Repeated start generation
#define I2C_CR1_STOP  				 	9		//Bit 9 STOP: Stop generation	0: No Stop generation.	1: Stop generation after the current byte transfer or after the current Start condition is sent.
#define I2C_CR1_ACK 				 	10		//Bit 10 ACK: Acknowledge enable
#define I2C_CR1_SWRST  				 	15		//Bit 15 SWRST: Software reset

/*
 * Bit position definitions I2C_CR2
 */
#define I2C_CR2_FREQ				 	0
#define I2C_CR2_ITERREN				 	8
#define I2C_CR2_ITEVTEN				 	9
#define I2C_CR2_ITBUFEN 			    10

/*
 * Bit position definitions I2C_OAR1
 */
#define I2C_OAR1_ADD0    				 0
#define I2C_OAR1_ADD71 				 	 1
#define I2C_OAR1_ADD98  			 	 8
#define I2C_OAR1_ADDMODE   			 	15

/*
 * Bit position definitions I2C_SR1
 */

#define I2C_SR1_SB 					 	0
#define I2C_SR1_ADDR 				 	1
#define I2C_SR1_BTF 					2
#define I2C_SR1_ADD10 					3
#define I2C_SR1_STOPF 					4
#define I2C_SR1_RXNE 					6
#define I2C_SR1_TXE 					7
#define I2C_SR1_BERR 					8
#define I2C_SR1_ARLO 					9
#define I2C_SR1_AF 					 	10
#define I2C_SR1_OVR 					11
#define I2C_SR1_TIMEOUT 				14

/*
 * Bit position definitions I2C_SR2
 */
#define I2C_SR2_MSL						0
#define I2C_SR2_BUSY 					1
#define I2C_SR2_TRA 					2
#define I2C_SR2_GENCALL 				4
#define I2C_SR2_DUALF 					7

/*
 * Bit position definitions I2C_CCR
 */
#define I2C_CCR_CCR 					 0
#define I2C_CCR_DUTY 					14
#define I2C_CCR_FS  				 	15


/******************************************************************************************
 *Bit position definitions of USART peripheral
 ******************************************************************************************/

/*Bit position definitions USART_CR1*/
#define USART_CR1_SBK					0
#define USART_CR1_RWU 					1
#define USART_CR1_RE  					2
#define USART_CR1_TE 					3
#define USART_CR1_IDLEIE 				4
#define USART_CR1_RXNEIE  				5
#define USART_CR1_TCIE					6
#define USART_CR1_TXEIE					7
#define USART_CR1_PEIE 					8
#define USART_CR1_PS 					9
#define USART_CR1_PCE 					10
#define USART_CR1_WAKE  				11
#define USART_CR1_M 					12
#define USART_CR1_UE 					13
#define USART_CR1_OVER8  				15

/*Bit position definitions USART_CR2*/
#define USART_CR2_ADD   				0
#define USART_CR2_LBDL   				5
#define USART_CR2_LBDIE  				6
#define USART_CR2_LBCL   				8
#define USART_CR2_CPHA   				9
#define USART_CR2_CPOL   				10
#define USART_CR2_STOP   				12
#define USART_CR2_LINEN   				14


/*
 * Bit position definitions USART_CR3
 */
#define USART_CR3_EIE   				0
#define USART_CR3_IREN   				1
#define USART_CR3_IRLP  				2
#define USART_CR3_HDSEL   				3
#define USART_CR3_NACK   				4
#define USART_CR3_SCEN   				5
#define USART_CR3_DMAR  				6
#define USART_CR3_DMAT   				7
#define USART_CR3_RTSE   				8
#define USART_CR3_CTSE   				9
#define USART_CR3_CTSIE   				10
#define USART_CR3_ONEBIT   				11

/*
 * Bit position definitions USART_SR
 */

#define USART_SR_PE        				0
#define USART_SR_FE        				1
#define USART_SR_NE        				2
#define USART_SR_ORE       				3
#define USART_SR_IDLE       			4
#define USART_SR_RXNE        			5
#define USART_SR_TC        				6
#define USART_SR_TXE        			7
#define USART_SR_LBD        			8
#define USART_SR_CTS        			9


#include "stm32f446xx_gpio_driver.h"
#include "stm32f446xx_spi_driver.h"
#include "stm32f446xx_i2c_driver.h"
//#include "stm32f446xx_usart_driver.h"
//#include "stm32f446xx_rcc_driver.h"

#endif /* INC_STM32F446XX_H_ */
