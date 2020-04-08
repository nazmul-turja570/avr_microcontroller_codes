/*
 * Day 8.c
 *
 * Created: 10/27/2017 5:52:21 PM
 * Author : Bumblebee
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define baudrate 12

int main(void)
{
	usart_init();
    
    while (1) 
    {
		usart_send('A');
		usart_send('B');
		usart_send('C');
		_delay_ms(1000);
    }
}

void usart_init()
{
	UCSRB |= (1<<TXEN)|(1<<RXEN); // ENABLE RECEIVER AND TRANSMITTER
	UBRRL = baudrate; // 1100 1000 1111 0111
	UBRRH = baudrate>>8;
	UCSRC |= (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0); // Data Size Selection (8 bit)
}

void usart_send(char data)
{
	while(!(UCSRA&(1<<UDRE))); //confirm the data is transmitted
	UDR = data;
}