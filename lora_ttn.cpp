#include "DHT.h"
#include <TheThingsNetwork.h>

#define DHTPIN 5
#define DHTTYPE DHT11

// Set your AppEUI and AppKey
const char *appEui = "XXXXXXXXXXXXXXXX";
const char *appKey = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";

#define loraSerial Serial1
#define debugSerial Serial

#define freqPlan TTN_FP_EU868

int LDR_Pin = A0; // Analog pin connected to LDR
int LDR_Reading;  // Variable to store the LDR reading

DHT dht(DHTPIN, DHTTYPE);
TheThingsNetwork ttn(loraSerial, debugSerial, freqPlan);

void setup() {
  debugSerial.begin(9600);
  loraSerial.begin(57600);
  dht.begin();
  ttn.join(appEui, appKey);
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Read temperature as Celsius.
  float tempC = dht.readTemperature();

  // Check if any reads failed.
  if (isnan(tempC)) {
    debugSerial.println("Failed to read from DHT sensor!");
  } else {
    debugSerial.print("Temperature: ");
    debugSerial.print(tempC);
    debugSerial.println("°C");
  }

  // Prepare byte array to send temperature and LDR data.
  byte data[2];
  int16_t temp = (int16_t)(tempC * 100); // Convert float to int16_t.
  data[0] = temp >> 8; // MSB of temperature.
  data[1] = temp & 0xFF; // LSB of temperature.

  // Send temperature and LDR data to TTN.
  ttn.sendBytes(data, sizeof(data));

  delay(10000); // Wait 10 seconds before sending again.
}