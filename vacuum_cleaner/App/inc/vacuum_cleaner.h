/*
 * vacuum_cleaner.h
 *
 * Created: 4/18/2021 5:01:38 AM
 *  Author: Hossam Mohamed
 */ 


#ifndef VACUUM_CLEANER_H_
#define VACUUM_CLEANER_H_

#include "board.h"
#include "data_types.h"
#include "bit_handle.h"
#include "ext_interrupt.h"
#include "Timers.h"
#include "motor_control.h"
#include "lm_35_temp_sens.h"

/************************************************************************************************************************/
/***********This project simulate a vacuum cleaner system and it's a state machie designed system************************/
/*There are 4 Btns for control start stop btn, speed increase btn, speed decrease btn, and speed decrease btn if pressed*/
/*for 30 seconds. The vacuum cleaner has three speeds the default speed is the middle speed. The vacuum cleaner has     */
/*************a safety mechanism if it's temperature reach the threshold degree it will stop immediately*****************/
/************************************************************************************************************************/

typedef enum
{
	VC_STOP,
	VC_MIN_SPEED,
	VC_MID_SPEED,
	VC_MAX_SPEED	
}vacuum_cleaner_states;

#define START_STOP_BTN		INT_NUM_0
#define INCREASE_SPEED_BTN	INT_NUM_1
#define DECREASE_SPEED_BTN	INT_NUM_2

#define VC_MAX_TEMP			50
#define P_BTN_TIME			76			//475 for 30 sec  //76 for 5 sec
#define TEMP_SENS_CHANEEL	0

void vacuum_cleaner_init(void);
void vacuum_cleaner_start(void);



#endif /* VACUUM_CLEANER_H_ */