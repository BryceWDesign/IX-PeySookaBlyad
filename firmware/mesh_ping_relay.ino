// firmware/mesh_ping_relay.ino
// ESP32-C3 | IX-PeySookaBlyad Mesh Relay Firmware
// Author: Bryce Wooster (2025) – All Rights Reserved

#include <esp_now.h>
#include <WiFi.h>

// STRUCT: Payload structure
typedef struct struct_message {
  char tower_id[12];    // Unique short ID
  bool storm_active;    // Storm Priority mode flag
  uint8_t batt_percent; // Battery status 0–100
  uint16_t sump_cm;     // Last ultrasonic reading (cm)
  bool venting;         // Hydrogen venting state
} struct_message;

struct_message outgoing;
uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

// Setup callback
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("Mesh ping sent: ");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "✅ SUCCESS" : "❌ FAIL");
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    Serial.println("❌ ESP-NOW init failed");
    return;
  }
  esp_now_register_send_cb(OnDataSent);
  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;
  esp_now_add_peer(&peerInfo);
}

void loop() {
  // Set test message values — in real deployment, pull from local sensors
  strcpy(outgoing.tower_id, "PSB-MNL-01");
  outgoing.storm_active = true;
  outgoing.batt_percent = 78;
  outgoing.sump_cm = 44;
  outgoing.venting = true;

  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *)&outgoing, sizeof(outgoing));
  if (result == ESP_OK) {
    Serial.println("📡 Ping sent to mesh");
  } else {
    Serial.println("⚠️ Mesh ping error");
  }

  delay(30000); // Ping every 30 seconds
}
