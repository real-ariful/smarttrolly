
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t timeVariable = 0;

ISR(TIMER0_OVF_vect)
{	timeVariable++;
	if (timeVariable >=122)
	{
		timeVariable =0;
		PORTB ^= (1 << PORTB0);
	}
}

int main(void)
{	DDRB = 0xFF;
	TCCR0B |= (1<<CS02);//( 1 << CS02);//Timer Scaling 256(Divide by 256)
	TIFR0 |= ( 1 << TOV0 ); // Clear the overflow flag
	TIMSK0 |= ( 1 << TOIE0 ); // Enable Overflow interrupter
	sei ();//set external interrupt
	
	while (1) 
		{
		}
}



