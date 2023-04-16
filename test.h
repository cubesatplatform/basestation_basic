#pragma once
#include <systemobject.h>


class CTest:public CSystemObject{
  public:
  CTest(){ setInterval(10);}

  void setup(){setState(_PLAY);}
  void loop(){
   
    CMsg m=getDataMap("IMUIGYRO");
    m.writetoconsoleln();
    //writeconsoleln(m.get("CLUSTER"));
    float x=abs(m.get("X",0.0));
    float y=abs(m.get("Y",0.0));

    m.set(_SYS,"PINS");
    m.set(_ACT,"CHANGEPIN");
   
    if(x>.5){
      m.set(_VALUE,100.0);
      m.set(_PIN,0);
      addMessageList(m);
    }
    else{
      m.set(_VALUE,0.0);
      m.set(_PIN,0);       
      addMessageList(m);      
    }

    if(y>.5){
      m.set(_VALUE,100.0);
      m.set(_PIN,2);
      addMessageList(m);
    }
    else{
      m.set(_VALUE,0.0);
      m.set(_PIN,2);       
      addMessageList(m);      
    }    
  }
  
};
