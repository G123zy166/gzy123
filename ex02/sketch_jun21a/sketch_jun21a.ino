const int ledPin = 2;
unsigned long prevTime = 0;
const unsigned long interval = 500;
bool ledState = false;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long curTime = millis();
  if (curTime - prevTime >= interval) {
    prevTime = curTime;
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }
}
