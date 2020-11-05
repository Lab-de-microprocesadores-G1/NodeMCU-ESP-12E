#define LED D0
#define BLINK_PERIOD 5

long lastMillis = 0;
long currentMillis = 0;
boolean ledState = false;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  currentMillis = millis();
  
  if( (currentMillis - lastMillis) > BLINK_PERIOD) {
    lastMillis = currentMillis;
    ledState = !ledState;
    digitalWrite(LED, ledState);
  }              
}
