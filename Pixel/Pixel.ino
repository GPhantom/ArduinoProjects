#include <IRremoteInt.h>
#include <IRremote.h>

int right_1 = 4;
int right_2 = 2;
int left_1 = 8;
int left_2 = 7;
const int irReceiverPin = 11;
IRrecv irrecv(irReceiverPin);
decode_results decodedSignal;

void setup(){
  pinMode(right_1, OUTPUT);
  pinMode(right_2, OUTPUT);
  pinMode(left_1, OUTPUT);
  pinMode(left_2, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

unsigned long last = millis();

void loop(){
  
   if (irrecv.decode(&decodedSignal) == true){
    if (millis() - last > 250){
      Serial.println(decodedSignal.value, HEX);
      int v = (decodedSignal.value);
      while ((v, HEX) == 16){
        digitalWrite(left_1, HIGH);
        digitalWrite(left_2, LOW);
        delay(100);
        digitalWrite(left_1, LOW);
        digitalWrite(left_2, LOW);
        break;
        
    }
   
    last = millis();
    irrecv.resume();
  }
  
  
  
  
}
}
