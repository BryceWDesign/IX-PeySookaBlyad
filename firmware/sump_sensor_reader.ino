// firmware/sump_sensor_reader.ino
// Ultrasonic flood detection + intake activation logic
// Author: Bryce Wooster 

#include <Wire.h>
#include <NewPing.h>

#define TRIG_PIN 10
#define ECHO_PIN 11
#define MAX_DISTANCE_CM 200  // sensor ceiling height above pit

#define INTAKE_RELAY_PIN 7
#define LED_ALERT_PIN 6

unsigned long lastCheck = 0;
unsigned long checkInterval = 3000; // check every 3s
int flushTriggerLevel = 60; // cm to trigger flush

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE_CM);

void setup() {
  pinMode(INTAKE_RELAY_PIN, OUTPUT);
  pinMode(LED_ALERT_PIN, OUTPUT);
  digitalWrite(INTAKE_RELAY_PIN, LOW);
  digitalWrite(LED_ALERT_PIN, LOW);
  Serial.begin(9600);
}

void loop() {
  if (millis() - lastCheck > checkInterval) {
    lastCheck = millis();
    int level = sonar.ping_cm();
    if (level == 0) {
      Serial.println("No return - sensor might be out of range.");
      return;
    }

    Serial.print("Water level: ");
    Serial.print(level);
    Serial.println(" cm");

    if (level < flushTriggerLevel) {
      activateIntake();
    } else {
      deactivateIntake();
    }
  }
}

void activateIntake() {
  digitalWrite(INTAKE_RELAY_PIN, HIGH);
  digitalWrite(LED_ALERT_PIN, HIGH);
  Serial.println("Intake: ON");
}

void deactivateIntake() {
  digitalWrite(INTAKE_RELAY_PIN, LOW);
  digitalWrite(LED_ALERT_PIN, LOW);
  Serial.println("Intake: OFF");
}
