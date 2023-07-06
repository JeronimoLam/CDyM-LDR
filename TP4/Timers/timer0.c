#include "timers.h"
#include "../sEOS/sEOS.h"

void TIMERS_InitTimer0(){
	// Interrupcion cada 1ms
	TCCR0A |= (1 << WGM01);
	TCCR0B |= (1 << CS01) | (1 << CS00);  // prescaler 64
	TIMSK0 |= (1 << OCIE0A);
	
	OCR0A = 249;
}
static volatile uint16_t counter = 499;
ISR(TIMER0_COMPA_vect){
	sEOS_SCH_Tasks();
}