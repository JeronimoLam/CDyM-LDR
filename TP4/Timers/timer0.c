#include "timers.h"

volatile uint16_t counter = 0;

void TIMERS_InitTimer0(){
	// Interrupcion cada 1ms
	TCCR0A |= (1 << WGM01);
	TCCR0B |= (1 << CS01) | (1 << CS00);  // prescaler 64
	TIMSK0 |= (1 << OCIE0A);
	
	OCR0A = 249;
}

ISR(TIMER0_COMPA_vect){
	if(++counter == 50){
		counter = 0;
	}
}

/*
if (counter  < 500){
	counter++;
}
if (counter % 50 == 0){
	setBlue(blue + (MAX_B/10)); //Al valor del led actual se le suma 1/10 del total
	setGreen(green + MAX_G/10);
}
if(counter == 500){
	setBlue(255);
	setGreen(255);
	PORTB ^= (1<<PORTB4);
	counter = 0;
	_delay_ms(1000);
}

*/