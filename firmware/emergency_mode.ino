// firmware/emergency_mode.ino
// Failsafe logic for sensor blackout or sustained flood events
// Author: Bryce Wooster — IX-PeySookaBlyad

#define RELAY_PIN 7
#define LED_PIN 6
#define SENSOR_TIMEOUT_MS 10000
#define EMERGENCY_DURATION_MS 15000

unsigned long lastValidPing = 0;
bool emergencyActive = false;
unsigned long emergencyStart = 0;

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
  Serial.begin(9600);
}

void loop() {
  int level = readWaterLevel();  // this uses the shared ultrasonic logic
  unsigned long now = millis();

  if (level > 0 && level < 100) {
    lastValidPing = now;
    emergencyActive = false;
  }

  if (!emergencyActive && now - lastValidPing > SENSOR_TIMEOUT_MS) {
    activateEmergency();
  }

  if (emergencyActive && now - emergencyStart > EMERGENCY_DURATION_MS) {
    deactivateEmergency();
  }
}

int readWaterLevel() {
  // Placeholder: should call the shared ping routine
  // For now we simulate with random or stub
  return random(0, 120); // Replace with actual sonar call
}

void activateEmergency() {
  emergencyActive = true;
  emergencyStart = millis();
  digitalWrite(RELAY_PIN, HIGH);
  digitalWrite(LED_PIN, HIGH);
  Serial.println("EMERGENCY FLUSH MODE: ON");
}

void deactivateEmergency() {
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
  emergencyActive = false;
  Serial.println("EMERGENCY FLUSH MODE: OFF");
}
