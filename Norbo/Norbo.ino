#include <IRremoteInt.h>
#include <IRremote.h>




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
const int irReceiverPin = 2;
IRrecv irrecv(irReceiverPin);
decode_results decodedSignal;



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
      Serial.println(decodedSignal.value);
      int v = (decodedSignal.value);
      while (irrecv.decode(&decodedSignal) == true){
        if ((v == 2704)){
        digitalWrite(j, HIGH);
        digitalWrite(k, LOW);
        digitalWrite(l, HIGH);
        digitalWrite(m, LOW);
        digitalWrite(g, HIGH);
        digitalWrite(f, LOW);
        digitalWrite(x, HIGH);
        digitalWrite(y, LOW);
        
        
        
        
      }
      if ((v == 16)){
        digitalWrite(j, LOW);
        digitalWrite(k, LOW);
        digitalWrite(l, LOW);
        digitalWrite(m, LOW);
        digitalWrite(g, LOW);
        digitalWrite(f, LOW);
        digitalWrite(x, LOW);
        digitalWrite(y, LOW);
        
      }
      if ((v == 32)){
        
        digitalWrite(j, LOW);
        digitalWrite(k, HIGH);
        digitalWrite(l, LOW);
        digitalWrite(m, HIGH);
        digitalWrite(g, LOW);
        digitalWrite(f, HIGH);
        digitalWrite(x, LOW);
        digitalWrite(y, HIGH);
      }
      last = millis();
      irrecv.resume();
    }
  }
}
}
