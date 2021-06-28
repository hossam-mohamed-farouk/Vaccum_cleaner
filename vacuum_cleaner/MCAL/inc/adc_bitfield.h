/*
 * adc_bitfield.h
 *
 * Created: 5/31/2020 1:12:20 PM
 *  Author: H
 */ 


#ifndef ADC_BITFIELD_H_
#define ADC_BITFIELD_H_

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <util/delay.h>
#include "avr/io.h"
#include "data_types.h"
#include "bit_handle.h"

/*
	_BFD -> Bitfield decl
	_BF	-> Bitfield
	_B	->Bit
*/
typedef struct  
{
	U_8 MUX			:5;
	U_8 ADLAR_B		:1;
	U_8 REFS		:2;
}ADCMUX_BFD;

typedef struct
{
	U_8 ADPS		:3;
	U_8 ADIE_B		:1;
	U_8 ADIF_B		:1;
	U_8 ADFR_B		:1;
	U_8 ADSC_B		:1;
	U_8 ADEN_B		:1;
}ADCSRA_BFD;

typedef struct
{
	U_16			ADC_DATA;
	ADCSRA_BFD		ADCSRA_BF;
	ADCMUX_BFD		ADCMUX_BF;
}ADC_STRUCT_BFD;

#define ADC_STRUCT	(((volatile ADC_STRUCT_BFD*)(0x24)))	//(*((volatile ADC_STRUCT_BFD*)(0x24)))    . not ->
/*#define	ADC_Data_LR	(((volatile INT8U*)(0x24)))#define	ADC_Data_HR	(((volatile INT8U*)(0x25)))#define	ADC_Data_R	(((volatile INT16U*)(0x24)))#define	ADC_Data_R	(((volatile INT16U*)(0x24)))#define	ADCMUX_BFR	(((volatile ADCMUX_BFD*)(0x27)))#define	ADCSRA_BFR	(((volatile ADCSRA_BFD*)(0x26)))
*/


void adc_b_init(void);  /*selects Avcc as the reference voltage, it enables the ADC hardware*/

U_16 adc_b_read(U_8 adc_channel);		/*selects the ADC channel source based on user input, 
									then starts the conversion and waits for conversion to be completed,
									prepare and return the ADC value to the user*/




#endif /* ADC_BITFIELD_H_ */