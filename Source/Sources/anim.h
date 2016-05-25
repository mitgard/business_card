#ifndef _STD_LIB_INC_
#include <avr/io.h>
#include <util/delay.h>
#include <util/delay_basic.h>
#include <avr/sleep.h>
#include <stdio.h>
#include <inttypes.h>
#endif




void animation (uint8_t scenary);

void delay_ms(uint8_t delay);

void led_controlOn(uint8_t ledInit, uint8_t ledNumber);
void led_controlOff(uint8_t ledInit, uint8_t ledNumber);
