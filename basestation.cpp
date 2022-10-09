#include "basestation.h"

CBaseStation::CBaseStation(){
  //addSystem(&cloud);
  addSystem(&radio); 
  addSystem(&MSG);
  addSystem(&mgr);
  addSystem(&keyboard);
  addSystem(&bsoperations);
  addSystem(&sch);

  cloud.MSG=&MSG;
  radio.setACK(false);

  radio.Name("RADIO");      
  radio.setTransmitter(true);  
  }

void CBaseStation::callCustomFunctions(CMsg &msg){
  writeconsoleln("void CBaseStation::callCustomFunctions(CMsg &msg)");
  CStateObj::callCustomFunctions(msg);

}
