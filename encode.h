#pragma once
#include <ArduinoJson.h>
 
unsigned char h2int(char c);
String urldecode(String str);
String urlencode(String str);
std::string convertStringToCommand(std::string str);
