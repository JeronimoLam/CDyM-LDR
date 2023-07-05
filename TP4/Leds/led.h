#ifndef LED_H_
#define LED_H_

	#include <avr/io.h>
	
	void LEDS_init();
	
	void LEDS_setRed(uint8_t);
	void LEDS_setGreen(uint8_t);
	void LEDS_setBlue(uint8_t);
	uint8_t LEDS_getRed();
	uint8_t LEDS_getGreen();
	uint8_t LEDS_getBlue();
	void LEDS_setFinalRed(uint8_t);
	void LEDS_setFinalGreen(uint8_t);
	void LEDS_setFinalBlue(uint8_t);
	void LEDS_setFinalRGB(uint8_t, uint8_t, uint8_t);
	
#endif /* LED_H_ */