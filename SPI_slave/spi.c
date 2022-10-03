/*
 * spi.c
 *
 *  Created on: Aug 25, 2022
 *      Author: Ghefo
 */

#include "spi.h"


void SPI_initMaster(void)
{
	/*
	 * 1- SS is output
	 * 2- MOSI output
	 * 3- MISO input
	 * 4- CLK output
	 */
	SET_BIT(DDRB,PB4);
	SET_BIT(DDRB,PB5);
	CLR_BIT(DDRB,PB6);
	SET_BIT(DDRB,PB7);

	/*
	 * 1 - Enable SPI
	 * 2 - No interrupt mode
	 * 3 - Enable Master mode
	 * 4 - Choose speed (FCPU/4)
	 */
	SPCR = 0;
	SPCR = (1<<SPE) | (1<<MSTR);
}

void SPI_initSlave(void)
{
	/*
	 * 1- SS is input
	 * 2- MOSI input
	 * 3- MISO output
	 * 4- CLK input
	 */
	CLR_BIT(DDRB,PB4);
	CLR_BIT(DDRB,PB5);
	SET_BIT(DDRB,PB6);
	CLR_BIT(DDRB,PB7);

	/*
	 * 1 - Enable SPI
	 * 2 - No interrupt mode
	 * 3 - Enable slave mode
	 */
	SPCR = 0;
	SET_BIT(SPCR,SPE);
}


void SPI_sendByte(const u8 data)
{
	SPDR = data;
	while(!GET_BIT(SPSR,SPIF));
}

u8   SPI_recieveByte(void)
{
	while(!GET_BIT(SPSR,SPIF));
	return SPDR;
}
void SPI_sendString(const char* str)
{
	while(*str != '0x00')
	{
		SPI_sendByte(*str);
		str++;
	}
}

void SPI_recieveString(char* str,u8 size)
{
	u8 i = 0;
	str[i] = SPI_recieveByte();
	while(str[i-1] != '0x00')
	{
		i++;
		str[i] = SPI_recieveByte();
	}
	str[i]= '0x00';

}


