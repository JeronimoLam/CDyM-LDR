#ifndef MEF_H_
#define MEF_H_
	#include <avr/io.h>
	#include <math.h>
	#include "../Leds/led.h"
	#include "../LDR/ldr.h"
	
	#define MIN_INF_LDR 0	// Valor minimo tapando con el dedo
	#define MAX_INF_LDR 110	// Valor maximo tapando con el dedo
	
	#define MIN_SUP_LDR 300 // Valor minimo en luz ambiente
	#define MAX_SUP_LDR 800	// Valor maximo alumbrando con el celular

	void MEF_init();
	void MEF_Update();

#endif