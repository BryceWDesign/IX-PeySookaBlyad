// firmware/power_router_firmware.ino
// IX-PeySookaBlyad — Power Allocation Controller
// Platform: Seeed Studio XIAO ESP32-C3

// Pin definitions
#define ELECTROLYSIS_RELAY 4
#define QI_CHARGER_RELAY   5
#define BEACON_LED_PIN     6

// ADC pin for capacitor voltage
#define CAP_VOLTAGE_PIN    A0

// Thresholds (in volts)
const float V_ELECTROLYSIS_ON = 5.5;
const float V_CHARGER_ON      = 6.2;
const float V_SYSTEM_MIN      = 3.3;

bool stormMode = false;

void setup() {
  Serial.begin(115200);
  pinMode(ELECTROLYSIS_RELAY, OUTPUT);
  pinMode(QI_CHARGER_RELAY, OUTPUT);
  pinMode(BEACON_LED_PIN, OUTPUT);

  digitalWrite(ELECTROLYSIS_RELAY, LOW);
  digitalWrite(QI_CHARGER_RELAY, LOW);
  digitalWrite(BEACON_LED_PIN, LOW);

  Serial.println("Power Router Online");
}

void loop() {
  float capVoltage = readCapacitorVoltage();
  Serial.print("Capacitor Voltage: ");
  Serial.println(capVoltage);

  if (stormMode) {
    handleStormPriority(capVoltage);
  } else {
    handleNormalPriority(capVoltage);
  }

  delay(5000); // Check every 5 seconds
}

float readCapacitorVoltage() {
  int raw = analogRead(CAP_VOLTAGE_PIN);
  float voltage = (raw / 4095.0) * 7.5; // Adjust 7.5V max based on voltage divider
  return voltage;
}

void handleStormPriority(float v) {
  if (v > V_SYSTEM_MIN) {
    digitalWrite(ELECTROLYSIS_RELAY, HIGH);  // Always on during storm
    digitalWrite(BEACON_LED_PIN, HIGH);      // Alert mode
    digitalWrite(QI_CHARGER_RELAY, LOW);     // Charging disabled
    Serial.println("Storm Mode: Electrolysis ON, Charging OFF");
  } else {
    powerDownAll();
    Serial.println("Storm Mode: Low power fallback");
  }
}

void handleNormalPriority(float v) {
  if (v >= V_CHARGER_ON) {
    digitalWrite(QI_CHARGER_RELAY, HIGH);
    Serial.println("Normal Mode: Charging ENABLED");
  } else {
    digitalWrite(QI_CHARGER_RELAY, LOW);
    Serial.println("Normal Mode: Charging DISABLED");
  }

  if (v >= V_ELECTROLYSIS_ON) {
    digitalWrite(ELECTROLYSIS_RELAY, HIGH);
    Serial.println("Normal Mode: Electrolysis ENABLED");
  } else {
    digitalWrite(ELECTROLYSIS_RELAY, LOW);
    Serial.println("Normal Mode: Electrolysis DISABLED");
  }

  digitalWrite(BEACON_LED_PIN, HIGH); // Always on
}

void powerDownAll() {
  digitalWrite(ELECTROLYSIS_RELAY, LOW);
  digitalWrite(QI_CHARGER_RELAY, LOW);
  digitalWrite(BEACON_LED_PIN, LOW);
}
