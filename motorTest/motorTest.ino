#include <Arduino.h>

const int pin9 = 9;
const int pin10 = 10;

const int rotatorDelay = 10000;

void setup() {
  pinMode(pin9, OUTPUT);
  pinMode(pin10, OUTPUT);
}

void loop() {
    digitalWrite(pin10, LOW);
    digitalWrite(pin9, HIGH);

    delay(rotatorDelay);

    digitalWrite(pin9, LOW);
    digitalWrite(pin10, HIGH);
    
    delay(rotatorDelay);
}