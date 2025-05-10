#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
char KeyValue[]={'1','2','3','A','4','5','6','B','7','8','9','C','*','0','#','D'};
byte rows[] = {10, 11, 12, 13};
byte cols[] = {A0, A1, A2, A3};
byte keyindex_cur=0;
void setup() {
  for(int i=0;i<4;i++)  pinMode(rows[i], INPUT_PULLUP);
  for(int i=0;i<4;i++){
    pinMode(cols[i], OUTPUT);
    digitalWrite(cols[i],HIGH);
  }
  lcd.begin(16, 2);
}

void loop() {
 byte keyindex=0;
 if(keyscan())
 {
   keyindex=keyindex_cur;
   delay(5);
   if (keyscan() && (keyindex==keyindex_cur))
   {
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print(KeyValue[keyindex]);
     for(int i=0;i<4;i++)digitalWrite(cols[i],LOW);
     delayMicroseconds(100);
     while ((digitalRead(10) == LOW) || (digitalRead(11) == LOW) ||
             (digitalRead(12) == LOW) || (digitalRead(13) == LOW));
   }
 }
}
bool keyscan() {
  for (int c = 0; c < 4; c++) {
    // 將當前行設為 LOW，其餘為 HIGH
    for (int i = 0; i < 4; i++) {
      digitalWrite(cols[i], HIGH);
    }
    digitalWrite(cols[c], LOW);
    delayMicroseconds(50); // 稍作延遲以穩定訊號

    // 掃描所有列，看是否有按下
    for (int r = 0; r < 4; r++) {
      if (digitalRead(rows[r]) == LOW) {
        keyindex_cur = r * 4 + c;
        return true;
      }
    }
  }
  return false;
}
