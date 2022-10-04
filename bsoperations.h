#pragma once

#include <systemobject.h>

  
class CBSOperations:public CSystemObject {
private:

public:
  CBSOperations (){Name("OPERATIONS");}

  
  void sendFile(CMsg &msg);
  void callCustomFunctions(CMsg &msg); 
};
