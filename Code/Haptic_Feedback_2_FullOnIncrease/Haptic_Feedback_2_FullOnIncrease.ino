/*  
 Author: Max Crutzen  
 Date:   21-03-2025  

 This is code to test the mapping of the Force Sensitive Resistors with the vibration motor output.  
 Confirming that indeed the data can be mapped and experienced in an intuitive way.  
 This means more pressure equals stronger vibration.  
*/

#define vibOutPin1 3
#define vibOutPin2 4
#define vibOutPin3 5
#define vibOutPin4 6
#define vibOutPin5 9  //could not be consecutive because of the way the pins were ordered
#define vibOutPin6 10

#define sensorPin1 A0
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

int prevSensorValue1 = 0;
int prevSensorValue2 = 0;
int prevSensorValue3 = 0;
int prevSensorValue4 = 0;
int prevSensorValue5 = 0;
int prevSensorValue6 = 0;

unsigned long lastUpdate1 = 0, lastUpdate2 = 0, lastUpdate3 = 0;
unsigned long lastUpdate4 = 0, lastUpdate5 = 0, lastUpdate6 = 0;

bool isVibrating1 = false, isVibrating2 = false, isVibrating3 = false;
bool isVibrating4 = false, isVibrating5 = false, isVibrating6 = false;

const int rawDeltaThreshold = 200;
const unsigned long vibrationDuration = 500; // 500ms = 0.5s
const unsigned long updateInterval = 1000;

int scale = 5;

float minLog = 0.0, maxLog = 6.5, maxLogRef = 1;

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
  unsigned long currentMillis = millis();

  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);
  sensorValue3 = analogRead(sensorPin3);
  sensorValue4 = analogRead(sensorPin4);
  sensorValue5 = analogRead(sensorPin5);
  sensorValue6 = analogRead(sensorPin6);

  float resistanceValue1 = (1023.0 / sensorValue1 - 1.0) * 10e4;
  float resistanceValue2 = (1023.0 / sensorValue2 - 1.0) * 10e4;
  float resistanceValue3 = (1023.0 / sensorValue3 - 1.0) * 10e4;
  float resistanceValue4 = (1023.0 / sensorValue4 - 1.0) * 10e4;
  float resistanceValue5 = (1023.0 / sensorValue5 - 1.0) * 10e4;
  float resistanceValue6 = (1023.0 / sensorValue6 - 1.0) * 10e4;

  float logValue1 = maxLog - log10(resistanceValue1);
  float logValue2 = maxLog - log10(resistanceValue2);
  float logValue3 = maxLog - log10(resistanceValue3);
  float logValue4 = maxLog - log10(resistanceValue4);
  float logValue5 = maxLog - log10(resistanceValue5);
  float logValue6 = maxLog - log10(resistanceValue6);

  outputValue1 = map(logValue1, minLog, maxLogRef, 0, 250);
  outputValue2 = map(logValue2, minLog, maxLogRef, 0, 250);
  outputValue3 = map(logValue3, minLog, maxLogRef, 0, 250);
  outputValue4 = map(logValue4, minLog, maxLogRef, 0, 250);
  outputValue5 = map(logValue5, minLog, maxLogRef, 0, 250);
  outputValue6 = map(logValue6, minLog, maxLogRef, 0, 250);

  // Sensor 1
  if (sensorValue1 > prevSensorValue1 + rawDeltaThreshold) {
    analogWrite(vibOutPin1, 255);
    isVibrating1 = true;
    lastUpdate1 = currentMillis;
  } else if (isVibrating1 && currentMillis - lastUpdate1 >= vibrationDuration) {
    analogWrite(vibOutPin1, 0);
    isVibrating1 = false;
  }
  prevSensorValue1 = sensorValue1;

  // Sensor 2
  if (sensorValue2 > prevSensorValue2 + rawDeltaThreshold) {
    analogWrite(vibOutPin2, 255);
    isVibrating2 = true;
    lastUpdate2 = currentMillis;
  } else if (isVibrating2 && currentMillis - lastUpdate2 >= vibrationDuration) {
    analogWrite(vibOutPin2, 0);
    isVibrating2 = false;
  }
  prevSensorValue2 = sensorValue2;

  // Sensor 3
  if (sensorValue3 > prevSensorValue3 + rawDeltaThreshold) {
    analogWrite(vibOutPin3, 255);
    isVibrating3 = true;
    lastUpdate3 = currentMillis;
  } else if (isVibrating3 && currentMillis - lastUpdate3 >= vibrationDuration) {
    analogWrite(vibOutPin3, 0);
    isVibrating3 = false;
  }
  prevSensorValue3 = sensorValue3;

  // Sensor 4
  if (sensorValue4 > prevSensorValue4 + rawDeltaThreshold) {
    analogWrite(vibOutPin4, 255);
    isVibrating4 = true;
    lastUpdate4 = currentMillis;
  } else if (isVibrating4 && currentMillis - lastUpdate4 >= vibrationDuration) {
    analogWrite(vibOutPin4, 0);
    isVibrating4 = false;
  }
  prevSensorValue4 = sensorValue4;

  // Sensor 5
  if (sensorValue5 > prevSensorValue5 + rawDeltaThreshold) {
    analogWrite(vibOutPin5, 255);
    isVibrating5 = true;
    lastUpdate5 = currentMillis;
  } else if (isVibrating5 && currentMillis - lastUpdate5 >= vibrationDuration) {
    analogWrite(vibOutPin5, 0);
    isVibrating5 = false;
  }
  prevSensorValue5 = sensorValue5;

  // Sensor 6
  if (sensorValue6 > prevSensorValue6 + rawDeltaThreshold) {
    analogWrite(vibOutPin6, 255);
    isVibrating6 = true;
    lastUpdate6 = currentMillis;
  } else if (isVibrating6 && currentMillis - lastUpdate6 >= vibrationDuration) {
    analogWrite(vibOutPin6, 0);
    isVibrating6 = false;
  }
  prevSensorValue6 = sensorValue6;

  delay(20);
}
