/*
 * main.c
 *
 *  Created on: 7 янв. 2022 г.
 *      Author: Maxim
 */
/*
	Неиспользованная память заполняется(padding) нулями.
	Выравнивание и заполнение структур

 * */


#include<stdio.h>
#include<stdint.h>

struct carModel{
//	unsigned int carNumber;
	uint32_t carNumber;
	uint32_t carPrice;
	uint16_t carMaxSpeed;
	float carWeight;
//	uint8_t carSpeed;
};

int main(void)
{

//	struct carModel carBMW={2021,15000,220,1300};



	printf("sizeof=%u\n", sizeof(unsigned int));
	printf("sizeof of structure carModel is =%u\n", sizeof(struct carModel));
	getchar();

	return 0;
}
