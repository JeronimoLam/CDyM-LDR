#ifndef LED_H_
#define LED_H_

	#include <avr/io.h>
	#include "../SW_PWM/PWM.h"
	
	void LEDS_init();
	
	void LEDS_setRed(uint8_t);
	void LEDS_setGreen(uint8_t);
	void LEDS_setBlue(uint8_t);
	void LEDS_setFinalRGB(uint8_t, uint8_t, uint8_t);
	
	uint8_t LEDS_getRed();
	uint8_t LEDS_getGreen();
	uint8_t LEDS_getBlue();
	uint8_t LEDS_getFinalRed();
	uint8_t LEDS_getFinalGreen();
	uint8_t LEDS_getFinalBlue();
	
	void LEDS_incrementRed(uint16_t);
	void LEDS_incrementGreen(uint16_t);
	void LEDS_incrementBlue(uint16_t);
	
	void LEDS_decrementRed(uint16_t);
	void LEDS_decrementGreen(uint16_t);
	void LEDS_decrementBlue(uint16_t);
	
#endif /* LED_H_ */