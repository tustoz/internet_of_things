#define BLYNK_MAX_SENDBYTES 1200
#include <ESP8266WiFi.h>

#define BLYNK_PRINT Serial    
#include <BlynkSimpleEsp8266.h>
char auth[] = "";

char ssid[] = "";
char pass[] = "";


#define tombol D2 
int tbValue; 

void setup()
{
  Serial.begin(115200);
  delay(10);
  Blynk.begin(auth, ssid, pass);
  pinMode(tombol, INPUT);    
}

void loop()
{
  cek_tombol();
  Blynk.run();
}

void cek_tombol(void)
{
  tbValue = digitalRead(tombol);
  if (tbValue) 
  { 
    Serial.println("Tombol ON");   
    Blynk.email("", "", "");
    delay(1000);
  }  
}
