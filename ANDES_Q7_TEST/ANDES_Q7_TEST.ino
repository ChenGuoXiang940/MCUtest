void setup() {
  Serial.begin(9600);
}
void loop(){
  char ch;
  int number;
  if (Serial.available()){
    ch = Serial.read();
    if (ch >= '1' && ch <= '9'){
      number = ch - '0';
      Serial.print(number);
      Serial.print(" ");
      for (int i = 0; i < number; i++)
        Serial.print("*");
      Serial.println(); // 分行
    }
  }
}
