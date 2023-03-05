#include <boards.h>
#include "basestation.h"

#define SYSNAME "BS"           //Remember there is a class name  And a Instance name given by the database  They may or may not be the same.

CBaseStation bs;


void setup() {    
  bs.name(SYSNAME); 
  bs.setIAM(bs.name());
  Serial.begin(1000000); 
  while(!Serial){};  
  delay(500);

  Wire.begin(); 
  Wire1.begin(); 
  Wire2.begin(); 

  initBoard();  //New LilyGo boards
 
  writeconsoleln("Starting Basestation BASIC: ");      

  delay(4000);
  bs._keyboard.name(_KEYBOARD);
  bs._radio.name(_RADIO);
  bs._tbeamgps.name(_GPS);
  bs._msgpump.name("PUMP");
  
  //bs._phone.name(_PHONE);
  //bs._cloud.name(_CLOUD);
  //bs._msgpump.saveToCloud();
  
 //bs._ir_X1.name(_IRX1);
 //bs._magX.name(_MAGX);
 //bs._manager.name(_MANAGER);
 //bs._scheduler.name(_SCHEDULER); 
}

void loop(){  
  bs.loop();    
}
