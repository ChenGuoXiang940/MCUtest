#include <FlexiTimer2.h>
 //************* Timer1*** 計時中斷控制實習****************************
//*動作：致能計時中斷，控制LED閃爍時間
//*******************************************************************

const int led_pin = 13;  // LED接至13腳
bool flag = 1; // 位元旗標預設為1，來記錄目前 LED 的狀態

void flash() { // 計時中斷函數
  digitalWrite(led_pin, flag); // LED輸出
  flag = !flag; // 位元旗標反相
}

void setup() {
  pinMode(led_pin, OUTPUT);
  FlexiTimer2::set(5000, flash); // 設定每5000mS產生中斷，進入中斷函數(flash)
  FlexiTimer2::start(); // 啟動開始計時
}

void loop() { // 主程式無作用，或執行其它程式
}
