// C++ code
// Constants
const int PIR_SENSOR = 2; // PIR sensor's pin
const int LED = 8; // LED output pin
const int TEMPERATURE = A0; // TEMPERATURE SENSOR PIN

// Variables
bool MOTION = false;

void setup() {
  pinMode(PIR_SENSOR, INPUT); // Set the PIR pin as input
  pinMode(LED, OUTPUT); // Set the LED pin as output
  pinMode(LED_BUILTIN, OUTPUT); // Set the built-in LED of the Arduino as output
  Serial.begin(9600);
  
  attachInterrupt(digitalPinToInterrupt(PIR_SENSOR), detect, CHANGE);
}

void loop() {
  int Temp = analogRead(TEMPERATURE);  
  float volts = (Temp * 5.0 / 1024.0); 
  float celcius = (volts - 0.5) * 100;  
  Serial.print("Temperature: ");
  Serial.print(celcius);
  Serial.println(" C");
  delay(1000);
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