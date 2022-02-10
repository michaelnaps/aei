const int trn1 = 10;
// const int trn2 = 9;

void setup() {
  pinMode(trn1, OUTPUT);
  // pinMode(trn2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for (int i(0); i < 255; i += 5) {
    analogWrite(trn1, 255/2);
    // analogWrite(trn2, i);
    Serial.println(i);

    delay(10000);
  }
}
