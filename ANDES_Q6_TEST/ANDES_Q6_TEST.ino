int speak_pin = D3;
char notes[] = "ccggaagffeeddc ";// 依照簡譜的順序，填入代表的音符，空白代表休止符
unsigned long beats[] = {1,1,1,1,1,1,2,1,1,1,1,1,1,2,4};// 決定每個音階的拍子
char names[]= { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' }; // 音符字元與對應的頻率由兩個矩陣表示
int tones[] = { 261, 294, 330, 349, 392, 440, 494, 523 }; // 播放音符對應的頻率
int tempo = 300;
void setup() {
  pinMode(speak_pin, OUTPUT);
}

void loop() {
  for (int i = 0; i < (int)sizeof(notes); i++) {
    unsigned long duration=beats[i] * tempo;
    if (notes[i] == ' ') {
      delay(duration);
    }
    else {
      for (int j = 0; j < 8; j++) {
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
