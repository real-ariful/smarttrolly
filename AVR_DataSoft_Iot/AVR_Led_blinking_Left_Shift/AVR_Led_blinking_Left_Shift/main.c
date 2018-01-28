/*
 * AVR_Led_Input_Output.c
 *
 * Created: 10/23/2017 11:39:13 AM
 * Author : real
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
uint8_t inputTemp=0;

int main(void)
{	
	DDRC &=~ (1<<PC0);
	//DDRD |= (1<<PD5); 
	DDRD = 0xff;
	
	
	
	while(1)
	{
// 		inputTemp = PINC & 0x01;
// 		if (inputTemp ==0x00)
// 		{
// 			PORTD &=~ (1<<PD0);
// 			PORTD |= (1<<PD7);			
// 		}
// 		else
// 		{
// 			PORTD |= (1<<PD0);
// 			PORTD &=~ (1<<PD7);
// 		}
    PORTD |= (0b10000000>>PD5);

	}

return 0;
}

