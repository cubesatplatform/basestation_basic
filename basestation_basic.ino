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
  writeconsoleln("Starting Basestation BASIC: ");

  simpleCMDs[std::string("normal")]=std::string("SYS:SAT~ACT:NORMAL~ACK:0");
  simpleCMDs[std::string("lowpower")]=std::string("SYS:SAT~ACT:LOWPOWER~ACK:0");
  simpleCMDs[std::string("deploy")]=std::string("SYS:SAT~ACT:DEPLOY~ACK:0");  
  simpleCMDs[std::string("adcs")]=std::string("SYS:SAT~ACT:ADCS~ACK:0");
  simpleCMDs[std::string("detumble")]=std::string("SYS:SAT~ACT:DETUMBLE~ACK:0");
  simpleCMDs[std::string("phone")]=std::string("SYS:SAT~ACT:PHONE~ACK:0");
  
  simpleCMDs[std::string("counts")]=std::string("SYS:SAT~ACT:COUNTS");
  simpleCMDs[std::string("gps")]=std::string("SYS:GPS~ACT:START~ACK:0");
  simpleCMDs[std::string("reset")]=std::string("SYS:SAT~ACT:RESET~ACK:0");

  simpleCMDs[std::string("transmitdata")]=std::string("SYS:SAT~ACT:TRANSMITDATA~ACK:0");
  simpleCMDs[std::string("datalistclear")]=std::string("SYS:SAT~ACT:DATALISTCLEAR~ACK:0"); 
  simpleCMDs[std::string("messagelistclear")]=std::string("SYS:SAT~ACT:MESSAGESLISTCLEAR~ACK:0");
  simpleCMDs[std::string("transmitlistclear")]=std::string("SYS:SAT~ACT:TRANSMITLISTCLEAR~ACK:0");
  simpleCMDs[std::string("transmittedlistclear")]=std::string("SYS:SAT~ACT:TRANSMITTEDLISTCLEAR~ACK:0");

  simpleCMDs[std::string("datatest")]=std::string("SYS:SAT~ACT:OUTPUT~D:000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999");   
 
  simpleCMDs[std::string("phonegps")]=std::string("SYS:PHONE~ACT:CGPS~ACK:0");
  simpleCMDs[std::string("phonetime")]=std::string("SYS:PHONE~ACT:CTIME~ACK:0");
  simpleCMDs[std::string("photo")]=std::string("SYS:PHONE~ACT:CPHOTO(B,50%,100,100,AUTO)");    
  simpleCMDs[std::string("light")]=std::string("SYS:LIGHT~ACT:START");  
  simpleCMDs[std::string("acktest")]=std::string("SYS:SAT~ACT:OUTPUT~ACK:0~D:000000000000000000000000111111111111111111111111111111111222222222222222222222222222223333333333333333333333333333333444444444444444444444444444444444444555555555555555555555555555555555556666666666666666666666666666677777777777777777777777777777777777778888888888888888888888888888888888999999999999999999999999999999999"); 
 
  simpleCMDs[std::string("irx")]=std::string("SYS:IRX1~ACT:START");  
  simpleCMDs[std::string("irxout")]=std::string("SYS:IRX1~ACT:OUTPUT~TYPE:A");  
  simpleCMDs[std::string("irxsend")]=std::string("SYS:MGR~ACT:ADD~_SYS:IRX1~_ACT:OUTPUT~TYPE:A~_INTERVAL:60000~_START:0~_STOP:1000000");  
  simpleCMDs[std::string("forwardx")]=std::string("SYS:MOTORX~ACT:SPEED~SPEED:0.2~DURATION:2000~ACK:0");  
  simpleCMDs[std::string("backwardx")]=std::string("SYS:MOTORX~ACT:SPEED~SPEED:0.2~DURATION:2000~ACK:0");  
  simpleCMDs[std::string("forwardy")]=std::string("SYS:MOTORY~ACT:SPEED~SPEED:0.2~DURATION:2000~ACK:0");  
  simpleCMDs[std::string("backwardy")]=std::string("SYS:MOTORY~ACT:SPEED~SPEED:0.2~DURATION:2000~ACK:0");  
  simpleCMDs[std::string("forwardz")]=std::string("SYS:MOTORZ~ACT:SPEED~SPEED:0.2~DURATION:2000~ACK:0");  
  simpleCMDs[std::string("backwardz")]=std::string("SYS:MOTORZ~ACT:SPEED~SPEED:0.2~DURATION:2000~ACK:0");  
  
 
  simpleCMDs[std::string("dur1")]=std::string("SYS:MOTORX~ACT:SPEED~SPEED:0.2~DURATION:2000~D:000000000000000000000000001111111111111111111111111111112222222222222222222222222333333333333333333333344444444444"); 

  simpleCMDs["radio"]=std::string("SYS:MGR~ACT:RADIO");
  simpleCMDs["mag"]=std::string("SYS:MGR~ACT:MAG");
  simpleCMDs["magx"]=std::string("SYS:MGR~ACT:MAGX");
  simpleCMDs["magy"]=std::string("SYS:MGR~ACT:MAGY");
  simpleCMDs["magz"]=std::string("SYS:MGR~ACT:MAGZ");

  simpleCMDs["motorx"]=std::string("SYS:MGR~ACT:MOTORX~SETPOINT:2767~MODE:PWM~DURATION:10000");  //SPEED  SIMPLE  ROTATION RAMP  PWM
  simpleCMDs["motory"]=std::string("SYS:MGR~ACT:MOTORY~SETPOINT:2767~MODE:PWM~DURATION:10000");
  simpleCMDs["motorz"]=std::string("SYS:MGR~ACT:MOTORZ~SETPOINT:2767~MODE:PWM~DURATION:10000");
  
  simpleCMDs["magdx"]=std::string("SYS:MGR~ACT:MAGDX");
  simpleCMDs["magdy"]=std::string("SYS:MGR~ACT:MAGDY");
  simpleCMDs["magdz"]=std::string("SYS:MGR~ACT:MAGDZ");

  simpleCMDs["adcson"]=std::string("SYS:MGR~ACT:ADCSON");
  simpleCMDs["adcsoff"]=std::string("SYS:MGR~ACT:ADCSOFF");
  simpleCMDs["pinson"]=std::string("SYS:MGR~ACT:PINSON");
  simpleCMDs["pinsoff"]=std::string("SYS:MGR~ACT:PINSOFF");
  simpleCMDs["phoneon"]=std::string("SYS:MGR~ACT:PHONEON");
  simpleCMDs["phoneoff"]=std::string("SYS:MGR~ACT:PHONEOFF");
  simpleCMDs["burn"]=std::string("SYS:MGR~ACT:BURN");
  
  simpleCMDs["imuspi"]=std::string("SYS:IMUSPI~ACT:START");  
  simpleCMDs["imui2c"]=std::string("SYS:IMUI2C~ACT:START");
  
  simpleCMDs["imui2ct"]=std::string("SYS:MGR~ACT:IMUI2C");
  simpleCMDs["imuspit"]=std::string("SYS:MGR~ACT:IMUSPI");
  
  simpleCMDs["i2c0"]=std::string("SYS:MGR~ACT:I2C0");
  simpleCMDs["i2c1"]=std::string("SYS:MGR~ACT:I2C1");
  simpleCMDs["i2c2"]=std::string("SYS:MGR~ACT:I2C2");

  simpleCMDs["irx1"]=std::string("SYS:MGR~ACT:IRX1");
  simpleCMDs["irx2"]=std::string("SYS:MGR~ACT:IRX2");
  simpleCMDs["iry1"]=std::string("SYS:MGR~ACT:IRY1");
  simpleCMDs["iry2"]=std::string("SYS:MGR~ACT:IRY2");
  simpleCMDs["irz1"]=std::string("SYS:MGR~ACT:IRZ1");
  simpleCMDs["irz2"]=std::string("SYS:MGR~ACT:IRZ2");

  simpleCMDs["tempx1"]=std::string("SYS:MGR~ACT:TEMPX1");
  simpleCMDs["tempy1"]=std::string("SYS:MGR~ACT:TEMPY1");
  simpleCMDs["tempz1"]=std::string("SYS:MGR~ACT:TEMPZ1");

  simpleCMDs["tempx2"]=std::string("SYS:MGR~ACT:TEMPX2");
  simpleCMDs["tempy2"]=std::string("SYS:MGR~ACT:TEMPY2");
  simpleCMDs["tempz2"]=std::string("SYS:MGR~ACT:TEMPZ2");

  simpleCMDs["tempobc"]=std::string("SYS:MGR~ACT:TEMPOBC");
  simpleCMDs["switchradios"]=std::string("SYS:SAT~ACT:UPDATERADIOS~TRANSMITTER:RADIO");
  simpleCMDs["switchradios2"]=std::string("SYS:SAT~ACT:UPDATERADIOS~TRANSMITTER:RADIO2");
  simpleCMDs["sleepradios"]=std::string("SYS:SAT~ACT:UPDATERADIOS~SLEEP:RADIO");
  simpleCMDs["sleepradios2"]=std::string("SYS:SAT~ACT:UPDATERADIOS~SLEEP:RADIO2");
  
 
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
      radio.Name("RADIO2");
      
      radio.setup();
      radio.setTransmitter(true);
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

