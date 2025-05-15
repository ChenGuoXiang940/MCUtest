int speak_pin = D3;
char notes[] = "ddrdfm ddrdsf ";// 依照簡譜的順序，填入代表的音符，空白代表休止符
unsigned long beats[] = {1,1,2,2,2,4,1,1,1,2,2,2,4,1};// 決定每個音階的拍子
char names[]= { 'd', 'r', 'm', 'f', 's'}; // 音符字元
int tones[] = { 261, 294, 330, 349, 392}; // 音符對應的頻率
// d [261] Do 開頭音
// r [294] Re 每級上升約 +30Hz
// m [330] Mi 像 3 開頭
// f [349] Fa 比 MI 再高一點
// s [392] Sol 快到 400
// DO DO RE DO Fa MI
// DO DO RE DO So Fa
// 11 222 4 1 循環
int tempo = 300;
void setup() {
  pinMode(speak_pin, OUTPUT);
}
void loop() {
  // notes 字串實際上是 14 個字符再加上一個 \0 結束符
  for (int i = 0; i < (int)sizeof(notes)-1; i++) {
    unsigned long duration=beats[i] * tempo;
    if (notes[i] == ' ') {
      delay(duration);
    }
    else {
      for (int j = 0; j < 5; j++) {
          if (names[j] == notes[i]) {
            // enable & speaking
            tone(speak_pin,tones[j],duration);
            delay(duration);
            // disable
            noTone(speak_pin);
        }
      }
    }
    delay(tempo/10); // 每個音符之間的間隔
  }
}
