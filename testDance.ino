#include <Servo.h>
#include <Oscillator.h>
#include <EEPROM.h>
#include "MoveFunction.h"

int count=1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9200);
  pinMode(A0, INPUT); // 定义超声波输入脚
  pinMode(A1, OUTPUT); // 定义超声波输出脚 
  
  getOldPosition(90,90,90,90);
  
}
void loop() {
  delay(2);
  getOldPosition(90,90,90,90);
//put your main code here, to run repeatedly:
  digitalWrite(A1,LOW);
  delayMicroseconds(2);
  digitalWrite(A1,HIGH);
  delayMicroseconds(20);
  digitalWrite(A1,LOW);
  float S=pulseIn(A0,HIGH);
  S=S/58.00;
  if(S<10) count++;
  if(count==9) count=1;
  switch(count){
    case 1:drunk(1000);break;
    case 2:backyard(2,1000);break;
    case 3:run(2,1000);break;
    case 4:moonWalkLeft(2,1000);break;
    case 5:swing(2,1000);break;
    case 6:goingUp(700);break;
    case 7:noGravity(800);break;
    case 8:kickLeft(900);break;
    case 9:primera_parte();break;
    
  }
}


