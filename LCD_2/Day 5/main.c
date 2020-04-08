/*
 * Day 5.c
 *
 * Created: 10/7/2017 6:21:57 PM
 * Author : Bumblebee
 */ 

#include <avr/io.h>
int overflow = 0;

int main(void)
{
    TCCR0B |= (1<<CS02)|(1<<CS00); //Prescaler 1024
	TCNT0 = 0;
	DDRB |= 1<<PB0; // Setting it to output mode
    while (1) 
    {
		if(TCNT0>=254)
		{
			overflow++;
			TCNT0=0;
		}
		if(overflow>=4)
		{
			PORTB ^=1<<PB0; //Bitwise  xor or toggle
			overflow = 0;
		}
    }
}

