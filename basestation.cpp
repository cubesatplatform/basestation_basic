#include "basestation.h"

CBaseStation::CBaseStation(){
  addSystem(&cloud);
  addSystem(&radio); 
  addSystem(&MSG);
  addSystem(&mgr);
  addSystem(&keyboard);
  addSystem(&bsoperations);

  cloud.MSG=&MSG;
  radio.setACK(false);

  radio.Name("RADIO");      
  radio.setup();
  radio.setTransmitter(true);
  }
