/*
 * attiny13.c
 *
 * Created: 06-Dec-17 12:46:54 PM
 * Author : Ahmed Deep
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>

#include <util/delay.h>
uint8_t inputTemp=0;

int main(void)
{
	DDRB = 0b0111111 ; 

    
    while (1) 
    {
		
		inputTemp = PINB & 0x01 ;
	if (inputTemp ==0x00)
		{
			PORTB |= (1<<PB2);
			/*PORTD |= (1<<PD7);*/
			_delay_ms(111);
		}
		else
		{
			PORTB |=~ (1<<PB2);
			_delay_ms(111);
			/*PORTD &=~ (1<<PD7);*/
		}

    }
}
