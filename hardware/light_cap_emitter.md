# Light Cap Emitter — IX-PeySookaBlyad

Mounted at the top of the 9-foot tower is a **light cap module** — a hybrid dispersal and signaling light that:

- **Burns off excess power**  
- **Glows during tower activity**  
- **Signals to citizens it's working**  
- **Adds minimal area lighting** at night

This is not a spotlight or CCTV. This is soft, visible proof of energy being used for good.

---

## 💡 Physical Description

| Component         | Spec                                 |
|-------------------|--------------------------------------|
| Height Above Deck | +1 foot above main cylinder cap      |
| Diffuser Dome     | Frosted polycarbonate, impact-resistant  
| LEDs              | WS2812B 5050 RGB OR single-color COB  
| Beam Angle        | 270° lateral wash                    |
| Base Mount        | Weather-sealed aluminum ring, M6 bolts  

---

## 🌈 Light Behavior

| Condition               | LED Color / Pattern     |
|--------------------------|-------------------------|
| Idle (charged, inactive)| Soft amber pulse        |
| Storm mode              | Flashing white beacon   |
| Hydrogen venting        | Slow pulsing blue       |
| Self-cleaning active    | Rainbow wave            |
| Error / Overheat        | Solid red               |
| Manual override         | Constant green (steady) |

Controlled by `status_led_driver.ino` (to be submitted)

---

## 🔋 Electrical Specs

| Parameter            | Value                        |
|-----------------------|------------------------------|
| Operating Voltage    | 5V regulated (from buck or LDO)  
| Typical Current Draw | 20–80mA (RGB) or 200mA (COB)  
| Interface            | Digital GPIO OR PWM dimming  
| Mounting             | Ring PCB or radial bracket  

---

## 🧠 Energy Wasting Mode

> Flooding drops → solar input increases → battery nears full → energy must go somewhere.

To avoid overcharge:
- Light stays ON during daylight even if not needed  
- Dumps excess wattage as photon output  
- Optional: switch to dummy load resistor if needed (see `power_core_stack.md`)

---

## 🔧 Real-World BOM

| Vendor         | Part                             | Notes                        |
|----------------|----------------------------------|------------------------------|
| Adafruit       | NeoPixel Ring 24px               | Addressable, waterproofable  |
| SparkFun       | 3W COB Warm White LED Module     | Constant-on burnoff option   |
| Waveshare      | Diffuser Dome (65mm–90mm)        | Polycarb, screw-on cap       |
| AliExpress     | LED aluminum heatsink PCB        | Passive thermal relief       |

---

## 🚨 Safety

- Always thermally isolated from upper hydrogen vent  
- Waterproof sealed (IP65 or above)  
- Lightning-safe with grounded surge diode (TVS clamp)  
- Firmware fails to OFF if system errors

---

## ✅ Summary

This isn’t for flash.  
It’s for **function** and **faith** — a pulsing beacon of energy saying:

**“We’re not just absorbing the storm. We’re burning it off, safely.”**
