#define BLYNK_PRINT Serial 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>

SimpleTimer timer;
int adc0;
int outputpin= A0;
float celcius,millivolts;

char auth[] = "";

char ssid[] = "";
char pass[] = "";

void setup()
{
  Serial.begin(115200); 
  delay(10);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000, sendData);
}

void sendData()
{   
  adc0 = analogRead(outputpin);
  millivolts = (adc0/1024.0) * 3300; 
  celcius = millivolts/10;
  Serial.println(celcius);
  Blynk.virtualWrite(0, celcius);
}

void loop()
{
  Blynk.run();
  timer.run();
}
