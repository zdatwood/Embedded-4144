#include <Arduino.h>

//ADC

//A5, PF0(ADC0) is the light sensor on th board

unsigned short MyLightLevel;
unsigned char  MyLightV;

void setup() {
  // put your setup code here, to run once:
  ADMUX = 0b01000000;
    //      00000 = Use single-ended ADC0
    //     0      = right justify
    //   01       = Use Vcc = 3.3V as a reference 
  ADCSRA = 0b10100101;
    //            111 = Clock / 64
    //          00    = dont use interupts
    //         1      = Auto Trigger
    //        0       = Dont start yet
    //      1         = Enable ADC

  ADCSRB = 0b00000000;
  //  Free running, Normal Speed, No differential measurements (MUX5)

  ADCSRA |= (1<<ADSC);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);

  MyLightLevel = ADCW;
  MyLightV = map(MyLightLevel, 0, 1023, 0, 33);
  MyLightV /= 10;
  Serial.println("My Val = ");
  Serial.println(MyLightLevel);
  delay(100);

}