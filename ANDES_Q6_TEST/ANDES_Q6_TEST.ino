int speak_pin = D3;
char notes[] = "ccggaagffeeddc ";// 依照簡譜的順序，填入代表的音符，空白代表休止符
unsigned long beats[] = {1,1,1,1,1,1,2,1,1,1,1,1,1,2,4};// 決定每個音階的拍子
int length = sizeof(notes);
int tempo = 300;//一拍 300 ms

void setup() {
  pinMode(speak_pin, OUTPUT);
}

void loop() {
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo);
    }
    else {
      playNote(speak_pin,notes[i], beats[i] * tempo);
      // 呼叫 palyNote() 這個 function，將音符轉換成訊號讓蜂鳴器發聲
    }
    delay(tempo/10); // 每個音符之間的間隔，這邊設定的長短會有連音 or 段音的效果
  }
}

void playNote(int OutputPin, char note, unsigned long duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' }; // 音符字元與對應的頻率由兩個矩陣表示
  int tones[] = { 261, 294, 330, 349, 392, 440, 494, 523 }; // 播放音符對應的頻率
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      tone(OutputPin,tones[i], duration);
      delay(duration);
      noTone(OutputPin);
    }
  }
}
