int r_1 = 7;
int r_2 = 4;
int l_1 = 9;
int l_2 = 10;
int LED = 13;
int Buzzer = 2;
int echo = 8;
int trig = 12;

void setup(){
  pinMode(r_1, OUTPUT);
  pinMode(r_2, OUTPUT);
  pinMode(l_1, OUTPUT);
  pinMode(l_2, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);
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
  if (distance > 0 && distance < 30){
    digitalWrite(LED, HIGH);
    digitalWrite(Buzzer, LOW);
    digitalWrite(l_1, LOW);
    digitalWrite(l_2, HIGH);
    digitalWrite(r_1, LOW);
    digitalWrite(r_2, LOW);
    delay(1550);
    digitalWrite(Buzzer, LOW);
}
else{
  digitalWrite(r_1, LOW);
  digitalWrite(r_2, HIGH);
  digitalWrite(l_1, LOW);
  digitalWrite(l_2, HIGH);
  digitalWrite(Buzzer, LOW);
}
}
