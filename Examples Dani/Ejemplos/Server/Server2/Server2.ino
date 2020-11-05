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
  server.on("/plain", plain);
  server.on("/red", red);
  server.on("/blue", blue);
  server.on("/image", image);
  server.begin();
  Serial.println("WEB SERVER INICIADO");
}

void loop() {
  server.handleClient();
}

void root() {
  String webPage;
  webPage += "<h1>Conectado al servidor web!</h1>";
  webPage += "<p>Su direccion IP es: </p>";
  webPage += WiFi.localIP().toString();
  server.send(200, "text/html", webPage);
}

void plain() {
  server.send(200, "text/plain", "Texto plano (sin formato)");
}

void red() {
  server.send(200, "text/html", " <!DOCTYPE html> <html> <body> <h2 style=\"background-color:red\"> Podemos escribir con fondo rojo! </h2> </body> </html>");  
}

void blue() {
  String webPage;
  webPage += "<!DOCTYPE html>";
  webPage += "<html>";
  webPage += "<body>";
  webPage += "<h2 style=\"color:#0000FF;\"> Caracteres azules! </h2>";
  webPage += "</body>";
  webPage += "</html>";
  server.send(200, "text/html", webPage);  
}

void image() {
  String webPage;
  String image ="<img src=\"https://www.itba.edu.ar/wp-content/uploads/2016/12/Gal-Elec-6.jpg\">";
  webPage += "<!DOCTYPE html>";
  webPage += "<html>";
  webPage += "<body>";
  webPage += image;
  webPage += "</body>";
  webPage += "</html>";
  server.send(200, "text/html", webPage);  
}
