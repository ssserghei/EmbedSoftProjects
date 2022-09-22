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

/*Base addresses of peripherals which are hanging on APB1 bus*/
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

/*peripheral definition structure for EXTI
 * 10.3.5 Software interrupt event register (EXTI_SWIER)
 * 10.3.7 EXTI register map*/
typedef struct{
	__vo uint32_t IMR; 				/*!<10.3.1 Interrupt mask register (EXTI_IMR),  Address offset: 0x00*/
	__vo uint32_t EMR; 				/*!<10.3.2 Event mask register (EXTI_EMR),  Address offset: 0x04*/
	__vo uint32_t RTSR; 			/*!<10.3.3 Rising trigger selection register (EXTI_RTSR),  Address offset: 0x08*/
	__vo uint32_t FTSR; 			/*!<10.3.4 Falling trigger selection register (EXTI_FTSR),  Address offset: 0x0C*/
	__vo uint32_t SWIER; 			/*!<10.3.5 Software interrupt event register (EXTI_SWIER),  Address offset: 0x10*/
	__vo uint32_t PR; 				/*!<10.3.6 Pending register (EXTI_PR),  Address offset: 0x14*/
}EXTI_RegDef_t;

/*peripheral register definition structure for SPI
 * 26.7.10 SPI register map
 * */
typedef struct{
	__vo uint32_t CR1;        /*!< TODO,     										Address offset: 0x00 */
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
 * 8.2.9 SYSCFG register maps*/
typedef struct{
	__vo uint32_t MEMRMP;		/*!<Give a short description, 		Adress ofset: 0x00*/
	__vo uint32_t PMC;			/*!<TODO, 							Adress ofset: 0x04*/
	__vo uint32_t EXTICR[4];	/*!<TODO, 							Adress ofset: 0x08-0x14*/
		 uint32_t RESERVED1[2];	/*!<TODO, 							Adress ofset: 0x18-0x1C*/
	__vo uint32_t CMCPCR;		/*!<TODO, 							Adress ofset: 0x20*/
	 	 uint32_t RESERVED2[2];	/*!<TODO, 							Adress ofset: 0x24-0x28*/
	__vo uint32_t CFGR;			/*!<TODO, 							Adress ofset: 0x2C*/
}SYSCFG_RegDef_t;


/*peripheral register definition structure for I2C
 * 24.6.11 I2C register map*/
typedef struct{
  __vo uint32_t CR1;        /*!< TODO,     							Address offset: 0x00 */
  __vo uint32_t CR2;        /*!< TODO,     							Address offset: 0x04 */
  __vo uint32_t OAR1;       /*!< TODO,     							Address offset: 0x08 */
  __vo uint32_t OAR2;       /*!< TODO,     							Address offset: 0x0C */
  __vo uint32_t DR;         /*!< TODO,     							Address offset: 0x10 */
  __vo uint32_t SR1;        /*!< TODO,     							Address offset: 0x14 */
  __vo uint32_t SR2;        /*!< TODO,     							Address offset: 0x18 */
  __vo uint32_t CCR;        /*!< TODO,     							Address offset: 0x1C */
  __vo uint32_t TRISE;      /*!< TODO,     							Address offset: 0x20 */
  __vo uint32_t FLTR;       /*!< TODO,     							Address offset: 0x24 */
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

#define RCC			((RCC_RegDef_t*)RCC_BASEADDR)

#define EXTI		((EXTI_RegDef_t*)EXTI_BASEADDR)

#define SYSCFG		((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

#define SPI1  		((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2  		((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3  		((SPI_RegDef_t*)SPI3_BASEADDR)

#define I2C1  		((I2C_RegDef_t*)I2C1_BASEADDR)
#define I2C2  		((I2C_RegDef_t*)I2C2_BASEADDR)
#define I2C3  		((I2C_RegDef_t*)I2C3_BASEADDR)

#define USART1  	((USART_RegDef_t*)USART1_BASEADDR)
#define USART2  	((USART_RegDef_t*)USART2_BASEADDR)
#define USART3  	((USART_RegDef_t*)USART3_BASEADDR)
#define UART4  		((USART_RegDef_t*)UART4_BASEADDR)
#define UART5  		((USART_RegDef_t*)UART5_BASEADDR)
#define USART6  	((USART_RegDef_t*)USART6_BASEADDR)

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
 * 6.3.14 RCC APB2 peripheral clock enable register (RCC_APB2ENR)*/
#define SPI1_PCLK_EN()		(RCC->APB2ENR |=(1<<12))
//#define I2C1_PCLK_EN() (RCC->APB1ENR |= (1 << 21))
//#define I2C2_PCLK_EN() (RCC->APB1ENR |= (1 << 22))
//#define I2C3_PCLK_EN() (RCC->APB1ENR |= (1 << 23))

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
/*Clock Disable Macros for GPIOx peripherals*/
#define GPIOA_PCLK_DI()		(RCC->AHB1ENR &=~(1<<0))
#define GPIOB_PCLK_DI()		(RCC->AHB1ENR &=~(1<<1))
#define GPIOC_PCLK_DI()		(RCC->AHB1ENR &=~(1<<2))
#define GPIOD_PCLK_DI()		(RCC->AHB1ENR &=~(1<<3))
#define GPIOE_PCLK_DI()		(RCC->AHB1ENR &=~(1<<4))
#define GPIOF_PCLK_DI()		(RCC->AHB1ENR &=~(1<<5))
#define GPIOG_PCLK_DI()		(RCC->AHB1ENR &=~(1<<6))
#define GPIOH_PCLK_DI()		(RCC->AHB1ENR &=~(1<<7))

/*Clock Disable Macros for I2Cx peripherals*/
#define I2C1_PCLK_EN() (RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN() (RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN() (RCC->APB1ENR |= (1 << 23))

/*Clock Disable Macros for SYSCFG peripherals*/
//#define SYSCFG_PCLK_EN() (RCC->APB2ENR) |=(1<<14))

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

/*IRQ(Interrupt Request) Number of STM32F407x MCU*/
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

#endif /* INC_STM32F446XX_H_ */
