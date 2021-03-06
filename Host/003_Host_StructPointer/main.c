/*
 * main.c
 *
 *  Created on: 7 янв. 2022 г.
 *      Author: Maxim
 */

/*use dot (.) operator when you use structure variable of non pointer type
 * use arrow (->) operator when you use structure variable of pointer type
 *
 * */
#include<stdio.h>
#include<stdint.h>

struct DataSet{
	char data1;
	int data2;
	char data3;
	short data4;
};

int main(void)
{
	struct DataSet data;

	data.data1 =0x11;
	data.data2 =0xFFFFEEEE;
	data.data3 =0x22;
	data.data4 =0xABCD;

	printf("Before: data.data1=%X\n",data.data1);

	struct DataSet *pData;

	pData=&data;

	pData->data1=0x55;

	printf("After: data.data1=%X\n",data.data1);

	printf("sizeof=%u\n", sizeof(unsigned int));
	printf("sizeof of structure carModel is =%u\n", sizeof(struct DataSet));

	getchar();
	return 0;
}
