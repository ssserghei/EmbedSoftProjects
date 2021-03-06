/*
 * main.c
 *
 *  Created on: 13 янв. 2022 г.
 *      Author: SergheiSGarage
 */
#include<stdio.h>
#include<stdint.h>

void array_display(uint8_t const *const pArray,uint32_t nitems);

int main(void){
	uint8_t someData[]={0xf0,0xf1,0xf2,0xf3,0xf4,0xf5,0xf6,0xf7,0xf8,0xf9};	//compilatorul singur calculeaza marimea tabloului

	printf("Before : 2nd data item = %x\n",*(someData+1)); fflush(stdout);
/*
	for(uint32_t i=0; i<10; i++){
		someData[i]=i;
	}
*/
	uint32_t nItems=sizeof(someData)/sizeof(uint8_t);

	printf("sizeof(someData)= %d\n",sizeof(someData));
	printf("sizeof(uint8_t)= %d\n",sizeof(uint8_t));

	array_display((someData+2),nItems-3);

	fflush(stdout);
	while(getchar() != '\n');
	getchar();
	return 0;

}//end main

void array_display(uint8_t const *const pArray,uint32_t nItems){
	for(uint32_t i=0; i<nItems; i++){
	printf("= %x\n",*(pArray+i)); fflush(stdout);
	}//end for
}//end main
