#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX
#include <Servo.h>

// 定义舵机对象--左右转动
Servo myservo; 
Servo myservo1;

// 定义舵机对象--上下转动
Servo myservo2;
Servo myservo3;

int pos = 0; // 定义舵机转动位置--左右   
int pos1 = 0; // 定义舵机转动位置--上下

int a;                     //接收串口的值

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

  // 设置舵机控制针脚--左右，默认90度
  myservo.attach(7);
  myservo.write(90); 
  myservo1.attach(8); 
  myservo1.write(90);

  // 设置舵机控制针脚--上下，默认160度 
  myservo2.attach(9); 
  myservo2.write(160); 
  myservo3.attach(10); 
  myservo3.write(160); 
}

void loop() {
   if(mySerial.available()){
   a=mySerial.read();      //读取串行端口的值

   //收到语音口令---1
   if(a=='1'){
      //左右转动，两个循环

      //90--180
      for(pos = 90; pos < 180; pos += 1) { 
            myservo.write(pos); 
            myservo1.write(pos);
            delay(15);
           }
      //180--1
      for(pos = 180; pos >= 1; pos -= 1)  { 
            myservo.write(pos);
            myservo1.write(pos);
            delay(15);
           }
      //1--180  
      for(pos = 0; pos < 180; pos += 1)  { 
            myservo.write(pos); 
            myservo1.write(pos);
            delay(15);
           }
      //180--1
      for(pos = 180; pos >= 1; pos -= 1)  { 
            myservo.write(pos);
            myservo1.write(pos);
            delay(15); 
           }
      //1--90
      for(pos = 0; pos < 90; pos += 1) { 
            myservo.write(pos); 
            myservo1.write(pos);
            delay(15);
           }
           
      //延时1S 
      delay(1000);

      //上下转动2次

      //160--50
      for(pos1 = 160; pos1 >= 50; pos1 -= 1){ 
            myservo2.write(pos1);
            myservo3.write(pos1);
            delay(15); 
           }

      //50--160
      for(pos1 = 50; pos1 < 160; pos1 += 1) { 
            myservo2.write(pos1);
            myservo3.write(pos1);
            delay(15);
           }

      //160--50
      for(pos1 = 160; pos1 >= 50; pos1 -= 1) { 
            myservo2.write(pos1);
            myservo3.write(pos1);
            delay(15);  
           }

      //50--160
      for(pos1 = 50; pos1 < 160; pos1 += 1) { 
            myservo2.write(pos1);
            myservo3.write(pos1);
            delay(15);
           }
      }
    }
  }
