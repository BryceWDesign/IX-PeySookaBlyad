# IX-PeySookaBlyad: Full Build & Assembly Walkthrough  
Real-world step-by-step construction guide for full deployment of the flood-suction, hydrogen-dispersing, ambient-powered city pillar unit.

---

## 📦 Materials Needed  
Ensure all items in `bom/full_bom.md` are acquired before beginning. Local sourcing and recycling (e.g., tire rubber) encouraged to reduce cost.

---

## 🧰 Required Tools  
- Drill with concrete bit  
- Soldering iron and solder  
- Heat shrink tubing and hot air gun  
- Screwdrivers (flat and Philips)  
- Waterproof sealant  
- Utility knife  
- Multimeter  
- Zip ties + clamps  

---

## 🏗️ Assembly Steps  

### 1. **Build the Structural Shell**
- Cut the **polycarbonate tube** to 9ft height if not pre-sized.
- Mount the **rubber panels** (recycled tire rubber) to the lower half of the column as a shock-absorbent shell.
- Install **steel mesh screen** across the bottom intake. Make sure it covers all intake surfaces to block rodents and debris.
- Place the **rubber weather dome** over the top, centered around a rain intake funnel (≥ 1" gap).

### 2. **Prepare the Concrete Base**
- Drill 4 anchor bolt holes into your intended street location using the concrete bit.
- Secure the **concrete base plate** and bolt the structure’s lower end to this plate.
- Seal all base seams with **weatherproof caulk or rubber gasket material**.

### 3. **Install Electronics**
- Mount the **XIAO ESP32-C3** inside a weatherproof enclosure halfway up the column interior.
- Wire the **ultrasonic sensor** and point it down into the sump intake or pit (or rain capture basin).
- Connect all power lines to a small **power distribution board** fed by:

    - Solar panel (external upper shell)
    - TEG modules (mounted near heated hydrogen system)
    - RF harvester (positioned near the charging pad)

> Use a **voltage regulator (5V)** if needed to normalize outputs for the ESP32 and charging pad.

### 4. **Set Up the Hydrogen Subsystem**
- Mount the **electrolysis cell** at mid-height inside the structure.
- Connect **rainwater intake tubing** from the base pump to the electrolysis cell.
- Link hydrogen output to the **top exhaust vent** near the dome — ensure safe, open-air dispersal.
- Connect **water pump (12V)** at base, just behind steel mesh, to drive water into electrolysis unit.

### 5. **Integrate Charging Shelf**
- At 4 feet from the base, install the first **circular shelf**.
- Attach and waterproof-mount the **Qi charging pad** into the shelf underside.
- Add a **rain-shield shelf** just above this level (~5 ft) to shield devices during storms.

### 6. **Install Lighting**
- Mount a weatherproof **12V LED strip** around the top 12 inches.
- Wire it to an energy dump controller or simply allow it to run continuously when excess power is available.
- Light should remain on while power is available, as a **public visual indicator** of working energy harvesting.

---

## ⚙️ Final System Checks

1. **Power**: Verify the solar, TEG, and RF harvesters are providing input via multimeter.
2. **Sensor**: Ultrasonic readings should reflect distance to water level (check serial output via USB or WiFi).
3. **Pump Flow**: Activate pump manually and confirm water is drawn from base intake into electrolysis chamber.
4. **Hydrogen Flow**: Confirm safe dispersal to upper vent — use soap bubble test to verify gas flow.
5. **Qi Pad**: Confirm phone begins to charge wirelessly (within ~1cm placement).
6. **Weatherproofing**: Ensure all seams, sensors, and electronics are sealed and waterproof.

---

## 🧠 Operation Logic Summary
- **Rain falls → water enters mesh intake**
- Pump pulls water → into electrolysis cell
- Hydrogen generated → dispersed upward into air
- Ambient energy powers pump and lighting
- Wireless phone charging always active when power available
- Flood water level monitored and logged if ESP32-C3 is connected via WiFi

---

## 🌐 Expansion Potential
- Add mesh LoRaWAN for remote flood tracking  
- Integrate pressure sensors for distributed rainfall analytics  
- Cluster in 10 ft spacing (adjust for terrain runoff and surface area)

---

## ✅ Deployment Reminder
This system is built for **free public use** in flood-prone zones.  
Do **not** install in enclosed rooms or trap hydrogen. Must vent freely.  
This repo and guide are **open source** for any nation or group willing to solve flooding now.

---

**Built by:**  
Bryce Wooster  
LICENSE: Open humanitarian license (see LICENSE)  
