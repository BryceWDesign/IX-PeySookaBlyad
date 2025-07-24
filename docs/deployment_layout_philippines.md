# Deployment Layout — Philippines Urban Grid Strategy

This document provides a **deployment guide** for installing IX-PeySookaBlyad towers in flood-prone areas of the Philippines — specifically addressing densely populated zones such as Manila, Quezon City, Cebu, and Davao.

---

## 📍 Urban Flooding Profile (Example: Metro Manila)

- **Average annual rainfall**: ~2,000–3,500 mm
- **Peak rain events**: 60–100 mm/hr
- **Common issues**:
  - Drainage backflow
  - Shallow street basins
  - Poor slope and runoff
  - Unmaintained storm infrastructure

---

## 📐 Recommended Spacing

| Zone Type            | Ideal Spacing Between Towers |
|----------------------|------------------------------|
| Urban street grid     | Every 8–10 meters            |
| Residential alleyways | Every 12–15 meters           |
| Public park/plaza     | One unit per 100m² block     |
| Flood basins/sumps    | Cluster of 3–5 towers        |

> Use **staggered offset layout** across intersections to avoid saturation overlap and ensure all flow channels are covered.

---

## 🧭 Orientation Strategy

- **Top dome** must face open sky (avoid under roof eaves)
- **Skirt intake** must sit flush to pavement — if road has crown, mount slightly offset toward drainage dip
- Charging shelf should face pedestrian traffic or walkways, never inward toward walls

---

## 🔧 Installation Notes

- Mount towers using:
  - 4x stainless anchor bolts (embedded in concrete footing)
  - Rebar cages for loose soil zones
- For temporary trials, base can be filled with concrete block ballast

---

## 🌀 Storm Priority Zone Mapping

Deploy extra towers in zones where:
- Water regularly pools >6 inches deep
- Previous flood incidents occurred in past 2 years
- Drainage reports show storm sewer overflow
- Street slopes are minimal (<3% grade)

Use existing LGU flood maps + barangay reports for targeting.

---

## 🌐 Mesh Upgrade Notes

If ESP32 mesh networking is enabled:
- Segment deployments into **30-node clusters**
- Assign each cluster a broadcast ID
- Add long-range beacon at barangay center for OTA updates or diagnostics

---

## 🧾 Local Material Sourcing

Where possible:
- Use local recycled tire programs for outer shells
- Partner with local welding shops for vent stacks
- Empower vocational schools or barangay fabricators to assemble units in-situ

---

## ✅ Summary

**This system isn’t for engineers in boardrooms.**  
It’s for the tricycle driver stuck in waist-high water.  
For the mother carrying groceries across flooded intersections.  
Deploy these towers where flooding has already won — and make sure it never wins again.
