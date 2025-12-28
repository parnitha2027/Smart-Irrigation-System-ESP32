## Schematic Design (Final)

This section documents the final validated schematic of the
ESP32-based Smart Irrigation System designed using EasyEDA.
This schematic was used directly for PCB layout and routing.

---

## Final Schematic Cleanup

After completing the schematic design, EasyEDA’s Design Manager
reported warnings for unused ESP32 pins. To ensure a clean and
professional schematic, "No Connect" (NC) flags were placed on
all intentionally unused pins. This cleared all warnings and
resulted in a 100% verified schematic.

---

## Power System

### USB Power Input
- USB1 (Micro USB)
  - VBUS → 5V Net
  - GND → GND

### Voltage Regulation
- U2 (LD1117 3.3V Regulator)
  - VIN → 5V Net
  - VOUT (Pins 2 & 4) → 3.3V Net
  - GND → GND

### Power Filtering Capacitors
- C1 (10µF) & C4 (100nF) between 5V and GND
- C2 (10µF) & C5 (100nF) between 3.3V and GND

---

## Core Chips & Communication

### ESP32 Module
- 3V3 pin → 3.3V Net
- All GND pins → GND

### USB to Serial Interface
- U3 (CH340C)
  - VCC → 3.3V Net
  - GND → GND
  - D+ / D− → USB D+ / D− Nets

### Decoupling
- C6 (100nF) placed between CH340C VCC and GND

### TX/RX Crossover
- CH340C TXD → ESP_RX → ESP32 RXD0
- CH340C RXD → ESP_TX → ESP32 TXD0

---

## Boot & Auto-Programming Circuit

### EN (Reset) Pin
- R5 (10k) pull-up to 3.3V
- C3 (1µF) to GND for noise filtering
- SW1 button to GND (manual reset)
- Connected to Q2 collector for auto-reset

### IO0 (Boot) Pin
- R4 (10k) pull-up to 3.3V
- SW2 button to GND (boot mode)
- Connected to Q1 collector for auto-programming

### Auto-Program Transistors
- Q2 (Reset): Base via 1k resistor to DTR# (CH340C)
- Q1 (Boot): Base via 1k resistor to RTS# (CH340C)

---

## Strapping Resistors

- R3 (10k) between GPIO15 and GND (pull-down)
- R2 (10k) between IO2 and GND (pull-down)
- R1 (10k) between ESP_TX and 3.3V (pull-up)

---

## Project I/O Connections

### LCD Header
- Pin 1 → GND
- Pin 2 → 3.3V
- Pin 3 → SDA (GPIO21)
- Pin 4 → SCL (GPIO22)

### DHT22 Sensor Header
- Pin 1 → 3.3V
- Pin 2 → GPIO15
- Pin 3 → GND

### Soil Moisture Sensor Header
- Pin 1 → 3.3V
- Pin 2 → GPIO34 (SOIL_AOUT)
- Pin 3 → GND

### Pump Indicator LED
- Cathode → GND
- Anode → 330Ω resistor → GPIO13 (LED_PUMP)

---

## Unused Pins

All unused ESP32 pins and unused switch pins were intentionally
terminated using No Connect (NC) flags to ensure schematic clarity
and error-free verification.
