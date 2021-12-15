/*
 * DataAllignment.c
 *
 *  Created on: 12 авг. 2020 г.
 *      Author: SimpalsGarage
 */

#include<stdint.h>
#include<stdio.h>

struct DataSet
{
	char 	data1;
	int 	data2;
	char 	data3;
	short 	data4;
}__attribute__((packed));


struct DataSet data;

int main (void)
{


		data.data1=0xAA;		//char
		data.data2=0XFFFFEEEE;	//int
		data.data3=0x55;		//char
		data.data4=0xA5A6;		//short

		printf("data.data1= %x\n", data.data1); fflush(stdout);
		printf("data.data2= %x\n", data.data2); fflush(stdout);
		printf("data.data3= %x\n", data.data3); fflush(stdout);
		printf("data.data4= %x\n", data.data4); fflush(stdout);

		for(;;);

}
