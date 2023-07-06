#include "MEF.h"

void MEF_init(){
	
}

void MEF_Update(){
	PORTB ^= (1<<PORTB4);
}
