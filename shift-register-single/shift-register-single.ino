/*
  Shift Register Example
  for 74HC595 shift register

  Shows how to interface with an 8-bit shift register. Cycles through each
  output, making one output HIGH at a time. To see the results of this, attach
  an LED to each output on the shift register with a 220-1k ohm resistor.

  Reference: https://www.arduino.cc/en/tutorial/ShiftOut

  Wiring:

  08 GND -> ground
  13 OE  -> ground
  16 VCC -> VCC
  10 MR  -> VCC

  09 DP    -> Digital Pin 10
  11 ST_CP -> Digital Pin 09
  12 SH_CP -> Digital Pin 08

  01-07 -> Output 01-07
  15    -> Output 08

*/

const int latchPin = 9; // ST_CP
const int clockPin = 8; // SH_CP
const int dataPin = 10; // DS

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 8; i++) {
    if (i == 0) {
      registerWrite(8, LOW);
    } else {
      registerWrite(i - 1, LOW);
    }

    registerWrite(i, HIGH);
    delay(50);
  }
}

void registerWrite(int whichPin, int whichState) {
  byte bitsToSend = 0;

  // turn off the output so the pins don't light up
  // while you're shifting bits:
  digitalWrite(latchPin, LOW);

  // turn on the next highest bit in bitsToSend:
  bitWrite(bitsToSend, whichPin, whichState);

  // shift the bits out:
  shiftOut(dataPin, clockPin, MSBFIRST, bitsToSend);

  // turn on the output so the LEDs can light up:
  digitalWrite(latchPin, HIGH);

}

