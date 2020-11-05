#include <Arduino.h>

#define LED 2
#define BLINK_PERIOD 5

long lastMillis = 0;
long currentMillis = 0;
boolean ledState = false;

void setup() {
  // Put your setup code here, to run once:

  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop() {
  // Put your main code here, to run repeatedly:
  
  digitalWrite(LED, HIGH);
  Serial.println("LED is on");
  delay(1000);
  digitalWrite(LED, LOW);
  Serial.println("LED is off");
  delay(1000);
}