#include <defs.h>
#include <msg.h>
#include <radio.h>
#include <map>

#include <string> 
char input;
std::string str;


CRadio radio;
CMessages MSG;

CMessages* getMessages() { return &MSG; }
std::map<std::string, std::string> simpleCMDs;

int id=0;



void init(){
  radio.setACK(false);
  simpleCMDs["NORMAL"]="STATE:NORMAL";
  simpleCMDs["LOWPOWER"]="STATE:LOWPOWER";
  simpleCMDs["DEPLOY"]="STATE:DEPLOY";
  simpleCMDs["gps"]="SYS:GPS~ACT:START~MODE:";
  simpleCMDs["phonegps"]="SYS:PHONE~ACT:CGPS";
  simpleCMDs["phonetime"]="SYS:PHONE~ACT:CTIME";
  simpleCMDs["photo"]="SYS:PHONE~ACT:CPHOTO(B,50%,100,100,AUTO)";
  simpleCMDs["imu"]="SYS:IMU~ACT:START";  
  simpleCMDs["light"]="SYS:LIGHT~ACT:START";  
  simpleCMDs["irx"]="SYS:IRX1~ACT:RUN";  

  simpleCMDs["forward"]="SYS:MOTOR~ACT:SPEED~SPEED:0.2~DURATION:2000";  
  simpleCMDs["backward"]="SYS:MOTOR~ACT:SPEED~SPEED:-0.2~DURATION:2000";  
  simpleCMDs["back"]="SYS:MOTOR~ACT:SPEED~SPEED:-0.2~DURATION:2000"; 
  
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
    

void setup() {
      Serial.begin(115200); 

   //   Serial2.begin(115200,SERIAL_8N1,35,15); 
      while(!Serial);
 //     while(!Serial2);
 
      init();
 //     sendSerial("Init");
      radio.setMessages(&MSG);
      radio.setup();

}

void kbloop() {
  
  if(Serial.available()){
        input = Serial.read();
        if(input =='?'){
          displayCMDs();    
           str="";
          input=' '; 
          return;
        }
        if((input !='\n')&&(input !=' ')) str+=input;              
    }

  //while(Serial2.available())   Serial2.print(Serial2.read());

   

  if(input =='\n'){
    writeconsoleln(str.c_str());

   SendCmd(str);
   
    str="";
    input=' ';
  }
}

void SendCmd(std::string str){
    std::string cmd=simpleCMDs[str.c_str()];
    if(cmd.size()>1){
      CMsg m(cmd.c_str());
      MSG.newTransmitMessage(m);   
      sendSerial(cmd.c_str());
    }
    else{
      if(str.size()>1){
        CMsg m(str.c_str());
        MSG.newTransmitMessage(m);      
        sendSerial(str.c_str());
      }
    }    

    writeconsoleln();
  
}

long last=0;
void loop(){
  kbloop();
  radio.loop();


   
}
