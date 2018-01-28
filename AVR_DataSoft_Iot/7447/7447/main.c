#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{	char seg_code[]={0x0,0x1,0x2,0x3,0x4,0x5,6,0x7,0x8,0x9};
	DDRC = 0xff;
	DDRD = 0xff;
// 	PORTD = 0x00;
// 	PORTC= 0x00;			
	while(1)
	{
			for (int r=0;r<11;r++)
		{
					PORTC = seg_code[0];
					PORTD= seg_code[r];	
					_delay_ms(100);							
					

			for (int i = 1; i<=9; i++)
		
				{
					PORTC = seg_code[i];
						_delay_ms(110);			
				}
		}

	}
}