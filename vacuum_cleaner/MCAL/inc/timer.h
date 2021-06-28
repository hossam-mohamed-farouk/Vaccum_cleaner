/*
 * timer.h
 *
 * Created: 6/2/2020 11:00:52 AM
 *  Author: H
 */ 


#ifndef TIMER_H_
#define TIMER_H_
/***This module using Timer_0***/
#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <util/delay.h>
#include "avr/interrupt.h"
#include "avr/io.h"
#include "data_types.h"
#include "bit_handle.h"

/*Timer_0 modes*/
#define MODE_NORMAL				0
#define MODE_CTC				1
#define MODE_FAST_PWM			2
#define MODE_PHASE_PWM			3
/*Timer notifier modes*/
#define NOTIFY_ONES				0
#define NOTIFY_CONTINUOUS		1



void timer0_init(U_8 timer_mode);
void timer0_start(void);
void timer0_stop(void);
void timer0_reset_counters(void);

void timer0_delay_us(U_32 delay_us);
void timer0_delay_ms(U_32 delay_ms);
/*duty in range 0:100*/
void timer0_set_duty(U_8 duty);
void timer0_inc_duty(U_8 inc_duty);
void timer0_dec_duty(U_8 dec_duty);
/*notify_delay in ms*/
void timer0_set_notification(void (*ptr_fun)(void),U_32 notify_delay,U_8 timer_noti_mode);		//Asynchronous function


#endif /* TIMER_H_ */