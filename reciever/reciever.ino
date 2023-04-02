// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 
 
// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
const int pin6 = 3;
 
void setup()
{
    // Initialize ASK Object
    rf_driver.init();
    // Setup Serial Monitor
    Serial.begin(9600);
    pinMode(pin6, OUTPUT);
    Serial.println("Starting new Session"); 
}
 
void loop()
{
    // Set buffer to size of expected message
    uint8_t buf[1];
    uint8_t buflen = sizeof(buf);
    // Check if received packet is correct size
    if (rf_driver.recv(buf, &buflen))
    {
      String dataRecieved = String((char*)buf);
      // Message received with valid checksum
      if(dataRecieved.equals("a")) {
        digitalWrite(pin6, HIGH);
        delay(150);
        // Serial.println("Found the 1st signal");
      } 
      // else if(dataRecieved.equals("b")) {
      //   digitalWrite(pin6, LOW);
      //   Serial.println("Found the 2nd signal");
      // } 
      else {
        Serial.println("Unable to determine what to do");
      }
      // Serial.print("Message Received: ");
      // Serial.println(dataRecieved);
      // Serial.println(dataRecieved.equals("b")); 
      digitalWrite(pin6, LOW);
    }
}