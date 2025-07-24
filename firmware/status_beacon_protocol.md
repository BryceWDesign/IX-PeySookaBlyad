# Status Beacon Protocol — IX-PeySookaBlyad

The **status beacon** is the visible pulse from the tower's upper LED ring — designed to **communicate real-time tower status** using universally recognizable **color-coded blink patterns**.

> 📡 This lets civilians, city workers, and emergency services know what the unit is doing **even if comms go down.**

---

## 🔷 Physical Hardware

- **LED Ring**: 16–24 addressable RGB LEDs (WS2812B or similar)
- **Controller**: XIAO ESP32-C3
- **Position**: Embedded under the top shelf dome (visible but rain-protected)
- **Power Source**: Shared with tower internal battery (auto-load balanced)

---

## 🚦 Status Colors + Blink Codes

| Mode                     | LED Color | Blink Pattern          | Meaning                            |
|--------------------------|-----------|------------------------|-------------------------------------|
| Standby (normal)         | Green     | 1 slow blink per 10s   | Tower healthy + ready               |
| Charging via rain        | Blue      | 1 fast blink per 2s    | Water detected, active suction      |
| Hydrogen venting         | Cyan      | Breathing fade loop    | Safe H₂ release in progress         |
| Emergency override       | Red       | Rapid 3-blink burst    | Sensor failure → auto-flush engaged |
| Power low (<30%)         | Yellow    | 1 long blink per 6s    | Battery is low, tower still active  |
| Offline/fault            | White     | Constant ON            | Check relay, vent, or sensor        |

---

## 🧠 Firmware Integration Logic

```cpp
// Simplified logic overview
if (emergencyActive) {
  pulseLED("red", 3, 200);
}
else if (ventingH2) {
  fadeLoop("cyan");
}
else if (suctionActive) {
  blinkLED("blue", 1, 500);
}
else if (batteryLow) {
  blinkLED("yellow", 1, 2000);
}
else {
  blinkLED("green", 1, 10000);
}
```

LED control is tied to **tower logic state** — no user input needed.  
LEDs auto-shutdown at critical battery floor (≤10%) to preserve core logic power.

---

## 🧪 Visibility Range & Brightness

- Default brightness: **65%** (suitable for most urban installs)
- Night mode dimming: Optional LDR sensor to scale down at night
- Max visual range: ~150–200m line-of-sight in clear weather

---

## ⚙️ Maintenance Notes

| Concern        | Design Countermeasure                   |
|----------------|------------------------------------------|
| Water ingress  | Dome shelf covers LEDs                   |
| Sun bleaching  | UV-rated LED diffusers or RGBW strips    |
| LED failure    | Modular strip, replaceable in <10 mins   |
| Vandalism      | Recessed placement, tamper screws        |

---

## ✅ Why This Matters

These towers aren’t just machines.

They’re **beacons**.

They show people something is working when the world around them is flooded, dark, or broken.

This status system makes the tower *speak back* to the people it’s saving.

Sometimes... just knowing it’s alive is enough.
