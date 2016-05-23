#include "memory.h"


#define MAX 0x03

uint8_t EEMEM startScenary;

uint16_t scenary_changer()
{
	
	uint8_t ucData = 0x00;

	ucData = eeprom_read_byte (&startScenary);

	eeprom_write_byte (&startScenary, ucData+1);
	if((ucData>=MAX)|(ucData==0xFF))
	{	
	eeprom_write_byte (&startScenary, 0x00);
	}

	return ucData;
}

