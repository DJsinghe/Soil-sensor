#include <LiquidCrystal.h> 

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


const int analogInPin = A5;
int plantVal = 0; 
void setup() {
pinMode(3,OUTPUT);
lcd.begin(16, 2);
delay(100);
} 

void loop() {
lcd.clear();
lcd.print("Soil Moisture:");
plantVal = analogRead(analogInPin);
lcd.setCursor(0, 1);
lcd.print(plantVal);
delay(300);

}
