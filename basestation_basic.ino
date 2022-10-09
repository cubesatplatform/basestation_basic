#include <string> 
#include <consoleio.h>

#include <messages.h>
#include <boards.h>
#include <sdfs.h>
#include "basestation.h"


#define SYSNAME "BS2" 

std::map<std::string,CSystemObject *> SysMap;
std::string CSystemObject::_IAM=SYSNAME;
std::string CSystemObject::_defaultTO="ADR1";

CBaseStation bs;
CMessages* getMessages(){return &bs.MSG;}


void setup() {    
  bs.Name(SYSNAME); 
  Serial.begin(115200); 
  while(!Serial){};
// Serial2.begin(115200,SERIAL_8N1,35,15); 
// sendSerial("Init");

  #ifdef TTGO1 
   initBoard();
  #endif
  
  writeconsoleln("Starting Basestation BASIC: ");      

  delay(1000);

  CMsg m;
  m.setSYS("MESSAGES");
  m.setACT("PINHIGH");
  m.setVALUE("1");
  m.setML("TRANSMITLIST");
  m.setPROCESSTIME(10000*1);
  m.writetoconsole();
  bs.addMessageList(m);
  m.setPROCESSTIME(10000*2);
  m.writetoconsole();
  bs.addMessageList(m);
  m.setPROCESSTIME(10000*3);
  m.writetoconsole();
  bs.addMessageList(m);
  m.setPROCESSTIME(10000*4);
  m.writetoconsole();
  bs.addMessageList(m);
}

void loop(){  
  
  bs.loop();

}
