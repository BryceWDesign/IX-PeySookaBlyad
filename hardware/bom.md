# Bill of Materials — IX-PeySookaBlyad

This BOM lists all components required to build a single IX-PeySookaBlyad unit. All parts are selected based on availability, affordability, and urban flood resilience.

---

## 🧱 STRUCTURE & ENCLOSURE

| Component                         | Description                                 | Qty | Est. Cost | Notes |
|----------------------------------|---------------------------------------------|-----|-----------|-------|
| Cylindrical housing shell        | Recycled tire rubber + ABS hybrid shell     | 1   | $45.00    | Repurpose tires; outer shell ~9ft tall |
| Weatherproof top intake cover    | Steel mesh dome + polymer lip               | 1   | $15.00    | Blocks debris and insects |
| Bottom intake skirt + mesh       | 1-inch gap + galvanized steel grid          | 1   | $12.00    | Rodent-resistant intake perimeter |
| Internal base ballast            | Local concrete fill or rebar                | 1   | $10.00    | Anchor against wind/flood push |

---

## ⚡ ENERGY HARVESTING

| Component                         | Description                                 | Qty | Est. Cost | Notes |
|----------------------------------|---------------------------------------------|-----|-----------|-------|
| 12V Flexible Solar Panel         | Waterproof, curved mount                    | 1   | $22.00    | Wraps around upper structure |
| Thermoelectric TEG Module (5V)   | Peltier-style energy harvester              | 2   | $8.00     | Optional, pairs with vent exhaust differential |
| Ground Coil (Tesla pickup)       | Copper coil w/ ferrite + tuning cap         | 1   | $9.00     | Mounted in subgrade ring or base |
| Energy capacitor bank (25V, 4700uF+) | Bulk energy smoothing                     | 1   | $6.00     | Regulates electrolysis bursts |

---

## 💧 ELECTROLYSIS SYSTEM

| Component                         | Description                                 | Qty | Est. Cost | Notes |
|----------------------------------|---------------------------------------------|-----|-----------|-------|
| Stainless steel or nickel plates | 5x electrode plates for water splitting     | 5   | $10.00    | Rustproof; spacing based on voltage curve |
| Electrolysis container           | Heat-rated, sealed polypropylene tank       | 1   | $15.00    | Integrated drain/vent ports |
| DC Boost Converter (5V to 12V)   | To step up harvested energy                 | 1   | $4.00     | Used to sustain electrolysis curve |
| Exhaust chimney + mesh cover     | Aluminum vent + bug mesh                    | 1   | $6.00     | For hydrogen dispersion, always open |

---

## 🔋 WIRELESS CHARGING MODULE

| Component                         | Description                                 | Qty | Est. Cost | Notes |
|----------------------------------|---------------------------------------------|-----|-----------|-------|
| Qi Wireless Charging Coil        | 10W standard, Type-A ready                  | 1   | $5.00     | Compatible with all modern phones |
| 5V Regulated Buck Converter      | Smooth power for charging coil              | 1   | $3.00     | From energy bank or solar directly |
| Protective shelf ring (ABS)      | UV-stable phone platform                    | 1   | $5.00     | 4 ft high mount height for user access |

---

## 🧠 SMART MONITORING CORE

| Component                         | Description                                 | Qty | Est. Cost | Notes |
|----------------------------------|---------------------------------------------|-----|-----------|-------|
| Seeed Studio XIAO ESP32-C3       | Microcontroller with Wi-Fi/BLE              | 1   | $6.50     | Ultra compact, supports OTA |
| HC-SR04 Ultrasonic Sensor        | Water level sensing module                  | 1   | $1.50     | Reads pit depth in real time |
| LED Indicator (Red/Orange/Green) | Visual status lights                        | 3   | $0.75     | Glows based on water level |
| Weather-sealed enclosure         | IP65 poly box for MCU & sensor              | 1   | $4.00     | Mountable behind phone shelf |

---

## 💡 LIGHT & STATUS MODULE

| Component                         | Description                                 | Qty | Est. Cost | Notes |
|----------------------------------|---------------------------------------------|-----|-----------|-------|
| High-efficiency LED strip/ring   | Beacon light for energy bleed               | 1   | $3.50     | Always on if power is present |
| Light dome cover (frosted ABS)   | Diffuser shell for top lamp                 | 1   | $2.50     | Glows to indicate system alive |

---

## 🛠️ MISC + FASTENERS

| Component                         | Description                                 | Qty | Est. Cost | Notes |
|----------------------------------|---------------------------------------------|-----|-----------|-------|
| Silicone gasket + caulk kit      | Waterproof all panel edges                  | 1   | $4.00     | Critical for high rain zones |
| Mounting hardware kit            | Screws, anchors, sealing washers            | 1   | $5.00     | Includes pole base and access panel bolts |
| Wiring & Connectors              | 22–18AWG wire, heatshrink, JST              | 1   | $6.00     | General internal wiring bundle |

---

## 🧾 TOTAL ESTIMATED COST PER UNIT

**~ $240.25 USD** (as of 2025)  
Prices can drop with bulk sourcing or local material substitutions (especially outer shell, ballast, and wiring).

---

## 🌍 Sourcing Notes

- All parts are chosen for international availability (AliExpress, Amazon, Mouser, Seeed, Banggood)
- Electrolysis plates, rubber shell, and intake mesh can be locally manufactured from recycled goods or scrap
- Tuning, spacing, and grounding guides to follow in individual module docs

---

**Build cheap. Build strong. Deploy wide. Let nothing drown unchallenged.**
