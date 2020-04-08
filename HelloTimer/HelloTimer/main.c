/*
 * HelloTimer.c
 *
 * Created: 10/7/2017 3:53:50 PM
 * Author : aQib
 */ 

#include <avr/io.h>

int overflow = 0; 
int main(void)
{
    TCCR0B |= (1<<CS02)|(1<<CS00); //Prescaler 1024
	TCNT0 = 0; //Timer starts counting
	DDRB |= 1<<PB0;
    while (1) 
    {
		if(TCNT0>=254){
			overflow++;
			TCNT0 = 0;
		}
		if (overflow>=4)
		{
			PORTB ^= 1<<PB0;
			overflow =0;
		}
		
    }
}

