 #include <stateobj.h>
//#include <encode.h>
#include <radio.h>
#include <msg.h>
#include <cloud.h>
#include <system_mgr.h>
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
  
  CBaseStation();
};
