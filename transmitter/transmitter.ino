// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h>
 
// Create Amplitude Shift Keying Object
RH_ASK rf_driver;

const int pin = 9;
 
void setup() {
  Serial.begin(9600);
  // Initialize ASK Object
  if(!rf_driver.init())
    Serial.println("init failed");
  pinMode(pin, INPUT);
}

void sendMessage(char* msg) {
  rf_driver.send((uint8_t *)msg, strlen(msg));
  rf_driver.waitPacketSent();
}
 
void loop() {
  int val = digitalRead(pin);
  if(val) {
    sendMessage("a");
  } else {
    // do-nothing
  }
}