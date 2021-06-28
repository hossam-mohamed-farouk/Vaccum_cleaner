/*
 * motor_control.c
 *
 * Created: 4/18/2021 4:59:32 AM
 *  Author: Hossam Mohamed
 */ 

#include "motor_control.h"

void motor_init(void)
{
	set_bit(MOTOR_DDR, MOTOR_PIN1);
	set_bit(MOTOR_DDR, MOTOR_PIN2);
	//SET OC0 AS OUPUT PIN
	//set_bit(DDRB, PB4);
	set_bit(DDRE, PE4);		
	//PWM INIT
	//Timer0_Init(TIMER0_PHASECORRECT_MODE,TIMER0_SCALER_8,OCO_NON_INVERTING);
	Timer3_Init(TIMER3_FASTPWM_OCRA_TOP_MODE, TIMER3_SCALER_8, OCR3A_DISCONNECTED, OCR3B_NON_INVERTING);
	OCR3A = 65535;
	motor_stop();
}

void motor_forward(void)
{
	set_bit(MOTOR_PORT, MOTOR_PIN1);
	clear_bit(MOTOR_PORT, MOTOR_PIN2);
}

void motor_reverse(void)
{
	clear_bit(MOTOR_PORT, MOTOR_PIN1);
	set_bit(MOTOR_PORT, MOTOR_PIN2);
}

void motor_stop(void)
{
	motors_speed_select(0);
	clear_bit(MOTOR_PORT, MOTOR_PIN1);
	clear_bit(MOTOR_PORT, MOTOR_PIN2);
}

void motors_speed_select(U_8 speed_rate)
{
	if ((speed_rate >= MIN_SPEED_RATE) && (speed_rate <= MAX_SPEED_RATE))
	{
		OCR3B = speed_rate * MAX_SPEED / MAX_SPEED_RATE;
	}
	else if (speed_rate < MIN_SPEED_RATE)
	{
		OCR3B = MIN_SPEED_RATE * MAX_SPEED / MAX_SPEED_RATE;
	}
	else
	{
		OCR3B = MAX_SPEED_RATE * MAX_SPEED / MAX_SPEED_RATE;
	}
}

//void motors_speed_select(U_8 speed_rate)
//{
	//if ((speed_rate >= MIN_SPEED_RATE) && (speed_rate <= MAX_SPEED_RATE))
	//{
		//OCR0 = speed_rate * MAX_SPEED / MAX_SPEED_RATE;
	//}
	//else if (speed_rate < MIN_SPEED_RATE)
	//{
		//OCR0 = MIN_SPEED_RATE * MAX_SPEED / MAX_SPEED_RATE;
	//}
	//else
	//{
		//OCR0 = MAX_SPEED_RATE * MAX_SPEED / MAX_SPEED_RATE;
	//}
//}

