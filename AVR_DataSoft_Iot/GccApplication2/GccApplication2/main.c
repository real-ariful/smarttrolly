/*
 * GccApplication2.c
 *
 * Created: 12/6/2017 8:34:12 PM
 * Author : real
 */ 

// 9.6 MHz, built in resonator
#define F_CPU 9600000

#include <avr/io.h>

void adc_setup (void)
{
	// Set the ADC input to PB2/ADC1
	ADMUX |= (1 << MUX0);
	ADMUX |= (1 << ADLAR);

	// Set the prescaler to clock/128 & enable ADC
	ADCSRA |= (1 << ADPS1) | (1 << ADPS0) | (1 << ADEN);
}

int adc_read (void)
{
	// Start the conversion
	ADCSRA |= (1 << ADSC);

	// Wait for it to finish
	while (ADCSRA & (1 << ADSC));

	return ADCH;
}

int main (void)
{
	int adc_in;

	adc_setup();

	while (1) {
		adc_in = adc_read();
	}
}

