#include <stateobj.h>
#include <system_gps.h>
#include <radio.h>
#include <msg.h>
#include <cloud.h>
#include <system_mgr.h>
#include <scheduler.h>
#include <kb.h>


#include "bsoperations.h"


#define CUBESAT "ADR1"

class CBaseStation:public CStateObj {
private:
  
    
public:
  CKeyboard keyboard;
  CRadio radio;  
  CCloud cloud;
  CBSOperations bsoperations;
  CMessages MSG;
  CSystemMgr mgr;
  CScheduler sch;
  CGPS gps;
  
  CBaseStation();

  void callCustomFunctions(CMsg &msg);
};
