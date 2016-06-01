//Made by: HowToCompute! 

//The config!
const int LED1 = 2;
const int TimeToAutoOff = 3; //In seconds!
const int PIDPin = A5;

//For keeping track of the time
float TimeScinceLastActivity = 0.0;

//Runs at the start!
void setup() {
  pinMode(LED1, OUTPUT); //Set LED1 as output, so it can be controlled
  digitalWrite(LED1, HIGH); //Put LED1 on!
  Serial.begin(9200); //Start the serial to print out data!
}

//Run as many times as possible!
void loop() {
  if(digitalRead(4) == 1) { //If the button is pressed:
   digitalWrite(LED1, HIGH);
   TimeScinceLastActivity = 0; //Reset!
  }
  
  if(digitalRead(PIDPin) == 0){ //Check if the PID has picked nothing up:
    TimeScinceLastActivity += 0.01; //If it picked nothing up, add some time!
  } else { //There must be some activity:
    TimeScinceLastActivity = 0.0; //Reset the time!
  }
  if(TimeScinceLastActivity >= TimeToAutoOff){ //If the time is equal or over the time to auto off:
    digitalWrite(LED1, LOW); //Switch the led off!
  }
  //Log variables for debugging
  Serial.println(TimeScinceLastActivity);
  Serial.println(digitalRead(PIDPin));
  //End of logging

  //Wait for 10 miliseconds, this is sothat we can properly keep track of the time!
  delay(10);
}
