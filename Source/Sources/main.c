#include <avr/io.h>
#include <inttypes.h>
#include "anim.h"
#include "memory.h"

#define REPEATER 5

int main (void)

{
	
	uint8_t scenary =0x00;
	scenary = scenary_changer();
	
	uint8_t i= 0;
	while(i<REPEATER)
	{
	animation(scenary);
	i++;
	
	}
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	sleep_enable(); 
    sleep_cpu();

}

