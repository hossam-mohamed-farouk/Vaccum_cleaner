/*
 * ext_interrupt.c
 *
 * Created: 6/1/2020 2:35:47 PM
 *  Author: H
 */ 
#include "ext_interrupt.h"

static void (*call_list[4])(void);

/*
void ext_enable(INT_NUM int_num,INT_SENSE int_sense_ctrl)
{
	switch(int_num)
	{
		case INT_NUM_0:
			switch(int_sense_ctrl)
			{
				case  INT_SENSE_FALLING:
					set_bit(EICRA,ISC01);
					clear_bit(EICRA,ISC00);
				break;
				case  INT_SENSE_RISING:
					set_bit(EICRA,ISC00);
					set_bit(EICRA,ISC01);
				break;
			}
			
		break;
		case INT_NUM_1:
			switch(int_sense_ctrl)
			{
				case  INT_SENSE_FALLING:
					set_bit(EICRA,ISC11);
					clear_bit(EICRA,ISC10);
				break;
				case  INT_SENSE_RISING:
					set_bit(EICRA,ISC11);
					set_bit(EICRA,ISC10);
				break;
			}
		
		break;
		case INT_NUM_2:
			switch(int_sense_ctrl)
			{
				case  INT_SENSE_FALLING:
					set_bit(EICRA,ISC21);
					clear_bit(EICRA,ISC20);
				break;
				case  INT_SENSE_RISING:
					set_bit(EICRA,ISC20);
					set_bit(EICRA,ISC21);
				break;
			}
		
		break;
		case INT_NUM_3:
			switch(int_sense_ctrl)
			{
				case  INT_SENSE_FALLING:
					set_bit(EICRA,ISC31);
					clear_bit(EICRA,ISC30);
				break;
				case  INT_SENSE_RISING:
					set_bit(EICRA,ISC30);
					set_bit(EICRA,ISC31);
				break;
			}
		break;
	}
	set_bit(EIMSK,int_num); //Enable
	//sei();				//Enable global int
}
*/
void ext_enable(INT_NUM int_num,INT_SENSE int_sense_ctrl)
{
	
	switch(int_sense_ctrl)
	{
		case  INT_SENSE_FALLING:
		clear_bit(EICRA,(int_num * 2));
		break;
		case  INT_SENSE_RISING:
		set_bit(EICRA,(int_num * 2));
		break;
	}
	set_bit(EICRA,(int_num * 2 + 1));
	set_bit(EIMSK,int_num);		//Enable
	//sei();					//Enable global int let to user
}

void ext_disable(INT_NUM int_num)
{
	clear_bit(EIMSK,int_num);
}

void ext_call_setup(INT_NUM int_num,void (*ptr_fun)(void))
{
	call_list[int_num] = ptr_fun; 
}



ISR(INT0_vect)
{
	call_list[INT_NUM_0]();
}
ISR(INT1_vect)
{
	call_list[INT_NUM_1]();
}
ISR(INT2_vect)
{
	call_list[INT_NUM_2]();
}
ISR(INT3_vect)
{
	call_list[INT_NUM_3]();
}