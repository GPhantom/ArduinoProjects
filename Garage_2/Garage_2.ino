#include <IRremoteInt.h>
#include <IRremote.h>




int j = 8;
int k = 2;
int l = 7;
int m = 4;

int echo = 10;
int trig = 12;
const int irReceiverPin = 11;
IRrecv irrecv(irReceiverPin);
decode_results decodedSignal;



void setup(){
  Serial.begin(9600);
  pinMode(j, OUTPUT);
  pinMode(k, OUTPUT);
  pinMode(l, OUTPUT);
  pinMode(m, OUTPUT);

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
        
        
        
        
        
      }
      if ((v == 16)){
        digitalWrite(j, LOW);
        digitalWrite(k, LOW);
        digitalWrite(l, LOW);
        digitalWrite(m, LOW);
     
        
      }
      if ((v == 32)){
        
        digitalWrite(j, LOW);
        digitalWrite(k, HIGH);
        digitalWrite(l, LOW);
        digitalWrite(m, HIGH);

      }
      last = millis();
      irrecv.resume();
    }
  }
}
}
