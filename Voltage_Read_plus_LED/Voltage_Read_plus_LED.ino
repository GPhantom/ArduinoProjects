/*
  ReadAnalogVoltage
  Reads an analog input on pin 0, converts it to voltage, and prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/

// the setup routine runs once when you press reset:

int ledPin = 2;
int potPin = 2;
int buzzer = 8;
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);  // declare the ledPin as an OUTPUT
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(potPin);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  if (voltage == 5.00){
    Serial.println(voltage);
  
      // read the value from the sensor
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzer, HIGH);  // turn the ledPin on
    delay(sensorValue);                  // stop the program for some time
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzer, LOW);  // turn the ledPin off
    delay(sensorValue);
  }
  else{
  
    Serial.println(voltage);
  
    digitalWrite(buzzer, LOW);  // read the value from the sensor
    digitalWrite(ledPin, HIGH);  // turn the ledPin on
    delay(sensorValue);                  // stop the program for some time
    digitalWrite(ledPin, LOW);   // turn the ledPin off
    delay(sensorValue);
  }    // stop the program for some time
}
