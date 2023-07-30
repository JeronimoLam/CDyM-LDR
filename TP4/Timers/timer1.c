#include "timers.h"

// Init timer
void TIMERS_InitTimer1(){
	//Modo Fast PWM con top = 0x00FF (Modo 5)
	//Prescaler en 256
	//Modo invertido (clear on count reset)
	TCCR1A |= (1 << WGM10) | (1<< COM1A1) | (1<< COM1B1);
	TCCR1B |= (1 << WGM12) | (1 << CS12) | (1 << CS10);// | (1 << CS10) ;
}
