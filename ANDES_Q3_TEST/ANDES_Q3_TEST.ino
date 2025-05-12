#include <LiquidCrystal.h>
#define rs_pin D8
#define enable_pin D9
//有範例程式可以看
LiquidCrystal lcd(rs_pin, enable_pin, 4, 5, 6, 7);
void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 1);
  lcd.print("Andes Hello!");
}

void loop() {
  // Nothing...
}
