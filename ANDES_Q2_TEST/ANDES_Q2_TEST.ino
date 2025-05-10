#define LATCH_DIO D15 //栓鎖器控制腳位
#define CLK_DIO   D14 //資料位移腳位
#define DATA_DIO  2 //Serial Data In
#define BUTTON_COUNT 5

const byte BUTTONS[BUTTON_COUNT] = {BT1, BT2, BT3, BT4, A0};
// [hgfe][dcba] 的順序 Ex. [0011][1111]=[3][f] 表示零
const byte SEGMENT_MAP[]   = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x00};
// 位元遮罩 Ex. [1111][1110]=[f][e] 選到第 1 位
const byte SEGMENT_SELECT[] = {0xFE, 0xFD, 0xFB, 0xF7};

void setup() {
  pinMode(LATCH_DIO, OUTPUT);
  pinMode(CLK_DIO, OUTPUT);
  pinMode(DATA_DIO, OUTPUT);
  for (int i = 0; i < BUTTON_COUNT; i++)pinMode(BUTTONS[i], INPUT);
}

void loop() {
  if (!digitalRead(BUTTONS[0])) WriteSegment(3, 3);//[0100][1111]=[4][f]
  if (!digitalRead(BUTTONS[1])) WriteSegment(2, 3);//[0100][1111]=[4][f]
  if (!digitalRead(BUTTONS[2])) WriteSegment(1, 5);//[0110][1101]=[6][d]
  if (!digitalRead(BUTTONS[3])) WriteSegment(0, 6);//[0111][1101]=[7][d]
  
  if (!digitalRead(BUTTONS[4])) {
    for (int i = 3; i >= 0; i--) {
      WriteSegment(i, 8);
      delay(600);
    }
  }
  WriteSegment(0, 14);//預設顯示
}

void WriteSegment(byte segment, byte value) {
  // enable
  digitalWrite(LATCH_DIO, LOW);
  // what?
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[value]);
  // where?
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[segment]);
  digitalWrite(LATCH_DIO, HIGH);
}
