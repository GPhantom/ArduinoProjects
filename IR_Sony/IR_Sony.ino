#include <IRremote.h>
//default pin for ir led is 3

IRsend irsend;

void setup() {
}

void loop() {
    irsend.sendSony(0xa90, 12);
    delay(100);
    irsend.sendSony(0xa90, 12);
    delay(100);
    irsend.sendSony(0xa90, 12);
    delay(300000);
}
