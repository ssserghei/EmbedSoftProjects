/*
 * stm32f446xx.h
 *
 *  Created on: Jul 18, 2022
 *      Author: Serghei
 */

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

/*base addresses of Flash and SRAM ,memories*/
#define FLASH_BASEADDR				0x08000000U				//3.3 Embedded Flash memory
#define SRAM1_BASEADDR				0x20000000U				//2.2.3 Embedded SRAM //Main internal SRAM1 (112 KB)
#define SRAM2_BASEADDR				0x2001C000U				//0x20000000U+1C000U //+112*1024=114688=1C000(h) Auxiliary internal SRAM2 (16 KB)
#define ROM_BASEADDR				0x1FFF0000U				//Table 4. Flash module organization // System memory	//30 Kbytes
#define SRAM						SRAM1_BASEADDR

/*AHBx and APBx Bus Peripheral base addresses*/
//Table 1. STM32F446xx register boundary addresses
#define PERIPH_BASEADDR			0x40000000U		//
#define APB1PERIPH_BASEADDR		PERIPH_BASEADDR	//
#define APB2PERIPH_BASEADDR		0x40010000U		//
#define AHB1PERIPH_BASEADDR		0x40020000U		//
#define AHB2PERIPH_BASEADDR		0x50000000U		//

/*Base addresses of peripherals which are hanging on AHB1 bus*/
#define GPIOA_BASEADDR 			(AHB1PERIPH_BASEADDR+0x0000)		//0x4002 0000 - 0x4002 03FF GPIOA
#define GPIOB_BASEADDR 			(AHB1PERIPH_BASEADDR+0x0400)		//0x4002 0400 - 0x4002 07FF GPIOB
#define GPIOC_BASEADDR 			(AHB1PERIPH_BASEADDR+0x0800)		//0x4002 0800 - 0x4002 0BFF GPIOC
#define GPIOD_BASEADDR 			(AHB1PERIPH_BASEADDR+0x0C00)		//0x4002 0C00 - 0x4002 0FFF GPIOD
#define GPIOE_BASEADDR 			(AHB1PERIPH_BASEADDR+0x1000)		//0x4002 1000 - 0x4002 13FF GPIOE
#define GPIOF_BASEADDR 			(AHB1PERIPH_BASEADDR+0x1400)		//0x4002 1400 - 0x4002 17FF GPIOF
#define GPIOG_BASEADDR 			(AHB1PERIPH_BASEADDR+0x1800)		//0x4002 1800 - 0x4002 1BFF GPIOG
#define GPIOH_BASEADDR 			(AHB1PERIPH_BASEADDR+0x1C00)		//0x4002 1C00 - 0x4002 1FFF GPIOH

/*Base addresses of peripherals which are hanging on APB1 bus*/
#define	I2C_BASEADDR			(AHB1PERIPH_BASEADDR+0x5400)		//0x4000 5400 - 0x4000 57FF I2C1
//
//
/*/
 *
 */


/*Base addresses of peripherals which are hanging on APB2 bus*/
#define EXTI_BASEADDR			(APB2PERIPH_BASEADDR+0x3C00)		//0x4001 3C00 - 0x4001 3FFF EXTI
//
//
//


/****************Peripheral Register Definition Structures********************/

/*Note: Register of a peripheral are specific to MCU
*e.g: Number of Register of SPI peripheral of STM32F4x family of MCUs may
*/





#endif /* INC_STM32F446XX_H_ */
