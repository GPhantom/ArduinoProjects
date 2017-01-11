int val;
int tempPin = 1;
int p_1 = 7;
int p_2 = 4;
int p_3 = 2;
void setup()
{
pinMode(p_1, OUTPUT);
pinMode(p_2, OUTPUT);
pinMode(p_3, OUTPUT);
Serial.begin(9600);
}
void loop()
{
val = analogRead(tempPin);
float mv = (val/1024.0)*5000;
float cel = mv/10;
float farh = (cel*9)/5 + 32;

if (cel > 20 && cel < 21){
  digitalWrite(p_1, HIGH);
  digitalWrite(p_2, LOW);
  digitalWrite(p_3, LOW);
  
}

else if (cel > 21 && cel < 22){
  digitalWrite(p_1, HIGH);
  digitalWrite(p_2, HIGH);
  digitalWrite(p_3, LOW);
  
}

else if (cel > 22){
  digitalWrite(p_1, HIGH);
  digitalWrite(p_2, HIGH);
  digitalWrite(p_3, HIGH);
  
}

else{
  digitalWrite(p_1, LOW);
  digitalWrite(p_2, LOW);
  digitalWrite(p_3, LOW);
}  



Serial.print("TEMPRATURE = ");
Serial.print(cel);
Serial.print("*C");
Serial.println();
delay(1000);

}

