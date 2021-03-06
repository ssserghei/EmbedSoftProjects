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

}/*__attribute__((packed))*/;

int main (void)
{

	struct DataSet data;
		data.data1=0x11;		//char
		data.data2=0XFFFFEEEE;	//int
		data.data3=0x22;		//char
		data.data4=0xABCD;		//short

		uint8_t *ptr;

		ptr=(uint8_t*)&data; //

		uint32_t totalSize=sizeof(struct DataSet);

	printf("Memory address			Content\n"); fflush(stdout);
	printf("====================================\n");fflush(stdout);

	for (uint32_t i=0; i<totalSize; i++){
		printf("%p		%X\n", ptr, *ptr);
		ptr++;
	};
	printf("Total memory consumed by this struct variable=%u\n", sizeof(struct DataSet));fflush(stdout);
	getchar();
}
