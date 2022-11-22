/*
 * main.h
 *
 *  Created on: Nov 16, 2022
 *      Author: Serghei
 */

#ifndef MAIN_H_
#define MAIN_H_

/*<TODO для чего ? */
#include <stdint.h>
#include <stddef.h>

/*******************Common Macros**********************/

/*<TODO для чего ? */
#define __vo volatile
#define __weak __attribute__((weak))

/*some generic macros*/
#define ENABLE			1
#define DISABLE			0
#define	SET				ENABLE
#define	RESET			DISABLE
#define GPIO_PIN_SET	SET
#define GPIO_PIN_RESET	RESET
#define FLAG_RESET      RESET
#define FLAG_SET 		SET


/*******************Reset and Clock Control (RCC) Base Address***********/

#define RCC_BASEADDR			(AHB1PERIPH_BASEADDR+0x3800)


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


/*AHBx and APBx Bus Peripheral base addresses*/
//Table 1. STM32F446xx register boundary addresses
#define PERIPH_BASEADDR			0x40000000U					/*Первый адрес начала APB1 //TIM2*/
#define APB1PERIPH_BASEADDR		PERIPH_BASEADDR				//
#define APB2PERIPH_BASEADDR		0x40010000U					/*TIM1*/
#define AHB1PERIPH_BASEADDR		0x40020000U					//
#define AHB2PERIPH_BASEADDR		0x50000000U					//


/*******************GPIO Base Address************************/

/*Base addresses of peripherals which are hanging on AHB1 bus*/
#define GPIOA_BASEADDR 			(AHB1PERIPH_BASEADDR+0x0000)		//0x4002 0000 - 0x4002 03FF GPIOA
#define GPIOB_BASEADDR 			(AHB1PERIPH_BASEADDR+0x0400)		//0x4002 0400 - 0x4002 07FF GPIOB
#define GPIOC_BASEADDR 			(AHB1PERIPH_BASEADDR+0x0800)		//0x4002 0800 - 0x4002 0BFF GPIOC
#define GPIOD_BASEADDR 			(AHB1PERIPH_BASEADDR+0x0C00)		//0x4002 0C00 - 0x4002 0FFF GPIOD
#define GPIOE_BASEADDR 			(AHB1PERIPH_BASEADDR+0x1000)		//0x4002 1000 - 0x4002 13FF GPIOE
#define GPIOF_BASEADDR 			(AHB1PERIPH_BASEADDR+0x1400)		//0x4002 1400 - 0x4002 17FF GPIOF
#define GPIOG_BASEADDR 			(AHB1PERIPH_BASEADDR+0x1800)		//0x4002 1800 - 0x4002 1BFF GPIOG
#define GPIOH_BASEADDR 			(AHB1PERIPH_BASEADDR+0x1C00)		//0x4002 1C00 - 0x4002 1FFF GPIOH


/*******************System Config Base Address*****************/

/*Base addresses of peripherals which are hanging on APB2 bus*/
#define EXTI_BASEADDR			(APB2PERIPH_BASEADDR+0x3C00)		//0x4001 3C00 - 0x4001 3FFF EXTI
//#define SPI1_BASEADDR			(APB2PERIPH_BASEADDR+0x3000)
#define SYSCFG_BASEADDR			(APB2PERIPH_BASEADDR+0x3800)
//#define USART1_BASEADDR		(APB2PERIPH_BASEADDR+0x1000)
//#define USART6_BASEADDR		(APB2PERIPH_BASEADDR+0x1400)

#define SYSCFG		((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

/**************************************************
 *					 GPIO Structures
 **************************************************/

/*Note: Register of a peripheral are specific to MCU
*e.g: Number of Register of SPI peripheral of STM32F4x family of MCUs may be different(more or less)
* Compared to number of registers of SPI peripheral of STM32Lx or STM32F0x family of MCUs
* Please check your Device RM*/

/*7.4.11 GPIO register map
 * 7.1 GPIO introduction*/
