const int ledPin = 2;
unsigned long prevTime = 0;
unsigned long curTime;

// 时序定义
const unsigned long shortFlash = 300;
const unsigned long longFlash = 900;
const unsigned long gap = 200;
const unsigned long sosWait = 1200;

int stage = 0;
bool lightOn = false;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  curTime = millis();
  if (curTime - prevTime < (lightOn ? (stage%2?shortFlash:longFlash) : gap)) return;
  prevTime = curTime;
  lightOn = !lightOn;
  digitalWrite(ledPin, lightOn);

  if (!lightOn) {
    stage++;
    // 完整SOS流程：3短 3长 3短，共18个阶段
    if (stage >= 18) {
      stage = 0;
      delay(sosWait); // 整套结束长停顿
    }
  }
}
