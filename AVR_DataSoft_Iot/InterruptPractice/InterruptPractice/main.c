/*
 * InterruptPractice.c
 *
 * Created: 10/25/2017 9:27:18 PM
 * Author : real
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
int extratime = 0;
ISR (TIMER0_COMPA_vect)
{
	extratime++;
	if (extratime > 100)
	{
		PORTB ^= (1 << PORTB0);
	}
}

int main(void)

{	DDRB = 0xFF;
	TCCR0A = (1 << WGM01); // Set CTC Bit
		
	OCR0A = 195;
	TIMSK0 = (1 << OCIE0A);
	TCCR0B |= (1 << CS02) | ( 1<< CS00); // Start at 1024 prescaler
    while (1) 
    {
		
    }
}

