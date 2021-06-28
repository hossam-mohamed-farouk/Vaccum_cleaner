/*
* board.h
*
* Created: 5/20/2020 12:51:41 PM
*  Author: H
*/


#ifndef BOARD_H_
#define BOARD_H_

/*
Single LED : PB4
8-LEDs	   : PA0-7 -> Enable latch PF1 (Active High)
Buttons	   : PD0-1 -> (Active Low)
Buzzer	   : PE7   -> (Active High)
*/
#include "avr/io.h"
#include "data_types.h"
#include "bit_handle.h"

//#define PORTA_R			(*((volatile U_8*)(0x3B))) //= PORTA

//Single LED config
#define LED_PORT		PORTB
#define LED_DDR			DDRB
#define LED_PIN			PB4
//LEDS config
#define LEDS_PORT		PORTA
#define LEDS_DDR		DDRA
/*New with kit For leds enable*/
#define LEDS_EN_PORT	PORTF
#define LEDS_EN_DDR		DDRA
#define LEDS_EN_PIN		PF1		/*Active high*/



//Buzzer config
#define BUZ_PORT		PORTE
#define BUZ_DDR			DDRE
#define BUZ_PIN			PE7
//Buttons config
#define BTN_PORT		PORTD
#define BTN_DDR			DDRD
#define BTN_PIN			PIND
typedef enum
{
	BTN0,BTN1
}Button;
typedef enum
{
	IN_STATE_NONE, IN_STATE_PULLUP
}In_state;

//LED APIs
void led_init(void);
void led_on(void);
void led_off(void);
void led_toggle(void);
//LEDS APIs
void leds_init(U_8 u8leds);
void leds_on(U_8 u8leds);
void leds_off(U_8 u8leds);
void leds_toggle(U_8 u8leds);
//Buzzer APIs
void buz_init(void);
void buz_on(void);
void buz_off(void);
void buz_toggle(void);
//Button APIs
void btn_init(Button btn,In_state btn_in_state);
Bool btn_is_pressed(Button btn);



#endif /* BOARD_H_ */