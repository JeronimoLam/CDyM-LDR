/*
 * ldr.c
 *
 * Created: 7/14/2023 12:41:23 AM
 *  Author: franc
 */ 

#include "LDR.h"

uint16_t result = 0;
uint8_t is_converting = 0;

void LDR_config(){
	DIDR0= 0x01; //Digital Input Disable (opcional)
	ADCSRA= 0x87;//make ADC enable and select ck/128
	ADMUX= 0x00;// Vref=AVCC, right-justified, ADC0 pin
	ADMUX |= (1<<REFS0);
}

/*void LDR_Update(){
	ADCSRA |= (1<<ADSC);//start conversion
	if((ADCSRA&(1<<ADIF))==0) {//wait for conversion to finish
		ADCSRA |= (1<<ADIF); //borrar flag
		result = ADC;
	}
}*/

void LDR_Update(){
	if (!is_converting){
		ADCSRA |= (1<<ADSC);//start conversion
		is_converting = 1;
	}
	if ((ADCSRA&(1<<ADIF))==1) {//wait for conversion to finish
		ADCSRA |= (1<<ADIF); //borrar flag
		result = (uint16_t) ADC;
		is_converting = 0;
	}
}

uint16_t LDR_get_value(){
	ADCSRA |= (1<<ADSC);//start conversion
	while((ADCSRA&(1<<ADIF))==0);//wait for conversion to finish
	ADCSRA |= (1<<ADIF); //borrar flag
	result = (uint16_t) ADC;
	// para no polling comentar las 4 lineas de arriba
	return result;
}