// From: http://www.thecoderscorner.com/electronics/microcontrollers/driving-displays/45-arduino-example-for-driving-7-segment-led-s/
// set this to the first pin where wiring starts.
int ledStart = 1;

// set to true if the common pin is HIGH, false otherwise
boolean commonHigh = false;


void setup() {
  // Enable all A-G and DP and outputs, 
  // set them to OFF (if common is high, then 1 is off).
  for(int i=0;i<8;++i) {
    pinMode(ledStart + i, OUTPUT);
    digitalWrite(ledStart + i, commonHigh?1:0);
  }
}

void loop() {
  // write the number 0 - F (hex)
  // onto the display each half second
  for(int i=0;i<16;i++) {
    writeDigitToDisplay(i);
    delay(500);
  }
}

// Now we define the bits that are on and off
// for each segment, These are used in the
// function below to turn the right bits on.
int dig[16] = {
// bits     6543210
// digits   abcdefg
          0b1111110,//0
          0b0110000,//1
          0b1101101,//2
          0b1111001,//3
          0b0110011,//4
          0b1011011,//5
          0b1011111,//6
          0b1110000,//7
          0b1111111,//8
          0b1111011,//9
          0b1110111,//a
          0b0011111,//b
          0b1001110,//c
          0b0111101,//d
          0b1001111,//e
          0b1000111 //f
};

void writeDigitToDisplay(int digit) {
  // iterate through each bit
  for(int i=0;i<7;++i) {
    // isolate the current bit in the loop.
    int currentBit = (1<<(6-i));
    // and compare with that bit in the digit
    // definition above.
    int bitOn = (currentBit&dig[digit])!=0;
    
    // if common is high we invert the logic, as 0 is on.
    if(commonHigh) {
      bitOn = !bitOn;
    }
    
    // and lastly set the bit
    digitalWrite(ledStart+i, bitOn);
  }
}
