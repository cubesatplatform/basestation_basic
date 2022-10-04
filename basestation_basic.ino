#include <string> 
#include <consoleio.h>

#include <messages.h>
#include <boards.h>
#include <sdfs.h>
#include "basestation.h"
 

std::map<std::string,CSystemObject *> SysMap;
std::string CSystemObject::_IAM="BS2";
std::string CSystemObject::_defaultTO="ADR1";

CBaseStation bs;
CMessages* getMessages(){return &bs.MSG;}


void setup() {     
  Serial.begin(115200); 
  while(!Serial){};
// Serial2.begin(115200,SERIAL_8N1,35,15); 
// sendSerial("Init");

  #ifdef TTGO1 
   initBoard();
  #endif
  
  writeconsoleln("Starting Basestation BASIC: ");      

  delay(1000);
}

void loop(){  
  bs.loop();

}
