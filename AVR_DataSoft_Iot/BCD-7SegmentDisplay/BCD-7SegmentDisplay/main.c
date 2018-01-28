/*
 * BCD-7SegmentDisplay.c
 *
 * Created: 24-Oct-17 7:29:33 AM
 * Author : user-3
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
   DDRD = 0b00001111;
   DDRC = 0b00001111;
    while (1) 
    { char ARR[]={0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9};
		
		for (int i=0; i<=9; i++)
			
		{PORTC = ARR[0];
				
		for (int j=0; j<=9; j++)
		{
			PORTD = ARR[i];
			_delay_ms(100);
			
			PORTC = ARR[j];
			_delay_ms (100);
		}
		}
    }
}

