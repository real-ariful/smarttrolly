/*
 * 7Segmenttwotransistors.cpp
 *
 * Created: 10/24/2017 1:50:53 PM
 * Author : real
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


/* Replace with your library code */
int main(void)
{while(1)
	{	DDRD=0xFF;
		char ARR[]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x7b, 0x07, 0xff, 0x6f};
		for(int i=0; i<=9; i++)
			{	DDRB=0b00000001;
				PORTD = ARR[i];
				_delay_ms(200);
			
			}

		for(int j=0; j<=9;j++)
			{
				
			DDRB = 0b00000010;
			PORTD = ARR[j];
			_delay_ms(200);
			}
				
	}
	return 0;
}

