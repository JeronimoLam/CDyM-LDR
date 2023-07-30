/*
 * ldr.h
 *
 * Created: 7/14/2023 12:41:34 AM
 *  Author: franc
 */ 


#ifndef LDR_H_
	
	#include <avr/io.h>

	void LDR_config();
	void LDR_Update();
	uint16_t LDR_get_value();

#define LDR_H_





#endif /* LDR_H_ */