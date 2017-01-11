
int j = 11;
int k = 10;
int l = 9;
int m = 7;
int g = 6;
int f = 5;
int x = 4;
int y = 3;
int echo = 8;
int trig = 12;




void setup(){
  Serial.begin(9600);
  pinMode(j, OUTPUT);
  pinMode(k, OUTPUT);
  pinMode(l, OUTPUT);
  pinMode(m, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(x, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  
  
}



void loop(){
  
 
        
  int duration, distance;
  digitalWrite(trig, HIGH);
  delay(1000);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);
  if (distance < 35){
  
  digitalWrite(j, LOW);
  digitalWrite(k, HIGH);
  digitalWrite(l, LOW);
  digitalWrite(m, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(f, LOW);
  digitalWrite(x, LOW);
  digitalWrite(y, LOW);  
  delay(1000);  
  digitalWrite(j, HIGH);
  digitalWrite(k, LOW);
  digitalWrite(l, LOW);
  digitalWrite(m, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(x, HIGH);
  digitalWrite(y, LOW);
  delay(1000);
    
   }
    else if (distance > 35){
    digitalWrite(j, HIGH);
    digitalWrite(k, LOW);
    digitalWrite(l, HIGH);
    digitalWrite(m, LOW);
    digitalWrite(g, LOW);
    digitalWrite(f, LOW);
    digitalWrite(x, LOW);
    digitalWrite(y, LOW);
}
   else{
     digitalWrite(j, LOW);
     digitalWrite(k, LOW);
     digitalWrite(l, LOW);
     digitalWrite(m, LOW);
     digitalWrite(g, LOW);
     digitalWrite(f, LOW);
     digitalWrite(x, LOW);
     digitalWrite(y, LOW);
   }
}   
    

  
    
