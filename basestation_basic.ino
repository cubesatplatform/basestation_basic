#include <boards.h>
#include "basestation.h"


#define SYSNAME "BS"           //Remember there is a class name  And a Instance name given by the database  They may or may not be the same.


#ifdef TTGO
#undef TTGO
#endif

//#define TTGO1

CBaseStation bs;


void setup() {    
  bs.name(SYSNAME); 
  bs.setIAM(bs.name());
  Serial.begin(115200); 
  while(!Serial){};  
  delay(500);

  Wire.begin(); 
  #ifdef TTGO1 
   initBoard();
  #endif
  
  writeconsoleln("Starting Basestation BASIC: ");      

  delay(4000);
  bs._keyboard.name(_KEYBOARD);
 // bs._scheduler.name(_SCHEDULER);
  bs._phone.name(_PHONE);
  bs._messages.name(_MESSAGES);
  bs._ir_X1.name(_IRX1);
  bs._magX.name(_MAGX);
  bs._manager.name(_MANAGER);
 
}

void loop(){
  

  bs.loop();  
  
}
