#include "basestation.h"
 
CBaseStation::CBaseStation(){
  CMsg m;
  m.set(_PIN,0);
  _pins.addpin(m);
  m.set(_PIN,2);
  _pins.addpin(m);
  
  //addSystem(&_test);
  //addSystem(&_pins);
  addSystem(&_keyboard);
  addSystem(&_radio); 
  addSystem(&_msgpump);
  addSystem(&_manager);  
  
  addSystem(&_cloud);
  //addSystem(&_tbeamgps);
  //_tbeamgps._m.set(_SAVEMAPTOCLOUD,1);
   
  
  addSystem(&_scheduler);
  _scheduler.schedule(_MANAGER,"GETDATA", _GPS,30000);
  _scheduler.schedule(_RADIO,"STATS", std::string(_RADIO)+std::string("_STATS"),60000);

//addSystem(&_phone);
 // addSystem(&_ir_X1);  
 // _ir_X1.config(IRADDRESS);
  
  //addSystem(&_motorX); 
  //addSystem(&_IMUI2C); 
  _IMUI2C.name("IMUI");
  _IMUI2C.config(IMUADDRESS1,&Wire);

  //_motorX.Mode(_LOCK);
  //addSystem(&_pincontroller);
  //addSystem(&_magX);
  //addSystem(&_magnetorquer);
 /*
          
  

  
  _radio.setACK(false);
  _radio.name("RADIO");        
  _radio.setTransmitter(true);  

  _ir_X1.name(_IRX1);
  _tempX1.name(_TEMPX1);  
  _motorX.name(_MOTORX);
  _magX.name(_MAGX);

  _motorX.config(MOTOR_SPEED,MOTOR_FG,MOTOR_DIR);
  
  _motorX.config(2,14,13);
*/
}

void CBaseStation::callCustomFunctions(CMsg &msg){
  writeconsoleln("void CBaseStation::callCustomFunctions(CMsg &msg)");
  CStateObj::callCustomFunctions(msg);
}
