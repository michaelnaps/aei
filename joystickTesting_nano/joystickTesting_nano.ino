int valX = 0;
int valY = 0;

const int ledX = 10;
const int ledY = 9;

const int jsX = A0;
const int jsY = A1;

void setup() {
  pinMode(ledX, OUTPUT);
  pinMode(ledY, OUTPUT);

  pinMode(jsX, INPUT);
  pinMode(jsY, INPUT);

  Serial.begin(9600);
}

void loop() {
  const int mjs = 500;
  const int tol = 300;

  int newX = analogRead(jsX);
  int newY = analogRead(jsY);

  if (newY > (mjs + tol) && valX < 255 && valY == 0) {
    valX = valX + 1;
  }
  else if (newY < (mjs - tol) && valX > 0) {
    valX = valX - 1;
  }

  if (newY < (mjs - tol) && valY < 255 && valX == 0) {
    valY = valY + 1;
  }
  else if (newY > (mjs + tol) && valY > 0) {
    valY = valY - 1;
  }

  analogWrite(ledX, valX);
  analogWrite(ledY, valY);

  Serial.print(valX); Serial.print(", "); Serial.print(valY); Serial.print(" | ");
  Serial.print(newX); Serial.print(", "); Serial.println(newY);
}
