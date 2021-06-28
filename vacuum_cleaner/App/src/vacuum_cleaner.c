/*
 * vacuum_cleaner.c
 *
 * Created: 4/18/2021 5:01:50 AM
 *  Author: Hossam Mohamed
 */ 

#include "vacuum_cleaner.h"

static volatile vacuum_cleaner_states vacuum_cleaner_state = VC_STOP;
static volatile vacuum_cleaner_states last_vacuum_cleaner_state = VC_MID_SPEED;
static volatile U_16 flag=0, VC_temp = 0, c=0;

static void start_stop_btn_cb(void);
static void increase_speed_btn_cb(void);
static void decrease_speed_btn_cb(void);
static void p_btn_cb(void);
static void p_btn_handle_cb(void);

void vacuum_cleaner_init(void)
{
	/*Initiate the Motor driver and it will initiate the Timer_3 in PWM mode*/
	motor_init();
	/*Initiate the temp sensor*/
	temp_sens_init();
	/*Timer_3 initiated in Motor control module*/
	/*Config the ICU*/
	/*ICP3 Input and pulled up*/
	clear_bit(DDRE, PE7);
	set_bit(PORTE, PE7);
	/*Set the ICU edge and call back functions*/
	Timer3_InputCaptureEdge(FALLING);
	Timer3_ICU_SetCallBack(p_btn_cb);
	Timer3_OVF_SetCallBack(p_btn_handle_cb);
	Timer3_ICU_InterruptEnable();
	/*Config the External interrupts for vacuum btns*/
	ext_enable(START_STOP_BTN, INT_SENSE_FALLING);
	ext_enable(INCREASE_SPEED_BTN, INT_SENSE_FALLING);
	ext_enable(DECREASE_SPEED_BTN, INT_SENSE_FALLING);
	/*Config the External interrupts call backs*/
	ext_call_setup(START_STOP_BTN, start_stop_btn_cb);
	ext_call_setup(INCREASE_SPEED_BTN, increase_speed_btn_cb);
	ext_call_setup(DECREASE_SPEED_BTN, decrease_speed_btn_cb);
}

void vacuum_cleaner_start(void)
{
	VC_temp = temperature_c(TEMP_SENS_CHANEEL);
	if ((VC_temp > VC_MAX_TEMP) && (last_vacuum_cleaner_state != VC_STOP))
	{
		vacuum_cleaner_state = VC_STOP;
		last_vacuum_cleaner_state = VC_STOP;
	} 
	else
	{
		last_vacuum_cleaner_state = vacuum_cleaner_state;
		switch(vacuum_cleaner_state)
		{
			case VC_STOP:
			motor_stop();
			break;
			case VC_MIN_SPEED:
			motor_forward();
			motors_speed_select(40);
			break;
			case VC_MID_SPEED:
			motor_forward();
			motors_speed_select(70);
			break;
			case VC_MAX_SPEED:
			motor_forward();
			motors_speed_select(100);
			break;
		}
	}
}

static void start_stop_btn_cb(void)
{
	if (vacuum_cleaner_state == VC_STOP)
	{
		VC_temp = 0;
		vacuum_cleaner_state = VC_MID_SPEED;
	}
	else 
	{
		VC_temp = 0;
		vacuum_cleaner_state = VC_STOP;
	}
}

static void increase_speed_btn_cb(void)
{
	if (vacuum_cleaner_state == VC_MIN_SPEED)
	{
		vacuum_cleaner_state = VC_MID_SPEED;
	} 
	else if (vacuum_cleaner_state == VC_MID_SPEED)
	{
		vacuum_cleaner_state = VC_MAX_SPEED;
	}
	else
	{
		//Do nothing
	}
}

static void decrease_speed_btn_cb(void)
{
	if (vacuum_cleaner_state == VC_MAX_SPEED)
	{
		vacuum_cleaner_state = VC_MID_SPEED;
	}
	else if (vacuum_cleaner_state == VC_MID_SPEED)
	{
		vacuum_cleaner_state = VC_MIN_SPEED;
	}
	else
	{
		//Do nothing
	}
}

void p_btn_cb(void)
{	
	if (flag == 0)
	{
		c=0;
		Timer3_OVF_InterruptEnable();
		Timer3_InputCaptureEdge(RISING);
		flag = 1;
	}
	else if (flag == 1)
	{
		flag = 0;
		Timer3_OVF_InterruptDisable();
		Timer3_InputCaptureEdge(FALLING);
	}		
}

static void p_btn_handle_cb(void)
{
	c++;
	if (c == P_BTN_TIME)
	{
		if (!read_bit(DDRE, PE7))
		{
			toggle_bit(PORTC, PC0);
			if (vacuum_cleaner_state == VC_MAX_SPEED)
			{
				vacuum_cleaner_state = VC_MID_SPEED;
			}
			else if (vacuum_cleaner_state == VC_MID_SPEED)
			{
				vacuum_cleaner_state = VC_MIN_SPEED;
			}
			else
			{
				//Do nothing
			}
		}
		else
		{
			Timer3_OVF_InterruptDisable();
			c = 0;
		}
	}
}