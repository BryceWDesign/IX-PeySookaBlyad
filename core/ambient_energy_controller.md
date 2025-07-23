# Ambient Energy Controller — IX-PeySookaBlyad

This module defines how all ambient energy sources (solar, thermal, Tesla-style inductive pickup, RF scavenging) are collected, balanced, and routed into usable power for:

- Electrolysis chamber
- Wireless public charging
- System beacon light
- Internal MCU logic

---

## ⚡ Inputs: Energy Harvesting Channels

### 1. **Solar Panel**
- Curved, weatherproof 12V flex panel (~10–15W peak)
- Output varies by sun intensity
- Connected via 12V→5V buck converter to shared rail

### 2. **Ground Resonance Coil**
- Copper coil wound around base with ferrite core
- Tapped into Earth’s minor EM fluctuations + local RF bleed
- Output: unpredictable, ~0.5–1.5V @ uA-mA range (boosted)

### 3. **Thermoelectric (TEG) Stack**
- 2–4 Peltier-style modules mounted between internal chamber and external wall
- Harvests delta-T between inside/outside air
- Output: 2–3V per unit under active cooling/heating gradient

### 4. **RF Harvester (Optional)**
- Antenna coil array with diode rectifier and cap bank
- Collects stray Wi-Fi, 3G/4G/5G radio waves
- Output: very low but persistent (uW-mW range)

---

## 🔀 Routing Logic (Simplified)

All sources feed into a **common supercapacitor bank** via individual **buck/boost converters**.

| Source         | Typical V In | Converter Needed | Role             |
|----------------|--------------|------------------|------------------|
| Solar Panel    | 12V          | Buck to 5V       | Primary load     |
| Ground Coil    | 0.8–1.2V     | Boost to 5V      | Supplemental     |
| Thermo Stack   | 2–3V         | Boost to 5V      | Nighttime core   |
| RF Harvester   | 0.5V         | Boost to 5V      | Idle-state trickle |

---

## 🔋 Storage & Buffer

- Central buffer: **2x 25V 4700uF supercapacitors**
- Connected in parallel
- Smoothed output feeds:
  - Electrolysis driver (12V via boost)
  - Qi charging module (5V regulated)
  - ESP32 MCU (via LDO or 3.3V buck)
  - LED beacon ring (direct or relay-driven)

---

## 🔄 Load Priority

1. **System operation** (MCU + sensors)
2. **Electrolysis** (floodwater processing)
3. **Beacon LED ring**
4. **Public phone charging (Qi)** — *only enabled when surplus available*

Surplus energy (esp. solar midday) is bled through LED ring for visibility and voltage drain.

---

## 🔥 Failover Behavior

- If energy falls below 3.3V:
  - MCU enters low-power sleep
  - Electrolysis pauses
  - Only beacon LED pulses dimly via RF trickle
- If water level is low, energy is cached
- If water is present and power exists → electrolysis prioritized

---

## 🧠 Smart Controller Upgrade (Optional)

- Add MPPT solar controller if budget allows
- ESP32 PWM pin can dynamically switch loads based on real-time telemetry
- Mesh firmware upgrade can prioritize energy sharing between nearby towers

---

## ✅ Summary

IX-PeySookaBlyad isn’t just off-grid.  
It’s **grid-agnostic**.  
Every spark that hits it is converted into work — work that helps people survive floods.  
Whether it’s the sun, the soil, or the stray static in the air — it **eats everything** and gives power back.
