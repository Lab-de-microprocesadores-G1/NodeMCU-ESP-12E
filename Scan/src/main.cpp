#include <Arduino.h>
#include "ESP8266WiFi.h"

#define LED 2
#define SCAN_PERIOD 5000

long lastMillis = 0;
long currentMillis = 0;
int networks = 0;

void setup() 
{
  // put your setup code here, to run once:

  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("Set up ready");
}

void loop() 
{
  // put your main code here, to run repeatedly:

  currentMillis = millis();
  if (currentMillis - lastMillis > SCAN_PERIOD) 
  {
    lastMillis = currentMillis;
    digitalWrite(LED, LOW);
    WiFi.scanNetworks(true);
    Serial.println();
    Serial.println("Scan start...");
  }

  networks = WiFi.scanComplete();
  if (networks >= 0)
  {
    digitalWrite(LED, HIGH);
    Serial.print(networks);
    Serial.println(" networks found!");

    for (int i=0; i < networks; i++)
    {
      Serial.print(i+1);
      Serial.print(":");
      Serial.println(WiFi.SSID(i));
    }

    WiFi.scanDelete();
  }
}