void setup() {
  Serial.begin(9600);
}
char ch;
int number;
void loop(){
  if (Serial.available()){
    ch = Serial.read();
    if(ch>'9'||ch<'0')return;
    number = ch - '0';
    Serial.print(number);
    Serial.print(" ");
    for (int i = 0; i < number; i++)
      Serial.print("*");
    Serial.println(); // 換行
  }
}
