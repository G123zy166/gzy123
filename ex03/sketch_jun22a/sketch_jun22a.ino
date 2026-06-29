#define TOUCH_PIN T0
#define LED_PIN 2

bool ledState = false;
bool lastTouch = false;
unsigned long debounceTime = 0;
const unsigned long debounceDelay = 50;
int touchThreshold = 30;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Serial.begin(115200);
}

void loop() {
  unsigned long now = millis();
  int touchVal = touchRead(TOUCH_PIN);
  bool currTouch = (touchVal < touchThreshold);

  if (now - debounceTime > debounceDelay) {
    if (currTouch && !lastTouch) {
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState ? HIGH : LOW);
      debounceTime = now;
    }
  }
  lastTouch = currTouch;
}
