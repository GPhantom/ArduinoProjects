int x = 7;
int y = 6;


void setup(){
  pinMode(x, OUTPUT);
  pinMode(y, OUTPUT);
}

void loop(){
  digitalWrite(x, HIGH);
  digitalWrite(y, LOW);
  delay(3000);
  digitalWrite(x, LOW);
  digitalWrite(y, HIGH);
  delay(3000);
}
