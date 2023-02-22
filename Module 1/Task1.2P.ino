// C++ code
// Constants
const int PIR_SENSOR = 2; // PIR sensor's pin
const int LED = 8; // LED output pin
// Variables
bool MOTION = false;

void setup() {
  pinMode(PIR_SENSOR, INPUT); // Set the PIR pin as input
  pinMode(LED, OUTPUT); // Set the LED pin as output
  Serial.begin(9600);
  
  attachInterrupt(digitalPinToInterrupt(PIR_SENSOR), detect, CHANGE);
}

void loop() {
}
void detect() {
  MOTION = digitalRead(PIR_SENSOR); // Check the input from the PIR sensor
  if (MOTION == HIGH) { // If motion was detected
    digitalWrite(LED, HIGH); // Turn on the LED
    Serial.println("Intruptred");
    
    delay(500);
  }
  else { // If motion was not detected
    digitalWrite(LED, LOW); // Turn off the LED
    Serial.println("No Motion Detected");
    
    delay(500);
  }
}