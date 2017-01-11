#include <Servo.h>
Servo X;
Servo Y;

int echo = 8;
int trig = 12;
int pin_1 = 7;
int pin_2 = 4;
int pin_3 = 2;
int Buzzer = 13;

void setup(){
  Serial.begin(9600);
  X.attach(10);
  Y.attach(9);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(Buzzer, OUTPUT);
   
}

void loop(){
  X.write(180);
  Y.write(0);
  int duration, distance;
  digitalWrite(trig, HIGH);
  delay(50);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 29.1;
  if (distance > 0 && distance < 10){
    digitalWrite(pin_1, HIGH);
    digitalWrite(pin_2, LOW);
    digitalWrite(pin_3, LOW);
    digitalWrite(Buzzer, HIGH);
    X.write(180);
    Y.write(90);
    delay(1550);
  }
  else if (distance > 10 && distance < 15){
    X.write(180);
    Y.write(0);
    digitalWrite(pin_1, HIGH);
    digitalWrite(pin_2, HIGH);
    digitalWrite(pin_3, LOW);
    digitalWrite(Buzzer, LOW);
    delay(500);
    digitalWrite(Buzzer, HIGH);
  }
  else if (distance > 15 && distance < 20){
    X.write(180);
    Y.write(0);
    digitalWrite(pin_1, HIGH);
    digitalWrite(pin_2, HIGH);
    digitalWrite(pin_3, HIGH);
    digitalWrite(Buzzer, LOW);
    delay(500);
    digitalWrite(Buzzer, HIGH);
  }
  else{
    digitalWrite(pin_1, LOW);
    digitalWrite(pin_2, LOW);
    digitalWrite(pin_3, LOW);
    digitalWrite(Buzzer, LOW);
    X.write(180);
    Y.write(0);
  }
  
  Serial.print(distance);
  Serial.println(" cm");
  delay(10);
  
}  
  

