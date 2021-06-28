/*
 * timer.c
 *
 * Created: 6/2/2020 11:02:31 AM
 *  Author: H
 */ 
#include "timer.h"

volatile static U_32 over_flows = 0;
volatile static U_32 calc_over_flows = 0;
volatile static U_8 noti_mode = 0;
static void (*volatile notifier)(void);
volatile static U_32 notifier_time = 0;

void timer0_init(U_8 timer_mode)
{
	timer0_stop();
	switch(timer_mode)
	{
		case MODE_NORMAL:
		clear_bit(TCCR0,WGM00);
		clear_bit(TCCR0,WGM01);
		set_bit(TIMSK,TOIE0);		//Enable ovf int
		break;
		case MODE_CTC:
		clear_bit(TCCR0,WGM00);
		set_bit(TCCR0,WGM01);
		/*Toggle oc0 pin*/
		set_bit(TCCR0,COM00);
		set_bit(TCCR0,COM01);
		break;
		case MODE_FAST_PWM:
		set_bit(TCCR0,WGM00);
		set_bit(TCCR0,WGM01);
		/*Config non_inverting mode*/
		clear_bit(TCCR0,COM00);
		set_bit(TCCR0,COM01);
		break;
		case MODE_PHASE_PWM:
		set_bit(TCCR0,WGM00);
		clear_bit(TCCR0,WGM01);
		/*Config non_inverting mode*/
		clear_bit(TCCR0,COM00);
		set_bit(TCCR0,COM01);
		break;
	}
}
void timer0_start(void)
{
	/*Clock select*/// CLK / 8     ->   clear-set-clear
	/*Clock select*/// CLK / 1024  ->   set-set-set
	clear_bit(TCCR0,CS00);
	set_bit(TCCR0,CS01);
	clear_bit(TCCR0,CS02);
}
void timer0_stop(void)
{
	clear_bit(TCCR0,CS00);
	clear_bit(TCCR0,CS01);
	clear_bit(TCCR0,CS02);
}
void timer0_reset_counters(void)
{
	TCNT0 = 0;
	over_flows = 0;
}

void timer0_delay_us(U_32 delay_us)
{
	timer0_reset_counters();
	timer0_start();
	while( (delay_us) > (TCNT0 + over_flows * 256 + 1) );
	
}
void timer0_delay_ms(U_32 delay_ms)
{
	timer0_reset_counters();
	timer0_start();
	while( (delay_ms * 1000UL) > (TCNT0 + over_flows * 256 + 1) );
}
/* duty in range 0 : 100 */
void timer0_set_duty(U_8 duty)
{
	OCR0 = (duty * 255)/100 ; //(duty/100.0) * (255)
}
void timer0_inc_duty(U_8 inc_duty)
{
	if ((OCR0 + (inc_duty*255UL)/100) <= 255)
	{
		OCR0 += (inc_duty*255UL)/100;
	}
	else
	{
		OCR0 = 255;
	}
}
void timer0_dec_duty(U_8 dec_duty)
{
	if ((OCR0 >=  (dec_duty*255UL)/100))	//(OCR0 - (dec_duty*255UL)/100) >= 0 -> Errors with unsigned
	{
		OCR0 -= (dec_duty*255UL)/100;
	}
	else
	{
		OCR0 = 0;
	}
}
/*notify_delay in ms*/
void timer0_set_notification(void (*ptr_fun)(void),U_32 notify_delay,U_8 timer_noti_mode)
{
	notifier = ptr_fun;
	notifier_time = notify_delay;
	noti_mode = timer_noti_mode;
	timer0_reset_counters();
	//calc counters
	TCNT0 = 256 - ((notify_delay * 1000)%256 - 1);
	calc_over_flows = (notify_delay * 1000)/256 +1;
	timer0_start();
}

ISR(TIMER0_OVF_vect)
{
	over_flows ++;
	
	if(over_flows == calc_over_flows)
	{
		if(noti_mode == NOTIFY_ONES)
		{
			notifier();
			timer0_stop();
		}
		else if(noti_mode == NOTIFY_CONTINUOUS)
		{
			notifier();
			over_flows = 0;
			TCNT0 = 256 - ((notifier_time * 1000)%256 - 1);
		}	
	}
}