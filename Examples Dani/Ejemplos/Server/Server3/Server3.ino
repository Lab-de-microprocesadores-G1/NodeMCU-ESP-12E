#include "ESP8266WiFi.h"
#include <ESP8266WebServer.h>

#define LED D0
#define LED_OFF HIGH
#define LED_ON  LOW

boolean ledState=false;
String webPage = "";

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

  initWebPage();
  server.on("/", root);
  server.on("/ledON", ledON);
  server.on("/ledOFF", ledOFF);
  server.begin();
  Serial.println("WEB SERVER INICIADO");
}

void loop() {
  server.handleClient();
}

void initWebPage() {
  webPage += "<!DOCTYPE html>";
  webPage += "<html>";
  webPage += "<body>";
  webPage += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"></style>";
  webPage += "<h1>CONTROL DEL LED</h1>";
  webPage += "<p>Utilice los botones para apagar y prender el led.</p>";
  webPage += "<p><a href=\"ledOFF\"><button>OFF</button></a>&nbsp<a href=\"ledON\"><button>ON</button></a></p>";
  webPage += "</body>";
  webPage += "</html>";
}
void root() {
  server.send(200, "text/html", webPage);
}

void ledON() {
  digitalWrite(LED, LED_ON);
  server.send(200, "text/html", webPage);
}

void ledOFF() {
  digitalWrite(LED, LED_OFF);
  server.send(200, "text/html", webPage);  
}
