#include <IRremote.h>   


const int ledPin = 3; //pin 3 has PWM funtion

const int flexPin_s = A0;

const int flexPin_m = A1;

int buzzer = 12;



int value_s;
int value_m;//save analog value

IRsend irsend;



void setup(){

  
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);  

  Serial.begin(9600);       



}



void loop(){

  

  value_s = analogRead(flexPin_s);
  value_m = analogRead(flexPin_m);
  //Serial.println(value);
  value_s = map(value, 700, 900, 0, 255);
  value_m = map(value, 700, 900, 0, 255);//Map value 0-1023 to 0-255 (PWM)

  analogWrite(ledPin_s, value_s);
  analogWrite(ledPin_m, value_m);  //Send PWM value to led

  delay(100);  //Read and save analog value from potentiometer
  Serial.print("Flex_s = ");
  Serial.println(value_s);
  Serial.print("Flex_m = ");
  Serial.println(value_m);
  
  if (value > 100 & value < 150){
    
    
    irsend.sendSony(0xa90, 12);
    delay(50);
    irsend.sendSony(0xa90, 12);
    delay(50);
    irsend.sendSony(0xa90, 12);
    digitalWrite(buzzer, 12);
    delay(50);
    digitalWrite(buzzer, LOW);
  }
  else if (value < 10 ){
    irsend.sendSony(0x10, 12);
    delay(50);
    irsend.sendSony(0x10, 12);
    delay(50);
    irsend.sendSony(0x10, 12);
    digitalWrite(buzzer, 12);
    delay(50);
    digitalWrite(buzzer, LOW);

   
  }
  else if (value > 150){
    irsend.sendSony(0x20, 12);
    delay(50);
    irsend.sendSony(0x20, 12);
    delay(50);
    irsend.sendSony(0x20, 12);
    digitalWrite(buzzer, 12);
    delay(50);
    digitalWrite(buzzer, LOW);
    
    
  }

}
