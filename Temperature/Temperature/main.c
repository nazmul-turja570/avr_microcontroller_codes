/*
 * Serial_data.c
 *
 * Created: 10/26/2017 6:34:41 PM
 *  Author: Mahin95
 */ 


#include <avr/io.h>
#include <util/delay.h>
#define baud_rate 12


int main(void)
{
	usart_init();
	char *str = "BUET EEE";	
    while(1)
    {
		usart_send_string("Temp: ");
		usart_send_string("   ");
		usart_send_string("38");
		usart_send_string("\n");
		_delay_ms(1000);
	}        
}

void usart_init()
{
	UCSRB |= (1<<RXEN)|(1<<TXEN); // RECEIVER TRANSMITTER ENABLE
	//UBRRL |= 12; //BAUD RATE 4800
	UBRRL=baud_rate;
	UBRRH=baud_rate<<8;
	UCSRC |= (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1); // DATA SIZE SELECTION (BIT DATA SIZE) ( 8 BIT)
	//STOP BIT IS DEFAULT ZERO, SO CHANGE IS NOT NEEDED.
}

void usart_send(char data)
{
	while(!(UCSRA&(1<<UDRE))); //WAIT TILL BUFFER IS EMPTY
	UDR = data; //LOAD NEW DATA
}

void usart_send_string(char *str)
{
	while(*str !='\0')
	{
		usart_send(*str);
		str++;	
	}
	
}	
	


