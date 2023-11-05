
// constants won't change. They're used here to set pin numbers:
const int readPin = 7;   // 
const int writePin = 6;  // 

// variables will change:
int laserState = 0;  // variable for reading the pushbutton status

void setup() {
  pinMode(writePin, OUTPUT);
  pinMode(readPin, INPUT);
}

void loop() {
  laserState = digitalRead(readPin);
  digitalWrite(writePin, laserState);
}
