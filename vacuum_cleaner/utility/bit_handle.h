/*
 * bit_handle.h
 *
 * Created: 5/20/2020 11:10:51 AM
 *  Author: H
 */ 


#ifndef BIT_HANDLE_H_
#define BIT_HANDLE_H_

/*Set, Clear, and Toggle a bit*/ //R:register N:bit_number
#define set_bit(R,N)			R |=  (1<<(N))
#define clear_bit(R,N)			R &= ~(1<<(N))
#define toggle_bit(R,N)			R ^=  (1<<(N))

/*Set, Clear, and Toggle group of bits*/ //R:register M:Mask
#define set_bits(R,M)			R |=  (M)
#define clear_bits(R,M)			R &= ~(M)
#define toggle_bits(R,M)		R ^=  (M)

/*Set, Clear and Toggle all bits*/ //R:register
#define set_all_bits(R)			R =   (0xff)
#define clear_all_bits(R)		R =   (0x00)
#define toggle_all_bits(R)		R ^=  (0xff)

/*Read bit*/
#define  read_bit(R,N)			((R>>(N)) & 1)



#endif /* BIT_HANDLE_H_ */