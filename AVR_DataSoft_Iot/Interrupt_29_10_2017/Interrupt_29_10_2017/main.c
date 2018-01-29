#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t timeVariable = 0;

ISR(TIMER0_OVF_vect)
{
	timeVariable++;
	if (timeVariable >=244)
		{
			timeVariable = 0;
			PORTB ^= (1 << PORTB0);
		}
}

	int main(void)
	{
		DDRB = 0x01;
		TCCR0B = (1 << CS02);
		TIFR0 = (1 << TOV0);
		TIMSK0 = (1 << TOIE0);
		sei();

		while(1)
		{
			
		}
	}
