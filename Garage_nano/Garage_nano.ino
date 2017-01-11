

#include <IRremote.h>   





const int ledPin = 3;   //pin 3 has PWM funtion

const int flexPin = A0; //pin A0 to read analog input

int buzzer = 12;



int value; 

IRsend irsend;



void setup(){

  
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);  

  Serial.begin(9600);       



}



void loop(){

  

  value = analogRead(flexPin);
  //Serial.println(value);
  value = map(value, 700, 900, 0, 255);//Map value 0-1023 to 0-255 (PWM)

  analogWrite(ledPin, value);          //Send PWM value to led

  delay(100);  //Read and save analog value from potentiometer
  Serial.println(value);
  
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
