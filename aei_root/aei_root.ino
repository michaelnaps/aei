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
int updateTCP(const int& pin, const int& pin_val, const int& val);

// input and output pins
const int JS[] = {A0, A1};
// const int ST[] = {A2, A3};
// const int AI   =  A4;

// output pins and info
const int nTCP  = 4;
const int TCP[] = {5, 6, 9, 10};

// values to be updated on each iteration
int TCP_val[4] = {0};

void setup() {
  // INPUT PINS (Manual Operation)
  pinMode(JS[0], INPUT);
  pinMode(JS[1], INPUT);

  // OUTPUT PINS
  pinMode(TCP[0], INPUT);
  pinMode(TCP[1], INPUT);
  pinMode(TCP[2], INPUT);
  pinMode(TCP[3], INPUT);

  // serial
  Serial.begin(9600);
}

void loop() {
  // tcp value adjustment coefficient
  const int adj[] = {1, -1, 1, -1};

  // read values from input pins (joystick)
  const int JS_val[] = {analogRead(JS[0]), analogRead(JS[0]), analogRead(JS[1]), analogRead(JS[1])};

  // update, write, and print TCP values
  updateTCP(TCP_val, JS_val, adj, nTCP);
  writeTCP(TCP, TCP_val, adj, nTCP);
  printTCP(TCP_val, adj, nTCP);
}
