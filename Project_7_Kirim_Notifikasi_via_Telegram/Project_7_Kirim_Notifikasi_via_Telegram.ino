#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

char ssid[] = "";
char password[] = "";

#define BOT_TOKEN ""
#define CHAT_ID ""
#define tombol D2

WiFiClientSecure client;
UniversalTelegramBot (token, client);
String ipAddress = "";
volatile bool tombolFlag = false;
int button;

void setup() {
  Serial.begin(115200);
  pinMode(tombol, INPUT);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);
  ipAddress = ip.toString();
}

void sendTelegramMessage() {
  Serial.println("Kirim pesan ke Telegram");
  String message = "Tombol ditekan ....";
  message.concat("\n");
  if (bot.sendMessage(CHAT_ID, message, "Markdown")) {
    Serial.println("Pesan telah dikirim ke TELEGRAM");
  }
  else Serial.println("gagal kirim..");
  tombolFlag = false;

}

void loop() {
  button = digitalRead(tombol);
  if (button == HIGH) {
    Serial.println("Tombol ditekan");
    while (button = digitalRead(tombol));
    sendTelegramMessage();
    delay(500);
  }
}
