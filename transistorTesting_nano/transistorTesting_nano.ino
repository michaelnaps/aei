int valX = 0;
int valY = 0;

const int trn1 = 10;
const int trn2 = 9;

const int jsX = A0;
const int jsY = A1;

void setup() {
  pinMode(trn1, OUTPUT);
  pinMode(trn2, OUTPUT);

  pinMode(jsX, INPUT);
  pinMode(jsY, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  const int mjs = 350;
  const int tol = 100;

  int newX = analogRead(jsX);
  int newY = analogRead(jsY);

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

  analogWrite(trn1, valX);
  analogWrite(trn2, valY);
  
  Serial.print(valX); Serial.print(", "); Serial.print(valY); Serial.print(" | ");
  Serial.print(newX); Serial.print(", "); Serial.println(newY);
}
