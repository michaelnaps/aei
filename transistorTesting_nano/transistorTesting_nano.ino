const int trnPin = 10;
const int potPin = 14;

void setup() {
  pinMode(trnPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  const int pVal = analogRead(potPin);

  analogWrite(trnPin, (int)(pVal * 255 / 1023));

  Serial.print(pVal); Serial.print(", ");
  Serial.println((int)(pVal*255/1023));
}
