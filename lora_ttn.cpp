#include "DHT.h"
#define DHTPIN 5
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin(); // initialize the sensor
}

void loop() {
  // wait a few seconds between measurements.
  delay(2000);
  
  // read temperature as Celsius
  float tempC = dht.readTemperature();

  // check if any reads failed
  if (isnan(tempC)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print(tempC);
    Serial.println("°C");
  }
}