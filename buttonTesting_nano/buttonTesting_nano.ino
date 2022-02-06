int valX = 0;
int valY = 0;
int valB = 0;

const int ledX = 10;
const int ledY = 9;
const int ledB = 3;

const int jsX = A0;
const int jsY = A1;

const int lowB = A2;
const int hghB = A3;

void setup() {
  // output pins
  pinMode(ledX, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledB, OUTPUT);

  // input pins
  pinMode(jsX, INPUT);
  pinMode(jsY, INPUT);
  pinMode(lowB, INPUT);
  pinMode(hghB, INPUT);

  Serial.begin(9600);
}

void loop() {
  // constant variables for duration of loop
  const int mjs = 600;
  const int tol = 100;

  // new js/button values from input pins
  const int newX = analogRead(jsX);
  const int newY = analogRead(jsY);
  const int lnewB = digitalRead(lowB);
  const int hnewB = digitalRead(hghB);

  // check the new readings and adjust
  if (newX > (mjs + tol) && valX < 255) {
    valX = valX + 1;
  }
  else if (newX < (mjs - tol) && valX > 0) {
    valX = valX - 1;
  }

  if (newY > (mjs + tol) && valY < 255) {
    valY = valY + 1;
  }
  else if (newY < (mjs - tol) && valY > 0) {
    valY = valY - 1;
  }

  if (lnewB && valB < 255) {
    valB = valB + 1;
  }
  else if (hnewB && valB > 0) {
    valB = valB - 1;
  }

  // write to LEDs
  analogWrite(ledX, valX);
  analogWrite(ledY, valY);
  analogWrite(ledB, valB);

  // print data for bug checking
  Serial.print(valX); Serial.print(", "); Serial.print(valY); Serial.print(" | ");
  Serial.print(newX); Serial.print(", "); Serial.print(newY); Serial.print(" | ");
  Serial.print(valB); Serial.print(" | ");
  Serial.print(lnewB); Serial.print(", "); Serial.println(hnewB);
}
