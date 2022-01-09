/*
 * main.c
 *
 *  Created on: 9 янв. 2022 г.
 *      Author: Maxim
 */

#include<stdio.h>
#include<stdint.h>

union Packet{

	uint32_t packetValue;

	struct{
		uint32_t crc		:2;		//2
		uint32_t status		:1;		//1
		uint32_t payload	:12;	//12
		uint32_t bat		:3;		//3
		uint32_t sensor		:3;		//3
		uint32_t longAddr	:8;		//8
		uint32_t shortAddr	:2;		//2
		uint32_t addrMode	:1;		//1
	}packetFields;
};

int main (void)
{
	union Packet packet;
	printf("Enter the 32bit packet value:\n"); fflush(stdout);
	scanf("%X",&packet.packetValue);


	printf("crc		:%#x\n",packet.packetFields.crc);
	printf("status		:%#x\n",packet.packetFields.status);
	printf("payload		:%#x\n",packet.packetFields.payload);
	printf("bat		:%#x\n",packet.packetFields.bat);
	printf("sensor		:%#x\n",packet.packetFields.sensor);
	printf("longAddr	:%#x\n",packet.packetFields.longAddr);
	printf("shortAddr	:%#x\n",packet.packetFields.shortAddr);
	printf("addrMode	:%#x\n",packet.packetFields.addrMode);

	printf("Size of struct is %I64u\n",sizeof(packet));
	fflush(stdout);
	while(getchar() != '\n');
	getchar();
	return 0;
}
