/*
 * lm_35.h
 *
 * Created: 5/31/2020 11:54:54 PM
 *  Author: H
 */ 


#ifndef LM_35_H_
#define LM_35_H_

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <util/delay.h>
#include "avr/io.h"
#include "data_types.h"
#include "bit_handle.h"
#include "adc_bitfield.h"

void   temp_sens_init(void);
FP_64  temperature_c(U_8 temp_sens_channel);
FP_64  temperature_f(U_8 temp_sens_channel);



#endif /* LM_35_H_ */