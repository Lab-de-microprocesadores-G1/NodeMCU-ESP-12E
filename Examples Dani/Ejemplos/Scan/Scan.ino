#include "ESP8266WiFi.h"

#define LED D0
#define SCAN_PERIOD   5000

long lastMillis = 0;
long currentMillis = 0;
int redes = 0;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}

void loop() {
  currentMillis = millis();
 
  if (currentMillis - lastMillis > SCAN_PERIOD) {
    lastMillis = currentMillis;
    digitalWrite(LED,LOW);
    WiFi.scanNetworks(true);
    Serial.println();
    Serial.println("Scan start ... ");
  }

  redes = WiFi.scanComplete();
  if(redes >= 0) {
    digitalWrite(LED,HIGH);
    Serial.print(redes);
    Serial.println(" Redes encontradas!");

    for(int i = 0; i < redes; i++) {
      Serial.print(i+1);
      Serial.print(": ");
      Serial.println(WiFi.SSID(i));
    }
    WiFi.scanDelete();
  }
}
