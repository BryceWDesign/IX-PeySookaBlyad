# Power Core Stack — IX-PeySookaBlyad

The tower runs entirely on **renewable and ambient energy**, requiring **no hard grid tie-in**. This stack outlines the physical and electrical layout of:

- Solar panel intake  
- Charge controller  
- Battery bank  
- Overcharge dispersal (via light or dummy load)  
- Rail distribution to sensors, fans, lighting, and venting

---

## ⚙️ Electrical Architecture Overview

```plaintext
       +-------------------+
       |   Solar Panel     |
       +---------+---------+
                 |
        +--------v--------+
        |  MPPT Controller |
        +--------+--------+
                 |
          +------v------+
          |  LiFePO4     | <-- Battery Bank (10–30Ah)
          +------^------+
                 |
   +-------------+-------------+
   |             |             |
+--v--+      +---v---+     +---v----+
| 5V  |      | 12V   |     | Dump   |
| Reg |      | Reg   |     | Load   |
+--+--+      +---+---+     +---+----+
   |             |             |
Sensors     Hydrogen Fan    Light Cap
MCU         LED Driver      Pulse Beacon
```

---

## 🔋 Key Components

| Role             | Part                                    | Notes                             |
|------------------|-----------------------------------------|-----------------------------------|
| Solar Panel      | 18V 30W–50W rigid/ETFE                  | Enough to offset full system draw |
| MPPT Charger     | EPEVER Tracer 1210A or Victron 75/10    | Efficient solar-to-battery logic  |
| Battery Bank     | 4S LiFePO4 12.8V, 10Ah–30Ah             | Safe chemistry, long life         |
| 5V Buck Reg      | LM2596 or DFRobot 5A Buck               | For ESP32, LEDs, sensors          |
| 12V Reg          | If battery ≠ 12V, use XL4015 module     | For fans or active vent valves    |
| Dump Load        | 1–5Ω resistor bank or always-on LED cap | Energy burnoff when near full     |

---

## ⚡ Energy Flow Breakdown

| System Function       | Power Draw (Peak) | Duration    | Source            |
|------------------------|-------------------|-------------|--------------------|
| ESP32 MCU + Sensor     | ~120mA            | Continuous  | 5V Buck            |
| LED Ring + Cap         | 200mA–500mA       | Event-based | 5V Buck            |
| Intake Fan             | 1–2A              | Storms      | 12V Reg            |
| Electrolysis Pulse     | 3A burst (<10s)   | Rain only   | 12V direct or cap  |
| Dump Light             | 100mA–300mA       | Daylight    | Dump Load Rail     |

---

## 🛡️ Safety and Redundancy

- All voltage lines fused with automotive mini blade fuses  
- Optional: current shunt for telemetry  
- Overvoltage protection via TVS diodes at panel and output rails  
- Waterproof battery housing (IP66), thermally vented via passive bottom port

---

## 🧠 Mounting & Integration

- Battery enclosure sits inside the main tower core  
- Charge controller affixed to inner bracket with vibration isolation  
- Panel tilt mount exposed externally (direction: equator-facing)  
- LED cap draws directly from 5V rail with PWM bypass  
- Intake and vent systems routed to shared 12V line with failsafe timer

---

## ✅ Summary

No grid. No wires. No handouts.  
Just the sun, the storm, and this tower.

It holds the charge. It spends it wisely.  
And if it has more than it needs?

It **burns it off** with light — for you to see it working.
