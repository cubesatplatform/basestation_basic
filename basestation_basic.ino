#include <string> 
#include <consoleio.h>

#include <messages.h>
#include <boards.h>
#include <radio.h>


char input;
std::string cmdstr;
long last=0;
int id=0;
std::string CSystemObject::_sat="ADR1";
std::map<std::string,CSystemObject *> SysMap;
std::map<std::string, std::string> simpleCMDs;
CMessages* MSG=new CMessages();
CMessages* getMessages() { return MSG; }
CRadio radio;

void myinit(){
  radio.setACK(false);
  writeconsoleln("Starting Basestation: ");


  simpleCMDs[std::string("normal")]=std::string("SYS:SAT~ACT:NORMAL~SAT:ADR2~ACK:0");
  simpleCMDs[std::string("lowpower")]=std::string("SYS:SAT~ACT:LOWPOWER~ACK:0");
  simpleCMDs[std::string("deploy")]=std::string("SYS:SAT~ACT:DEPLOY~ACK:0");
  simpleCMDs[std::string("COUNTS")]=std::string("SYS:SAT~ACT:COUNTS");
  
  simpleCMDs[std::string("adcs")]=std::string("SYS:SAT~ACT:ADCS~SAT:ADR2~ACK:0");
  simpleCMDs[std::string("detumble")]=std::string("SYS:SAT~ACT:DETUMBLE~ACK:0");
  simpleCMDs[std::string("phonestate")]=std::string("SYS:SAT~ACT:PHONE~ACK:0");
  
  simpleCMDs[std::string("gps")]=std::string("SYS:GPS~ACT:START~ACK:0");
  simpleCMDs[std::string("reset")]=std::string("SYS:SAT~ACT:RESET~ACK:0");


  simpleCMDs[std::string("TRANSMITDATA")]=std::string("SYS:SAT~ACT:TRANSMITDATA~ACK:0");
  simpleCMDs[std::string("DATALISTCLEAR")]=std::string("SYS:SAT~ACT:DATALISTCLEAR~ACK:0"); 
  simpleCMDs[std::string("MESSAGESLISTCLEAR")]=std::string("SYS:SAT~ACT:MESSAGESLISTCLEAR~ACK:1");
  simpleCMDs[std::string("TRANSMITLISTCLEAR")]=std::string("SYS:SAT~ACT:TRANSMITLISTCLEAR~ACK:1");
  simpleCMDs[std::string("TRANSMITTEDLISTCLEAR")]=std::string("SYS:SAT~ACT:TRANSMITTEDLISTCLEAR~ACK:1");

  simpleCMDs[std::string("datatest")]=std::string("SYS:SAT~ACT:OUTPUT~D:000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999");   
 
  simpleCMDs[std::string("phonegps")]=std::string("SYS:PHONE~ACT:CGPS~ACK:1");
  simpleCMDs[std::string("phonetime")]=std::string("SYS:PHONE~ACT:CTIME~ACK:1");
  simpleCMDs[std::string("photo")]=std::string("SYS:PHONE~ACT:CPHOTO(B,50%,100,100,AUTO)");
  simpleCMDs[std::string("imuspi")]=std::string("SYS:IMUSPI~ACT:START");  
  simpleCMDs[std::string("imui2c")]=std::string("SYS:IMUI2C~ACT:START");  
  simpleCMDs[std::string("light")]=std::string("SYS:LIGHT~ACT:START");  
  simpleCMDs[std::string("acktest")]=std::string("SYS:SAT~ACT:OUTPUT~ACK:0~D:000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999"); 
 
  simpleCMDs[std::string("irx")]=std::string("SYS:IRX1~ACT:START");  
  simpleCMDs[std::string("irxout")]=std::string("SYS:IRX1~ACT:OUTPUT~TYPE:A");  
  simpleCMDs[std::string("irxsend")]=std::string("SYS:MGR~ACT:ADD~_SYS:IRX1~_ACT:OUTPUT~TYPE:A~_INTERVAL:60000~_START:0~_STOP:1000000");  
  simpleCMDs[std::string("forwardx")]=std::string("SYS:MOTORX~ACT:SPEED~SPEED:0.2~DURATION:2000~ACK:1");  
  simpleCMDs[std::string("backwardx")]=std::string("SYS:MOTORX~ACT:SPEED~SPEED:0.2~DURATION:2000~ACK:1");  
  simpleCMDs[std::string("forwardy")]=std::string("SYS:MOTORY~ACT:SPEED~SPEED:0.2~DURATION:2000~ACK:1");  
  simpleCMDs[std::string("backwardy")]=std::string("SYS:MOTORY~ACT:SPEED~SPEED:0.2~DURATION:2000~ACK:1");  
  simpleCMDs[std::string("forwardz")]=std::string("SYS:MOTORZ~ACT:SPEED~SPEED:0.2~DURATION:2000~ACK:1");  
  simpleCMDs[std::string("backwardz")]=std::string("SYS:MOTORZ~ACT:SPEED~SPEED:0.2~DURATION:2000~ACK:1");  
  
 
  simpleCMDs[std::string("dur1")]=std::string("SYS:MOTORX~ACT:SPEED~SPEED:0.2~DURATION:2000~D:000000000000000000000000001111111111111111111111111111112222222222222222222222222333333333333333333333344444444444"); 

  simpleCMDs["RADIO"]=std::string("SYS:MGR~ACT:RADIO");
  simpleCMDs["MAG"]=std::string("SYS:MGR~ACT:MAG");
  simpleCMDs["MAGX"]=std::string("SYS:MGR~ACT:MAGX");
  simpleCMDs["MAGY"]=std::string("SYS:MGR~ACT:MAGY");
  simpleCMDs["MAGZ"]=std::string("SYS:MGR~ACT:MAGZ");
  
  simpleCMDs["MAGDX"]=std::string("SYS:MGR~ACT:MAGDX");
  simpleCMDs["MAGDY"]=std::string("SYS:MGR~ACT:MAGDY");
  simpleCMDs["MAGDZ"]=std::string("SYS:MGR~ACT:MAGDZ");

  simpleCMDs["ADCSON"]=std::string("SYS:MGR~ACT:ADCSON");
  simpleCMDs["ADCSOFF"]=std::string("SYS:MGR~ACT:ADCSOFF");
  simpleCMDs["PINSON"]=std::string("SYS:MGR~ACT:PINSON");
  simpleCMDs["PINSOFF"]=std::string("SYS:MGR~ACT:PINSOFF");
  simpleCMDs["PHONEON"]=std::string("SYS:MGR~ACT:PHONEON");
  simpleCMDs["PHONEOFF"]=std::string("SYS:MGR~ACT:PHONEOFF");
  simpleCMDs["BURN"]=std::string("SYS:MGR~ACT:BURN");
  simpleCMDs["IMUSPI"]=std::string("SYS:MGR~ACT:IMUSPI");
  simpleCMDs["IMU0"]=std::string("SYS:MGR~ACT:IMU0");
  simpleCMDs["IMU1"]=std::string("SYS:MGR~ACT:IMU1");
  simpleCMDs["IMU2"]=std::string("SYS:MGR~ACT:IMU2");
  simpleCMDs["I2C0"]=std::string("SYS:MGR~ACT:I2C0");
  simpleCMDs["I2C1"]=std::string("SYS:MGR~ACT:I2C1");
  simpleCMDs["I2C2"]=std::string("SYS:MGR~ACT:I2C2");
  simpleCMDs["H"]=std::string("SYS:MGR~ACT:H4");
  simpleCMDs["L"]=std::string("SYS:MGR~ACT:L4");
  simpleCMDs["W"]=std::string("SYS:MGR~ACT:PWM4");
  displayCMDs();
}

