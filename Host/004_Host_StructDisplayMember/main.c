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

void DisplayMemberElements(struct DataSet *pdata);

int main(void)
{
	struct DataSet data;

	data.data1 =0x11;
	data.data2 =0xFFFFEEEE;
	data.data3 =0x22;
	data.data4 =0xABCD;

	DisplayMemberElements(&data);

	getchar();
	return 0;
}

void DisplayMemberElements(struct DataSet *pdata){
	printf("data1=%X\n",pdata->data1);
	printf("data2=%X\n",pdata->data2);
	printf("data3=%X\n",pdata->data3);
	printf("data4=%X\n",pdata->data4);
}
