/*
 * adc_bitfield.c
 *
 * Created: 5/31/2020 1:12:47 PM
 *  Author: H
 */ 

#include "adc_bitfield.h"


void adc_b_init(void)
{
	/*Clock*/
	ADC_STRUCT->ADCSRA_BF.ADPS = 0b111;
	/*Ref -> AVcc*/
	ADC_STRUCT->ADCMUX_BF.REFS = 0b01;
	/*Enable*/
	ADC_STRUCT->ADCSRA_BF.ADEN_B = 1;
}

U_16 adc_b_read(U_8 adc_channel)
{
	/*Select channel*/
	ADC_STRUCT->ADCMUX_BF.MUX = adc_channel;
	/*Start conversion*/
	ADC_STRUCT->ADCSRA_BF.ADSC_B = 1;
	/*Wait until conversion complete*/
	while(ADC_STRUCT->ADCSRA_BF.ADSC_B == 1);
	/*Return ADC data*/
	return ADC_STRUCT->ADC_DATA;
}