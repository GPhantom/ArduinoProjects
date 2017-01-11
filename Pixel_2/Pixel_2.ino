int R_M_1 = 7;
int R_M_2 = 4;
int L_M_1 = 8;
int L_M_2 = 2;
int trig_r = 12;
int echo_r = 10;
int trig_l = 6;
int echo_l = 5;
int Buzzer = 13;


void setup(){
  pinMode(R_M_1, OUTPUT);
  pinMode(R_M_2, OUTPUT);
  pinMode(L_M_1, OUTPUT);
  pinMode(L_M_2, OUTPUT);
  pinMode(trig_r, OUTPUT);
  pinMode(echo_r, INPUT);
  pinMode(trig_l, OUTPUT);
  pinMode(echo_l, INPUT);
  pinMode(Buzzer, OUTPUT);
  Serial.begin(9600);
  
}

void Front(){
  digitalWrite(R_M_1, HIGH);
  digitalWrite(R_M_2, LOW);
  digitalWrite(L_M_1, HIGH);
  digitalWrite(L_M_2, LOW);
}

void Back(){
  digitalWrite(R_M_1, LOW);
  digitalWrite(R_M_2, HIGH);
  digitalWrite(L_M_1, LOW);
  digitalWrite(L_M_2, HIGH);
}

void Right(){
  digitalWrite(R_M_1, LOW);
  digitalWrite(R_M_2, LOW);
  digitalWrite(L_M_1, HIGH);
  digitalWrite(L_M_2, LOW);
}

void Left(){
  digitalWrite(R_M_1, HIGH);
  digitalWrite(R_M_2, LOW);
  digitalWrite(L_M_1, LOW);
  digitalWrite(L_M_2, LOW);
}

void loop(){
  int duration_r, duration_l, distance_r, distance_l;
  digitalWrite(trig_r, HIGH);
  digitalWrite(trig_l, HIGH);
  delay(1000);
  digitalWrite(trig_r, LOW);
  digitalWrite(trig_l, LOW);
  duration_r = pulseIn(echo_r, HIGH);
  duration_l = pulseIn(echo_l, HIGH);
  distance_r = (duration_r/2) / 29.1;
  distance_l = (duration_l/2) / 29.1;
  Serial.print("Right ultraSonic: ");
  Serial.print(distance_r);
  Serial.println(" cm");
  
  Serial.print("Left ultraSonic: ");
  Serial.print(distance_l);
  Serial.println(" cm");
  
}
