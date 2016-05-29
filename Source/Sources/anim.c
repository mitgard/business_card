
#include "anim.h"
#include "beep.h"



#define COUNTLED 12

const uint16_t ledInit[COUNTLED] = {


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
0x0C,
0x0A
};

const uint16_t ledCtrl[COUNTLED] = {



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
0x08,
0x02
};

void animation(uint8_t scenary)

{
	uint8_t i=0;
	if(scenary ==0x00)
	{
	
	
	while(i<COUNTLED)
	{
		led_controlOn(ledInit[i], ledCtrl[i]);
		delay_ms(25);
		led_controlOff(ledInit[i], ledCtrl[i]);
		i++;
	}
	
	}
	
	if(scenary ==0x01)
	{
	i=COUNTLED;
	while(i)
	{
		led_controlOn(ledInit[i], ledCtrl[i]);
		delay_ms(25);
		led_controlOff(ledInit[i], ledCtrl[i]);
		i--;
	}
	
	if(i==0)
	{
		led_controlOn(ledInit[i], ledCtrl[i]);
		delay_ms(25);
		led_controlOff(ledInit[i], ledCtrl[i]);
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
		led_controlOn(ledInit[i]|ledInit[COUNTLED-i],ledCtrl[i]|ledCtrl[COUNTLED-i]);
		delay_ms(100);
		led_controlOff(ledInit[i]|ledInit[COUNTLED-i],ledCtrl[i]|ledCtrl[COUNTLED-i]);

		i++; 
	}
	
	}

/*	if(scenary ==0x04)
	{
	
	i=0;
	while(i<COUNTLED)
	{
	
		led_controlOn(ledInit[i]|ledInit[(COUNTLED/2)+i],ledCtrl[i]|ledCtrl[(COUNTLED/2)+i]);
		delay_ms(100);
		led_controlOff(ledInit[i]|ledInit[(COUNTLED/2)+i],ledCtrl[i]|ledCtrl[(COUNTLED/2)+i]);


		i++; 
	}

	}
*/
	
}

void led_controlOn(uint8_t ledInit, uint8_t ledNumber)

{	
		DDRB |= ledInit;
		PORTB |= ledNumber;
	
}

void led_controlOff(uint8_t ledInit, uint8_t ledNumber)

{	
		DDRB &= ~ledInit;
		PORTB &= ~ledNumber;;
	
}
void delay_ms(uint8_t delay)

{
	while(delay)
	{	
		delay--;
		_delay_loop_2(2500);
	}
}















