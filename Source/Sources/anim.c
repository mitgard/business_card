
#include "anim.h"
#include "beep.h"


#define ON 0x01
#define OFF 0x00
#define COUNTLED 12

const uint16_t ledInit[COUNTLED] = {

0x0A,
0x0A,
0x06,
0x06,
0x14,
0x14,
0x12,
0x12,
0x18,
0x18,
0x0C,
0x0C
};

const uint16_t ledCtrl[COUNTLED] = {


0x02,
0x08,
0x02,
0x04,
0x10,
0x04,
0x02,
0x10,
0x10,
0x08,
0x04,
0x08
};

void animation(uint8_t scenary)

{
	uint8_t i=0;
	if(scenary ==0x00)
	{
	
	
	while(i<COUNTLED)
	{
		led_control(ledInit[i],ledCtrl[i],ON);
		_delay_ms(25);
		led_control(ledInit[i],ledCtrl[i],OFF);
		i++;
	}
	
	}
	
	if(scenary ==0x01)
	{
	i=COUNTLED;
	while(i)
	{
		led_control(ledInit[i],ledCtrl[i],ON);
		_delay_ms(25);
		led_control(ledInit[i],ledCtrl[i],OFF);
		i--;
	}
	
	if(i==0)
	{
		led_control(ledInit[i],ledCtrl[i],ON);
		_delay_ms(25);
		led_control(ledInit[i],ledCtrl[i],OFF);
	}
	
	}
	if(scenary ==0x02)
	{
		march();
	}

	if(scenary ==0x03)
	{
	
	i=0;
	while(i<COUNTLED)
	{
		led_control(ledInit[i]|ledInit[COUNTLED-i],ledCtrl[i],ON);
//		led_control(ledInit[COUNTLED-i],ledCtrl[COUNTLED-i],ON);
		
		_delay_ms(25);
		led_control(ledInit[i]|ledInit[COUNTLED-i],ledCtrl[i],OFF);
//		led_control(ledInit[COUNTLED-i],ledCtrl[COUNTLED-i],OFF);
		i++; 
	}
	
	}

	return 0;
}


void led_control(uint8_t ledInit, uint8_t ledNumber, uint8_t ledStatus)

{	
	if(ledStatus==OFF)	//Off led
	{	
		DDRB &= ~ledInit;
		PORTB &= ~ledNumber;
		
	}

	if(ledStatus==ON)	//On led
	{
		DDRB |= ledInit;
		PORTB |= ledNumber;
	}
	
}


















