#define data_pin  D2 //串列資料輸入腳位
#define clk_pin   D14 //資料位移腳位
#define latch_pin D15 //栓鎖器控制腳位
const byte BUTTONS[] = {BT1, BT2, BT3, BT4, A0};
// [hgfe][dcba] 的順序 Ex. [0011][1111]=[3][f] 表示零
const byte SEGMENT_MAP[]   = {0x4F,0x4F,0x6D,0x7d,0x7f,0x00};
// 位元遮罩 Ex. [1111][1110]=[f][e] 選到第 1 位
const byte SEGMENT_SELECT[] = {0xFE, 0xFD, 0xFB, 0xF7};

void setup() {
  pinMode(data_pin, OUTPUT);
  pinMode(clk_pin, OUTPUT);
  pinMode(latch_pin, OUTPUT);
  for(int i=0;i<5;i++)pinMode(BUTTONS[i], INPUT);
}

void loop() {
  if (!digitalRead(BUTTONS[0])) WriteSegment(3, 0);//[0100][1111]=[4][f]=3(BCD)
  if (!digitalRead(BUTTONS[1])) WriteSegment(2, 1);//[0100][1111]=[4][f]=3
  if (!digitalRead(BUTTONS[2])) WriteSegment(1, 2);//[0110][1101]=[6][d]=5
  if (!digitalRead(BUTTONS[3])) WriteSegment(0, 3);//[0111][1101]=[7][d]=6
  if (!digitalRead(BUTTONS[4])) {
    for (int i = 3; i >= 0; i--) {
      WriteSegment(i, 4);//[0111][1111]=[7][f]=8
      delay(600);
    }
  }
  for(int i=0;i<4;i++)WriteSegment(i, 5);//[0000][0000]=[0][0] 預設顯示
}

void WriteSegment(byte segment, byte value) {
  // enable
  digitalWrite(latch_pin, LOW);
  // what?
  shiftOut(data_pin, clk_pin, MSBFIRST, SEGMENT_MAP[value]);
  // where?
  shiftOut(data_pin, clk_pin, MSBFIRST, SEGMENT_SELECT[segment]);
  // disable
  digitalWrite(latch_pin, HIGH);
}
