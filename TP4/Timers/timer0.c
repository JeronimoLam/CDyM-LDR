#include "timers.h"
#include "../sEOS/sEOS.h"

void TIMERS_InitTimer0(){
	// Interrupcion cada 64 us
	// Prescaler en 8
	TCCR0A |= (1 << WGM01); // Modo CTC
	TCCR0B |= (1 << CS01);
	OCR0A = 127;
	
	TIMSK0 |= (1 << OCIE0A);
}

ISR(TIMER0_COMPA_vect){
	sEOS_SCH_Tasks();
}