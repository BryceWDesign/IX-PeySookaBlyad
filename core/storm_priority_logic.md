# Storm Priority Logic — IX-PeySookaBlyad

This module defines how the system shifts into **storm surge priority mode** — ensuring the device **maximizes water consumption and safety feedback** during extreme rain events.

---

## 🧠 Trigger Conditions

Storm priority mode activates when:

- Sump sensor reads water height >80% of internal volume  
- External rainfall detector (optional) exceeds 50mm/hr  
- Capacitor voltage is stable enough to sustain electrolysis

---

## 🔄 System Behavior Shift

| Subsystem             | Normal Mode                        | Storm Priority Mode                  |
|----------------------|------------------------------------|--------------------------------------|
| Electrolysis          | Intermittent bursts                | Continuous operation                 |
| Phone Charging        | Enabled if surplus power           | **Disabled immediately**             |
| LED Beacon            | Normal soft glow                   | **Strobing RED (1Hz pulse)**         |
| MCU Activity          | 30s interval checks                | 10s rapid scan loop                  |
| Energy Routing        | Priority: Charge > Electrolysis    | Priority: Electrolysis > Beacon > MCU only |
| Logging/Telemetry     | Passive logging                    | Aggressive mode if mesh is enabled   |

---

## 📛 Visual Feedback (Public View)

- Beacon flashes RED when storm priority is active  
- Charging shelf glows **off**, signaling unavailable service  
- Optional audio module may chirp or click as passive alert

---

## 💾 Optional Storm State Logging

- ESP32-C3 can store storm events in flash memory (timestamp, duration, peak water level)  
- Data can be retrieved over BLE or mesh OTA to help improve grid placement

---

## 🛑 Failover Behavior

If energy levels drop while in storm mode:

1. Electrolysis is throttled to minimum sustaining voltage
2. All non-essential loads disabled
3. LED switches to **dim red pulse** every 30 seconds
4. Unit remains in storm mode until water height returns <50%

---

## 🔐 Safeguards

- Charging is physically and programmatically cut off  
- All hydrogen vent paths remain open  
- Beacon cannot be disabled manually while water is above danger threshold

---

## ✅ Summary

Storm mode is the **life-saving override**.

When the streets flood, people don’t need Instagram.  
They need the water gone — **fast**.  
This logic ensures the tower becomes a single-minded flood killer,  
until it can breathe again.
