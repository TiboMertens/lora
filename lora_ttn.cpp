int LDR_Pin = A0; // Analog pin connected to LDR
int LDR_Reading;  // Variable to store the LDR reading

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  LDR_Reading = analogRead(LDR_Pin); // Read the LDR value
  int mapped_value = map(LDR_Reading, 450, 1032, 0, 100); // Map the LDR value
  Serial.print("LDR Reading: ");
  Serial.print(LDR_Reading); // Print the raw LDR value to serial monitor
  Serial.print(", Mapped Value: ");
  Serial.println(mapped_value); // Print the mapped value to serial monitor
  delay(1000); // Wait for a second before reading again
}