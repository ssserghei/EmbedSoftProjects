/***********************************************
 * Это проект Лед блинка БЕЗ отладки!!
 * Добавлена функция включения/выключения ВСЕХ пинов
 * пины отмеченные * не реагируют.
 */

/*Proiectul este realizat pe cablajul BluePill (MCU stm32f103c8t6)
 * In acest proiect voi seta in 1 toate pinurile MCU*/
/**Documentation Home page
https://www.st.com/en/microcontrollers-microprocessors/stm32f103c8.html
 **Datasheet
https://www.st.com/resource/en/datasheet/stm32f103c8.pdf
 **Reference manual RM0008
https://www.st.com/resource/en/reference_manual/cd00171190-stm32f101xx-stm32f102xx-stm32f103xx-stm32f105xx-and-stm32f107xx-advanced-armbased-32bit-mcus-stmicroelectronics.pdf
 Programming manual. Cortex®-M3 programming manual
https://www.st.com/resource/en/programming_manual/cd00228163-stm32f10xxx20xxx21xxxl1xxxx-cortexm3-programming-manual-stmicroelectronics.pdf
Programming manual. Flash memory microcontrollers STM32F10xxx PM0075
 * */

/*BluePill pinout
 *
 * PC13		PB9
 * PC14		PB8
 * PC15		PB7
 * PA0		PB6
 * PA1		PB5
 * PA2		PB4
 * PA3		PB3
 * PA4		PA15
 * PA5		PA12
 * PA6		PA11
 * PA7		PA10
 * PB0		PA9
 * PB1		PA8
 * PB10		PB15
 * PB11		PB14
 * 			PB13
 * 			PB12
 **/

//PA1;PA2;PA3;PA4;PA5;PA6;PA7;PA8;PA9;PA10;PA11;PA12;		PA15.
//PB1;	PB3;PB4;PB5;PB6;PB7;PB8;PB9;PB10;PB11;PB12;PB13;PB14;PB15.
//PC13;PC14;PC15

#include <stdint.h>
#include <stdio.h>
extern void initialise_monitor_handles(void);

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
/*Base addresses
 Table 3. Register boundary addresses (continued)
AHB
	0x4002 1000 - 0x4002 13FF Reset and clock control RCC
APB2
	0x4001 2000 - 0x4001 23FF GPIO Port G
	0x4001 1C00 - 0x4001 1FFF GPIO Port F
	0x4001 1800 - 0x4001 1BFF GPIO Port E
	0x4001 1400 - 0x4001 17FF GPIO Port D
	0x4001 1000 - 0x4001 13FF GPIO Port C
	0x4001 0C00 - 0x4001 0FFF GPIO Port B
	0x4001 0800 - 0x4001 0BFF GPIO Port A
 */
//-------------------------------------------------------
/* RCC
8.3.7 APB2 peripheral clock enable register (RCC_APB2ENR)
Address: 0x18
Reset value: 0x0000 0000

0x40021018 // 0x4002 1000+18

 */
//-------------------------------------------------------
/*MODE
 * для 0-7
9.2.1 Port configuration register low (GPIOx_CRL) (x=A..G)
Address offset: 0x00
Reset value: 0x4444 4444

0x40010800 		//for PORTA
0x40010C00		//for PORTB
0x40011000		//for PORTC

 для 8-15
9.2.2 Port configuration register high (GPIOx_CRH) (x=A..G)
Address offset: 0x04
Reset value: 0x4444 4444

0x40010804 		//for PORTA; +04
0x40010C04		//for PORTB; +04
0x40011004		//for PORTC; +04
*/
/*--------------------------------------------------------------
 OUTPUT
9.2.4 Port output data register (GPIOx_ODR) (x=A..G)
Address offset: 0x0C
Reset value: 0x0000 0000

0x4001080C		//PORTA; +0C
0x40010C0C		//PORTB; +0C
0x4001100C 		//PORTC; +0C

*///***************************************

//create pointer for RCC_APB2ENR
uint32_t *pClkCntrlReg	= (uint32_t*)0x40021018;

//create ponter for PortmodeReg
uint32_t *pPortAModeLowReg=		(uint32_t*)0x40010800;
uint32_t *pPortAModeHighReg=	(uint32_t*)0x40010804;

