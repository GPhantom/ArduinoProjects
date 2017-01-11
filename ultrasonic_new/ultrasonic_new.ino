#define echopin 8
#define trigpin 12

int echo = 8;
int trig = 12;
int pin_1 = 7;
int pin_2 = 4;
int pin_3 = 2;

void setup(){
  Serial.begin(9600);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
}

void loop(){
  int duration, distance;
  digitalWrite(trig, HIGH);
  delay(50);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 29.1;
  if (distance > 20 && distance < 45){
    digitalWrite(pin_1, HIGH);
    digitalWrite(pin_2, LOW);
    digitalWrite(pin_3, LOW);
  }
  else if (distance > 45 && distance < 75){
    digitalWrite(pin_1, HIGH);
    digitalWrite(pin_2, HIGH);
    digitalWrite(pin_3, LOW);
  }
  else if (distance > 75 && distance < 100){
    digitalWrite(pin_1, HIGH);
    digitalWrite(pin_2, HIGH);
    digitalWrite(pin_3, HIGH);
  }
  else{
    digitalWrite(pin_1, LOW);
    digitalWrite(pin_2, LOW);
    digitalWrite(pin_3, LOW);
  }
  
  Serial.print(distance);
  Serial.println(" cm");
  delay(10);
}  
  
