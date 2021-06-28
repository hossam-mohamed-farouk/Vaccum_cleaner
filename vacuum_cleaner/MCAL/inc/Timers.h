/*
 * Timers.h
 *
 * Created: 7/3/2020 11:18:33 PM
 *  Author: Hossam Mohamed
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_

#ifndef F_CPU
#define F_CPU	8000000UL
#endif
#ifndef	NULL
#define NULL   ((void*)0)
#endif
#include	"avr/io.h"
#include	"data_types.h"
#include	"bit_handle.h"
#include	"util/delay.h"
#include	"avr/interrupt.h"

/************************************************************************/
/*								Timer 0						            */
/************************************************************************/

/*enum for the mode to be selected in Timer0*/
typedef enum
{
	TIMER0_NORMAL_MODE=0,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE

}Timer0Mode_type;

/*Prescaler for Timer0*/
typedef enum{
	TIMER0_STOP=0,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_32,
	TIMER0_SCALER_64,
	TIMER0_SCALER_128,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024
}Timer0Scaler_type;
/**/
typedef enum
{
	OCO_DISCONNECTED=0,
	OCO_TOGGLE,
	OCO_NON_INVERTING,
	OCO_INVERTING

}OC0Mode_type;



void Timer0_Init( Timer0Mode_type mode,Timer0Scaler_type scaler,OC0Mode_type oc_mode);
void Timer0_OV_InterruptEnable(void);
void Timer0_OV_InterruptDisable(void);
void Timer0_OC_InterruptEnable(void);
void Timer0_OC_InterruptDisable(void);

/************************************************************************/
/*								Timer 1						            */
/************************************************************************/

typedef enum{
	TIMER1_STOP=0,
	TIMER1_SCALER_1,
	TIMER1_SCALER_8,
	TIMER1_SCALER_64,
	TIMER1_SCALER_256,
	TIMER1_SCALER_1024,
	EXTERNAL1_FALLING,
	EXTERNAL1_RISING
}Timer1Scaler_type;

typedef enum
{
	TIMER1_NORMAL_MODE=0,
	TIMER1_CTC_ICR_TOP_MODE,
	TIMER1_CTC_OCRA_TOP_MODE,
	TIMER1_FASTPWM_ICR_TOP_MODE,
	TIMER1_FASTPWM_OCRA_TOP_MODE

}Timer1Mode_type;

typedef enum
{
	OCRA_DISCONNECTED=0,
	OCRA_TOGGLE,
	OCRA_NON_INVERTING,
	OCRA_INVERTING

}OC1A_Mode_type;

typedef enum
{
	OCRB_DISCONNECTED=0,
	OCRB_TOGGLE,
	OCRB_NON_INVERTING,
	OCRB_INVERTING

}OC1B_Mode_type;


typedef enum{
	RISING,
	FALLING
}ICU_Edge_type;




void Timer1_InputCaptureEdge(ICU_Edge_type edge);
void Timer1_Init( Timer1Mode_type mode,Timer1Scaler_type scaler,OC1A_Mode_type oc1a_mode,OC1B_Mode_type oc1b_mode);

void Timer1_ICU_InterruptEnable(void);
void Timer1_ICU_InterruptDisable(void);
void Timer1_OVF_InterruptEnable(void);
void Timer1_OVF_InterruptDisable(void);
void Timer1_OCA_InterruptEnable(void);
void Timer1_OCA_InterruptDisable(void);
void Timer1_OCB_InterruptEnable(void);
void Timer1_OCB_InterruptDisable(void);
void Timer1_OVF_SetCallBack(void(*LocalFptr)(void));
void Timer1_OCA_SetCallBack(void(*LocalFptr)(void));
void Timer1_OCB_SetCallBack(void(*LocalFptr)(void));
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void));



/************************************************************************/
/*								Timer 3						            */
/************************************************************************/

typedef enum{
	TIMER3_STOP=0,
	TIMER3_SCALER_1,
	TIMER3_SCALER_8,
	TIMER3_SCALER_64,
	TIMER3_SCALER_256,
	TIMER3_SCALER_1024,
	EXTERNAL3_FALLING,
	EXTERNAL3_RISING
}Timer3Scaler_type;

typedef enum
{
	TIMER3_NORMAL_MODE=0,
	TIMER3_CTC_ICR_TOP_MODE,
	TIMER3_CTC_OCRA_TOP_MODE,
	TIMER3_FASTPWM_ICR_TOP_MODE,
	TIMER3_FASTPWM_OCRA_TOP_MODE

}Timer3Mode_type;

typedef enum
{
	OCR3A_DISCONNECTED=0,
	OCR3A_TOGGLE,
	OCR3A_NON_INVERTING,
	OCR3A_INVERTING

}OC3A_Mode_type;

typedef enum
{
	OCR3B_DISCONNECTED=0,
	OCR3B_TOGGLE,
	OCR3B_NON_INVERTING,
	OCR3B_INVERTING

}OC3B_Mode_type;

/*//No need, will use it for both timers
typedef enum{
	RISING,
	FALLING
}ICU_Edge_type;
*/

void Timer3_InputCaptureEdge(ICU_Edge_type edge);
void Timer3_Init( Timer3Mode_type mode,Timer3Scaler_type scaler,OC3A_Mode_type oc3a_mode,OC3B_Mode_type oc3b_mode);

void Timer3_ICU_InterruptEnable(void);
void Timer3_ICU_InterruptDisable(void);
void Timer3_OVF_InterruptEnable(void);
void Timer3_OVF_InterruptDisable(void);
void Timer3_OCA_InterruptEnable(void);
void Timer3_OCA_InterruptDisable(void);
void Timer3_OCB_InterruptEnable(void);
void Timer3_OCB_InterruptDisable(void);
void Timer3_OVF_SetCallBack(void(*LocalFptr)(void));
void Timer3_OCA_SetCallBack(void(*LocalFptr)(void));
void Timer3_OCB_SetCallBack(void(*LocalFptr)(void));
void Timer3_ICU_SetCallBack(void(*LocalFptr)(void));



#endif /* TIMERS_H_ */