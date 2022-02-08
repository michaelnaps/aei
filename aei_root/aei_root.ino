// Project: Automated Endotracheal Intubation (AEI)
// Created by: Michael Napoli
// Team Members: Tag Stork, Connor Gantt, Hossam Montasser
// Created on: 2/8/2020

/*
   Purpose: To control and guide the automated endotracheal intubation
    system developed by OSU capstone Team 6.2 during the 2021-2022
    academic year. This root file will work in conjunction with software
    written by a CSE capstone team working to automate the guiding
    functionality.
*/

// FUNCTION DECLARATIONS
int updateTCP(const int& pin, const int& val);

// input and output pins
const int js_x(A0), js_y(A1);
const int extr(A2), retr(A3), AI(A4);
const int tcp1(5),  tcp2(6),  tcp3(9), tcp4(10);

// values to be updated on each iteration
int tcp1_val(0), tcp2_val(0), tcp3_val(0), tcp4_val(0);

void setup() {
  // INPUT PINS (Manual Operation)
  pinMode(js_x, INPUT);
  pinMode(js_y, INPUT);
  pinMode(extr, INPUT);
  pinMode(retr, INPUT);
  pinMode(AI,   INPUT);

  // OUTPUT PINS
  pinMode(tcp1, OUTPUT);
  pinMode(tcp2, OUTPUT);
  pinMode(tcp3, OUTPUT);
  pinMode(tcp4, OUTPUT);

  // serial
  Serial.begin(9600);
}

void loop() {
  // read values from input pins
  const int js_x_val = analogRead(js_x);
  const int js_y_val = analogRead(js_y);
  const int extr_val = digitalRead(extr);
  const int retr_val = digitalRead(retr);
  const int AI_val   = digitalRead(AI);

  // TCP values to be updates
  tcp1_val = tcp1_val + updateTCP(tcp1, js_x_val);
  tcp2_val = tcp2_val + updateTCP(tcp2, js_x_val);
  tcp3_val = tcp3_val + updateTCP(tcp3, js_y_val);
  tcp4_val = tcp4_val + updateTCP(tcp4, js_y_val);

  // update analog TCP pins
  analogWrite(tcp1, tcp1_val);
  analogWrite(tcp2, tcp2_val);
  analogWrite(tcp3, tcp3_val);
  analogWrite(tcp4, tcp4_val);

  Serial.print(js_x_val); Serial.print(", ");
  Serial.print(js_y_val); Serial.print(", ");
  Serial.print(tcp3_val); Serial.print(", ");
  Serial.println(tcp4_val);
}
