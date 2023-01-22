#pragma once

#include <stateobj.h>
#include <kb.h>
#include <system_irarray.h>
#include <phone.h>
#include <systemmessages.h>
#include <scheduler.h>
#include <system_mgr.h>

//#include <system_gps.h>
#include <radio.h>

//#include <cloud.h>
#include <system_magtorquer.h>
#include <system_temperature.h>

#include <system_imu.h>

#include <fhmotor.h>

#include <cpins.h>

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
 

  CPhone _phone;  
  CMessagesObj _messages;
  CIRArray _ir_X1;
  CRadio _radio;  
  CMDrive _magX;

  CSystemMgr _manager;
 
  CTemperatureObject _tempX1;
  CIMU _IMUI2C;   
 // CCloud _cloud;  
  /*  
  CScheduler _scheduler;   
  CPinController _pincontroller;   
  CMagTorquer _magnetorquer;
  
  CMotorController _motorX;
  
  
  CGPS _tbeamgps;
  
  
  */
  CBaseStation();

  void callCustomFunctions(CMsg &msg);
};
