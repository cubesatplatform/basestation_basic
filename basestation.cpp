#include "basestation.h"

CBaseStation::CBaseStation(){
  
  addSystem(&_keyboard);
  addSystem(&_phone);
  addSystem(&_msgpump);
  addSystem(&_radio);  
  addSystem(&_cloud);
  
  //addSystem(&_scheduler);
  //addSystem(&_ir_X1);  
  //addSystem(&_manager);  
  
  
  //addSystem(&_motorX); 
  //addSystem(&_IMUI2C); 
  //_motorX.Mode(_LOCK);
  //addSystem(&_pincontroller);
  //addSystem(&_magX);
  //addSystem(&_magnetorquer);
 /*
          
  //addSystem(&_tbeamgps);

  _IMUI2C.name("IMUI");
  _IMUI2C.config(IMUADDRESS1,&Wire);
  
  _radio.setACK(false);
  _radio.name("RADIO");        
  _radio.setTransmitter(true);  

  _ir_X1.name(_IRX1);
  _tempX1.name(_TEMPX1);  
  _motorX.name(_MOTORX);
  _magX.name(_MAGX);

  _motorX.config(MOTOR_SPEED,MOTOR_FG,MOTOR_DIR);
  _ir_X1.config(IRADDRESS);
  _motorX.config(2,14,13);
*/
}

void CBaseStation::callCustomFunctions(CMsg &msg){
  writeconsoleln("void CBaseStation::callCustomFunctions(CMsg &msg)");
  CStateObj::callCustomFunctions(msg);
}
