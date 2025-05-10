#include <LiquidCrystal.h>
/*
  有範例程式可以看
  lcd(RS pin,Enable pin,D4,D5,D6,D7)
*/
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 1);
  lcd.print("Andes Hello!");
}

void loop() {
  // Nothing...
}