uint32_t *pPortBModeLowReg=		(uint32_t*)0x40010C00;
uint32_t *pPortBModeHighReg= 	(uint32_t*)0x40010C04;

//uint32_t *pPortCModeLowReg= 	(uint32_t*)0x40011000; не используется на блюпиле
uint32_t *pPortCModeHighReg= 	(uint32_t*)0x40011004;

//create pointer for OutRegister
uint32_t *pPortAOutReg	= (uint32_t*)0x4001080C;
uint32_t *pPortBOutReg	= (uint32_t*)0x40010C0C;
uint32_t *pPortCOutReg	= (uint32_t*)0x4001100C;

//Enable Clock for PORT ABC
*pClkCntrlReg |=0x1C;	//eneble PORTA-C;

//Configure the mode of PORT-----------------------------------------------
//Configure Mode of PORTA
*pPortAModeLowReg	&=0x22222222;	//clear PA0;PA1;PA2;PA3;PA4;PA5;PA6;PA7;
*pPortAModeLowReg	|=0x22222222;	//set	PA0;PA1;PA2;PA3;PA4;PA5;PA6;PA7;

*pPortAModeHighReg	&=0x44444444;	//0x2FF22222 clear	PA8;PA9;PA10;PA11;PA12;		PA15.
*pPortAModeHighReg	|=0x44444444;	//0x20022222set	PA8;PA9;PA10;PA11;PA12;		PA15.

//Configure Mode of PORTB
*pPortBModeLowReg	&=0x22222F22;	//clear	PB1;	PB3;PB4;PB5;PB6;PB7;
*pPortBModeLowReg	|=0x22222F22;	//set	PB1;	PB3;PB4;PB5;PB6;PB7;

*pPortBModeHighReg	&=0x22222222;	//clear	PB8;PB9;PB10;PB11;PB12;PB13;PB14;PB15.
*pPortBModeHighReg	|=0x22222222;	//set	PB8;PB9;PB10;PB11;PB12;PB13;PB14;PB15.

//Configure Mode of PORTC	//no pins on PCB
//*pPortCModeLowReg	&=0x222FFFFF;	//clear
//*pPortCModeLowReg	|=0x22200000;	//set

*pPortCModeHighReg	&=0x222FFFFF;	//clear	PC13;PC14;PC15
*pPortCModeHighReg	|=0x22200000;	//set	PC13;PC14;PC15


//Enable LED (Configure PC13 as low)
*pPortCOutReg	&=0xFFFFDFFF;	//set	PC13 as low (enable LED)
*pPortCOutReg	|=0x2000;		//set	PC13 as high (disable LED)


//**************************************************************
//PORTA; Configure PA0;PA1;PA2;PA3;PA4;PA5;PA6;PA7;PA8;!PA9;!PA10;!PA11;PA12		PA15; as HIGH
*pPortAOutReg |=0x9FFF;
//PORTA; Configure  PA0;PA1;PA2;PA3;PA4;PA5;PA6;PA7;PA8;PA9;PA10;PA11;!PA12		!PA15; as LOW
*pPortAOutReg &=0x6000;

//PORTB; PB1; Configure	*PB3;PB4;PB5;PB6;PB7;PB8;PB9;PB10;PB11;PB12;PB13;PB14;PB15  as HIGH
*pPortBOutReg |=0xFFF8;
//PORTB; Configure PB3;*PB4;PB5;PB6;PB7;PB8;PB9;PB10;PB11;PB12;PB13;PB14;PB15 as LOW
*pPortBOutReg &=0x0007;

//PORTC; Configure as HIGH PC13;PC14;PC15
*pPortCOutReg |=0xE000;
//PORTC; Configure as LOW PC13;PC14;PC15
*pPortCOutReg &=0x1FFF;
//*************************************************************************

	/* Loop forever */
while(1){
//turn ONN the LED
	*pPortCOutReg	&=0xFFFFDFFF;	//set	PC13 as low (enable LED)
	for(uint32_t i=0; i<80000; i++);
//turn OFF LED
	*pPortCOutReg	|=0x2000;		//set	PC13 as high (disable LED)
	for(uint32_t i=0; i<80000; i++);
	}//end while

}//end main
