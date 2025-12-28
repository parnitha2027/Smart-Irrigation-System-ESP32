## Simulation & Code Validation

This phase validates the Smart Irrigation System logic using the
Wokwi ESP32 simulator before hardware implementation.

### Components Used
- ESP32 DevKit
- DHT22 Sensor
- Capacitive Soil Moisture Sensor
- I2C LCD
- LED (Pump Indicator)

### Logic
- Reads soil moisture and temperature
- Displays values on LCD
- Turns ON pump LED when soil is dry

Simulation success confirmed correct logic
before moving to schematic design.
