#ifndef _STD_LIB_INC_
#include <avr/io.h>
#include <util/delay_basic.h>
#include <util/delay.h>
#include <avr/sleep.h>
#include <stdio.h>
#include <avr/pgmspace.h> 
#include <avr/interrupt.h>
#include <inttypes.h>
#endif

#include "anim.h"

void setup(void);
void march(void);
static inline void doSound(void);

