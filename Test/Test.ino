int Reading_r = 2;
int Reading_l = 4;
int M_R_1 = 7;
int M_R_2 = 8;
int M_L_1 = 10;
int M_L_2 = 11;

void setup(){
  pinMode(Reading_r, INPUT);
  pinMode(Reading_l, INPUT);
  pinMode(M_R_1, OUTPUT);
  pinMode(M_R_2, OUTPUT);
  pinMode(M_L_1, OUTPUT);
  pinMode(M_L_2, OUTPUT);
}

void loop(){
  val_r = digitalRead(Reading_r);
  val_l = digitalRead(Reading_l);
  if (val_r == HIGH && val_l == HIGH){
    digitalWrite(M_R_1, HIGH);
    digitalWrite(M_R_2, LOW);
    digitalWrite(M_L_1, HIGH);
    digitalWrite(M_L_2, LOW);
  }
  else if (val_r == HIGH && val_l == LOW){
    digitalWrite(M_R_1, LOW);
    digitalWrite(M_R_2, LOW);
    digitalWrite(M_L_1, HIGH);
    digitalWrite(M_L_2, LOW);
    delay(1000);
    digitalWrite(M_R_1, HIGH);
    digitalWrite(M_R_2, LOW);
    digitalWrite(M_L_1, HIGH);
    digitalWrite(M_L_2, LOW);
  }
  else if (val_r == LOW && val_l == HIGH){
    digitalWrite(M_R_1, HIGH);
    digitalWrite(M_R_2, LOW);
    digitalWrite(M_L_1, LOW);
    digitalWrite(M_L_2, LOW);
    delay(1000);
    digitalWrite(M_R_1, HIGH);
    digitalWrite(M_R_2, LOW);
    digitalWrite(M_L_1, HIGH);
    digitalWrite(M_L_2, LOW);
  }
  else{
    digitalWrite(M_R_1, LOW);
    digitalWrite(M_R_2, LOW);
    digitalWrite(M_L_1, LOW);
    digitalWrite(M_L_2, LOW);
  }
}
