/*
 * digital clock.c
 *
 * Created: 10/14/2017 4:22:08 PM
 * Author : ASUS
 */ 

#include <avr/io.h>
#include "lcd.h"
#include <avr/interrupt.h>
int millis = 0;
int Second = 0;
int minute = 0;
int hour   = 0;


int main(void)
{
	LCDInit(LS_NONE);
	init_clock();//clock with interrupt
	LCDWriteStringXY(0,0,"CLOCK");
	
    /* Replace with your application code */
    while (1) 
    {
		LCDWriteIntXY(0,1,hour,02);LCDWriteStringXY(2,1,":");
		LCDWriteIntXY(3,1,minute,02);LCDWriteStringXY(5,1,":");
		LCDWriteIntXY(6,1,Second,02);
		
    }
}
void init_clock()
{
	TCCR1B |=1<<CS11;//prescalar 8
	ICR1 = 124;//top value for 1KHz PWM
	TCCR1B |= (1<<WGM13)|(1<<WGM12);// Fast pwm selection
	TCCR1A |= (1<<WGM11); //fast pwm
	sei();//global interrupt
	TIMSK1 |= (1<<TOIE1);//timer counter overflow interrupt enable
}
ISR(TIMER1_OVF_vect)
{
	millis++;
	if(millis>=1000)
	{
		Second++;
		millis = 0;
	}
	if(Second>=60)
	{
		minute++;
		Second = 0;
		
	}
	if(minute>=60)
	{
		hour++;
		minute = 0;
	}
}