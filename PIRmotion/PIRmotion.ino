int buzzer_LED = 13;
int Reading = 2;
int val = 0;

void setup(){
  Serial.begin(9600);
  pinMode(buzzer_LED, OUTPUT);
  pinMode(Reading, INPUT);
}

void loop(){
  val = digitalRead(Reading);
  if (val == HIGH){
    Serial.println("Motion Detected!");
    digitalWrite(buzzer_LED, HIGH);
    delay(150);
    digitalWrite(buzzer_LED, LOW);
    delay(150);
  }
  else{
    Serial.println("Motion Ended");
    digitalWrite(buzzer_LED, LOW);
  }
}  
