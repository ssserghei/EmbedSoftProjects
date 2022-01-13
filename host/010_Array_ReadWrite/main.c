/*
 * main.c
 *
 *  Created on: 12 янв. 2022 г.
 *      Author: SergheiSGarage
 */

#include<stdio.h>
#include<stdint.h>

int main(void){
	uint8_t someData[]={0xf0,0xf1,0xf2,0xf3};	//compilatorul singur calculeaza marimea tabloului

	printf("Before : 2nd data item = %x\n",*(someData+1)); fflush(stdout);
	//se poate asa
	*(someData+1)=0x9;
	printf("After : 2nd data item = %x\n",*(someData+1)); fflush(stdout);
	//sau asa
	someData[1]=0xA;
	printf("After2 : 2nd data item = %x\n",*(someData+1)); fflush(stdout);
	//**********************************
	printf("0th element value = %x\n",someData[0]);
	//=
	printf("0th element value = %x\n",*(someData+0));
	//**********************************
	printf("content of this array\n");
	for(uint32_t i=0; i<10; i++){
		printf("%x\t", someData[i]);
	}
	someData[2]=0x33;

	printf("\n");

	for(uint32_t i=0; i<10; i++){
		printf("%x\t", someData[i]);
	}

	/*
	 	 *(someData+2)=10;   identical to someData[2]=10;
	 */

	fflush(stdout);
	while(getchar() != '\n');
	getchar();
	return 0;

}//end main
