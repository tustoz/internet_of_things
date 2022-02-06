int buzzer = D1;
int pirMotion = D5;
int led = 11;
int pirState = LOW;
int ledState = LOW;

void setup() {
  pinMode(pirMotion, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  if (digitalRead(pirMotion) == HIGH)
  {
  digitalWrite(led, HIGH);   
  delay(3000);                      
  digitalWrite(led, LOW);   
  delay(3000);                       
  tone(buzzer,1000);
  delay(3000);
  noTone(buzzer);
  delay(3000);
  }
}
