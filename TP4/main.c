#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

#include "Timers/timers.h"
#include "Leds/led.h"
#include "sEOS/sEOS.h"
#include "MEF/MEF.h"


int main(void)
{
	
	TIMERS_InitTimer0();
	TIMERS_InitTimer1();
	
	LEDS_init();
	MEF_init();
	LEDS_setFinalRGB(0, 255, 255);
	
	//Test PB4 como salida y un 1 en la misma
	DDRB |= (1 << PORTB4);
	PORTB &= ~(1 << PORTB4);
	
	sei();
	
    while(1)
    {
		sEOS_Dispatch_Tasks();
		sEOS_Go_To_Sleep();
    }
}

