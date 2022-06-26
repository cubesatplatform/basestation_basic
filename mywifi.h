#pragma once

#include <consoleio.h>
#include <WiFi.h> 
#include <WiFiClientSecure.h>
#include <WiFiClient.h>
#include <WiFiMulti.h>
#include <ArduinoJson.h>
#include "encode.h"



//ConsoleEcho SerialB;

// The code calls the path on the host below and 
// expects a response with one line containing an integer
// between 0 and maxMetric.


#define awshost  "9nxvzfnhrd.execute-api.us-east-1.amazonaws.com"
#define cmdpath  "/v1/commands?latest=sent&value=false"
#define updatecmdpath  "/v1/commands?sent=true&cid="
#define updateackpath  "/v1/commands?ack=true&cid="
#define logpath  "/v1/satlog?bid=1&rssi=0&data="
#define consolelogpath  "/v1/errorlog?bid=1&data="

//#define  server  "192.168.86.34"
//#define  port  80


#define httpsPort  443
#define serialBaudRate  115200
#define delayWaitingForWifiConnection  500



void connectWifi();


void sendRequestGet(const char *page="/dev/test/update35.bin",const char *server="maze-key.com",int port=80);
CMsg receiveFile();
void printLine();
