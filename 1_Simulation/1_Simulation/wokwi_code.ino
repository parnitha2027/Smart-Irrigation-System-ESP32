#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Pin Definitions
#define DHTPIN 15            // DHT22 data pin to GPIO15
#define DHTTYPE DHT22
#define SOIL_MOISTURE_PIN 34 // Analog input pin
#define PUMP_LED_PIN 13      // LED to indicate pump status (GPIO13)

// Threshold for dry soil (in %)
int moistureThreshold = 40;

// Initialize LCD and DHT
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  // Initialize components
  lcd.init();
  lcd.backlight();

  dht.begin();

  pinMode(PUMP_LED_PIN, OUTPUT);
  digitalWrite(PUMP_LED_PIN, LOW); // Start with LED OFF (soil wet)

  lcd.setCursor(0, 0);
  lcd.print("Smart Irrigation");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read temperature & humidity
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Read soil moisture
  int moistureRaw = analogRead(SOIL_MOISTURE_PIN);
  int moisturePercent = map(moistureRaw, 4095, 0, 0, 100); // ESP32 uses 12-bit ADC (0-4095)

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temperature, 1);
  lcd.print((char)223); // Degree symbol
  lcd.print("C ");

  lcd.setCursor(0, 1);
  lcd.print("Soil:");
  lcd.print(moisturePercent);
  lcd.print("%   ");

  // Debug Info
  Serial.println("=================================");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Soil Moisture: ");
  Serial.print(moisturePercent);
  Serial.println(" %");

  // Simulated Email Alert
  if (temperature > 35) {
    Serial.println(">> ALERT: High Temp! (Would send Email)");
  }

  // LED as Pump Indicator (ON when soil is dry)
  if (moisturePercent < moistureThreshold) {
    digitalWrite(PUMP_LED_PIN, HIGH); // Turn LED ON (soil is dry)
    Serial.println("Pump Status: ON (Soil is Dry)");
  } else {
    digitalWrite(PUMP_LED_PIN, LOW); // Turn LED OFF (soil is wet)
    Serial.println("Pump Status: OFF (Soil is Wet)");
  }

  Serial.println("=================================\n");

  delay(5000); // Wait before next reading
}
