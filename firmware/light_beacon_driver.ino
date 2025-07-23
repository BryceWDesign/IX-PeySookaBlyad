// firmware/light_beacon_driver.ino
// IX-PeySookaBlyad – System Beacon Driver
// Platform: Seeed Studio XIAO ESP32-C3
// Purpose: Drive beacon light color/pattern based on flood status

#define GREEN_PIN 6
#define ORANGE_PIN 7
#define RED_PIN 8

// These will be controlled externally by sump sensor logic via I2C or GPIO if integrated
int sumpLevel = 0; // Value: 0 = low, 1 = medium, 2 = high

void setup() {
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(ORANGE_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("Beacon Light Driver Online");
}

void loop() {
  updateBeacon(sumpLevel);

  // For test/demo only – cycle through all 3 levels
  sumpLevel = (sumpLevel + 1) % 3;
  delay(15000); // Switch every 15s (testing only)
}

void updateBeacon(int level) {
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(ORANGE_PIN, LOW);
  digitalWrite(RED_PIN, LOW);

  switch (level) {
    case 0:
      digitalWrite(GREEN_PIN, HIGH);
      Serial.println("Status: NORMAL (Green)");
      break;
    case 1:
      digitalWrite(ORANGE_PIN, HIGH);
      Serial.println("Status: FILLING (Orange)");
      break;
    case 2:
      digitalWrite(RED_PIN, HIGH);
      Serial.println("Status: HIGH FLOOD RISK (Red)");
      break;
    default:
      Serial.println("Status: UNKNOWN");
  }
}
