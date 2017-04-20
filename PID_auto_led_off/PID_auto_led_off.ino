// Created by: HowToCompute

// Configuration Parameters
const int LED1 = 2;
const int timeToAutoOff = 3; // in seconds
const int PIDPin = A5;

// Create a float to keep track of the time since the last PID activity
float timeScinceLastActivity = 0.0;

// Runs at the start!
void setup() {
  pinMode(LED1, OUTPUT); // Set LED1 as output, so it can be controlled
  digitalWrite(LED1, HIGH); // Switched LED1 on!
  Serial.begin(9200); // Start the serial to print out data!
}

// Run as many times as possible!
void loop() {
  if(digitalRead(4) == 1) { // If the button is pressed:
   digitalWrite(LED1, HIGH);
   timeScinceLastActivity = 0; // Reset!
  }
  
  if(digitalRead(PIDPin) == 0) { // Check if the PID has picked nothing up:
    timeScinceLastActivity += 0.01; // If it picked nothing up, add the 10ms we waited!
  } else { // There must be some activity:
    timeScinceLastActivity = 0.0; // Reset the time
  }
  if(timeScinceLastActivity >= timeToAutoOff) { // If the time is equal or over the time to auto off:
    digitalWrite(LED1, LOW); // Switch the led off
  }
  // Log variables for debugging
  Serial.println(timeScinceLastActivity);
  Serial.println(digitalRead(PIDPin));
  // End of logging

  //Wait for 10 miliseconds, this is sothat we can properly keep track of the time!
  delay(10);
}
