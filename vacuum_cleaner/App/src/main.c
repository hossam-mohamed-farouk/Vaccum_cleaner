/*
 * vacuum_cleaner.c
 *
 * Created: 4/18/2021 4:10:03 AM
 * Author : Hossam Mohamed
 */ 

#include <avr/io.h>
#include "vacuum_cleaner.h"

int main(void)
{
    /* Replace with your application code */
	sei();
	//clear_bit(DDRD,0);
	//clear_bit(DDRD,1);
	//clear_bit(DDRD,2);
	
	set_bit(PORTD,0);
	set_bit(PORTD,1);
	set_bit(PORTD,2);

	vacuum_cleaner_init();
	
    while (1) 
    {
		vacuum_cleaner_start();
    }
}

