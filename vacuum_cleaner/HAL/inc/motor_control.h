/*
 * motor_control.h
 *
 * Created: 4/18/2021 4:59:17 AM
 *  Author: Hossam Mohamed
 */ 


#ifndef MOTOR_CONTROL_H_
#define MOTOR_CONTROL_H_

#include "Timers.h"

#define MOTOR_DDR	DDRA
#define MOTOR_PORT	PORTA
#define MOTOR_PIN1	0
#define MOTOR_PIN2	1

#define MAX_SPEED		65535	  //65535 //255
#define MAX_SPEED_RATE  100
#define MIN_SPEED_RATE	0

void motor_init(void);
void motor_forward(void);
void motor_reverse(void);
void motor_stop(void);
void motors_speed_select(U_8 speed_rate);


#endif /* MOTOR_CONTROL_H_ */