#pragma once

#include <stateobj.h>
#include <kb.h>
#include <msgpump.h>
#include <radio.h>
#include <system_gps.h>

#include <cloud.h>
#include <phone.h>

#include <system_irarray.h>

#include <scheduler.h>
#include <system_mgr.h>
//#include <system_magtorquer.h>
//#include <system_temperature.h>
#include <system_imu.h>
//#include <fhmotor.h>
#include <cpins.h>
#include "test.h"

#define IMUADDRESS1 BNO080_DEFAULT_ADDRESS    //==75
#define IRADDRESS MLX90640_I2CADDR_DEFAULT
#define MOTOR_SPEED 2
#define MOTOR_FG 14
#define MOTOR_DIR 13



#define CUBESAT "ADR1"

  
class CBaseStation:public CStateObj {
private:
public:
  CKeyboard _keyboard;
  CRadio _radio;  
  
  CMsgPump _msgpump;
  CGPS _tbeamgps;

  CPhone _phone;  
  CCloud _cloud;  
  
  CSystemMgr _manager;
  CScheduler _scheduler;   
  CIRArray _ir_X1;  
 CMDrive _magX;
  //CTemperatureObject _tempX1;
  CIMU _IMUI2C;  
CTest _test;
  CPins _pins;
  /*  
  
  
  CPinController _pincontroller;   
  CMagTorquer _magnetorquer;
  CMotorController _motorX;
  */
  CBaseStation();

  void callCustomFunctions(CMsg &msg);
};
