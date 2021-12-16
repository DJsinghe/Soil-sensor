#include <LiquidCrystal.h>
#include <math.h>

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);

}

void setup() 
{
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(5,OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Counting the cm");
}

void loop() 
{
  lcd.setCursor(0, 1);
  int cm;
  cm = 0.01723 * readUltrasonicDistance(7, 6);
    if (cm < 30) {
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(5,HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(5,LOW);
}
  lcd.print(round(cm));
  delay(100);

}
