/*
 * LED_Blinking_8_23Oct2017.c
 *
 * Created: 10/23/2017 9:06:14 AM
 * Author : real
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD = 0xFF;
	while(1)
	{	for (int i=0; i <8; i++)
		{
		PORTD |= (1<<i);
		_delay_ms(150);
// 		PORTD &=~ (1<<i);
// 		_delay_ms(150);
		}
		for (int j=7; j >=0; j--)
		{
// 			PORTD |= (1<<j);
// 			_delay_ms(150);
			PORTD &=~ (1<<j);
			_delay_ms(150);
		}
	}
	return 0;
}

