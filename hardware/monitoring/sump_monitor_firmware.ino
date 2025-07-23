// hardware/monitoring/sump_monitor_firmware.ino
// IX-PeySookaBlyad — Sump Level Monitoring Firmware
// Author: Bryce Wooster
// Platform: Seeed Studio XIAO ESP32-C3

#include <WiFi.h>
#include <Wire.h>
#include <HardwareSerial.h>

// For ultrasonic distance sensor
#define TRIG_PIN 2   // GPIO for trigger pin
#define ECHO_PIN 3   // GPIO for echo pin

// System thresholds
#define SUMP_HEIGHT_CM 60         // Physical max height of sump pit
#define LEVEL_ALERT_CM 45         // Trigger height to consider "flood warning"
#define READ_INTERVAL_MS 30000    // Check level every 30 seconds

// LED pin (optional visual output)
#define ALERT_LED_PIN 10

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(ALERT_LED_PIN, OUTPUT);
  digitalWrite(ALERT_LED_PIN, LOW);

  Serial.println("IX-PeySookaBlyad Sump Monitor Booted");
}

void loop() {
  float level = readWaterLevelCM();
  Serial.print("Sump Level: ");
  Serial.print(level);
  Serial.println(" cm");

  if (level >= LEVEL_ALERT_CM) {
    digitalWrite(ALERT_LED_PIN, HIGH); // Flash alert light
    Serial.println("!!! FLOOD WARNING LEVEL REACHED !!!");
  } else {
    digitalWrite(ALERT_LED_PIN, LOW);
  }

  delay(READ_INTERVAL_MS);
}

float readWaterLevelCM() {
  long duration;
  float distanceCm;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distanceCm = duration * 0.034 / 2;

  float waterDepth = SUMP_HEIGHT_CM - distanceCm;
  return constrain(waterDepth, 0, SUMP_HEIGHT_CM);
}
