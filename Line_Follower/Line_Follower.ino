int buzzer = 12;
int Reading = 1;
int val_1;
int val_2;
int val_3;

void setup(){
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  val_1 = analogRead(Reading);
  val_2 = val_1 - 20;
  val_3 = val_2 / 10;
  if (val_3 < 15){
    Serial.println(val_3);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    Serial.println(val_3);
    delay(500);
  }
  else{
    digitalWrite(buzzer, LOW);
    Serial.println(val_3);
    delay(500);
  }
  
}
