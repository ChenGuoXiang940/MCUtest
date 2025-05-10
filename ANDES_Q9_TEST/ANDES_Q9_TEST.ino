const int led_pin = 13;

void flash() { // 中斷函數 替代方案
  static boolean flag = 1;
  digitalWrite(led_pin, flag);
  flag = !flag;
}

void setup() {
  pinMode(led_pin, OUTPUT);
}
void loop() {
  flash();
  delay(5000);
}
