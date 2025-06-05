/*  
 Author: Max Crutzen  
 Date:   02-06-2025  

 This is code testing the feasability of coupling the force sensitive resitor data directly to the haptic feedback motors, with only denoising the data so you don't feel
 the sensors responding to normal load of bodyweight. 
*/

#define vibOutPin1 3
#define vibOutPin2 4
#define vibOutPin3 5
#define vibOutPin4 6
#define vibOutPin5 9  //could not be consecutive because of the way the pins were ordered
#define vibOutPin6 10

#define sensorPin1 A0  // Removed the semicolon
#define sensorPin2 A1
#define sensorPin3 A2
#define sensorPin4 A3
#define sensorPin5 A4
#define sensorPin6 A5

int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;
int sensorValue5 = 0;
int sensorValue6 = 0;

int outputValue1 = 0;
int outputValue2 = 0;
int outputValue3 = 0;
int outputValue4 = 0;
int outputValue5 = 0;
int outputValue6 = 0;

int scale = 5;

//this threshold can vary of course due to bodyweight 
int Threshold = 900;

void setup() {
  pinMode(vibOutPin1, OUTPUT);
  pinMode(vibOutPin2, OUTPUT);
  pinMode(vibOutPin3, OUTPUT);
  pinMode(vibOutPin4, OUTPUT);
  pinMode(vibOutPin5, OUTPUT);
  pinMode(vibOutPin6, OUTPUT);

  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
  pinMode(sensorPin3, INPUT);
  pinMode(sensorPin4, INPUT);
  pinMode(sensorPin5, INPUT);
  pinMode(sensorPin6, INPUT);
}

void loop() {
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);
  sensorValue3 = analogRead(sensorPin3);
  sensorValue4 = analogRead(sensorPin4);
  sensorValue5 = analogRead(sensorPin5);
  sensorValue6 = analogRead(sensorPin6);

  // Map the sensor value alternatively (1000-1023 instead of 0-205)
  outputValue1 = map(sensorValue1, Threshold, 1023, 0, 255);
  outputValue2 = map(sensorValue2, Threshold, 1023, 0, 255);
  outputValue3 = map(sensorValue3, Threshold, 1023, 0, 255);
  outputValue4 = map(sensorValue4, Threshold, 1023, 0, 255);
  outputValue5 = map(sensorValue5, Threshold, 1023, 0, 255);
  outputValue6 = map(sensorValue6, Threshold, 1023, 0, 255);


  analogWrite(vibOutPin1, 0);
  analogWrite(vibOutPin2, 0);
  analogWrite(vibOutPin3, 0);
  analogWrite(vibOutPin4, 0);
  analogWrite(vibOutPin5, 0);
  analogWrite(vibOutPin6, 0);


  if (sensorValue1 > Threshold) {
    analogWrite(vibOutPin1, outputValue1);
  }
  if (sensorValue2 > Threshold) {
    analogWrite(vibOutPin2, outputValue2);
  }
  if (sensorValue3 > Threshold) {
    analogWrite(vibOutPin3, outputValue3);
  }
  if (sensorValue4 > Threshold) {
    analogWrite(vibOutPin4, outputValue4);
  }
  if (sensorValue5 > Threshold) {
    analogWrite(vibOutPin5, outputValue5);
  }
  if (sensorValue6 > Threshold) {
    analogWrite(vibOutPin6, outputValue6);
  }
}
