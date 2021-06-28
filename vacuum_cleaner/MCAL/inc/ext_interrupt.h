/*
 * ext_interrupt.h
 *
 * Created: 6/1/2020 2:35:35 PM
 *  Author: H
 */ 


#ifndef EXT_INTERRUPT_H_
#define EXT_INTERRUPT_H_

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <util/delay.h>
#include "avr/interrupt.h"
#include "avr/io.h"
#include "data_types.h"
#include "bit_handle.h"

typedef enum
{
	INT_NUM_0,INT_NUM_1,INT_NUM_2,INT_NUM_3
	
}INT_NUM;

typedef enum
{
	INT_SENSE_FALLING,INT_SENSE_RISING
	
}INT_SENSE;

void ext_enable(INT_NUM int_num,INT_SENSE int_sense_ctrl);
void ext_disable(INT_NUM int_num);
void ext_call_setup(INT_NUM int_num,void (*ptr_fun)(void));


#endif /* EXT_INTERRUPT_H_ */