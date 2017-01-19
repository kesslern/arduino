/**
 * RGB LED Example
 * 
 * Common cathode configuration: connect the cathode to ground. Attach
 * a resistor in series with each output.
 *
 **/
 
int redPin = 10;
int greenPin = 9;
int bluePin = 8;
 
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}
 
void loop()
{
  // red
  setColor(255, 0, 0);
  delay(1000);
  // green
  setColor(0, 255, 0);
  delay(1000);
  // blue
  setColor(0, 0, 255);  
}
