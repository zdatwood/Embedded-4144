#include <Arduino.h>
extern "C" uint8_t MyAssemblyAdd(uint8_t, uint8_t);
extern "C" void TurnOnLED();
extern "C" void TurnOffLED();
extern "C" uint8_t YesTheresAnA(const char*);

const char* Andrew="Andrew";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  uint8_t a = 24;
  uint8_t b = 36;
  uint8_t result = MyAssemblyAdd(a, b);

  Serial.println(a);
  Serial.println(b);
  Serial.println(result);

  uint8_t result2 = YesTheresAnA(Andrew);
  Serial.println(result2);
}

void loop() {
  // put your main code here, to run repeatedly:
  TurnOnLED;
  delay(500);
  TurnOffLED;
  delay(500);
}