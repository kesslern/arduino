/**
 * LM35 Temperature Sensor Example
 *
 * When looking at the flat side of the sensor:
 * Left Pin   -> VCC
 * Middle Pin -> Ground
 * Right Pin  -> Analog Input
 *
 **/

int outputpin = A0;

// Set VCC to the voltage of your VCC output
#define VCC 3.3

void setup() {
}

void loop() {
  int rawvoltage= analogRead(outputpin);
  float celsius = (rawvoltage/1023.0) * VCC * 100;

  Particle.publish("temp", String(celsius).c_str());
  delay(5000);
}
  