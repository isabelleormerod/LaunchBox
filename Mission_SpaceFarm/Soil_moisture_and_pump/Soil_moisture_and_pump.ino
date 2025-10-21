
// this is where we initialise values, moisture is the signal that is returned from the moisture sensor!
int moisture = 0;


//this is a setup loop, below we tell the controller all the things it needs to start using the sensor
void setup()
{
  //below I'm setting pin 'A0' (where the moisture sensor is attached to) to an input signal
  //this input signal is sent to the controller and is then read
  pinMode(A0, INPUT);
  //this statement tells the controller how fast it should be sending information in Hz
  //9600 is the default value 
  Serial.begin(9600);
  //below I set pin '6' (where the LED is plugged in) to an output signal, 
  //this way my controller sends voltage to my LED to turn it on
  pinMode(6, OUTPUT);
}

//this is the main loop, once the setup loop has told the controller how to use the sensor, 
//the controller repeatedly goes through the main loop below
void loop()
{
  //this tells the controller to read the signal from the sensor
  moisture = analogRead(A0);
  //this statement writes 0 or (LOW) voltage to the LED, i.e. by default it should be off
  digitalWrite(6, LOW);
  //this is an if loop, here we check what value moisture has been recorded as, if it is less than the value given
  //then we right a HIGH signal to the LED, turning it on, telling us we need to water the plant!
  if (moisture < 100) {
    digitalWrite(6, HIGH);

  }
   // Wait for 100 millisecond(s), 
   // this is a common operation so we don't send to much information to the controller at once
  delay(100);
}
