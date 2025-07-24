# Wireless Charging Shelf — IX-PeySookaBlyad

This module outlines the **phone-safe**, **rain-sheltered**, and **flood-resilient wireless charging system** integrated into the PeySooka tower at street-access height.

---

## 🧩 Core Design Features

- **Primary Shelf:** 4-foot height — ergonomic for adults
- **Rain Hood:** Second shell above shelf — fully shields charging port
- **Wireless Coil:** Qi-compatible, fixed-position coil beneath shelf glass
- **No Cable Ports:** Wireless only — prevents shock hazard and vandalism

---

## ⚡ Charging Hardware

| Component                     | Specs / Notes                                |
|------------------------------|----------------------------------------------|
| Qi Charging Coil             | 5V input / 1A output (5W)                     |
| Wireless Charging Controller | Any Qi-standard module (e.g., XKT-412)       |
| Shelf Top Surface            | Polycarbonate or Gorilla Glass (shatterproof)|
| LED Ring (Green/Blue/Red)    | Embedded to indicate charge status           |

---

## 🟢 Status Indicator Logic

| LED Color | Meaning                         |
|-----------|----------------------------------|
| Blue      | Idle, ready to charge           |
| Green     | Charging device                 |
| Red       | No power / error / flooded base |

---

## 🛠️ Mounting Instructions

| Step | Action                                       |
|-----:|----------------------------------------------|
| 1    | Align shelf ring to pole at 4ft height       |
| 2    | Use weatherproof bolts + vibration gasket    |
| 3    | Seal wireless coil in epoxy-potted chamber   |
| 4    | Test with waterproof phone before final lock |
| 5    | Ensure dome rain shield is locked above it   |

---

## 🔌 Power Source Routing

- Default source: Ambient energy system (solar + RF + thermal)
- Backup source: Tower battery (shared with pump + ESP32)
- Priority logic:
  1. Wireless coil active if capacitor voltage > threshold  
  2. Shutoff if battery reserve drops below emergency flush minimum

---

## 🧼 Hygiene and Debris Mitigation

- Surface treated with hydrophobic nano-coating (e.g., Rain-X variant)
- Rounded lip prevents water pooling
- Integrated mesh undertray catches sand/debris
- Easy-swap top panel for public maintenance crews

---

## 🔐 Security and Abuse Resistance

- No open ports = no vandal loop
- No plug = no cable theft
- Coil only activates with valid coil handshake
- Epoxy-potted electronics = waterproof and tamperproof

---

## ✅ Why This Matters

When floods knock out the grid, your phone becomes your lifeline.  

These shelves **don’t ask for coins**. They don’t demand passwords.  
They **just charge** — in the dark, in the rain, in the chaos.

This is not convenience.  
This is **infrastructure disguised as kindness**.
