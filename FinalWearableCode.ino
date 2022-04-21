/*
Blind Proximity Indicator
Ethan Griffin
DIGF-3010-001 Avanced Wearable Electronics
OCAD University
03 April, 2022
Based on:
Accelerometer
IR Sensor
*/

#include <Adafruit_CircuitPlayground.h>

float X; //X value
float Y; //Y value
float Z; //Z value

bool slideSwitch;

int proximitySensor = 9; //analog pin 9

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
  CircuitPlayground.begin();
  pinMode(6, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
   int pVal = analogRead(proximitySensor);
   Serial.println(pVal);
  
   X = CircuitPlayground.motionX();
   Y = CircuitPlayground.motionY();
   Z = CircuitPlayground.motionZ();

   slideSwitch = CircuitPlayground.slideSwitch();

   Serial.print("X: ");
   Serial.print(X);
   Serial.print(" Y: ");
   Serial.print(Y);
   Serial.print(" Z: ");
   Serial.println(Z);

  
    Serial.print("Slide Switch: ");
  if (slideSwitch) {
    Serial.println("Speaker");
   
    if (X > 5 && X < 15 && Y > -3 && Y < 6 && Z > -4 && Z <6) {
    Serial.println("ON");
    //Speaker Code
      if (pVal > 0 && pVal < 100){
        CircuitPlayground.playTone(100, 800);
      }
      if (pVal > 100 && pVal < 200){
        CircuitPlayground.playTone(300, 650);
      }
      if (pVal > 200 && pVal < 300){
        CircuitPlayground.playTone(500, 500);
      }
      if (pVal > 300 && pVal < 400){
        CircuitPlayground.playTone(700, 400);
      }
      if (pVal > 400 && pVal < 500){
        CircuitPlayground.playTone(900, 300);
      }
      if (pVal > 500 && pVal < 600){
        CircuitPlayground.playTone(1100, 200);
      }
      if (pVal > 600 && pVal < 700){
        CircuitPlayground.playTone(1300, 100);
      }
      if (pVal > 700 && pVal < 800){
        CircuitPlayground.playTone(1500, 75);
      }
      if (pVal > 800 && pVal < 900){
        CircuitPlayground.playTone(1700, 50);
      }
      if (pVal > 900 && pVal < 1000){
        CircuitPlayground.playTone(1700, 25);
      }
      if (pVal > 1000 && pVal < 1500){
        CircuitPlayground.playTone(1700, 10);
      }
      delay(10);
      
    }
     else {
      Serial.println("OFF");
      delay(10);
     }
  }
  else {
    Serial.println("Vibration");
    if (X > 5 && X < 15 && Y > -3 && Y < 6 && Z > -4 && Z <6) {
    Serial.println("ON");
    //Vibration Code
     if (pVal > 0 && pVal < 100){
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW);
    delay(800);
  }
  if (pVal > 100 && pVal < 200){
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW);
    delay(700);
  }
  if (pVal > 200 && pVal < 300){
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW);
    delay(600);
  }
  if (pVal > 300 && pVal < 400){
  digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW);
    delay(500);
  }
  if (pVal > 400 && pVal < 500){
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW);
    delay(400);
  }
  if (pVal > 500 && pVal < 600){
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW);
    delay(300);
  }
  if (pVal > 600 && pVal < 700){
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW);
    delay(200);
  }
  if (pVal > 700 && pVal < 800){
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW);
    delay(100);
  }
  if (pVal > 800 && pVal < 900){
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW);
    delay(50);
  }
  if (pVal > 900 && pVal < 1000){
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW);
    delay(10);
  }
  if (pVal > 1000 && pVal < 1500){
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW);
    delay(1);
  }
  delay(10);
    
   }
   else {
    Serial.println("OFF");
    delay(10);
   }
  }


   delay(100);

}
