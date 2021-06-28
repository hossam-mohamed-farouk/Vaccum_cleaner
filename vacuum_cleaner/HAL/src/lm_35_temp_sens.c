/*
 * lm_35.c
 *
 * Created: 5/31/2020 11:55:17 PM
 *  Author: H
 */ 

#include "lm_35_temp_sens.h"


void   temp_sens_init(void)
{
	adc_b_init();
}

FP_64 temperature_c(U_8 temp_sens_channel)
{
	U_16 adc_val = 0;
	adc_val = adc_b_read(temp_sens_channel);
	/*Convert back from digits to volt*/
	FP_64 voltage = (adc_val * 5.0) / 1024;
	/*Each 10 mv -> 1C*/
	return (voltage / 0.01);
}

FP_64 temperature_f(U_8 temp_sens_channel)
{
	return ((temperature_c(temp_sens_channel)) * 9.0 / 5.0) + 32.0;
}
