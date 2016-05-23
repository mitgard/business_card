#include "beep.h"


#define COUNT_NOTES 39

//Freq note
const uint16_t frequences[COUNT_NOTES] PROGMEM = {
	392, 392, 392, 311, 466, 392, 311, 466, 392,
	587, 587, 587, 622, 466, 369, 311, 466, 392,
	784, 392, 392, 784, 739, 698, 659, 622, 659,
	415, 554, 523, 493, 466, 440, 466,
	311, 369, 311, 466, 392 };

//Note duration
const uint16_t durations[COUNT_NOTES] PROGMEM = {
	350, 350, 350, 250, 100, 350, 250, 100, 700,
	350, 350, 350, 250, 100, 350, 250, 100, 700,
	350, 250, 100, 350, 250, 100, 100, 100, 450,
	150, 350, 250, 100, 100, 100, 450,
	150, 350, 250, 100, 750 };


#ifndef	_FREQ_
#define F_CPU 9600000UL
#endif

 void setup() 	 
{ 	 
 
  	DDRB |= 0xFF;
	PORTB |= 0x00;
  
} 	 
  	 
 
 


void march()
{ 	 
		setup();
		doSound();
		PORTB=0x00;
		DDRB |= 0x00;
		set_sleep_mode(SLEEP_MODE_PWR_DOWN);
		sleep_enable(); 
    	sleep_cpu();
}


inline void doSound(void)
{
	
	//On timer and setting
	TCCR0A = (1 << COM0A0) | (1 << WGM01);	//Toggle OC0A (PB0) on Compare Match ; mode = CTC
	TCCR0B = (1 << CS01) | (1 << CS00);		//Clock Select = F_CPU/64
	
	//playing notes
	for (uint8_t i = 0; i < COUNT_NOTES; i++)
	{
		//read data from mem
		int16_t freq = pgm_read_word(&(frequences[i]));
		int16_t dur = pgm_read_word(&(durations[i]));
		
		//Amplifation duration 1.5 time
//		dur *= 3;
//		dur /= 2;
		
		//Enter freq in the exit PB0
		OCR0A = (F_CPU / (2UL * 64UL * freq)) - 1;
		PORTB = OCR0A|0xAA;
		//waiting
		while (dur > 0)
		{
			_delay_ms(10);
			dur -= 10;
		}
	}
	
	//Timer off
	TCCR0A = 0;
	TCCR0B = 0;
	
}