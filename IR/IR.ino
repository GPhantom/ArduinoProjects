#include <IRremoteInt.h>
#include <IRremote.h>

const int irReceiverPin = 2;
IRrecv irrecv(irReceiverPin);
decode_results decodedSignal;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
}

unsigned long last = millis();

void loop(){
  if (irrecv.decode(&decodedSignal) == true){
    if (millis() - last > 250){
      Serial.println(decodedSignal.value, HEX);
    }
    last = millis();
    irrecv.resume();
  }
}

