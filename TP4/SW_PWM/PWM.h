/*
 * PWM.h
 *
 * Created: 7/15/2023 2:29:45 AM
 *  Author: Jero
 */ 


#ifndef PWM_H_
#define PWM_H_

	#include <stdio.h>
	#include <stdlib.h>
	#include <avr/io.h>

	void PWM_soft_Update();
	void PWM_soft_init();
	void PWM_set_comp_value(uint8_t);


#endif /* PWM_H_ */