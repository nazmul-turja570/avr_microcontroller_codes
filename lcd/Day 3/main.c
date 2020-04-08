/*
 * Day 3.c
 *
 * Created: 9/23/2017 6:36:18 PM
 * Author : Bumblebee
 */ 

#include <avr/io.h>
#include "lcd.h"   //local directory


int main(void)
{
    /* Replace with your application code */
	LCDInit(LS_NONE);
	LCDWriteStringXY(0,0,"THOR RAGNARAK");
	
	ADC_Initialize();
	
    while (1) 
    {
		int adc_value=ADC_Read();
		LCDWriteIntXY(0,1,adc_value,4);
    }
}

void ADC_Initialize()
{
	ADCSRA |=1<<ADEN;   //ADC Enable
	ADCSRA |=1<<ADPS1; // Prescaler 8
	ADCSRA |=1<<ADPS0; //Prescaler 8
	ADMUX |=1<<REFS0;
}

int ADC_Read()
{
	int adc_value=0;
	ADMUX |=1<<MUX0;   //channel 1 selected
	ADCSRA |=1<<ADSC; //conversion started
	while(!(ADCSRA&(1<<ADIF))); //wait until conversion completes
	ADCSRA |=1<<ADIF; //New Conversion started
	adc_value=ADCW;
	return adc_value;
	
}