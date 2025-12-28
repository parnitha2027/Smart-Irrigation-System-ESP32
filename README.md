## Simulation & Code Validation

This phase validates the Smart Irrigation System logic using
the Wokwi ESP32 simulator before hardware implementation.

### Components Used
- ESP32 DevKit
- DHT22 Temperature & Humidity Sensor
- Capacitive Soil Moisture Sensor
- I2C LCD Display
- LED (Pump Indicator)

### Working Logic
- Reads soil moisture and temperature values
- Displays readings on the LCD
- Turns ON the pump LED when soil moisture falls below threshold

Successful simulation confirmed correct system behavior
before proceeding to schematic and PCB design.
