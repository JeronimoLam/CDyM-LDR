#ifndef SEOS_H_
#define SEOS_H_
	#include <avr/io.h>
	#include <stdio.h>
	#include "../Leds/led.h"


	void sEOS_Dispatch_Tasks();
	void sEOS_Go_To_Sleep();
	void sEOS_SCH_Tasks();

#endif /* SEOS_H_ */