std::string d,d1,d2,d3,d4;

void processIR(CMsg &m){  
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

  if(m.getOFFSET()=="4"){
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

void processMSG(){  
  if(MSG->ReceivedList.size()){

    CMsg m=MSG->ReceivedList.front();
    int pin=m.getParameter("SYS",4);
    std::string  act=m.getACT();    
    MSG->ReceivedList.pop_front();
    if(m.getTABLE()=="IR") processIR(m);
    
 
     if(act=="ON") {                //SYS:13~PIN:ON
      pinMode(pin, OUTPUT);
      digitalWrite(pin,HIGH);
      writeconsole(pin);    
      writeconsoleln("  HIGH");    
     }
     if(act=="OFF") {               //SYS:13~PIN:OFF
      //pinMode(pin, OUTPUT);
      digitalWrite(pin,LOW);
      writeconsole(pin);    
      writeconsoleln("  LOW");    
     }

     if(act=="BLINK") {               //SYS:13~PIN:OFF
      //pinMode(pin, OUTPUT);
      for(auto count=0; count<20;count++){
        digitalWrite(pin,HIGH);
        delay(200);
        digitalWrite(pin,LOW);
        delay(200);
        writeconsole(pin);    
        writeconsoleln("  BLINK");    
      }
     }
               
  }
}

void loop(){
  if(millis()>t+5000){
    t=millis();
 //   writeconsoleln();writeconsole("Loop "); writeconsoleln((long)ESP.getFreeHeap());writeconsoleln(" -------------------------------------------   ");
  }
    
    
  kbloop();
  radio.loop();   
  processMSG();
  //dataloop();
  

}
