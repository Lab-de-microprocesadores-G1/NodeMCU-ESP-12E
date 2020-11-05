#define LED D0
#define BLINK_PERIOD 1000

long lastMillis = 0;
long currentMillis = 0;
boolean ledState = true;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  currentMillis = millis();
  
  if( (currentMillis - lastMillis) > BLINK_PERIOD) {
    lastMillis = currentMillis;
    ledState = !ledState;
    digitalWrite(LED, ledState);
    Serial.print("LED State is: ");
    Serial.println(ledState);
  }              
}
