#include <boards.h>
#include "basestation.h"

#define SYSNAME "BS1"           //Remember there is a class name  And a Instance name given by the database  They may or may not be the same.

CBaseStation bs;


void setup() {    
  
  bs.name(SYSNAME); 
  bs.setIAM(bs.name());
  Serial.begin(1000000); 
  while(!Serial){};  
  bs.initPins();
  delay(500);



  initBoard();  //New LilyGo boards

  Wire.begin(); 
  #if defined(ARDUINO_PORTENTA_H7_M4) || defined(ARDUINO_PORTENTA_H7_M7)
    Wire1.begin(); 
    Wire2.begin(); 
  #endif
 
  writeconsoleln("Starting Basestation BASIC: ");      

  delay(4000);
  bs._keyboard.name(_KEYBOARD);
  bs._radio.name(_RADIO);
  bs._tbeamgps.name(_GPS);

  bs._msgpump.name("PUMP");

  bs._radio.setTransmitter(true);
  bs._radio.setReceiver(true);
  
  //bs._phone.name(_PHONE);
  bs._cloud.name(_CLOUD);
 bs._scheduler.name(_SCHEDULER);  
  
 bs._ir_X1.name(_IRX1);
 //bs._magX.name(_MAGX);
 bs._manager.name(_MANAGER);
 bs._test.name("TEST"); 
 bs._pins.name("PINS"); 
 
}

void loop(){  
  bs.loop();    
}
