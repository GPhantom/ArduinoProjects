#include <SPI.h>

// Poor Man's Wireless 2.4GHz Scanner
//
// uses an nRF24L01p connected to an Arduino
//
// Cables are:
//     SS       -> 10
//     MOSI     -> 11
//     MISO     -> 12
//     SCK      -> 13
//
// and CE       ->  9
//
// created March 2011 by Rolf Henkel
//

#define CE  9

// Array to hold Channel data
#define CHANNELS  64
int channel[CHANNELS];

// greyscale mapping
int LED = 5;
int  line;
char grey[] = " .:-=+*aRW";

// nRF24L01P registers we need
#define _NRF24_CONFIG      0x00
#define _NRF24_EN_AA       0x01
#define _NRF24_RF_CH       0x05
#define _NRF24_RF_SETUP    0x06
#define _NRF24_RPD         0x09

// get the value of a nRF24L01p register
byte getRegister(byte r)
{
 byte c;
 
 PORTB &=~_BV(2);
 c = SPI.transfer(r&0x1F);
 c = SPI.transfer(0);  
 PORTB |= _BV(2);

 return(c);
}

// set the value of a nRF24L01p register
void setRegister(byte r, byte v)
{
 PORTB &=~_BV(2);
 SPI.transfer((r&0x1F)|0x20);
 SPI.transfer(v);
 PORTB |= _BV(2);
}
 
// power up the nRF24L01p chip
void powerUp(void)
{
 setRegister(_NRF24_CONFIG,getRegister(_NRF24_CONFIG)|0x02);
 delayMicroseconds(130);
}

// switch nRF24L01p off
void powerDown(void)
{
 setRegister(_NRF24_CONFIG,getRegister(_NRF24_CONFIG)&~0x02);
}

// enable RX
void enable(void)
{
   PORTB |= _BV(1);
}

// disable RX
void disable(void)
{
   PORTB &=~_BV(1);
}

// setup RX-Mode of nRF24L01p
void setRX(void)
{
 setRegister(_NRF24_CONFIG,getRegister(_NRF24_CONFIG)|0x01);
 enable();
 // this is slightly shorter than
 // the recommended delay of 130 usec
 // - but it works for me and speeds things up a little...
 delayMicroseconds(100);
}

// scanning all channels in the 2.4GHz band
void scanChannels(void)
{
 disable();
 for( int j=0 ; j<200  ; j++)
 {
   for( int i=0 ; i<CHANNELS ; i++)
   {
     // select a new channel
     setRegister(_NRF24_RF_CH,(128*i)/CHANNELS);
     
     // switch on RX
     setRX();
     
     // wait enough for RX-things to settle
     delayMicroseconds(40);
     
     // this is actually the point where the RPD-flag
     // is set, when CE goes low
     disable();
     
     // read out RPD flag; set to 1 if
     // received power > -64dBm
     if( getRegister(_NRF24_RPD)>0 )   channel[i]++;
   }
 }
}

// outputs channel data as a simple grey map
void outputChannels(void)
{
  
 int norm = 0;
 
 // find the maximal count in channel array
 for( int i=0 ; i<CHANNELS ; i++)
   if( channel[i]>norm ) norm = channel[i];
   
 // now output the data
 Serial.print('|');
 for( int i=0 ; i<CHANNELS ; i++)
 {
   int pos;
   
   // calculate grey value position
   if( norm!=0 ) pos = (channel[i]*10)/norm;
   else          pos = 0;
   
   // boost low values
   if( pos==0 && channel[i]>0 ) pos++;
   
   // clamp large values
   if( pos>9 ) pos = 9;
 
   // print it out
   Serial.print(grey[pos]);  //print grey[pos] for ASCII-greyscale mapping
   channel[i] = 0;
 }
 
 // indicate overall power
 Serial.print("| ");
 Serial.println(norm);
 if (norm == 1){
   digitalWrite(LED,HIGH);
   delay(1000);
   digitalWrite(LED,LOW);
   }
   else if (norm == 2){
     digitalWrite(LED,HIGH);
     delay(900);
     digitalWrite(LED,LOW);
   }
   else if (norm == 3){
     digitalWrite(LED,HIGH);
     delay(800);
     digitalWrite(LED,LOW);
   }
   else if (norm == 4){
     digitalWrite(LED,HIGH);
     delay(700);
     digitalWrite(LED,LOW);
   }
   else if (norm == 5){
     digitalWrite(LED,HIGH);
     delay(600);
     digitalWrite(LED,LOW);
   }
   else if (norm == 6){
     digitalWrite(LED,HIGH);
     delay(500);
     digitalWrite(LED,LOW);
   }
   else if (norm == 7){
     digitalWrite(LED,HIGH);
     delay(400);
     digitalWrite(LED,LOW);
   }
   else if (norm == 8){
     digitalWrite(LED,HIGH);
     delay(300);
     digitalWrite(LED,LOW);
   }
   else if (norm == 9){
     digitalWrite(LED,HIGH);
     delay(200);
     digitalWrite(LED,LOW);
   }
   else if (norm == 10){
     digitalWrite(LED,HIGH);
     delay(100);
     digitalWrite(LED,LOW);
   }
   else if (norm > 10){
     digitalWrite(LED,HIGH);
     delay(20);
     digitalWrite(LED,LOW);
   }
   else if (norm == 0){
     digitalWrite(LED,HIGH);
   }
   else{
     digitalWrite(LED,LOW);
   }
}

// give a visual reference between WLAN-channels and displayed data
void printChannels(void)
{
 // output approximate positions of WLAN-channels
 Serial.println(">      1 2  3 4  5  6 7 8  9 10 11 12 13  14                     <");
}

void setup()
{
 pinMode(LED,OUTPUT);
 Serial.begin(57600);
 
 Serial.println("Starting Poor Man's Wireless 2.4GHz Scanner ...");
 Serial.println();

 // Channel Layout
 // 0         1         2         3         4         5         6
 // 0123456789012345678901234567890123456789012345678901234567890123
 //       1 2  3 4  5  6 7 8  9 10 11 12 13  14                     |
 //
 Serial.println("Channel Layout");
 printChannels();
 
 // Setup SPI
 SPI.begin();
 SPI.setDataMode(SPI_MODE0);
 SPI.setClockDivider(SPI_CLOCK_DIV2);
 SPI.setBitOrder(MSBFIRST);
 
 // Activate Chip Enable
 pinMode(CE,OUTPUT);
 disable();
 
 // now start receiver
 powerUp();
 
 // switch off Shockburst
 setRegister(_NRF24_EN_AA,0x0);
 
 // make sure RF-section is set properly
 // - just write default value...
 setRegister(_NRF24_RF_SETUP,0x0F);
 
 // reset line counter
 line = 0;
}

void loop()
{
 // do the scan
 scanChannels();
 
 // output the result
 outputChannels();
 
 // output WLAN-channel reference every 12th line
 if( line++>12 )
 {
   printChannels();
   line = 0;
 }
}
