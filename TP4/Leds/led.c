#include "led.h"

static uint8_t final_red = 0;
static uint8_t final_green = 0;
static uint8_t final_blue = 0;

static uint8_t red = 0;
static uint8_t green = 0;
static uint8_t blue = 0;

void LEDS_init(){
	//PIN 1, 2 y 5 como salida
	DDRB |= (1<<PORTB1) | (1<<PORTB2) | (1<<PORTB5);
	PORTB |= (1 << PINB5);
	
	LEDS_setRed(0);
	LEDS_setGreen(0);
	LEDS_setBlue(0);
}

void LEDS_setRed(uint8_t value){
	
}

void LEDS_setGreen(uint8_t value){
	OCR1B = 255 - value;
	green = value;
}

void LEDS_setBlue(uint8_t value){
	OCR1A = 255 - value;
	blue = value;
}

uint8_t LEDS_getRed(){
	return red;
}

uint8_t LEDS_getGreen(){
	return red;
}

uint8_t LEDS_getBlue(){
	return red;
}

void LEDS_setFinalRed(uint8_t value){
	final_red = value;
}

void LEDS_setFinalGreen(uint8_t value){
	final_green = value;
}

void LEDS_setFinalBlue(uint8_t value){
	final_blue = value;
}

void LEDS_setFinalRGB(uint8_t valueR, uint8_t valueG, uint8_t valueB){
	final_red = valueR;
	final_green = valueG;
	final_blue = valueB;
}


