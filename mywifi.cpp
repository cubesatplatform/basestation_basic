#include "mywifi.h"

WiFiClientSecure clientSecure;
WiFiClient client;
WiFiMulti wifiMulti;

void connectWifi() {
  
  wifiMulti.addAP("Truffle1", "Alexander1");
  wifiMulti.addAP("Cabana", "alexander");
  long count=0;
  while ((wifiMulti.run() != WL_CONNECTED)&&(count<10)) {
    delay(delayWaitingForWifiConnection);
    writeconsole(".");
    count++;
  }
  writeconsoleln("");
  writeconsole("WiFi connected to ");
  writeconsole(WiFi.SSID());
  writeconsole(" with IP ");
  writeconsoleln(String(WiFi.localIP()));
}

void sendRequestGet(const char *page,const char *server,int port){
  std::string spage=page;
  if (spage.size()<1)spage="/";
   Serial.println("\nStarting connection to server...");
  // if you get a connection, report back via serial:
  if (client.connect(server, port)) {
    Serial.println("connected to server");
    // Make a HTTP request:
  //  client.println("GET /search?q=arduino HTTP/1.1");
   // client.println("GET /dev/test/update35.bin HTTP/1.1");
    std::string path="GET ";
    path+=spage;
    path+= " HTTP/1.1";
    std::string host="Host: ";
    host+=server;
   Serial.println(path.c_str());
    //client.println("GET  HTTP/1.1");
    client.println(path.c_str());
    client.println(host.c_str());     //Need this   So it knows where to route to
    client.println("Connection: close");
    client.println();
  }
}  

CMsg receiveFile() {
  Serial.println("CMsg receiveFile()");
  CMsg m;
  int maxloops = 0;
  unsigned char buffer[500];

  //wait for the server's reply to become available
  while (!client.available() && maxloops < 1500)
  {
    maxloops++;
    delay(1); //delay 1 msec
  }  
  // if there are incoming bytes available
  // from the server, read them and print them:

  if(client.available()){
    while (client.available()) {  //Clears out headers
      String line = client.readStringUntil('\r');
      //Serial.print(line);      Serial.print("   =>");      Serial.print(line.length());
      if (line.length()<=1)
        break;  
    }

    int count=0;
    while (client.available()&&(count<250)) {
      //Serial.println("Got something........................");
  
      char c = client.read();      
      Serial.write(c);
      buffer[count]=c;
      count++;
    }

    if(count>20){
      buffer[count]=NULL;
      buffer[19]=NULL;
      std::string filename=(char *)buffer;
      Serial.print(filename.c_str());
      Serial.println((char *)buffer+21);   //Should be 20  error
      m.setParameter("FILENAME",filename);
      m.initArray(buffer+21, count-21);
    }

    client.stop();
  }

  delay(100);
  return m;
 
}
