# Electrolysis Module — IX-PeySookaBlyad

This module outlines the real-world electrolysis system used in IX-PeySookaBlyad to rapidly convert rain and floodwater into hydrogen and oxygen — with **zero storage** and **immediate dispersion**.

---

## 💧 Objective

- Consume incoming water **as quickly as ambient power allows**
- Split H₂O into usable gases using **low-voltage, real-material electrodes**
- Expel hydrogen to atmosphere via passive chimney vent (safe, non-pressurized)
- Expel oxygen via side port
- No dangerous tanks. No hoarding. No explosion risk.

---

## ⚙️ Technical Architecture

### 🔋 Power Source
- Supplied by:
  - Ambient energy (solar, thermal, ground resonance, etc.)
  - Boost converter (5V → 12V @ ~2A) for electrolysis headroom
- Input voltage: **10–15V DC**
- Max current draw: **~2A**

### 🧪 Electrodes
- **Material**: Stainless steel 304 or nickel plate
- **Count**: 5 plates (2 cathodes, 2 anodes, 1 neutral return)
- **Spacing**: ~5–10 mm between plates
- **Surface area per plate**: ~70–100 cm²
- **Mounting**: Slide rail inside poly container for cleaning access

### ⚗️ Electrolysis Reaction
- Electrolyte: **Pure rainwater or floodwater** (trace ions provide conductivity)
- No additives unless conductivity too low (fallback: a pinch of NaCl if needed)
- Reaction:  
  **2H₂O → 2H₂ + O₂**
- Expected output at 12V 2A:  
  ~15–20 mL of hydrogen per second (small but continuous)

### 🛑 Safety & Disposal
- **Hydrogen vent**: 1-inch chimney vent with wire mesh & water trap
  - Vents upward into air immediately
  - Prevents backflash and insect intrusion
- **Oxygen vent**: Side slit + screen disperses safely
- **No pressure build-up**: All vent paths are always open
- **No storage tanks or cylinders**

---

## 🧠 Controller Integration

- Electrolysis is toggled ON/OFF via ESP32 GPIO relay if smart modulation is desired (optional)
- Water intake level is checked every 30s
- If water >15% full and energy available → electrolysis begins

---

## 📦 Physical Housing

- **Container**: Polypropylene (PP) or HDPE, sealed
- **Volume**: ~2L working space
- **Seals**: Rubber gasket + silicone edge bead
- **Service Port**: Removable top with locking ring
- **Drain plug**: Bottom corner for flushing debris buildup

---

## 🔧 Maintenance

- Electrode plates may build scale over time; clean every 3–6 months with vinegar rinse
- Inspect vent mesh for clogs or bugs
- Service ports are tool-free for field access

---

## 🌍 Deployment Notes

- System is designed for continuous, safe, autonomous operation
- Hydrogen is expelled instantly to prevent theft, ignition, or hoarding
- Output volume is small but **constant**, ensuring floodwater is processed fast and efficiently
- Units may be daisy-chained or mirrored in parallel across deployments

---

## ✅ Summary

This module transforms **floodwater into harmless gas**, releasing it safely with no tanks, no batteries, and no human intervention.  
It is designed to run forever, so long as the rain falls and the ambient field hums.

Build it. Seal it. Let it eat.
