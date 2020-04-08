/*
 * Day1.c
 *
 * Created: 9/21/2017 5:22:45 PM
 * Author : Bumblebee
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB &= ~(1<<PB0);  //input
	DDRB |= (1<<PB2);  //output
	while (1)
	{
		int pin_state = PINB&(1<<PB0);
		if(pin_state == 0 )
		{
			PORTB |= 1<<PB2;
		}
		else
		PORTB &= ~(1<<PB2);
		//button open, PINB = 0b0000 0001;
		
		
	}
}

