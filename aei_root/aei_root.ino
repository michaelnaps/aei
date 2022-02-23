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
const int JS[]    = {A0, A1, A2};
// const int ST[] = {A3, A4};
// const int AI   =  A5;

// output pins and info
const int nTCP  = 4;
const int TCP[] = {5, 6, 9, 10};

// values to be updated on each iteration
int TCP_val[4] = {0};

// constant loop variables for TCP
const int TCP_MAX = 0.30*255;
const int adj[] = {1, -1, 1, -1};


void setup() {
  // INPUT PINS (Manual Operation)
  pinMode(JS[0], INPUT);
  pinMode(JS[1], INPUT);
  pinMode(JS[2], INPUT_PULLUP);

  // OUTPUT PINS
  pinMode(TCP[0], INPUT);
  pinMode(TCP[1], INPUT);
  pinMode(TCP[2], INPUT);
  pinMode(TCP[3], INPUT);

  // serial
  Serial.begin(9600);
}

void loop() {
  // read values from input pins (joystick)
  const int JS_val[] = {
    analogRead(JS[0]), analogRead(JS[0]),
    analogRead(JS[1]), analogRead(JS[1]),
    digitalRead(JS[2])
  };

  // check joystick button
  resetTCP(TCP_val, JS_val[4], TCP_MAX, nTCP);

  // update, write, and print TCP values
  updateTCP(TCP_val, JS_val, adj, TCP_MAX, nTCP);
  writeTCP(TCP, TCP_val, adj, TCP_MAX, nTCP);
  printTCP(TCP_val, adj, TCP_MAX, nTCP);
}
