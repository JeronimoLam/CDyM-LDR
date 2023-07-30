#include "led.h"
#define STEPS 10

static uint8_t final_red = 0;
static uint8_t final_green = 0;
static uint8_t final_blue = 0;

static uint8_t red = 0;
static uint8_t green = 0;
static uint8_t blue = 0;

static uint8_t red_increments [STEPS] ;
static uint8_t green_increments [STEPS];
static uint8_t blue_increments [STEPS];

void LEDS_init(){
	//PIN 1, 2 y 5 como salida
	DDRB |= (1<<PORTB1) | (1<<PORTB2) | (1<<PORTB5);
	PORTB |= (1 << PINB5);
	
	LEDS_setRed(0);
	LEDS_setGreen(0);
	LEDS_setBlue(0);
	
	for (uint8_t i = 0; i < STEPS; i++){
		red_increments[i] = 0;
		green_increments[i] = 0;
		blue_increments[i] = 0;
	}
}

void distributeValues(uint8_t inputR, uint8_t inputG, uint8_t inputB) {
	uint8_t baseR = inputR / STEPS;
	uint8_t remainderR = inputR % STEPS;

	uint8_t baseG = inputG / STEPS;
	uint8_t remainderG = inputG % STEPS;
	
	uint8_t baseB = inputB / STEPS;
	uint8_t remainderB = inputB % STEPS;

	// Distribute the base value and the remainder for each array
	for (uint8_t i = 0; i < STEPS; i++) {
		red_increments[i] = (i < remainderR) ? baseR + 1 : baseR;
		green_increments[i] = (i < remainderG) ? baseG + 1 : baseG;
		blue_increments[i] = (i < remainderB) ? baseB + 1 : baseB;
	}
}

void LEDS_setRed(uint8_t value){
	PWM_set_comp_value(value);
	red = value;
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
	return green;
}

uint8_t LEDS_getBlue(){
	return blue;
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

uint8_t LEDS_getFinalRed(){
	return final_red;
}

uint8_t LEDS_getFinalGreen(){
	return final_green;
}

uint8_t LEDS_getFinalBlue(){
	return final_blue;
}

void LEDS_setFinalRGB(uint8_t valueR, uint8_t valueG, uint8_t valueB){
	final_red = valueR;
	final_green = valueG;
	final_blue = valueB;
	distributeValues(valueR, valueG, valueB);
}

void LEDS_incrementRed(uint16_t value){
	LEDS_setRed(LEDS_getRed() + red_increments[value]);
}

void LEDS_incrementGreen(uint16_t value){
	LEDS_setGreen(LEDS_getGreen() + green_increments[value]);
	
}

void LEDS_incrementBlue(uint16_t value){
	LEDS_setBlue(LEDS_getBlue() + blue_increments[value]);
}

void LEDS_decrementRed(uint16_t value){
	LEDS_setRed(LEDS_getRed() - red_increments[9 - value]);
}

void LEDS_decrementGreen(uint16_t value){
	LEDS_setGreen(LEDS_getGreen() - green_increments[9 - value]);
}

void LEDS_decrementBlue(uint16_t value){
	LEDS_setBlue(LEDS_getBlue() - blue_increments[9 - value]);
}



