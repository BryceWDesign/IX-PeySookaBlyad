// firmware/status_led_driver.ino
// Controls all RGB and signal lighting for IX-PeySookaBlyad
// Author: Bryce Wooster 

#include <Adafruit_NeoPixel.h>

#define RING_PIN 4
#define CAP_PIN  5
#define NUM_RING_LEDS 24
#define NUM_CAP_LEDS  16

Adafruit_NeoPixel ring(NUM_RING_LEDS, RING_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel cap(NUM_CAP_LEDS, CAP_PIN, NEO_GRB + NEO_KHZ800);

enum TowerState {
  IDLE,
  CHARGING,
  STORM_MODE,
  VENTING,
  SELF_CLEANING,
  ERROR_STATE
};

TowerState currentState = IDLE;

void setup() {
  ring.begin();
  cap.begin();
  ring.show();
  cap.show();
}

void loop() {
  updateLEDs(currentState);
  delay(100);
}

void updateLEDs(TowerState state) {
  switch (state) {
    case IDLE:
      pulseColor(ring, 0xFFA500); // Amber pulse
      solidColor(cap, 0xFFA500);
      break;
    case CHARGING:
      blinkColor(ring, 0x00FF00, 500);
      solidColor(cap, 0x00FF00);
      break;
    case STORM_MODE:
      blinkColor(cap, 0xFFFFFF, 300);
      pulseColor(ring, 0xFFFFFF);
      break;
    case VENTING:
      pulseColor(cap, 0x0000FF);
      solidColor(ring, 0x0000FF);
      break;
    case SELF_CLEANING:
      rainbowWave(ring);
      rainbowWave(cap);
      break;
    case ERROR_STATE:
      solidColor(ring, 0xFF0000);
      solidColor(cap, 0xFF0000);
      break;
  }
}

// ========== Effects ==========

void solidColor(Adafruit_NeoPixel& strip, uint32_t color) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}

void blinkColor(Adafruit_NeoPixel& strip, uint32_t color, int interval_ms) {
  static unsigned long lastToggle = 0;
  static bool on = false;
  if (millis() - lastToggle >= interval_ms) {
    on = !on;
    lastToggle = millis();
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, on ? color : 0);
    }
    strip.show();
  }
}

void pulseColor(Adafruit_NeoPixel& strip, uint32_t color) {
  static int brightness = 0;
  static int delta = 5;

  brightness += delta;
  if (brightness <= 0 || brightness >= 255) delta = -delta;

  for (int i = 0; i < strip.numPixels(); i++) {
    uint8_t r = (uint8_t)((color >> 16) & 0xFF) * brightness / 255;
    uint8_t g = (uint8_t)((color >> 8) & 0xFF) * brightness / 255;
    uint8_t b = (uint8_t)(color & 0xFF) * brightness / 255;
    strip.setPixelColor(i, strip.Color(r, g, b));
  }
  strip.show();
}

void rainbowWave(Adafruit_NeoPixel& strip) {
  static uint16_t j = 0;
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.ColorHSV((i * 65536 / strip.numPixels() + j) % 65536));
  }
  strip.show();
  j += 256;
}
