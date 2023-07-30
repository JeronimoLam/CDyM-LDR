#include "sEOS.h"

//#include "../MEF/MEF.h"
//#include "../MEF_Buttons/MEF_Buttons.h"

static volatile uint16_t counter_MEF = 780;
static volatile uint8_t FLAG_MEF = 0;

static volatile uint16_t counter_LDR = 0;
static volatile uint8_t FLAG_LDR = 0;


void sEOS_Dispatch_Tasks(){
	if(FLAG_MEF){
		MEF_Update();
		FLAG_MEF = 0;	
	}
	else if (FLAG_LDR){
		LDR_Update();
		FLAG_LDR = 0;
	}
}

void sEOS_SCH_Tasks(){
	//Cada 50 ms pone el flag en 1
	if (++counter_MEF == 781) {
		FLAG_MEF = 1;
		counter_MEF = 0;
	}
	if (++counter_LDR == 2) {
		FLAG_LDR = 1;
		counter_LDR = 0;
	}
	PWM_soft_Update();
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