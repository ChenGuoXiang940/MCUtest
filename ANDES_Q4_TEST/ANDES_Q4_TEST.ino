#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
char KeyValue[]={'1','2','3','A','4','5','6','B','7','8','9','C','*','0','#','D'};
byte rows[] = {10, 11, 12, 13};
byte cols[] = {A0, A1, A2, A3};
byte keyindex=0;
void setup() {
  for(int i=0;i<4;i++)  pinMode(rows[i], INPUT);
  for(int i=0;i<4;i++){
    pinMode(cols[i], OUTPUT);
    digitalWrite(cols[i],HIGH);
  }
  lcd.begin(16, 2);
}

void loop() {
   if (keyscan())
   {
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print(KeyValue[keyindex]);
     while (!digitalRead(10)||!digitalRead(11)||
             !digitalRead(12)||!digitalRead(13));
   }
}
bool keyscan() {
  for (int c = 0; c < 4; c++) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(cols[i],(i==c?LOW:HIGH));
    }
    for (int r = 0; r < 4; r++) {
      if (!digitalRead(rows[r])) {
        keyindex = r * 4 + c;
        return true;
      }
    }
  }
  return false;
}
