#include <Arduino.h>
#include "ESP8266WiFi.h"

#define LED 2
#define SCAN_PERIOD 5000

long lastMillis = 0;
long currentMillis = 0;
int networks = 0;
boolean ledState = false;

void setup() 
{
  // put your setup code here, to run once:

  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  WiFi.begin("Mart?n 2.4", "Ass31105441");
  Serial.println("Connecting...");

  while(WiFi.status() != WL_CONNECTED)
  {
    ledState = !ledState;
    digitalWrite(LED, ledState);
    delay(100);
  }

  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
  digitalWrite(LED, LOW);
}

void loop() 
{
  // put your main code here, to run repeatedly:
}