/*
 * spi.h
 *
 *  Created on: Aug 25, 2022
 *      Author: Ghefo
 */

#ifndef SPI_H_
#define SPI_H_

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "avr/io.h"

/*****************************************************************************************
 *  								Functions Prototypes
 ****************************************************************************************/
void SPI_initMaster(void);
void SPI_initSlave(void);
void SPI_sendByte(const u8 data);
u8   SPI_recieveByte(void);
void SPI_recieveString(char* str);
void SPI_sendString(const char* str);
#endif /* SPI_H_ */
