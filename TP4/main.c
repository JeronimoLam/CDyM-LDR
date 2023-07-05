#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

#define MAX_R 252
#define MAX_G 89
#define MAX_B 7

// Init timer
void InitTimer1(){
	//Modo Fast PWM con top = 0x00FF (Modo 5)
	//Prescaler en 256
	//Modo NO invertido
	TCCR1A |= (1 << WGM10) | (1<< COM1A1) | (1<< COM1B1);
	TCCR1B |= (1 << WGM12) | (1 << CS12);
	
	OCR1A = 0;
	OCR1B = 0;
}

void InitTimer0(){
	// Interrupcion cada 1ms
	TCCR0A |= (1 << WGM01);
	TCCR0B |= (1 << CS02);
	TIMSK0 |= (1 << OCIE0A);
	
	OCR0A = 62;
}

ISR(TIMER1_COMPA_vect){
	PORTB ^= (1<<PORTB4);
}

int main(void)
{
    /* Replace with your application code */
	//PIN 51 y 2 como salida
	
	InitTimer1();
	InitTimer0();
	DDRB |= (1<<PORTB1) | (1<<PORTB2) | (1<<PORTB5);
	PORTB |= (1 << PINB5);
	
	//Test
	DDRB |= (1<<PORTB4);
	PORTB &= ~(1<<PORTB4);
	//
	
    while (1)
    {
		OCR1A += 1;
		//PORTB ^= (1 << PORTB1);
		//_delay_ms(100);
    }
}

