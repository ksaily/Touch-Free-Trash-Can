#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
// include the library code:
#include <LiquidCrystal.h>

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
int distanceCm;
unsigned long pulseduration = 0;
void setup()
{

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  myservo.attach(11);
}
void measureDistance()
{
  // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
pulseduration = pulseIn(echoPin, HIGH);
// Calculating the distance
distanceCm = pulseduration*0.034/2;
}
void loop()
{
  // get the raw measurement data from Ping)))
  measureDistance();

  delay(500);
   if (distanceCm < 40)
   {
     myservo.write(180);
     delay(4000);
     if (distanceCm < 40)
     {
       myservo.write(180);
     }
     else
     {
       myservo.write(0);
     }
   }
   else {
     myservo.write(0);
   }
}
