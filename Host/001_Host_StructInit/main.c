/*
 * main.c
 *
 *  Created on: 29 дек. 2021 г.
 *      Author: Maxim
 */

/*
 * StructInt.c
 *
 *  Created on: 12 авг. 2020 г.
 *      Author: SimpalsGarage
 */


#include<stdio.h>
#include<stdint.h>

struct carModel{
//	unsigned int carNumber;
	uint32_t carNumber;
	uint32_t carPrice;
	uint16_t carMaxSpeed;
	float carWeight;
	uint8_t carSpeed;
};

int main(void)
{

//	struct carModel carBMW={0};
	struct carModel carBMW={2021,15000,220,1300};
	struct carModel carFord={4031,35000,160,1900.96};
	struct carModel carHonda={.carWeight=90.90,.carPrice=1500};

//	printf("Car BMV carmodel speed= %d",carBMW.carSpeed);
//	struct carModel carFord={2021,15000, 220, 1330};
//	struct carModel carHonda={.carWeight =90.90, .carPrice = 15000};

	printf("Details of car BMW is as follows\n\n");

//	printf("carPrice= %u\n",carBMW.carPrice);

//	carFord.carNumber = 1011;

	printf("carNumber= %u\n",carBMW.carNumber);
	printf("carPrice= %u\n",carBMW.carPrice);
	printf("carMaxSpeed= %u\n",carBMW.carMaxSpeed);
	printf("carWeight= %f\n",carBMW.carWeight);
//	printf("carHonda carWeight = %f\n",carHonda.carWeight);

	carFord.carNumber=1000;

	printf("Details of car Ford is as follows\n\n");

	printf("carNumber= %u\n",carFord.carNumber);
	printf("carPrice= %u\n",carFord.carPrice);
	printf("carMaxSpeed= %u\n",carFord.carMaxSpeed);
	printf("carWeight= %f\n",carFord.carWeight);

	getchar();

//	printf("sizeof=%u\n", sizeof(unsigned int));
	printf("sizeof of structure carModel is =%u\n", sizeof(struct carModel));

//	return 0;
}
