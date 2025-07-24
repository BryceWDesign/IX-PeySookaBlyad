# Public Education Display — IX-PeySookaBlyad

Every unit must **communicate clearly** with the people it’s protecting.  
This file defines the signage, symbols, and visual indicators used to explain:

- What the tower does
- How to safely interact with it
- When it's helping (and how)

---

## 🧾 Physical Signage

Each tower includes a **laminated or etched plate** placed at:
- Eye-level (5ft) for adults
- Optional second copy at child height (3ft)

### 🏷️ Minimum Wording (English):

```
THIS DEVICE REMOVES FLOOD WATER  
AND TURNS IT INTO CLEAN HYDROGEN  
WHILE CHARGING PHONES WIRELESSLY  
POWERED BY AMBIENT ENERGY  
⚠️ DO NOT BLOCK INTAKES  
⚡ PHONE CHARGING = GREEN LIGHT  
🌧️ ACTIVE STORM MODE = FLASHING WHITE  
💨 HYDROGEN VENTING = BLUE PULSE  
```

---

## 🌐 Multilingual Strategy

Provide signage in **English + local language** (Tagalog, Cebuano, etc.)

- Use iconography (📱💨⚠️) to reinforce understanding  
- Optional QR code for full explanation PDF hosted online  
- Simple one-liner like:  
  - 🇵🇭 *“Para sa tubig-baha. Libre. Ligtas.”*  
    (For floodwater. Free. Safe.)

---

## 💡 LED Communication Scheme

| Light Behavior        | Meaning                              |
|------------------------|---------------------------------------|
| Solid green (ring)    | Charging ready                        |
| Flashing green        | Charging active                       |
| Flashing white (top)  | Storm mode engaged                    |
| Pulsing blue          | Hydrogen being vented                 |
| Red ring              | Error state / offline                 |
| Rainbow wave          | Self-cleaning cycle in progress       |

> LED logic handled in `firmware/status_led_driver.ino` (see future file)

---

## 🖼️ Optional E-Paper Display

If cost allows, consider a **2.13" or 2.9" e-paper display** (Waveshare or Inkplate) showing:

- “Charging available” / “Storm mode: ON” messages  
- Animated arrow showing water movement  
- QR code for FAQ or reporting issues  
- Can be solar-powered, refreshed once per hour

---

## 🧠 Psychological Notes

- Give tower a **non-threatening visual identity**  
  - Soft LED ring = friendly  
  - Recycled rubber base = non-industrial  
  - Sign uses **helpful tone**, not warnings  

- Colors and sounds must never mimic police/military  
- All signage: etched, UV-resistant, vandal-resistant

---

## ✅ Summary

The public won’t read a spec sheet — but they’ll remember a green light, a phone charge, and a sign that says:  
**“This tower is here for you.”**

Flood defense isn’t just tech.  
It’s trust.
