# Ambient Energy Harvesting Array — IX-PeySookaBlyad

This module defines the **multi-source ambient energy harvesting system**, designed to power:

- The tower’s ESP32-C3 logic
- Status LED ring
- Wireless charger shelf
- Supplemental energy for suction relay, if battery drops

It scavenges free energy from **sunlight**, **vibrations**, **ambient radio waves**, and **temperature differentials**.

---

## ⚡ Source Matrix

| Source Type      | Method                              | Output Power (typical)         |
|------------------|-------------------------------------|-------------------------------|
| Solar            | 12V flexible urban PV + DC buck     | 3–9W peak daytime             |
| Vibration        | Piezo panel inside base mount       | 50–200mW intermittent         |
| RF               | RF-to-DC scavenger (900MHz–2.4GHz)  | 5–50mW                         |
| Thermal          | TEG between intake water and frame  | 100–300mW during rain         |

---

## 🔩 Materials BOM

| Component                         | Source                   | Notes                          |
|----------------------------------|--------------------------|--------------------------------|
| 12V Flexible Solar Panel (6–9W)  | SunPower, Renogy, or OEM | Mounted around upper dome rim |
| Piezo Vibration Plate (≥20mm)    | SparkFun, Adafruit       | Mounted under suction motor   |
| TEG Module (40x40mm, e.g. TEC1)  | Amazon / OEM             | Sandwiches cold water vs warm steel |
| RF Harvester Board               | PowerCast / Coilcraft    | SMA antenna included          |
| Buck Regulator (12V→5V)          | Any high-efficiency buck | Powers USB/wireless coil      |

---

## 🔋 Energy Routing Logic

- All harvested energy is fed into a **central supercapacitor array**
- When capacitor > threshold → feeds 5V DC bus  
- If main battery low, it **buffers critical systems**: ESP32 + LED + wireless shelf  
- If all else fails, priority is:
  1. Emergency flush  
  2. Status beacon  
  3. Wireless charger  

---

## 🔧 Mounting Design

- **Solar:** flexible strips glued onto circular dome cap + vertical shell  
- **Piezo:** bonded underneath suction pump cavity to capture pump or vibration shock  
- **TEG:** contact surface between rainwater pipe and warm inner shell  
- **RF:** internal SMA antenna + reflective base plane in cap

---

## ✅ Why This Matters

The grid goes out.

Floods rise.

Your tower’s **last watt** decides whether a citizen knows it’s alive — or not.

This system gives it the **power to whisper**, even when the world’s gone silent.

Harvest everything. Waste nothing.
