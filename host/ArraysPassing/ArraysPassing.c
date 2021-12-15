/*
 * ArraysPassing.c
 *
 *  Created on: 6 сент. 2020 г.
 *      Author: SSS_notebok
 */

#include<stdio.h>
#include<stdint.h>

void array_display(uint8_t const *const pArray, uint32_t nItems);

int main(void){
	uint8_t someData[10]={0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa};

	for(uint32_t i=0; i<10; i++)
	{
		someData[i] = i;

	}//end for

	uint32_t nItems=sizeof(someData) / sizeof(uint8_t);

	array_display(&someData[2], nItems-2);

	return 0;
}//end main

void array_display(uint8_t const *const pArray, uint32_t nItems)
{
	//lets display the content of the received array
	for(uint32_t i=0; i<nItems; i++){
		printf("%#x\t", *(pArray+i));

	}//end for

}//end array_display

