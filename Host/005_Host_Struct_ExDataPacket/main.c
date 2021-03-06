/*
 * main.c
 *
 *  Created on: 7 янв. 2022 г.
 *      Author: Maxim
 */
/*write a program to decode a  given 32bit packet information and print the values
 *  of different fields. Create a structure with member elements as packet fields as shown below
 *
 */
#include<stdio.h>
#include<stdint.h>

struct Packet{
	uint8_t crc;		//2
	uint8_t status;		//1
	uint16_t payload;	//12
	uint8_t bat;		//3
	uint8_t sensor;		//3
	uint8_t longAddr;	//8
	uint8_t shortAddr;	//2
	uint8_t addrMode;	//1
};

int main (void)
{
	uint32_t PacketValue;
	printf("Enter the 32bit packet value:\n"); fflush(stdout);
	scanf("%X",&PacketValue);

	struct Packet packet;

	packet.crc=(uint8_t)		(PacketValue & 0x3);
	packet.status=(uint8_t)		((PacketValue>>2) & 0x1);
	packet.payload=(uint16_t)	((PacketValue>>3) & 0xFFF);
	packet.bat=(uint8_t)		((PacketValue>>15) & 0x7);
	packet.sensor=(uint8_t)		((PacketValue>>18) & 0x7);
	packet.longAddr=(uint8_t)	((PacketValue>>21) & 0xFF);
	packet.shortAddr=(uint8_t)	((PacketValue>>29) & 0x3);
	packet.addrMode=(uint8_t)	((PacketValue>>31) & 0x1);


	printf("crc		:%#x\n",packet.crc);
	printf("status		:%#x\n",packet.status);
	printf("payload		:%#x\n",packet.payload);
	printf("bat		:%#x\n",packet.bat);
	printf("sensor		:%#x\n",packet.sensor);
	printf("longAddr	:%#x\n",packet.longAddr);
	printf("shortAddr	:%#x\n",packet.shortAddr);
	printf("addrMode	:%#x\n",packet.addrMode);

	printf("Size of struct is %I64u\n",sizeof(packet));
	fflush(stdout);
	while(getchar() != '\n');
	getchar();
	return 0;
}
