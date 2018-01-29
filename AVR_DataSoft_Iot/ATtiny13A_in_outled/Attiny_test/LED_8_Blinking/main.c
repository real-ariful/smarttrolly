// 9.6 MHz, built in resonator
// #define F_CPU 9600000
// #define LED PB1 
//  
//  
// #include <avr/io.h>
//  
// void adc_setup (void)
// {
//     // Set the ADC input to PB2/ADC1
//     ADMUX |= (1 << MUX0);
//     ADMUX |= (1 << ADLAR);
//  
//     // Set the prescaler to clock/128 & enable ADC
//     // At 9.6 MHz this is 75 kHz.
//     // See ATtiny13 datasheet, Table 14.4.
//     ADCSRA |= (1 << ADPS1) | (1 << ADPS0) | (1 << ADEN);
// }
//  
// int adc_read (void)
// {
//     // Start the conversion
//     ADCSRA |= (1 << ADSC);
//  
//     // Wait for it to finish
//     while (ADCSRA & (1 << ADSC));
//  
//     return ADCH;
// }
//  
// void pwm_setup (void)
// {
//     // Set Timer 0 prescaler to clock/8.
//     // At 9.6 MHz this is 1.2 MHz.
//     // See ATtiny13 datasheet, Table 11.9.
//     TCCR0B |= (1 << CS01);
//  
//     // Set to 'Fast PWM' mode
//     TCCR0A |= (1 << WGM01) | (1 << WGM00);
//  
//     // Clear OC0B output on compare match, upwards counting.
//     TCCR0A |= (1 << COM0B1);
// }
//  
// void pwm_write (int val)
// {
//     OCR0B = val;
// }
//  
// int main (void)
// {
//     int adc_in;
//  
//     // LED is an output.
//     DDRB |= (1 << LED);  
//  
//     adc_setup();
//     pwm_setup();
//   
//     while (1) {
//         // Get the ADC value
//         adc_in = adc_read();
//         // Now write it to the PWM counter
//         pwm_write(adc_in);
//     }
// }












 #define F_CPU 9600000UL
#include <avr/io.h>
#include <util/delay.h>
uint8_t inputTemp=0;
uint16_t adc_in;




void adc_setup (void)
{
	// Set the ADC input to PB2/ADC1
	ADMUX |= (1 << MUX0);
	ADMUX |= (1 << ADLAR);

	// Set the prescaler to clock/128 & enable ADC
	ADCSRA |= (1 << ADPS1) | (1 << ADPS0) | (1 << ADEN);
}

uint16_t adc_read (void)
{
	// Start the conversion
	ADCSRA |= (1 << ADSC);

	// Wait for it to finish
	while (ADCSRA & (1 << ADSC));

	return ADCH;
}



int main(void)
{	
	DDRB |= (1<<PB1) | (1 << PB3) | (1<< PB4);
	DDRB &=~ (1<<PB0);
	
	adc_setup();
	//pwm_setup();
	

    
    while (1) 
    {
		inputTemp = PINB & 0x01 ;
		if (inputTemp == 0x01)
		{
			PORTB |= (1<<PB4);
		}
		else
		{
			PORTB &=~ (1<<PB4);
		}
		
		adc_in = adc_read();
		//pwm_write(adc_in);
		if (adc_in > 512)
		{
			PORTB |= (1 << PB3);
			PORTB &=~ (1 << PB1);
		}
		else if(adc_in <= 512)
		{
			PORTB &=~ (1 << PB3);
			PORTB |= (1 << PB1);
			
		}
		
		
	}

}


// void pwm_write (int val)
// {
// 	OCR0B = val;
// }
// 
// void pwm_setup(){
// // Set Timer 0 prescaler to clock/8.
// // At 9.6 MHz this is 1.2 MHz.
// TCCR0B |= (1 << CS01) | (1 << CS00);
// // Set to 'Fast PWM' mode
// TCCR0A |= (1 << WGM01) | (1 << WGM00);
// 
// // Clear OC0B output on compare match, upwards counting.
// TCCR0A |= (1 << COM0B1);
// 
// }