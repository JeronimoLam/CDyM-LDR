#ifndef SEOS_H_
#define SEOS_H_
	#include <avr/io.h>
	#include <stdio.h>
	#include <avr/sleep.h>
	#include "../Leds/led.h"
	#include "../MEF/MEF.h"
	#include "../SW_PWM/PWM.h"

	void sEOS_Dispatch_Tasks();
	void sEOS_Go_To_Sleep();
	void sEOS_SCH_Tasks();

#endif /* SEOS_H_ */