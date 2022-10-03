#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD.h"
#include "spi.h"
int main()
{
	LCD_vidinit();
	SPI_initMaster();
	char * hello="hello";
	SPI_sendString(hello);
	return 1;
}

