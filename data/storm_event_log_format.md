# Storm Event Log Format — IX-PeySookaBlyad

Each tower passively logs flood conditions during storm priority mode. These logs are exportable via BLE, serial, or mesh OTA (if enabled) for use by disaster response agencies, urban planners, or researchers.

---

## 📦 Data Format: JSON (preferred) or CSV (fallback)

---

### ✅ JSON Structure (Example)

```json
{
  "tower_id": "IX-PSB-MNL-014",
  "event_id": "STORM-2025-08-12-15:47",
  "timestamp_start": "2025-08-12T15:47:00Z",
  "timestamp_end": "2025-08-12T17:11:00Z",
  "max_water_cm": 53,
  "avg_water_cm": 36,
  "total_duration_min": 84,
  "electrolysis_runtime_min": 71,
  "charging_suspended": true,
  "power_floor_hit": true,
  "beacon_alerts": 3,
  "vent_cycles": 14
}
```

---

### ✅ CSV Fallback Format

| tower_id        | event_id           | start_time | end_time | max_cm | avg_cm | dur_min | electrolysis_min | charging_off | power_low | alerts | vents |
|-----------------|--------------------|------------|----------|--------|--------|---------|------------------|---------------|------------|--------|--------|
| IX-PSB-MNL-014 | STORM-2025...      | 15:47      | 17:11    | 53     | 36     | 84      | 71               | TRUE          | TRUE       | 3      | 14     |

---

## 🔍 Field Descriptions

| Field                 | Meaning                                      |
|----------------------|----------------------------------------------|
| tower_id             | Unique unit code (geo-encoded optional)      |
| event_id             | Unique storm signature ID (date/time encoded)|
| timestamp_start/end  | ISO 8601 timestamps                          |
| max_water_cm         | Highest level reached during event           |
| avg_water_cm         | Running average during entire event          |
| total_duration_min   | Total duration in minutes (start → end)      |
| electrolysis_runtime | How long H₂ production was active            |
| charging_suspended   | TRUE if Qi charging was paused during event  |
| power_floor_hit      | TRUE if voltage dropped below safe threshold |
| beacon_alerts        | Count of red LED pulsing cycles              |
| vent_cycles          | Number of hydrogen stack discharge events    |

---

## 🔄 Export Mechanism

- **BLE Dump** (preferred for field use)
  - Triggered via Android phone or field scanner
  - JSON pushed to local device + timestamped

- **Serial Dump**
  - Via USB-C debug cable
  - Raw JSON or CSV dump triggered via command input

- **Mesh OTA (Future)**
  - If tower is part of a mesh group, it can transmit storm logs nightly or post-event to collector node

---

## 🧠 Use Cases

- Local governments tracking street-level flood severity  
- NGOs analyzing performance of each deployed tower  
- Engineers tuning intake logic or upgrading firmware based on real data  
- Public transparency reporting — posting tower response logs on LED screen or app frontend

---

## ✅ Summary

What good is a system that works if no one knows how well it worked?  
These logs prove it. They teach. They warn. They guide the next build.  
This isn’t just reaction — it’s memory. Logged by the storm itself.
