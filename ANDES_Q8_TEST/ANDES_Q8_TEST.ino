int count = 0;
void setup(){
  Serial.begin(9600);
  pinMode(BT1, INPUT_PULLUP);
  attachInterrupt(BT1, disp_count, FALLING);
}

void loop(){
  // Nothing...
}

// INT0 中斷服務程式
void disp_count(){
  noInterrupts();
  delay(50);  // 防彈跳處理
  if (digitalRead(BT1) == LOW) { // 確認按鈕仍然被按著
    while (digitalRead(BT1) == LOW); // 等待按鈕放開
    delay(50);  // 再次防彈跳
    Serial.print("you have pressed ");
    Serial.print(count++);
    Serial.println(" times");
  }
  interrupts();
}
