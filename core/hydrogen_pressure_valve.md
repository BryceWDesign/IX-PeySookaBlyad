# Hydrogen Pressure Valve Subsystem — IX-PeySookaBlyad

This module governs **safe, rapid venting** of generated hydrogen gas during electrolysis operations in storm conditions.

Hydrogen must be **expelled immediately** to avoid:
- Compression buildup
- Unauthorized storage
- Delays in water throughput during heavy rainfall

---

## 💨 Valve Type

| Feature          | Value                      |
|------------------|----------------------------|
| Type             | Normally-closed solenoid valve  
| Size             | 1/4" BSP or compression fit  
| Material         | Stainless steel or brass, Viton seal  
| Pressure Rating  | 0–100 psi  
| Operating Voltage| 3.3V–5V (direct from ESP32 GPIO via MOSFET)  
| Activation Method| Software-controlled OR analog burst threshold  

---

## 📟 Control Logic

> Controlled by `storm_priority()` and `venting_flag` signals in firmware stack

### Basic Logic Flow:
```
IF (electrolysis_active == true) AND (sump_cm > threshold):
    enable_valve()
    delay(7000ms)
    disable_valve()
```

### Emergency Pressure Mode:
- Optional analog pressure sensor (e.g., MPX5700 or BMP280 repurposed for gas chamber)
- Override timer logic if pressure exceeds 30 psi
- Can trigger an LED beacon or warning tone

---

## 🧱 Physical Placement

- Located **above electrolysis chamber** in vertical escape stack  
- 20cm copper or PTFE tube guides gas vertically upward  
- Covered by angled weather shroud with screen to block debris/insects  
- Optional flame arrestor insert (sintered bronze)

---

## 🔋 Power Budget

| State        | Current Draw |
|--------------|--------------|
| Idle (closed)| 0 mA         |
| Open (active)| ~140–250 mA  |
| Burst Cycle  | ~2–4 seconds typical |
| Compatible With| PWM MOSFET driver (IRFZ44N or similar) |

---

## 🧠 Safety Notes

- Always vent into **open air**, never enclosed containers  
- Never store hydrogen — vent it hot, wet, and gone  
- No flame/no spark zone enforced within 20cm  
- Optional redundancy: second mechanical pop-off valve at 40 psi

---

## 🛠️ Real-World Parts (Suggested)

| Vendor          | Model                     | Notes                        |
|------------------|---------------------------|------------------------------|
| Tameson          | Brass 1/4" N.C. Valve     | Compact, low-voltage         |
| SparkFun         | MPX5700 Analog Sensor     | Pressure sensing option      |
| McMaster-Carr    | Flame Arrestor Insert     | Safety-grade, 10mm diameter  |
| Aliexpress       | IRFZ44N MOSFET modules    | GPIO triggered driver        |

---

## ✅ Summary

Hydrogen wants to float. Let it.  
This system opens a door, not a storage tank.  
Push it out, move the water, drop the flood.

This isn't about storing energy.  
It's about restoring streets.
