#define fo(xx) for(int i=0;i<=(xx);i++)
void setup() {
//D3腳位連接到蜂鳴器 如果讓他輸出會一直叫
  fo(15){
    if(i!=3)pinMode(i, OUTPUT);
  }
}
void loop() {
  fo(15){
    digitalWrite(i, ((i&0x1)?LOW:HIGH));
  }
  delay(1000);
  fo(13){
    digitalWrite(i, ((i&0x1)?HIGH:LOW));
  }
  delay(1000);
  fo(13){
    digitalWrite(i, HIGH);
  }
  for(int i = 13; i >= 0; i--){
    digitalWrite(i, LOW);
    delay(600);
    digitalWrite(i, HIGH);
  }
}
