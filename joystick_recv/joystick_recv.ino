#include <SPI.h>   // Comes with Arduino IDE
#include "RF24.h"  // Download and Install (See above)
#include "printf.h" // Needed for "printDetails" Takes up some memory
// NEED the SoftwareServo library installed
// http://playground.arduino.cc/uploads/ComponentLib/SoftwareServo.zip
  // Regular Servo library creates timer conflict!
/*-----( Declare Constants and Pin Numbers )-----*/
#define  CE_PIN  7   // The pins to be used for CE and SN
#define  CSN_PIN 8

#define ServoHorizontalPIN 3   //Pin Numbers for servos and laser/LED
#define ServoVerticalPIN   5
#define LaserPIN           6

#define ServoMIN_H  30  // Don't go to very end of servo travel
#define ServoMAX_H  150 // which may not be all the way from 0 to 180. 
#define ServoMIN_V  30  // Don't go to very end of servo travel
#define ServoMAX_V  150 // which may not be all the way from 0 to 180

/*-----( Declare objects )-----*/
/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus (usually) pins 7 & 8 (Can be changed) */
RF24 radio(CE_PIN, CSN_PIN);

 // create servo objects to control servos

/*-----( Declare Variables )-----*/
byte addresses[][6] = {"1Node", "2Node"}; // These will be the names of the "Pipes"

// Allows testing of radios and code without servo hardware. Set 'true' when servos connected
boolean hasHardware = false;  // Allows testing of radios and code without Joystick hardware.
//boolean hasHardware = true;

int HorizontalJoystickReceived; // Variable to store received Joystick values
int HorizontalServoPosition;    // variable to store the servo position

int VerticalJoystickReceived;   // Variable to store received Joystick values
int VerticalServoPosition;      // variable to store the servo positio

/**
  Create a data structure for transmitting and receiving data
  This allows many variables to be easily sent and received in a single transmission
  See http://www.cplusplus.com/doc/tutorial/structures/
*/
struct dataStruct {
  unsigned long _micros;  // to save response times
  int Xposition;          // The Joystick position values
  int Yposition;
  bool switchOn;          // The Joystick push-down switch
} myData;                 // This can be accessed in the form:  myData.Xposition  etc.


void setup()   /****** SETUP: RUNS ONCE ******/
{
  Serial.begin(115200);   // MUST reset the Serial Monitor to 115200 (lower right of window )
  // NOTE: The "F" in the print statements means "unchangable data; save in Flash Memory to conserve SRAM"
  Serial.println(F("YourDuino.com Example: Receive joystick data by nRF24L01 radio from another Arduino"));
  Serial.println(F("and control servos if attached (Check 'hasHardware' variable"));
  printf_begin(); // Needed for "printDetails" Takes up some memory
  /*-----( Set up servos )-----*/
  

  radio.begin();          // Initialize the nRF24L01 Radio
  radio.setChannel(108);  // 2.508 Ghz - Above most Wifi Channels
  radio.setDataRate(RF24_250KBPS); // Fast enough.. Better range

  // Set the Power Amplifier Level low to prevent power supply related issues since this is a
  // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
  // PALevelcan be one of four levels: RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH and RF24_PA_MAX
  radio.setPALevel(RF24_PA_LOW);
  //   radio.setPALevel(RF24_PA_MAX);

  // Open a writing and reading pipe on each radio, with opposite addresses
  radio.openWritingPipe(addresses[1]);
  radio.openReadingPipe(1, addresses[0]);

  // Start the radio listening for data
  radio.startListening();
//  radio.printDetails(); //Uncomment to show LOTS of debugging information
}//--(end setup )---


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{

  if ( radio.available())
  {

    while (radio.available())   // While there is data ready to be retrieved from the receive pipe
    {
      radio.read( &myData, sizeof(myData) );             // Get the data
    }

    radio.stopListening();                               // First, stop listening so we can transmit
    radio.write( &myData, sizeof(myData) );              // Send the received data back.
    radio.startListening();                              // Now, resume listening so we catch the next packets.

    Serial.print(F("Packet Received - Sent response "));  // Print the received packet data
    Serial.print(myData._micros);
    Serial.print(F("uS X= "));
    Serial.print(myData.Xposition);
    Serial.print(F(" Y= "));
    Serial.print(myData.Yposition);
    if ( myData.switchOn == 1)
    {
      Serial.println(F(" Switch ON"));
    }
    else
    {
      Serial.println(F(" Switch OFF"));
    }

  } // END radio available

// END hasHardware
}//--(end main loop )---

/*-----( Declare User-written Functions )-----*/

// NONE YET
//*********( THE END )***********
