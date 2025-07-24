# System Validation Protocol — IX-PeySookaBlyad

This document defines the **full testing checklist and validation methods** for ensuring that each PeySooka tower unit functions correctly **before field deployment**.

All tests must be conducted **on-site or at staging area** before live use.

---

## 🔋 Power System Tests

| Test Name          | Method                                                         | Pass Criteria                |
|--------------------|----------------------------------------------------------------|------------------------------|
| Solar Panel Check  | Shade → sunlight transition test (multimeter)                 | 5V+ output surge in 3 sec    |
| Ambient Harvesting | RF + thermal coil under heat lamp                              | Detects >0.1W generation     |
| Battery Reserve    | Full charge → timed drain via load resistor                    | Minimum 4hr backup runtime   |
| Auto-Flush Trigger | Battery underdrain → observe emergency water expel            | Flush initiates at threshold |

---

## 💧 Water Intake and Disposal

| Test Name          | Method                                                        | Pass Criteria                     |
|--------------------|---------------------------------------------------------------|-----------------------------------|
| Suction Activation | Pour 3L water into intake basin                               | Flow rate ≥ 1L/sec                |
| Filter Check       | Visual inspect lower mesh screen                              | 100% intact, no tear              |
| Overflow Bypass    | Block primary drain and test secondary vent                    | Overflow exits through top port  |
| Odor Emission      | Hydrogen vented test → use gas sensor                         | No trapped H₂ — vent completes   |

---

## 📶 Wireless Charging Test

| Test Name          | Method                                                       | Pass Criteria                     |
|--------------------|--------------------------------------------------------------|-----------------------------------|
| Phone Detection    | Place Qi-enabled phone on pad                                | Blue → Green LED within 2 sec    |
| Rain Resistance    | Drizzle water on shelf and retry                             | Still charges, no error flash    |
| LED Ring Test      | Cover solar panel, watch for red indicator                   | Red appears = low power state    |
| Foreign Object     | Metal key on coil = no charge, LED red                       | Safety trip functions             |

---

## 🌐 ESP32 Monitoring

| Test Name          | Method                                                       | Pass Criteria                     |
|--------------------|--------------------------------------------------------------|-----------------------------------|
| Boot Sequence      | Power-on via 3.7V Li-Ion                                     | Serial debug: “Node Online”      |
| Ultrasonic Sensor  | Insert test float object into pit                            | Sensor reports change in depth   |
| LoRa Broadcast     | (If used) — Simulate 3 towers with LoRa comms                | Ping and data sync succeed       |

---

## ⚙️ Mechanical + Weather Stress

| Test Name          | Method                                                       | Pass Criteria                     |
|--------------------|--------------------------------------------------------------|-----------------------------------|
| Vibration Test     | Simulate street rumble (shaker plate or hammer tap)         | No loosened joints or shorts     |
| Rain Simulation    | Hose down from above for 2 min                               | No water ingress to internal bay |
| Dust Ingress       | Fine powder blown at intake skirt                           | Filters prevent major entry      |
| Tamper Attempt     | Attempt to unscrew panels with standard tools                | No removal without specialty bit |

---

## 🧾 Final Sign-Off Checklist

- [ ] All LED states verified  
- [ ] Suction system passes flow test  
- [ ] Water basin drains fully  
- [ ] H₂ vent emits no odor trace  
- [ ] All charging pads work post-wet test  
- [ ] No panel or dome is loose  
- [ ] Unit label and QR code applied  
- [ ] Deployment site geo-logged  

---

## ✅ Why This Matters

You don't win public trust with press releases.

You earn it by **never deploying a unit that fails the checklist**.

This isn't just quality control — it's **life control**. When you're knee-deep in water and still have signal on your phone…  
that’s not an accident.

That’s a tower that passed **this test**.
