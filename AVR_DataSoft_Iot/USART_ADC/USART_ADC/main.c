#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#define BAUDRATE 19200
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)
#include <avr/interrupt.h>

//Declaration of our functions
void USART_init(void);
unsigned char USART_receive(void);
void USART_send( unsigned char data);
void USART_putstring(char* StringPtr);
void USART_putInt(int number);


int main(void){
	USART_init();   
	int i=10;
	DDRC = 0xff;
	while(1)
		{ //sending 
			UDR0 = i;
			_delay_ms(150);
			i++;
			unsigned char y = USART_receive();
			PORTC = y;
			_delay_ms(50);
			} 
		}


void USART_init(void){ 
	
	UBRR0H = (uint8_t)(BAUD_PRESCALLER>>8);
	UBRR0L = (uint8_t)(BAUD_PRESCALLER);
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0C = (3<<UCSZ00);
}

unsigned char USART_receive(void)
{
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
}

void USART_send( unsigned char data)
{
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
	
	}
