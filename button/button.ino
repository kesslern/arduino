/**
 * State change detection (edge detection)
 *
 * The circuit:
 * - VCC to one side of pushbutton 
 * - pin 9 to other side of pushbutton
 * - resistor from same side as pin 9 going to ground 
 *
 * A small capacitor can be added to both ends of the resistor
 * to reduce bouncing.
 *
 **/

#define DOWN false
#define UP true

#define LED_PIN 1 // built in LED
#define BUTTON_PIN 9

boolean buttonState = UP;
boolean buttonStateChanged = false;

void updateButtonState(boolean newState) {
  
  if (buttonState == newState) {
    buttonStateChanged = false;
  } else {
    buttonStateChanged = true;
    buttonState = newState;
  }
}


void readButton() {

  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH) {
    updateButtonState(DOWN);
    digitalWrite(LED_PIN, HIGH);
  } else {
    updateButtonState(UP);
    digitalWrite(LED_PIN, LOW);
  }
}

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}


void loop() {
  readButton();

  if (buttonStateChanged) {
    if (buttonState == UP) {
      Particle.publish("button state", "up");
    } else {
      Particle.publish("button state", "down");
    }
  }
}

