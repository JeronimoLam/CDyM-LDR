#include "MEF.h"

typedef enum {RAISING, ON, FALLING, OFF}states;
static states state;
static uint16_t stateCount;
static uint16_t timeOff = 20;

void MEF_init(){
	state = OFF;
	stateCount = 0;
}

void MEF_Update(){
	stateCount++;
	
	switch (state){
		case OFF:
			PORTB |= (1<<PORTB4);
			
			LEDS_setRed(0);
			LEDS_setGreen(0);
			LEDS_setBlue(0);
			
			if(stateCount == timeOff){
				state = RAISING;
				stateCount = 0;
			}
			break;
			
		case RAISING:
			PORTB |= (1<<PORTB4);

			/*LEDS_setGreen(150);
			LEDS_setBlue(150);*/
			
			if (LEDS_getFinalRed() != 0) LEDS_incrementRed(stateCount - 1);
			if (LEDS_getFinalGreen() != 0) LEDS_incrementGreen(stateCount - 1);
			if (LEDS_getFinalBlue() != 0) LEDS_incrementBlue(stateCount - 1);
			
			if(stateCount == 10){
				state = ON;
				stateCount = 0;
			}
			break;
			
		case ON:
			PORTB &= ~(1<<PORTB4);

			
			LEDS_setRed(LEDS_getFinalRed());
			LEDS_setGreen(LEDS_getFinalGreen());
			LEDS_setBlue(LEDS_getFinalBlue());
			
			if(stateCount == 20){
				state = FALLING;
				stateCount = 0;
			}
			break;
			
		case FALLING:
			PORTB |= (1<<PORTB4);
			
			if (LEDS_getFinalRed() != 0) LEDS_decrementRed(stateCount - 1);
			if (LEDS_getFinalGreen() != 0) LEDS_decrementGreen(stateCount - 1);
			if (LEDS_getFinalBlue() != 0) LEDS_decrementBlue(stateCount - 1);
			
			if(stateCount == 10){
				state = OFF;
				stateCount = 0;
			}
			break;
	
	}
}
