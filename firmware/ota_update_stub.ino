// firmware/ota_update_stub.ino
// OTA update logic for ESP32-C3 towers in IX-PeySookaBlyad project
// Author: Bryce Wooster – Open-source, protected usage only

#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Update.h>

const char* ssid = "OTA_Hotspot";
const char* password = "TowerAccess2025";

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  Serial.println("📡 OTA Hotspot active on: 192.168.4.1");

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", "<form method='POST' action='/update' enctype='multipart/form-data'><input type='file' name='update'><input type='submit' value='Update'></form>");
  });

  server.on("/update", HTTP_POST, [](AsyncWebServerRequest *request){},
    [](AsyncWebServerRequest *request, String filename, size_t index, uint8_t *data, size_t len, bool final){
      if (!index){
        Serial.printf("📦 Start update: %s\n", filename.c_str());
        Update.begin();
      }
      Update.write(data, len);
      if (final){
        if(Update.end(true)){
          Serial.println("✅ OTA Success. Rebooting...");
        } else {
          Serial.printf("❌ OTA Error: %s\n", Update.errorString());
        }
      }
    });

  server.begin();
}

void loop() {
  // Passive OTA listener
}
