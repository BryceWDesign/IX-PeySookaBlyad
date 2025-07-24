# Sensor Enclosure Specification — IX-PeySookaBlyad

This document defines the physical enclosure used to house the system’s **ESP32-C3 microcontroller** and **ultrasonic water level sensor**, ensuring protection from rain, debris, and heat while remaining serviceable in the field.

---

## 📐 Mounting Position

- Location: Internal tower chamber, ~30cm above sump bottom
- Orientation: Sensor faces vertically downward into sump
- Enclosure is **side-mounted** to structural column or wall bracket

---

## 🧱 Housing Materials

| Component             | Material                    | Notes                           |
|----------------------|-----------------------------|---------------------------------|
| Main Box             | ABS or PC plastic (IP65/IP67)| Impact-resistant, UV-safe       |
| Mounting Bracket     | Stainless steel or reinforced nylon | Pre-drilled wall slots   |
| Gasket Seal          | Silicone O-ring or edge bead | Waterproof compression seal     |
| Access Cover         | Screw-sealed lid (4-point)   | For firmware or sensor service  |
| Condensation Trap    | Optional Gore vent plug      | Equalizes pressure/humidity     |

---

## 🧰 Internal Layout

| Element           | Placement                        |
|------------------|-----------------------------------|
| ESP32-C3 Board   | Mounted flat against rear wall    |
| Power wires      | Enters through sealed grommet     |
| HC-SR04 Sensor   | Mounted at bottom opening         |
| Optional LED     | Exits through clear front window  |
| Sensor opening   | 22mm diameter, waterproof foam collar + mesh |

---

## 🐜 Ingress Protection

- IP65 minimum (target IP67 preferred)  
- Mesh screen over all external holes (≤ 0.5mm)  
- All cable penetrations sealed with compression grommets  
- Drain hole with flap valve optional for extreme humidity environments

---

## 🔌 Serviceability

- Lid accessible with standard Torx or Phillips driver  
- Internal USB-C access optional via flap port (for local firmware upload)  
- All connectors JST or screw terminal block for field swap  
- Modular sensor head (HC-SR04) replaceable without removing MCU

---

## 🔋 Environmental Performance

| Property         | Value              |
|------------------|--------------------|
| Operating Temp   | –10°C to +55°C     |
| UV Exposure      | 3+ years, direct sun rated |
| Water Resistance | Direct rain safe (vertical and side) |
| Vibration        | Tolerates street-level impact & cycling |

---

## ✅ Summary

The enclosure doesn’t just house the brains — it **protects the eyes**.  
It sees the storm. It stays dry.  
And when maintenance comes knocking, it doesn’t fight back — it opens like it knows you’ve got work to do.
