
int echo = 8;
int trig = 12;
int Buzzer = 2;
int LED = 13;

void setup(){
  Serial.begin(9600);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
   
}

void loop(){
  
  int duration, distance;
  digitalWrite(trig, HIGH);
  delay(50);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 29.1;
  if (distance > 0 && distance < 30){
    digitalWrite(LED, HIGH);
    digitalWrite(Buzzer, LOW);
    delay(500);
    digitalWrite(Buzzer, HIGH);
  }
  else if (distance > 30){
    digitalWrite(LED, HIGH);
    digitalWrite(Buzzer, LOW);
    
  }
  else{
    digitalWrite(LED, LOW);
    digitalWrite(Buzzer, LOW);
    
  }
  
  Serial.print(distance);
  Serial.println(" cm");
  delay(10);
  
}  
  

