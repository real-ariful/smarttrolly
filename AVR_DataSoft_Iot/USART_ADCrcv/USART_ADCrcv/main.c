#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define BAUDRATE 19200
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)

//Declaration of our functions
void USART_init(void);
unsigned char USART_receive(void);
void USART_send( unsigned char data);
void USART_putstring(char* StringPtr);
void USART_putInt(int number);
int j=100;
unsigned char y;

int main(void)
{
	USART_init();        //Call the USART initialization code
	DDRC = 0xFF;
	
	sei();
	while(1)
	{
		//receiving
		y = USART_receive();
		PORTC = y;
 	}
}

void USART_init(void)
{	
	UBRR0H = (uint8_t)(BAUD_PRESCALLER>>8);
	UBRR0L = (uint8_t)(BAUD_PRESCALLER);
	UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0) | (1 << TXCIE0);
	UCSR0C = (3<<UCSZ00);
	UCSR0A= (1 << RXCIE0);
}

unsigned char USART_receive(void)
{
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
}

void USART_send( unsigned char data )
{
	while ( !( UCSR0A & (1<<UDRE0)) );
	UDR0 = data;
	}
	
	ISR(USART_RX_vect)
	{
		if (y == 0x00)	
		{	UDR0 = j;
			j--;
		}
	}
	
