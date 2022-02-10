const int trn1 = 10;
const int trn2 = 9;

void setup() {
  pinMode(trn1, OUTPUT);
  pinMode(trn2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for (int i(0); i < 255; ++i) {
    analogWrite(trn1, i);
    analogWrite(trn2, i);
    Serial.print(i); Serial.print(", "); Serial.println(i * (700 / 255));

    delay(500);
  }
}