typedef struct{	//7.4.11 GPIO register map
	__vo uint32_t MODER;	/*!< GPIO port mode register,	Address offset: 0x00*/ //00: Input (reset state) 01: General purpose output mode 10: Alternate function mode 11: Analog mode
	__vo uint32_t OTYPER;	/*!< 0: Output push-pull (reset state) 	1: Output open-drain	Address offset: 0x04*/ //7.4.2 GPIO port output type register (GPIOx_OTYPER) (x = A..H)
	__vo uint32_t OSPEEDR;	/*!< Possible OSPEEDER							0x08*/
	__vo uint32_t PUPDR;	/*												0x0C*/
	__vo uint32_t IDR;		/*												0x10*/
	__vo uint32_t ODR;		/*												0x14*/
	__vo uint32_t BSRR;		/*												0x18*/
//	__vo uint32_t LCKR;		/*												0x1C*/
	__vo uint32_t AFR[2];	/*!< AFR[0] : GPIO alternate function low register, AF[1] : GPIO alternate function high register    		Address offset: 0x20-0x24 */
}GPIO_RegDef_t;				//

GPIO_RegDef_t volatile *GPIOA_RegDef=((GPIO_RegDef_t*)GPIOA_BASEADDR);
GPIO_RegDef_t volatile *GPIOC_RegDef=((GPIO_RegDef_t*)GPIOC_BASEADDR);

/*Вместо этого
 * GPIO_RegDef_t volatile *GPIOA_RegDef=((GPIO_RegDef_t*)GPIOA_BASEADDR);
 *можно использовать макрос предварительно инициировав его до использования
 *#define GPIOA		((GPIO_RegDef_t*)GPIOA_BASEADDR)	//
 *вот так
 *GPIO_RegDef_t volatile *GPIOA_RegDef=GPIOA;
 * */

/*************************GPIO Macros and Modes ****************************/

/*@GPIO_PIN_NUMBERS
 * GPIO pin numbers*/
#define GPIO_PIN_NO_0		0
#define GPIO_PIN_NO_1		1
#define GPIO_PIN_NO_2		2
#define GPIO_PIN_NO_3		3
#define GPIO_PIN_NO_4		4
#define GPIO_PIN_NO_5		5
#define GPIO_PIN_NO_6		6
#define GPIO_PIN_NO_7		7
#define GPIO_PIN_NO_8		8
#define GPIO_PIN_NO_9		9
#define GPIO_PIN_NO_10		10
#define GPIO_PIN_NO_11		11
#define GPIO_PIN_NO_12		12
#define GPIO_PIN_NO_13		13
#define GPIO_PIN_NO_14		14
#define GPIO_PIN_NO_15		15

/* @GPIO_PIN_MODES
 //7.4.1 GPIO port mode register (GPIOx_MODER) (x = A..H)
 * GPIO pin possible modes
 * Bits 2y:2y+1 MODERy[1:0]: Port x configuration bits (y = 0..15)
These bits are written by software to configure the I/O direction mode.
00: Input (reset state)
01: General purpose output mode
10: Alternate function mode
11: Analog mode*/
#define GPIO_MODE_IN 		0
#define GPIO_MODE_OUT 		1
#define GPIO_MODE_ALTFN 	2
#define GPIO_MODE_ANALOG 	3
//10.3.4 Falling trigger selection register (EXTI_FTSR)
#define GPIO_MODE_IT_FT		4	//Fooling interrupt mode
#define GPIO_MODE_IT_RT		5	//Rising interrupt mode
#define GPIO_MODE_IT_RFT	6	//both interrupt mode

/*GPIO pin possible output types*/
//7.4.2 GPIO port output type register (GPIOx_OTYPER) (x = A..H)
#define GPIO_OP_TYPE_PP		0	//push-pull
#define GPIO_OP_TYPE_OD		1	//open-drain

/*@GPIO_PIN_SPEED
 * GPIO pin possible output speeds*/
#define GPIO_SPEED_LOW			0
#define GPIO_SPEED_MEDIUM		1
#define GPIO_SPEED_FAST			2
#define GPOI_SPEED_HIGH			3

/*GPIO pin pull up and pull down configuration macros */
#define GPIO_NO_PUPD   		0
#define GPIO_PIN_PU			1
#define GPIO_PIN_PD			2

/*Clock Enable Macros for GPIOx peripherals*/
#define GPIOA_PCLK_EN()		(RCC->AHB1ENR |=(1<<0))
#define GPIOB_PCLK_EN()		(RCC->AHB1ENR |=(1<<1))
#define GPIOC_PCLK_EN()		(RCC->AHB1ENR |=(1<<2))
#define GPIOD_PCLK_EN()		(RCC->AHB1ENR |=(1<<3))
#define GPIOE_PCLK_EN()		(RCC->AHB1ENR |=(1<<4))
#define GPIOF_PCLK_EN()		(RCC->AHB1ENR |=(1<<5))
#define GPIOG_PCLK_EN()		(RCC->AHB1ENR |=(1<<6))
#define GPIOH_PCLK_EN()		(RCC->AHB1ENR |=(1<<7))

