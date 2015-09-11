//Motor variables
#define switchPin 4 // switch input
#define motorPin1 5 // L293D Input 1
#define motorPin2 6 // L293D Input 2
#define speedPin 9 // L293D enable Pin 1
#define potPin 0 // Potentiometer on Analog Pin 0
int Mspeed = 0; // a variable to hold the current speed value

//Encoder variables
#define encoder0PinA 2
#define encoder0PinB 3
volatile unsigned int encoder0Pos = 0;

void setup() {
 
  // Encoder setup
  pinMode(encoder0PinA, INPUT); // encoder pin on interrupt 0 (pin 2)
  pinMode(encoder0PinB, INPUT); // encoder pin on interrupt 1 (pin 3)
  attachInterrupt(0, doEncoderA, CHANGE);
  attachInterrupt(1, doEncoderB, CHANGE);
 
  // Motor setup
  pinMode(switchPin, INPUT); // set switch pin as INPUT
 
  pinMode(motorPin1, OUTPUT); // set remaining pins as outputs
  pinMode(motorPin2, OUTPUT);
  pinMode(speedPin, OUTPUT);

  // Encoder setup
  pinMode(encoder0PinA, INPUT); // encoder pin on interrupt 0 (pin 2)
  pinMode(encoder0PinB, INPUT); // encoder pin on interrupt 1 (pin 3)
  attachInterrupt(0, doEncoderA, CHANGE);
  attachInterrupt(1, doEncoderB, CHANGE);
 
  Serial.begin (9600);
}

void loop() {
  Mspeed = analogRead(potPin)/4; // read the speed value from the potentiometer
  analogWrite(speedPin, Mspeed); // write speed to Enable 1 pin
  if (digitalRead(switchPin)) { // If the switch is HIGH, rotate motor clockwise
    digitalWrite(motorPin1, LOW); // set Input 1 of the L293D low
    digitalWrite(motorPin2, HIGH); // set Input 2 of the L293D high
  }
  else { // if the switch is LOW, rotate motor anti-clockwise
    digitalWrite(motorPin1, HIGH); // set Input 1 of the L293D low
    digitalWrite(motorPin2, LOW); // set Input 2 of the L293D high
  }
}

void doEncoderA(){
  // look for a low-to-high on channel A
  if (digitalRead(encoder0PinA) == HIGH) {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder0PinB) == LOW) { 
      encoder0Pos = encoder0Pos + 1;         // CW
    }
    else {
      encoder0Pos = encoder0Pos - 1;         // CCW
    }
  }
  else   // must be a high-to-low edge on channel A                                       
  {
    // check channel B to see which way encoder is turning 
    if (digitalRead(encoder0PinB) == HIGH) {   
      encoder0Pos = encoder0Pos + 1;          // CW
    }
    else {
      encoder0Pos = encoder0Pos - 1;          // CCW
    }
  }
  //Serial.println (encoder0Pos, DEC);         
  // use for debugging - remember to comment out
}

void doEncoderB(){
  // look for a low-to-high on channel B
  if (digitalRead(encoder0PinB) == HIGH) {   
   // check channel A to see which way encoder is turning
    if (digitalRead(encoder0PinA) == HIGH) { 
      encoder0Pos = encoder0Pos + 1;         // CW
    }
    else {
      encoder0Pos = encoder0Pos - 1;         // CCW
    }
  }
  // Look for a high-to-low on channel B
  else {
    // check channel B to see which way encoder is turning 
    if (digitalRead(encoder0PinA) == LOW) {   
      encoder0Pos = encoder0Pos + 1;          // CW
    }
    else {
      encoder0Pos = encoder0Pos - 1;          // CCW
    }
  }
}
