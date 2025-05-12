int led_pin = 13;
void setup() {
  pinMode(led_pin, OUTPUT);
}
void loop() {
  flash();
  delay(5000);
}
// 中斷函數 替代方案
void flash() {
  static boolean flag = 1;
  digitalWrite(led_pin, flag);
  flag = !flag;
}
