const int pwm1 = 10;
const int pwm2 = 9;

void setup() {
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int val1 = 0;
  int val2 = 0;

  for (int i(0); i < 255; ++i)
  {
    analogWrite(pwm1, i);
    analogWrite(pwm2, i);
    delay(500);
    
    Serial.print(i);
    Serial.print(", ");
    Serial.println(i);
  }

  for (int i(255); i > 0; --i)
  {
    analogWrite(pwm1, i);
    analogWrite(pwm2, i);
    delay(500);
    
    Serial.print(i);
    Serial.print(", ");
    Serial.println(i);
  }
}
