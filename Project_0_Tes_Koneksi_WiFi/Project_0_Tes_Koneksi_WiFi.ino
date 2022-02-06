#include <ESP8266WiFi.h> 
const char* ssid = "";
const char* password = "";
WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(2000); 
  // Connect to WiFi network
  Serial.print("Connecting to ");
  Serial.println(ssid); 
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");  
}