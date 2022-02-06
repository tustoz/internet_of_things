#include <DHT.h>
#include <ESP8266WiFi.h>
#include <SimpleTimer.h>
#include <BlynkSimpleEsp8266.h>

#define DHTPIN D5 
#define DHTTYPE DHT11
#define BLYNK_PRINT Serial 

DHT dht(DHTPIN, DHTTYPE);

SimpleTimer timer;
float humi, temp; 

char auth[] = ""; 

char ssid[] = "";
char pass[] = "";
char outstr[15];

WidgetLCD lcd(V0); 

void setup()
{
  Serial.begin(115200); 
  delay(10);
  Blynk.begin(auth, ssid, pass);
  lcd.clear();
  lcd.print(0, 0, "Monitoring DHT11");
  lcd.print(0, 1, "Inkubatek Jogja"); 
  delay(2000); 
  lcd.clear();
  lcd.print(0, 0, "Temp=      C");
  lcd.print(0, 1, "Humi=      %RH"); 
  timer.setInterval(1000, sendData);
}


void sendData()
{  
  humi = dht.readHumidity();
  temp = dht.readTemperature();
  if (isnan(humi) || isnan(temp)) {
    Serial.println("DHT11 tidak terbaca... !");
    return;
  }
  else{
  Serial.println(temp);
  Serial.println(humi);
  Blynk.virtualWrite(1, temp);
  Blynk.virtualWrite(2, humi);
  dtostrf(temp,4, 2, outstr); 
  lcd.print(5, 0, outstr);  
  dtostrf(humi,4, 2, outstr); 
  lcd.print(5, 1, outstr);   
  }
}

void loop()
{
  Blynk.run();
  timer.run();
}
