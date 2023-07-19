#ifndef MEF_H_
#define MEF_H_
	#include <avr/io.h>
	#include <math.h>
	#include "../Leds/led.h"
	
	#define MIN_INF_LDR 50	// Valor minimo tapando con el dedo
	#define MAX_INF_LDR 150	// Valor maximo tapando con el dedo
	
	#define MIN_SUP_LDR 200 // Valor minimo en luz ambiente
	#define MAX_SUP_LDR 800	// Valor maximo alumbrando con el celular

	void MEF_init();
	void MEF_Update();

#endif