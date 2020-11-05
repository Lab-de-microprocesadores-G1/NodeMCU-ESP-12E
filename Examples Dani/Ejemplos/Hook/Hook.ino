#include "ESP8266WiFi.h"

#define LED D0
#define SCAN_PERIOD   5000

long lastMillis = 0;
long currentMillis = 0;
int redes = 0;
boolean ledState = false;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  
  WiFi.begin("NODE_RED", "GEDA2016");
  Serial.println("Connecting...");
  while(WiFi.status() != WL_CONNECTED) {
    ledState = !ledState;
    digitalWrite(LED, ledState);
    delay(100);
  }
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
  digitalWrite(LED,LOW);
}

void loop() {
}
