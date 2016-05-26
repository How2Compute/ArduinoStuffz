/*The default config will work with an LED connected to pin 9 and ground, this was made using an arduino uno rev3, so if you have another pin, please make sure that it is a PWM pin */
 
//Variables, play around with variables to change how it works!
int Brightness = 0;
bool CountingUp = true;
const int Speed = 100;
const int MaxBrightness = 254;
const int LedPin = 9;


void setup() {
  // put your setup code here, to run once:
  //Start the serial to debug out the values
  Serial.begin(9600);
  //Blink 2 times to indicate that the system has started
  for(int i = 0; i < 2; i++){
    //Put the LED at full brightness
    analogWrite(9, 254);
    //Wait for half a second
    delay(500);
    //Switch off the light
    analogWrite(9, 0);
    //Wait half a second
    delay(500);
  }
  
  //Wait a second before the program starts
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  //If the brightness is under the maxbrightness, and it is counting up do:
  if(Brightness <= MaxBrightness && CountingUp){
    //Add 1 level of brightness to the Brightness variable
    Brightness++;
  }
  //If the above if resulted in false: 
  else {
    //put CountingUp to false sothat it will not count up
    CountingUp = false;
    //Remove 1 level of brightness from the Brightness variable
    Brightness--;
    //If the Brightness is less or equal to 0:
    if(Brightness <= 0){
      //Make the program counting up to increase brightness
      CountingUp=true;
    }
  }
  
  //Set the led to the brightness
  analogWrite(9, Brightness);
  //Print out the Brightness to the serial for debugging purposes
  Serial.println(Brightness);
  //Wait for speed(the time) to make sure it doesn't do it multiple times per second
  delay(Speed);
}
