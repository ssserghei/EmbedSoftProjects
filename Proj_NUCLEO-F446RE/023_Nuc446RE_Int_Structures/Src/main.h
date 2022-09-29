/*
 * main.h
 *
 *  Created on: Sep 27, 2022
 *      Author: SergheiSGarage
 */

#ifndef MAIN_H_
#define MAIN_H_



/*This is a Configuration structure for a GPIO pin*/
typedef struct{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;			/*!< possible values from @GPIO_PIN_MODES >*/
	uint8_t GPIO_PinSpeed;			/*!< possible values from @GPIO_PIN_SPEED >*/
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;


typedef struct{	//7.4.11 GPIO register map
	RCC_AHB1ENR_t	RCC_AHB1ENR;
	GPIOx_MODER_t	GPIOx_MODER;
	GPIOx_ODR_t		GPIOx_ODR;
	GPIOx_IDR_t		GPIOx_IDR;
}GPIO_RegDef_t

/*This in a Handle structure for a GPIO pin*/
typedef struct{
	GPIO_RegDef_t *pGPIOx;       		/*!< This holds the base address of the GPIO port to which the pin belongs >*/
	GPIO_PinConfig_t GPIO_PinConfig;   /*!< This holds GPIO pin configuration settings >*/
}GPIO_Handle_t;




#define GPIOA		((GPIO_RegDef_t*)GPIOA_BASEADDR)	//
#define GPIOB		((GPIO_RegDef_t*)GPIOB_BASEADDR)	//
#define GPIOC		((GPIO_RegDef_t*)GPIOC_BASEADDR)	//
#define GPIOD		((GPIO_RegDef_t*)GPIOD_BASEADDR)	//
#define GPIOE		((GPIO_RegDef_t*)GPIOE_BASEADDR)	//
#define GPIOF		((GPIO_RegDef_t*)GPIOF_BASEADDR)	//
#define GPIOG		((GPIO_RegDef_t*)GPIOG_BASEADDR)	//
#define GPIOH		((GPIO_RegDef_t*)GPIOH_BASEADDR)


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
 * GPIO pin possible modes*/
#define GPIO_MODE_IN 		0
#define GPIO_MODE_OUT 		1
#define GPIO_MODE_ALTFN 	2
#define GPIO_MODE_ANALOG 	3
#define GPIO_MODE_IT_FT		4	//Fooling interrupt mode
#define GPIO_MODE_IT_RT		5	//Rising interrupt mode
#define GPIO_MODE_IT_RFT	6	//both interrupt mode


/******************************************************************************/
/******************************************************************************
 * CLOCK_EN
 * 6.3.10 RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
 * Address offset: 0x30
 *
 * */
//
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
	RCC_AHB1ENR_t volatile *pClkCtrlReg=(RCC_AHB1ENR_t*) (0x40023800+0x30);


/******************************************************************************
 * PORT_MODER	//GPIOx_MODER
 * 7.4.1 GPIO port mode register (GPIOx_MODER) (x = A..H)
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

	//pPortAModeReg->moder5=1;	//output
	//pPortAModeReg->moder5=0;	//input


/*******************************************************************************
//PORT_OUT	//GPIO_OUT
//7.4.6 GPIO port output data register (GPIOx_ODR) (x = A..H)
 * Address offset: 0x14
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
	GPIOx_ODR_t volatile *pPortFOutReg=(GPIOx_ODR_t*) (0x40021400+0x14);
	GPIOx_ODR_t volatile *pPortGOutReg=(GPIOx_ODR_t*) (0x40021800+0x14);
	GPIOx_ODR_t volatile *pPortHOutReg=(GPIOx_ODR_t*) (0x40021C00+0x14);

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
	GPIOx_IDR_t volatile *pPortFIntReg=(GPIOx_IDR_t*) (0x40021400+0x10);
	GPIOx_IDR_t volatile *pPortGIntReg=(GPIOx_IDR_t*) (0x40021800+0x10);
	GPIOx_IDR_t volatile *pPortHIntReg=(GPIOx_IDR_t*) (0x40021C00+0x10);


#endif /* MAIN_H_ */
