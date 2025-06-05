/*
 Author: Max Crutzen
 Date:   21-03-2025

 Version using raw analog values.
 Full vibration on pressure spike, then intermittent half-vibration if pressure stays high.
*/

#define vibOutPin1 3
#define vibOutPin2 4
#define vibOutPin3 5
#define vibOutPin4 6
#define vibOutPin5 9
#define vibOutPin6 10

#define sensorPin1 A0
#define sensorPin2 A1
#define sensorPin3 A2
#define sensorPin4 A3
#define sensorPin5 A4
#define sensorPin6 A5

const int vibPins[6] = {vibOutPin1, vibOutPin2, vibOutPin3, vibOutPin4, vibOutPin5, vibOutPin6};
const int sensorPins[6] = {sensorPin1, sensorPin2, sensorPin3, sensorPin4, sensorPin5, sensorPin6};

int sensorValues[6], prevSensorValues[6];
bool isVibrating[6] = {false};
bool isInHoldPulse[6] = {false};

unsigned long lastFullPulse[6] = {0};    // For the initial full vibration
unsigned long lastHoldPulse[6] = {0};    // For the intermittent half-vibrations

const int rawDeltaThreshold = 100;
const int pressureHoldThreshold = 800;

const int fullStrength = 255;
const int halfStrength = 128;

const unsigned long fullPulseDuration = 500;     // 0.5s full pulse
const unsigned long halfPulseDuration = 500;     // 0.5s half pulse
const unsigned long interPulseDelay = 2000;      // Wait 2s before next half-pulse

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(vibPins[i], OUTPUT);
    pinMode(sensorPins[i], INPUT);
  }
}

void loop() {
  unsigned long currentMillis = millis();

  for (int i = 0; i < 6; i++) {
    sensorValues[i] = analogRead(sensorPins[i]);

    // Detect spike for full-strength pulse
    if (sensorValues[i] > prevSensorValues[i] + rawDeltaThreshold) {
      analogWrite(vibPins[i], fullStrength);
      isVibrating[i] = true;
      lastFullPulse[i] = currentMillis;
      isInHoldPulse[i] = false;
    }

    // End full-strength pulse
    else if (isVibrating[i] && currentMillis - lastFullPulse[i] >= fullPulseDuration) {
      analogWrite(vibPins[i], 0);
      isVibrating[i] = false;
      lastHoldPulse[i] = currentMillis;  // reset for delay before half-pulses
    }

    // Intermittent half-strength vibration if pressure remains high
    else if (sensorValues[i] > pressureHoldThreshold) {
      if (!isInHoldPulse[i] && currentMillis - lastHoldPulse[i] >= interPulseDelay) {
        analogWrite(vibPins[i], halfStrength);
        isInHoldPulse[i] = true;
        lastHoldPulse[i] = currentMillis;
      } else if (isInHoldPulse[i] && currentMillis - lastHoldPulse[i] >= halfPulseDuration) {
        analogWrite(vibPins[i], 0);
        isInHoldPulse[i] = false;
        lastHoldPulse[i] = currentMillis; // wait again before next half-pulse
      }
    }

    // No pressure: turn off vibration completely
    else {
      analogWrite(vibPins[i], 0);
      isInHoldPulse[i] = false;
    }

    prevSensorValues[i] = sensorValues[i];
  }

  delay(20);
}
