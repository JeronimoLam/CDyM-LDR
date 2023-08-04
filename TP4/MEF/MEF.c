#include "MEF.h"

typedef enum {RAISING, ON, FALLING, OFF}states;
static states state;
static uint16_t stateCount;
static uint16_t timeOff = 20;
static double pendiente;
static uint16_t desplazamiento;

void MEF_init(){
	state = OFF;
	stateCount = 0;

	pendiente = (10-100) / (MIN_SUP_LDR - MAX_INF_LDR);
	desplazamiento = 100 + round(pendiente * MAX_INF_LDR);
}

void  update_timeOff(){
	uint16_t LDR_value = LDR_get_value();
	
	// Caso en el que Tparpadeo = 5seg (minima luz o menos)
	if (LDR_value < MAX_INF_LDR){
		timeOff = 1000;
	}
	// Caso en el que Tparepadeo = 2seg (luz ambiente o mas)
	else if (LDR_value > MIN_SUP_LDR){
		timeOff = 100;
	}
	else {
		timeOff = desplazamiento - round(pendiente*LDR_value); // Parte de la recta con pendiente m negativa
	}
}

void MEF_Update(){
	stateCount++;
	
	switch (state){
		case OFF:
			PORTB |= (1<<PORTB4);
			
			LEDS_setRed(0);
			LEDS_setGreen(0);
			LEDS_setBlue(0);
			
			update_timeOff();
			if(stateCount >= timeOff){
				state = RAISING;
				stateCount = 0;
			}
			break;
			
		case RAISING:
			PORTB |= (1<<PORTB4);
			
			LEDS_incrementRed(stateCount - 1);
			LEDS_incrementGreen(stateCount - 1);
			LEDS_incrementBlue(stateCount - 1);
			
			if(stateCount == 100){
				state = ON;
				stateCount = 0;
			}
			break;
			
		case ON:
			PORTB &= ~(1<<PORTB4);

			
			LEDS_setRed(LEDS_getFinalRed());
			LEDS_setGreen(LEDS_getFinalGreen());
			LEDS_setBlue(LEDS_getFinalBlue());
			
			if(stateCount == 200){
				state = FALLING;
				stateCount = 0;
			}
			break;
			
		case FALLING:
			PORTB |= (1<<PORTB4);
			
			LEDS_decrementRed(stateCount - 1);
			LEDS_decrementGreen(stateCount - 1);
			LEDS_decrementBlue(stateCount - 1);
			
			if(stateCount == 100){
				state = OFF;
				stateCount = 0;
			}
			break;
	
	}
}
