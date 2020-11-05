#include "ESP8266WiFi.h"
#include <ESP8266WebServer.h>

#define LED D0
#define LED_OFF HIGH
#define LED_ON  LOW

boolean ledState=false;

ESP8266WebServer server(80);

void setup() {

  pinMode(LED, OUTPUT);
  digitalWrite(LED,LED_OFF);
  Serial.begin(115200);
  
  Serial.println();
  Serial.println("Connecting to Access Point ...");
  WiFi.disconnect();
  WiFi.begin("NODE_RED", "GEDA2016");
      
  while (WiFi.status() != WL_CONNECTED) {
    ledState = !ledState;
    digitalWrite(LED, ledState);
    delay(100);
  }
  digitalWrite(LED,LED_ON);
  Serial.print("Conectado a NODE_RED! IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", root);
  server.begin();
  Serial.println("WEB SERVER INICIADO");
}

void loop() {
  server.handleClient();
}

void root() {
  server.send(200, "text/html", "<h1>Conectado al servidor web!</h1>");
}
