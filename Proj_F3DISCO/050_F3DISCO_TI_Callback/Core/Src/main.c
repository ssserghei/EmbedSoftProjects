/*
 LED's Расположены по часовой стрелке сверху вниз начиная с 00 часов
PE9 	LD3		Red		N
PE10	LD5		Orange
PE11 	LD7		Green	E
PE12 	LD9		Blue
PE13 	LD10	Red		S
PE14 	LD8		Orange
PE15 	LD6		Green	W
PE8 	LD4		Blue
 */

#include <string.h>
#include "stm32f3xx_hal.h"
#include "main.h"

#define TRUE 	1U
#define FALSE 	0U

void SystemClockConfig(void);
void UART1_Init(void);
void Error_handler(void);
void GPIO_Init(void);

void delay(void){
	// this will introduce ~200ms delay when system clock is 16MHz
	for(uint32_t i = 0 ; i < 50000 ; i ++);
}

UART_HandleTypeDef huart1;

char *user_data="The application is running\r\n";

/*************************MAIN************************************/
uint8_t data_buffer[100];
uint8_t recvd_data;
uint8_t count=0;
uint8_t reception_complete=FALSE;
int main (void){

	HAL_Init();
	SystemClockConfig();
	GPIO_Init();

	UART1_Init();

//	uint16_t len_of_data=strlen(user_data);
//	HAL_UART_Transmit(&huart1, (uint8_t*)user_data, len_of_data, HAL_MAX_DELAY);




uint8_t count=0;

while(1)
{

HAL_UART_Transmit(&huart1, &count, 1, HAL_MAX_DELAY);
count++;
HAL_Delay(500);
}
/*
 http://www.customelectronics.ru/wp-content/uploads/2018/08/10.jpg
 * */



while(1){

	HAL_GPIO_TogglePin(GPIOE,GPIO_PIN_9);
	delay();
	HAL_GPIO_TogglePin(GPIOE,GPIO_PIN_10);
	delay();
	HAL_GPIO_TogglePin(GPIOE,GPIO_PIN_11);
	delay();
	HAL_GPIO_TogglePin(GPIOE,GPIO_PIN_12);
	delay();
	HAL_GPIO_TogglePin(GPIOE,GPIO_PIN_13);
	delay();
	HAL_GPIO_TogglePin(GPIOE,GPIO_PIN_14);
	delay();
	HAL_GPIO_TogglePin(GPIOE,GPIO_PIN_15);
	delay();
	HAL_GPIO_TogglePin(GPIOE,GPIO_PIN_8);
	delay();


}




	return 0;
}//END MAIN


void GPIO_Init(void)
{
    __HAL_RCC_GPIOE_CLK_ENABLE();
	GPIO_InitTypeDef ledgpio;
	ledgpio.Pin = GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15 | GPIO_PIN_8;
	ledgpio.Mode = GPIO_MODE_OUTPUT_PP;
	ledgpio.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOE,&ledgpio);
}

void SystemClockConfig(void){

}

void UART1_Init(void){

	huart1.Instance=USART1;						//
	huart1.Init.BaudRate=115200;				//
	huart1.Init.WordLength=UART_WORDLENGTH_8B;	//
	huart1.Init.StopBits=UART_STOPBITS_1;		//
	huart1.Init.Parity=UART_PARITY_NONE;		//
	huart1.Init.HwFlowCtl=UART_HWCONTROL_NONE;	//
	huart1.Init.Mode=UART_MODE_TX_RX;			//
	if (HAL_UART_Init(&huart1) !=HAL_OK){
		//There is a problem
		Error_handler();
	}
}


void Error_handler(void){
	while(1);
}
