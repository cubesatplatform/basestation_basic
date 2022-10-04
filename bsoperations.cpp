#include "bsoperations.h"






void CBSOperations::sendFile(CMsg &msg){  //TO:BSALL~ACT:SENDFILE~FIRST:0~LAST:20~FILE:UPDATE

  writeconsoleln("Called Send File");
  int chunk=0,first=0,last=-1;
  std::string path="/dev/test/";
 
  std::string filename=msg.getParameter("FILE","update");
  
  first=msg.getParameter("FIRST",first);
  last=msg.getParameter("LAST",first);

  for(int chunk=first;chunk<=last;chunk++){
    std::string fullpath=path;
    fullpath+=filename;
    fullpath+=tostring(chunk);
    fullpath+=".bin";

    writeconsoleln(fullpath); 
    
    /*sendRequestGet(fullpath.c_str());  /////////////////////  ????????????????????????????
    CMsg m=receiveFile();
  
    m.setTO(CUBESAT);
    addTransmitList(m);    
    */
  }
  //updateRadio(m);  

}

void CBSOperations::callCustomFunctions(CMsg &msg)  {  //Used to be NewMsg
  
  std::string sys=msg.getSYS();
  std::string act=msg.getACT();

  msg.writetoconsole();

  if(act=="") {}
}
