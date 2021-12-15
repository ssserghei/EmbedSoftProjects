/*
 * Arrays.c
 *
 *  Created on: 5 сент. 2020 г.
 *      Author: SSS_notebok
 */


#include<stdio.h>
#include<stdint.h>

void array_display(uint8_t const *const pArray,uint32_t nItems);


int main(void){
	uint8_t someData[10] ={0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa};
	printf("someData= %#x;\n", *(someData+1)); fflush(stdout);

	*(someData+1)=0x9;

	printf("someData= %#x;\n", *(someData+1)); fflush(stdout);

	printf("someData= %#x;\n", someData[0]); fflush(stdout);
	printf("someData= %#x;\n", *(someData+0)); fflush(stdout);

	printf("contents of this array\n"); fflush(stdout);

	for(uint32_t i=0; i<10; i++){
		printf("%#x\t", someData[i]); fflush(stdout);
		}
	someData[2]=0x33;
	printf("\n");

	for(uint32_t i=0; i<10; i++){
			printf("%#x\t", someData[i]); fflush(stdout);
		}
	printf("\n");

	uint32_t nItems=sizeof(someData)/sizeof(uint8_t);

	array_display(someData+2, nItems);
	return 0;
}//end main

void array_display(uint8_t  const *const pArray, uint32_t nItems)
{
	for(uint32_t i=0; i<nItems; i++){

//		printf("%#x\t",*(pArray+i)); fflush(stdout);
		printf("%#x\t",pArray[i]); fflush(stdout);

	}
}
