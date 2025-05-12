#include <LiquidCrystal.h>
#include <RTC.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
const byte day = 25;
const byte hours = 12;
const byte minutes = 0;
const byte seconds = 0;
void setup() {
  lcd.begin(16, 2);
  RTC.settime(day, hours, minutes, seconds);
  RTC.startcounting();
}
void loop() {
  lcd.clear();
  lcd.print("2020/12/");
  lcd.print(RTC.getday());
  lcd.print(",");
  lcd.setCursor(0, 1);
  lcd.print(RTC.gethours());
  lcd.print(":");
  lcd.print(RTC.getminutes());
  lcd.print(":");
  lcd.print(RTC.getseconds());
  delay(1000);
}
