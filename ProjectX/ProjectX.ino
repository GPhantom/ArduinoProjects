#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define CE_PIN   9
#define CSN_PIN 10

int M_F_R_1 = 3;
int M_F_R_2 = 4;
int M_F_L_1 = A0;
int M_F_L_2 = A1;
int M_B_R_1 = A4;
int M_B_R_2 = A5;
int M_B_L_1 = A2;
int M_B_L_2 = A3;
int buzzer = 2;
int echo = 5;
int trig = 6;

const uint64_t pipe = 0xE8E8F0F0E1LL;

RF24 radio(CE_PIN, CSN_PIN); 

int data[9];

void setup(){
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(A0,OUTPUT);
 pinMode(A1,OUTPUT);
 pinMode(A4,OUTPUT);
 pinMode(A5,OUTPUT);
 pinMode(A2,OUTPUT);
 pinMode(A3,OUTPUT);
 pinMode(2,OUTPUT);
 Serial.begin(9600);
 pinMode(echo, INPUT);
 pinMode(trig, OUTPUT);
 radio.begin();
 radio.openReadingPipe(1,pipe);
 radio.startListening();; 
}

void loop(){
  if ( radio.available() ) //Eğer sinyal algılarsan...
  {
    radio.read( data, sizeof(data) ); 
    
    if (data[5] == 0){
      digitalWrite(buzzer,HIGH);
      analogWrite(M_F_L_1,0);
      analogWrite(M_F_L_2,255);
      analogWrite(M_B_R_1,0);
      analogWrite(M_B_R_2,255);
      analogWrite(M_B_L_1,0);
      analogWrite(M_B_L_2,255);
      digitalWrite(M_F_R_1,LOW);
      digitalWrite(M_F_R_2,HIGH);
    }
    else if (data[6] == 0){
      digitalWrite(buzzer,HIGH);
      analogWrite(M_F_L_1,255);
      analogWrite(M_F_L_2,0);
      analogWrite(M_B_R_1,255);
      analogWrite(M_B_R_2,0);
      analogWrite(M_B_L_1,255);
      analogWrite(M_B_L_2,0);
      digitalWrite(M_F_R_1,HIGH);
      digitalWrite(M_F_R_2,LOW);
    }

    else if (data[0] > 600){
      digitalWrite(buzzer,HIGH);
      analogWrite(M_F_L_1,0);
      analogWrite(M_F_L_2,255);
      analogWrite(M_B_R_1,255);
      analogWrite(M_B_R_2,0);
      analogWrite(M_B_L_1,0);
      analogWrite(M_B_L_2,255);
      digitalWrite(M_F_R_1,HIGH);
      digitalWrite(M_F_R_2,LOW);
    }
    else if (data[0] < 100){
      digitalWrite(buzzer,HIGH);
      analogWrite(M_F_L_1,255);
      analogWrite(M_F_L_2,0);
      analogWrite(M_B_R_1,0);
      analogWrite(M_B_R_2,255);
      analogWrite(M_B_L_1,255);
      analogWrite(M_B_L_2,0);
      digitalWrite(M_F_R_1,LOW);
      digitalWrite(M_F_R_2,HIGH);
    }
    else if (data[5] == 1 | data[6] == 1 | data[0] == 332){
      digitalWrite(buzzer,LOW);
      analogWrite(M_F_L_1,0);
      analogWrite(M_F_L_2,0);
      analogWrite(M_B_R_1,0);
      analogWrite(M_B_R_2,0);
      analogWrite(M_B_L_1,0);
      analogWrite(M_B_L_2,0);
      digitalWrite(M_F_R_1,LOW);
      digitalWrite(M_F_R_2,LOW); 
    }

    
}
}

