#include "stdio.h"
#define rs_pin 8
#define enable_pin 9
#define OUTPUT 1
#define INPUT 0
#define pinMode(xx,yy) printf("LED %d is set to %s\n",xx,(yy==OUTPUT)?"OUTPUT":"INPUT")
void setup();
void loop();
typedef struct {} LiquidCrystal;
void LiquidCrystal_init(LiquidCrystal* lcd,int rs, int enable, int d4, int d5, int d6, int d7){
    pinMode(rs, OUTPUT);
    pinMode(enable, OUTPUT);
    pinMode(d4, OUTPUT);
    pinMode(d5, OUTPUT);
    pinMode(d6, OUTPUT);
    pinMode(d7, OUTPUT);
}
void begin(int cols, int rows){
    printf("LCD begin with %d cols and %d rows\n",cols,rows);
}
void serCursor(int x,int y){
    printf("Set cursor to (%d,%d)\n",x,y);
}
void print(char* str){
    printf("Print: %s\n",str);
}
void main(){
    setup();
    while(1)loop();
}
void setup(){
    LiquidCrystal lcd;
    LiquidCrystal_init(&lcd,rs_pin, enable_pin,4,5,6,7);
    begin(16,2);
    serCursor(0,1);
    print("Andes Hello!");
}
void loop(){
    // Nothing ...
}

