# Charging Ring Subsystem — IX-PeySookaBlyad

Each tower includes a **public-facing charging station** designed to let anyone wirelessly charge their phone — no cable, no plug, no login.

This is built into a **two-shelf ring structure** positioned ~4 feet from the base, protected from rain, kids, pets, and vandals.

---

## 🧱 Physical Design

| Component           | Spec / Material                                      |
|---------------------|------------------------------------------------------|
| Base ring shelf     | Circular shelf, 4" wide, 3 ft diameter               |
| Upper rain shield   | Matching shelf, 6" above base shelf                  |
| Charging pad insert | Embedded Qi coil under toughened glass or epoxy top |
| Status lighting     | Circular LED ring, green when active, red if offline|
| Structural material | Repurposed tire rubber + weather-grade ABS shell    |

> 🧠 Bonus: recycled rubber adds weather resistance, softness, and impact survivability.

---

## ⚡ Charging Specs

| Feature             | Value                            |
|---------------------|----------------------------------|
| Standard            | Qi v1.2 or higher                |
| Output              | 5W – 10W (adaptive by phone)     |
| Voltage Input       | 5V–12V (from tower's central rail)|
| Pad Count           | 3 pads evenly spaced per tower   |
| Safety Distance     | Auto-disable if water detected   |

---

## 💡 LED Trim Logic

- Trim ring lights up when tower is live  
- Pulses when water is being processed  
- Flashes red if hydrogen vent fails  
- Uses low-power 2812B (NeoPixel) or analog strip  
- Controlled via GPIO on ESP32-C3

---

## 🔧 Real-World Parts

| Vendor        | Part                            | Notes                          |
|---------------|----------------------------------|--------------------------------|
| Adafruit      | Qi Wireless Charger Transmitter | 5V input, low profile          |
| SparkFun      | WS2812B LED Ring (24px)         | Addressable, visible in daylight |
| AliExpress    | Qi Modules with epoxy layer     | Prebuilt insert for epoxy or polycarbonate mount |
| ReRubber      | Crumb rubber sheets             | Recycled material for mounting |
| Local fab     | CNC laser cut ABS ring frame    | Bolt-on retrofit

---

## 🧠 Design Notes

- Shelves should include water runoff grooves  
- Use tamper-proof fasteners to mount insert trays  
- Clear icon engraving ("📱⚡") recommended  
- Charging only available when tower has >20% battery  
- Optionally tied to BLE beacons to notify users nearby

---

## 🛡️ Safety

- Epoxy-sealed coils: fully weatherproof  
- Short-range inductive field: safe for skin  
- Auto cut-off if overheating, surge, or liquid detection  
- UL-listed preferred if importing

---

## ✅ Summary

You walk up. You put your phone down. You walk away charged.  
This isn’t just fighting the flood — it’s powering the people.

Even in the rain. Even at night.  
**Because power should be free when nature’s this brutal.**
