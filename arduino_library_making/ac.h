#include "Arduino.h"
#include "hardwareSerial.h"

class Measure
{
  public:
  Measure(int pin);
  int port;
  void ADC_init();
  int ADC_Read(int channel);
  float volt();
};

