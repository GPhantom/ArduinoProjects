#include <IRremoteInt.h>
#include <IRremote.h>

const int irReceiverPin = 2;
IRrecv irrecv(irReceiverPin);
decode_results decodedSignal;
int a = 3;
int b = 4;
int c = 5;
int d = 6;
int e = 7;
int f = 8;
int g = 9;
int h = 10;
int i = 11;
int j = 12;
int v;


void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(h, OUTPUT);
  pinMode(i, OUTPUT);
  pinMode(j, OUTPUT);
  
}

unsigned long last = millis();

void loop(){
  if (irrecv.decode(&decodedSignal) == true){
    if (millis() - last > 250){
      //Serial.println(decodedSignal.value, HEX);
      int v = (decodedSignal.value);
      Serial.println(v);
      if (v == 16){
        digitalWrite(a, HIGH);
        digitalWrite(b, LOW);
        digitalWrite(c, LOW);
        digitalWrite(d, LOW);
        digitalWrite(e, LOW);
        digitalWrite(f, LOW);
        digitalWrite(g, LOW);
        digitalWrite(h, LOW);
        digitalWrite(i, LOW);
        digitalWrite(j, LOW);
       
        
    }
    
    else if (v == 2064){
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      digitalWrite(h, LOW);
      digitalWrite(i, LOW);
      digitalWrite(j, LOW);
      
    }
    else if (v == 1040){
        digitalWrite(a, HIGH);
        digitalWrite(b, HIGH);
        digitalWrite(c, HIGH);
        digitalWrite(d, LOW);
        digitalWrite(e, LOW);
        digitalWrite(f, LOW);
        digitalWrite(g, LOW);
        digitalWrite(h, LOW);
        digitalWrite(i, LOW);
        digitalWrite(j, LOW);
    }
    else if (v == 3088){
        digitalWrite(a, HIGH);
        digitalWrite(b, HIGH);
        digitalWrite(c, HIGH);
        digitalWrite(d, HIGH);
        digitalWrite(e, LOW);
        digitalWrite(f, LOW);
        digitalWrite(g, LOW);
        digitalWrite(h, LOW);
        digitalWrite(i, LOW);
        digitalWrite(j, LOW);
    }
    else if (v == 528){
        digitalWrite(a, HIGH);
        digitalWrite(b, HIGH);
        digitalWrite(c, HIGH);
        digitalWrite(d, HIGH);
        digitalWrite(e, HIGH);
        digitalWrite(f, LOW);
        digitalWrite(g, LOW);
        digitalWrite(h, LOW);
        digitalWrite(i, LOW);
        digitalWrite(j, LOW);
    }
    else if (v == 2576){
        digitalWrite(a, HIGH);
        digitalWrite(b, HIGH);
        digitalWrite(c, HIGH);
        digitalWrite(d, HIGH);
        digitalWrite(e, HIGH);
        digitalWrite(f, HIGH);
        digitalWrite(g, LOW);
        digitalWrite(h, LOW);
        digitalWrite(i, LOW);
        digitalWrite(j, LOW);
    }
    else if (v == 1552){
        digitalWrite(a, HIGH);
        digitalWrite(b, HIGH);
        digitalWrite(c, HIGH);
        digitalWrite(d, HIGH);
        digitalWrite(e, HIGH);
        digitalWrite(f, HIGH);
        digitalWrite(g, HIGH);
        digitalWrite(h, LOW);
        digitalWrite(i, LOW);
        digitalWrite(j, LOW);
    }
    else if (v == 3600){
        digitalWrite(a, HIGH);
        digitalWrite(b, HIGH);
        digitalWrite(c, HIGH);
        digitalWrite(d, HIGH);
        digitalWrite(e, HIGH);
        digitalWrite(f, HIGH);
        digitalWrite(g, HIGH);
        digitalWrite(h, HIGH);
        digitalWrite(i, LOW);
        digitalWrite(j, LOW);
    }
    else if (v == 272){
        digitalWrite(a, HIGH);
        digitalWrite(b, HIGH);
        digitalWrite(c, HIGH);
        digitalWrite(d, HIGH);
        digitalWrite(e, HIGH);
        digitalWrite(f, HIGH);
        digitalWrite(g, HIGH);
        digitalWrite(h, HIGH);
        digitalWrite(i, HIGH);
        digitalWrite(j, LOW);
    }
    else if (v == 2320){
        digitalWrite(a, HIGH);
        digitalWrite(b, HIGH);
        digitalWrite(c, HIGH);
        digitalWrite(d, HIGH);
        digitalWrite(e, HIGH);
        digitalWrite(f, HIGH);
        digitalWrite(g, HIGH);
        digitalWrite(h, HIGH);
        digitalWrite(i, HIGH);
        digitalWrite(j, HIGH);
    }
    else if (v == 112){
        digitalWrite(a, LOW);
        digitalWrite(b, LOW);
        digitalWrite(c, LOW);
        digitalWrite(d, LOW);
        digitalWrite(e, LOW);
        digitalWrite(f, LOW);
        digitalWrite(g, LOW);
        digitalWrite(h, LOW);
        digitalWrite(i, LOW);
        digitalWrite(j, LOW);
    }
      
    last = millis();
    irrecv.resume();
  
}
}
}
