/*
 * BCD-Segment_Display-shortened.c
 *
 * Created: 10/24/2017 12:31:31 PM
 * Author : real
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRD= 0xFF;
	PORTD =0;
	int a=0;
		
    while (1) 
    {
		for (int i=0; i<10; i++)
		{
			_delay_ms (100);
			for (int j=0; j<10; j++)
			{
				PORTD = j|a;
				_delay_ms (100);
			}
			a=a+0b00010000;
			PORTC= a|0;
		}
    }
}

