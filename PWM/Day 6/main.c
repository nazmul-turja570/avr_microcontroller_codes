/*
 * Day 6.c
 *
 * Created: 10/13/2017 6:15:55 PM
 * Author : Bumblebee
 */ 

#include <avr/io.h>


int main(void)
{
    DDRB |= (1<<PB1)|(1<<PB2); //OC1A and OC1B are set as output mode
	TCCR1B |= 1<<CS11; // Prescaler 8
	ICR1 = 124; // Top value for 1 KHz PWM
	TCCR1B |= (1<<WGM13)|(1<<WGM12); //Fast PWM
	TCCR1A |= 1<<WGM11; //Fast PWM
	OCR1A = 40;
	OCR1B = 80;
	TCCR1A |=1<<COM1A1; //Clear on Compare Match
	
	
    while (1) 
    {
    }
}

