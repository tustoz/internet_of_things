#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>
char auth[] = "";

char ssid[] = "";
char pass[] = "";

#define MQ2Pin D5
int MQ2Value;

void setup()
{
  Serial.begin(115200);
  delay(10);
  Blynk.begin(auth, ssid, pass);
  pinMode(MQ2Pin, INPUT);
}

void loop()
{
  getMQ2Value();
  Blynk.run();
}

void getMQ2Value(void)
{
  MQ2Value = digitalRead(MQ2Pin);
  if (!MQ2Value)
  {
    Serial.println("==>Gas terdeteksi");
    Blynk.notify("Kebocoran Gas terdeteksi.....!");
    delay(10000);
  }

}
