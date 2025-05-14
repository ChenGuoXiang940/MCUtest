#include "stdio.h"
#include <windows.h>
#define delay(xx) Sleep(xx)
#define fo(xx) for(int i=0;i<=xx;i++)
#define LOW 0
#define HIGH 1
#define OUTPUT 1
#define INPUT 0
#define digitalWrite(xx,yy) printf("LED %d is %s\n",xx,(yy==HIGH)?"ON":"OFF")
#define pinMode(xx,yy) printf("LED %d is set to %s\n",xx,(yy==OUTPUT)?"OUTPUT":"INPUT")
int LED[14]={0,1,2,3,4,5,6,7,8,9,10,11,12,13};
int State[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
void setup();
void loop();
void main(){
    printf("LED test\n");
    setup();
    while(1)loop();
}
void setup(){
    fo(13){
        if(i!=3)pinMode(LED[i],OUTPUT);
    }
}
void loop(){
    fo(13){
        digitalWrite(i,((i&0x1)?LOW:HIGH));
    }
    delay(1000);
    fo(13){
        digitalWrite(i,(!(i&0x1)?LOW:HIGH));
    }
    delay(1000);
    for(int i = 13; i >= 0; i--){
        digitalWrite(i, LOW);
        delay(600);
        digitalWrite(i, HIGH);
    }
}