#define LED_A 2
#define LED_B 5

int val = 0;
int step = 1;

void setup()
{
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

void loop()
{
  analogWrite(LED_A, val);
  analogWrite(LED_B, 255 - val);

  val = val + step;
  if (val <= 0 || val >= 255)
  {
    step = -step;
  }
  delay(5);
}
