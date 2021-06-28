/*
 * board.c
 *
 * Created: 5/20/2020 12:51:58 PM
 *  Author: H
 */ 
#include "board.h"

void led_init(void)
{
	/*OUT*/
	set_bit(LED_DDR,LED_PIN);
	/*OFF*/
	led_off();
}
void led_on(void)
{
	/*HIGH*/
	set_bit(LED_PORT,LED_PIN);
}
void led_off(void)
{
	/*LOW*/
	clear_bit(LED_PORT,LED_PIN);
}
void led_toggle(void)
{
	/*TOGGLE*/
	toggle_bit(LED_PORT,LED_PIN);
}
void leds_init(U_8 u8leds)
{
	/*Leds EN new*/
	//set_bit(LEDS_EN_DDR,LEDS_EN_PIN);
	//set_bit(LEDS_EN_PORT,LEDS_EN_PIN);
	/*----------------------------------*/
	
	/*OUT*/
	set_bits(LEDS_DDR,u8leds);
	/*OFF*/
	leds_off(u8leds);
}
void leds_on(U_8 u8leds)
{
	/*HIGH*/
	set_bits(LEDS_PORT,u8leds);
}
void leds_off(U_8 u8leds)
{
	/*LOW*/
	clear_bits(LEDS_PORT,u8leds);
}
void leds_toggle(U_8 u8leds)
{
	/*TOGGLE*/
	toggle_bits(LEDS_PORT,0xff);
}
void buz_init(void)
{
	/*OUT*/
	set_bit(BUZ_DDR,BUZ_PIN);
	/*OFF*/
	buz_off();
}
void buz_on(void)
{
	/*HIGH*/
	set_bit(BUZ_PORT,BUZ_PIN);
}
void buz_off(void)
{
	/*LOW*/
	clear_bit(BUZ_PORT,BUZ_PIN);
}
void buz_toggle(void)
{
	/*TOGGLE*/
	toggle_bit(BUZ_PORT,BUZ_PIN);
}
void btn_init(Button btn,In_state btn_in_state)
{
	/*IN*/
	clear_bit(BTN_DDR,btn);
	/*ACTIVE PULLUP*/
	switch(btn_in_state)
	{
		case  IN_STATE_NONE:
		clear_bit(BTN_PORT,btn);
		break;
		case IN_STATE_PULLUP:
		set_bit(BTN_PORT,btn);
		break;
		default:
		//default
		break;
	}
}
Bool btn_is_pressed(Button btn)
{
	return (!read_bit(BTN_PIN,btn));
}