/*Clock Disable Macros for GPIOx peripherals*/
#define GPIOA_PCLK_DI()		(RCC->AHB1ENR &=~(1<<0))
#define GPIOB_PCLK_DI()		(RCC->AHB1ENR &=~(1<<1))
#define GPIOC_PCLK_DI()		(RCC->AHB1ENR &=~(1<<2))
#define GPIOD_PCLK_DI()		(RCC->AHB1ENR &=~(1<<3))
#define GPIOE_PCLK_DI()		(RCC->AHB1ENR &=~(1<<4))
#define GPIOF_PCLK_DI()		(RCC->AHB1ENR &=~(1<<5))
#define GPIOG_PCLK_DI()		(RCC->AHB1ENR &=~(1<<6))
#define GPIOH_PCLK_DI()		(RCC->AHB1ENR &=~(1<<7))


/*******************************************
 * 				Interrupt Structures
 * ****************************************/

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

EXTI_RegDef_t volatile *EXTI=((EXTI_RegDef_t*)EXTI_BASEADDR);


/*******************Interrupt Macros and Modes *******************/

/*IRQ(Interrupt Request) Number of STM32F407x MCU
 * Table 38. Vector table for STM32F446xx*/
#define IRQ_NO_EXTI0 		6
#define IRQ_NO_EXTI1 		7
#define IRQ_NO_EXTI2 		8
#define IRQ_NO_EXTI3 		9
#define IRQ_NO_EXTI4 		10
#define IRQ_NO_EXTI9_5 		23
#define IRQ_NO_EXTI15_10 	40

/*ARM Cortex Mx Processor Priority Register Address Calculation
 * The NVIC_IPR0-NVIC_IPR59 registers provide an 8-bit priority field for each interrupt and
each register holds four priority fields.*/
#define NVIC_PR_BASE_ADDR ((__vo uint32_t*)0xE000E400)	/*Interrupt Priority Registers on page 4-7*/

/*macros for all the possible priority levels*/
#define NVIC_IRQ_PRI0    0
#define NVIC_IRQ_PRI15    15



/***********************************************
 * 			SystemConfig SYSCFG Structure
 * *********************************************/

/*peripheral register definition structure for SYSCFG
 * 8.2.9 SYSCFG register maps
 * Table 27. SYSCFG register map and reset values*/
typedef struct{
	__vo uint32_t MEMRMP;		/*!<Give a short description, 						Adress ofset: 0x00*/
	__vo uint32_t PMC;			/*!<TODO, 											Adress ofset: 0x04*/
	__vo uint32_t EXTICR[4];	/*!<SYSCFG external interrupt configuration register	Adress ofset: 0x08-0x14*/
		 uint32_t RESERVED1[2];	/*!<TODO, 											Adress ofset: 0x18-0x1C*/
	__vo uint32_t CMCPCR;		/*!<TODO, 											Adress ofset: 0x20*/
	 	 uint32_t RESERVED2[2];	/*!<TODO, 											Adress ofset: 0x24-0x28*/
	__vo uint32_t CFGR;			/*!<TODO, 											Adress ofset: 0x2C*/
}SYSCFG_RegDef_t;



/***************************************************
 * 			Reset and Clock Control (RCC) Structure
 **************************************************/

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

RCC_RegDef_t volatile *RCC=((RCC_RegDef_t*)RCC_BASEADDR);


/********************Reset and Clock Control (RCC) Macros and Modes*********************/

/*Clock Enable Macros for SYSCFG peripherals*/
#define SYSCFG_PCLK_EN() (RCC->APB2ENR |= (1 << 14))



/**************************************************************************
 * 						APIs supported by this driver
 * 		For more information about the APIs check the function definitions
 **************************************************************************/

void GPIO_ToggleOutPin(GPIO_RegDef_t volatile *GPIOx_RegDef, uint8_t PinNumber);					//

void GPIO_IRQHandling(uint8_t PinNumber);

void delay(void){
	// this will introduce ~200ms delay when system clock is 16MHz
	for(uint32_t i = 0 ; i < 50000 ; i ++);
}


#endif /* MAIN_H_ */