#include "sEOS.h"

//#include "../MEF/MEF.h"
//#include "../MEF_Buttons/MEF_Buttons.h"

static volatile uint16_t counter = 499;
static volatile uint8_t FLAG_MEF = 0;


void sEOS_Dispatch_Tasks(){
	if(FLAG_MEF){
		MEF_Update();
		FLAG_MEF = 0;	
	}
	// Actualiza la MEF cada 50ms
	/*if (FLAG_MEF) {
		PORTB ^= (1<<PORTB4);
		counter2++;
		if(counter2 == 10){
			counter2 = 0;
			//PORTB ^= (1<<PORTB4);
		
		}
		if (counter  < 500){
			counter++;
		}
		if (counter % 50 == 0){
			LEDS_incrementBlue(LEDS_getFinalBlue()/10); //Al valor del led actual se le suma 1/10 del total
			LEDS_incrementGreen(LEDS_getFinalGreen()/10);
		}
		if(counter == 500){
			LEDS_setBlue(LEDS_getFinalBlue());
			LEDS_setGreen(LEDS_getFinalGreen());
			counter = 0;
		}
		//MEF_Buttons_Update(); // Actualizamos la MEF para el antirebote y las colisiones multiples
		//MEF_Update(); // Actualizacion de la MEF principal de estados
		*/
}

void sEOS_SCH_Tasks(){
	//Cada 50 ms pone el flag en 1
	if (++counter == 500) {
		FLAG_MEF = 1;
		counter = 0;
	}
}


//Pone en modo ahorro el micro
void sEOS_Go_To_Sleep(){
	
	// Setea el sleep mode a "idle". Este modo permite a la CPU dormir
	// dejando los perifericos (Como Timers y UART) corriendo
	set_sleep_mode(SLEEP_MODE_IDLE);

	// Habilita sleep mode
	sleep_enable();

	// Duerme al cpu
	sleep_cpu();

	// Deshabilita sleep mode
	sleep_disable();
}