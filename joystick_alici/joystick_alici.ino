#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN   9
#define CSN_PIN 10





const uint64_t pipe = 0xE8E8F0F0E1LL;

RF24 radio(CE_PIN, CSN_PIN); 

int data[9]; 

void setup()   
{

  Serial.begin(9600);
  pinMode(2,OUTPUT);  
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();;
}


void loop() {
  
  if ( radio.available() ) //Eğer sinyal algılarsan...
  {
    radio.read( data, sizeof(data) ); 
    //digitalWrite(2, HIGH);
  
Serial.print("data[0]=");
Serial.println(data[0]);
Serial.print("data[1]=");
Serial.println(data[1]);
Serial.print("data[2]=");
Serial.println(data[2]);
Serial.print("data[3]=");
Serial.println(data[3]);
Serial.print("data[4]=");
Serial.println(data[4]);
Serial.print("data[5]=");
Serial.println(data[5]);
Serial.print("data[6]=");
Serial.println(data[6]);
Serial.print("data[7]=");
Serial.println(data[7]);
Serial.print("data[8]=");
Serial.println(data[8]);
  if (data[2] == 0){
    digitalWrite(2, HIGH);
  }
  
  else if(data[2] == 1){
    digitalWrite(2, LOW);
  }


  }

}



