/*
 * HardwareInterrupt.c
 *
 * Created: 10/7/2017 4:51:04 PM
 * Author : aQib
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>



int main(void)
{
    sei(); //globally calling the interrupt, avr/interrupt.h has to be called
	EIMSK |= 1<<INT0; //Enable Into Interrupt
	EICRA |= 1<<ISC01; //Falling edge trigger interrupts
	DDRB |= 1<<PB0;
    while (1) 
    {
    }
}

ISR(INT0_vect)
{
	PORTB ^= 1<<PB0;
}