void displayCMDs(){
  
  writeconsoleln();
  writeconsoleln("Commands: ");
  writeconsoleln("----------------------------------------------------------------");
  for (auto it = simpleCMDs.begin(); it != simpleCMDs.end(); it++) {    
    std::string tmpstr = "   "+it->first + ": " + it->second;
    writeconsoleln(tmpstr.c_str());
  }
  writeconsoleln("----------------------------------------------------------------");
}

void sendSerial(const char* cmd) {    //Send to Phone
  Serial2.print(id);
  Serial2.flush();
  Serial2.print(",");
  Serial2.flush();
  Serial2.println(cmd);
  Serial2.flush();
  delayMicroseconds(500); 
  id++;

  writeconsoleln(cmd);
}


void SendCmd(std::string str){
  
    std::string cmd=simpleCMDs[str];
    if(cmd.size()>1){
      CMsg m(cmd);
      
      writeconsoleln(m.serialize());
      radio.addTransmitList(m);   
      //sendSerial(cmd.c_str());
    }
    else{
      if(str.size()>1){
        CMsg m(str);
        
        radio.addTransmitList(m);         
        //sendSerial(str.c_str());
      }
    }      
}    



void kbloop() {
  
  if(Serial.available()){
        input = Serial.read();
        if(input =='?'){
          displayCMDs();    
          cmdstr="";
          input=' '; 
          return;
        }
        if((input !='\n')&&(input !=' ')) cmdstr+=input;              
    }

  //while(Serial2.available())   Serial2.print(Serial2.read());

  if(input =='\n'){
    writeconsoleln(cmdstr.c_str());
    SendCmd(cmdstr);   
    cmdstr="";
    input=' ';
  }
}


void setup() {     
      Serial.begin(115200); 
      while(!Serial){};
   // Serial2.begin(115200,SERIAL_8N1,35,15); 
    
      #ifdef TTGO1 
       initBoard();
      #endif
      myinit();
   // sendSerial("Init");
   // radio.setMessages(&MSG);
      radio.setup();
      delay(1000);
}

unsigned long dlast=0;
void dataloop(){
  if (millis()>dlast+20){
    dlast=millis();
    for (auto m:simpleCMDs){
        SendCmd(m.first);
        delay(10);
      }
  }
}

unsigned long t=0;
void loop(){
  if(millis()>t+5000){
    t=millis();
 //   writeconsoleln();writeconsole("Loop "); writeconsoleln((long)ESP.getFreeHeap());writeconsoleln(" -------------------------------------------   ");
  }
    
    
  kbloop();
  radio.loop();   
  //dataloop();
  
  if(MSG->ReceivedList.size()){
  std::string d,d1,d2,d3,d4;
  CMsg b = MSG->ReceivedList.back();
  if((b.getTABLE()=="IR")&&(b.getOFFSET()=="4")){
    
    while(MSG->ReceivedList.size()){
      CMsg m=MSG->ReceivedList.front();
      MSG->ReceivedList.pop_front();
      if(m.getTABLE()=="IR"){
        if(m.getOFFSET()=="4")
          d4=m.getDATA();
        if(m.getOFFSET()=="3")
          d3=m.getDATA();
        if(m.getOFFSET()=="2")
          d2=m.getDATA();
        if(m.getOFFSET()=="1")
          d1=m.getDATA();
        if(m.getOFFSET()=="0")
          d=m.getDATA();
         }                     
    }

    
    d+=d1;
    d+=d2;
    d+=d3;    
    d+=d4;    
    MSG->ReceivedList.clear();
    int count=0;
    for(auto a:d){
      writeconsole(a);
      writeconsole(" ");
      count++;
      if(count%32==0)
        writeconsoleln("");      
      
    }
    writeconsoleln("");
  }   
  }  
}
