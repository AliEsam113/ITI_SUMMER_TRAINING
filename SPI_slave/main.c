#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD.h"
#include "spi.h"
int main()
{
	SPI_initSlave();
	LCD_vidinit();
	char * h="";
	SPI_recieveString(h);
	LCD_vidwritedata('s');
	LCD_vidwritestring(0,5,"hello");
	return 1;
}

