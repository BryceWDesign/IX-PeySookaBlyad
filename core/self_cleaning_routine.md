# Self-Cleaning Intake Routine — IX-PeySookaBlyad

Urban deployments guarantee one thing: **clogged drains.**  
This subsystem ensures the tower **auto-clears** blockages to maintain full suction during rainfall surges.

---

## 🌀 How It Works

The system briefly **reverses intake suction** or activates **vibration/shock pulse** on the intake cone or mesh.

Two primary modes supported:

### 1. **Hydraulic Backpulse**
- Short burst of pressurized air or retained hydrogen vent
- Fires downward through intake grid
- Ejects leaves, wrappers, sand

### 2. **Vibration Motor Pulse**
- Small eccentric vibration motor mounted on intake housing
- Activates in 2-second bursts
- Breaks up clogs, dislodges debris

---

## ⚙️ Trigger Conditions

- `sump_rate_inflow` drops below expected values for ≥ 2 minutes  
- OR analog float sensor reads < 10% flow velocity delta  
- OR pressure sensor at intake detects increased vacuum pressure (suggests clog)

---

## 🧠 Routine Logic (Pseudocode)

```python
if (sump_expected_flow - actual_flow) > delta_threshold:
    for i in range(3):  # up to 3 retries
        activate_vibration()
        wait(2 seconds)
        check flow again
    if still clogged:
        fire backpulse_valve()
```

---

## 🔋 Power Impact

- Vibration pulse: ~0.5W per burst (micro motor)  
- Backpulse: 2–3W momentary draw  
- Runs only in **storm mode** and **if clog suspected**  

> System remains offline during dry periods. Energy budget preserved.

---

## 🧱 BOM Options

| Function       | Part                              | Notes                         |
|----------------|-----------------------------------|-------------------------------|
| Vibration      | 3V–5V eccentric motor              | Common in cellphones          |
| Backpulse Valve| N.C. solenoid valve (1/4" port)   | Uses compressed air / vapor   |
| Sensor Input   | Analog flow or pressure sensor    | MPX5700, FS2000, etc.         |
| Control        | ESP32 GPIO + PWM/MOSFET driver    | Already present in base firmware |

---

## 🌊 Safety Constraints

- Self-cleaning disabled during **venting** or **charging**  
- Max 3 retries per clog to prevent hardware stress  
- Backpulse pressure capped at 30 psi  

---

## ✅ Summary

This city won’t stay clean — but this tower **won’t choke**.  
Every drop counts. Every clog costs time.

Let the intake do what storm drains can't:  
**Recover. Reset. Keep pulling.**
