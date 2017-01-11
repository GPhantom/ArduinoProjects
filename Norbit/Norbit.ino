#include <IRremoteInt.h>
#include <IRremote.h>

const int irReceiverPin = 3;
IRrecv irrecv(irReceiverPin);
decode_results decodedSignal;
int j = 2;
int k = 4;
int l = 5;
int m = 6;
int g = 10;
int f = 9;
int x = 7;
int y = 11;
int echo = 8;
int trig = 12;
int v;

void(* resetFunc) (void) = 0;

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
  irrecv.enableIRIn();
}

unsigned long last = millis();

void loop(){
  if (irrecv.decode(&decodedSignal) == true){
    if (millis() - last > 250){
      int v = (decodedSignal.value);
      Serial.println(v);
      if (v == 16){
        
        int duration, distance;
        digitalWrite(trig, HIGH);
        delay(1000);
        digitalWrite(trig, LOW);
        duration = pulseIn(echo, HIGH);
        distance = (duration/2) / 29.1;
        if (distance < 30){
        digitalWrite(j, HIGH);
        digitalWrite(k, LOW);
        digitalWrite(l, HIGH);
        digitalWrite(m, LOW);
        digitalWrite(g, LOW);
        digitalWrite(f, HIGH);
        digitalWrite(x, LOW);
        digitalWrite(y, HIGH);
        delay(2000);
    
  }
    else if (distance > 30){
    digitalWrite(j, HIGH);
    digitalWrite(k, LOW);
    digitalWrite(l, HIGH);
    digitalWrite(m, LOW);
    digitalWrite(g, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(x, HIGH);
    digitalWrite(y, LOW);
}
    }
    
    if (v != 16){
      
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
      
    last = millis();
    irrecv.resume();
    
      
    
  }
  
}
