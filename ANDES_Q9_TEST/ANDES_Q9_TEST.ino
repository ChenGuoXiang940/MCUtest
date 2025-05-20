#include <FlexiTimer2.h>
int led_pin = 13;

void flash() {
  static bool flag = 1;
  digitalWrite(led_pin, flag?LOW:HIGH);
  flag = !flag;
}

void setup() {
  pinMode(led_pin, OUTPUT);
  FlexiTimer2::set(5000, flash);
  FlexiTimer2::start();
}

void loop() {
  // Nothing ...
}
