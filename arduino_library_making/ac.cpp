#include "ac.h"
Measure::Measure (int pin)
{//Constructor will go there
  port = pin;
}
void Measure::ADC_init()
{
  //ADC initialization code
  ADCSRA |=1<<ADEN;
  ADCSRA |= 1<<ADPS0;
  ADCSRA |= 1<<ADPS1; //division factor 8;
  ADMUX |= 1<<REFS0; //Reference voltage AVCC= 5V;
}
int Measure::ADC_Read(int channel)
{
  //ADC Reading will go as well
  int adc_value = 0;
  //ADMUX |= (ADMUX&0b11100000)|(channel&0b00011111); // First five bits of ADMUX for selecting channel
  ADMUX = (ADMUX&0xf0)|(channel&0x0f);
  ADCSRA |=1<<ADSC; //Conversion will start writing this bit to one.
  while(!(ADCSRA&(1<<ADIF))); //ADIF will set when conversion complete and loop breaks.
  ADCSRA|= 1<<ADIF; //ADIF must be cleared(1) to trigger a new conversion next time
  adc_value = ADCW;
  return(adc_value);
}
float Measure::volt()
{
  int adc_volt[200]= {0};
  for (int i=0;i<200;i++)
    {
      adc_volt[i] = ADC_Read(port);
      
    }
    float actual_volt = 0;
    float sum = 0;
    float measured_volt = 0;
    for (int i  = 0;i<200;i++)
    {
      adc_volt[i] = adc_volt[i] - 512;
      actual_volt = ((float)adc_volt[i]*5.00)/1023.00;
      actual_volt = pow(actual_volt,2.00);
      sum = sum + actual_volt;
      
    }
    measured_volt = sqrt(sum/200.0);
    return measured_volt;
}

