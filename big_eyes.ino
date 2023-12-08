#include <Servo.h>
// Bang Hu Part
volatile int item;
Servo servo_13;
Servo servo_12;
Servo servo_11;
Servo servo_10;
Servo servo_9;
Servo servo_8;
Servo servo_7;
volatile int a;

// Yuyan Zhang Part
float checkdistance_A4_A5() {
  digitalWrite(A4, LOW);
  delayMicroseconds(2);
  digitalWrite(A4, HIGH);
  delayMicroseconds(10);
  digitalWrite(A4, LOW);
  float distance = pulseIn(A5, HIGH) / 58.00;
  delay(10);
  return distance;
}

//Bang Hu Part
void setup(){
  item = 0;
  servo_13.attach(13);
  servo_12.attach(12);
  servo_11.attach(11);
  servo_10.attach(10);
  servo_9.attach(9);
  servo_8.attach(8);
  servo_7.attach(7);
  servo_13.write(90);
  delay(0);
  servo_12.write(90);
  delay(0);
  servo_11.write(90);
  delay(0);
  servo_10.write(150);
  delay(0);
  servo_9.write(90);
  delay(0);
  servo_8.write(90);
  delay(0);
  servo_7.write(90);
  delay(0);
  Serial.begin(9600);
  pinMode(A4, OUTPUT);
  pinMode(A5, INPUT);
  a = 0;
}

// Mingquan Yang Part
void loop(){
  if (Serial.available() > 0) {
    item = String(Serial.read()).toInt();
    Serial.println(item);
    
    // Bang Hu Part
    if (item == 1) {
      for (int i = 1; i <= 3; i = i + (1)) {
        for (int i = 90; i >= 35; i = i + (-1)) {
          servo_9.write(i);
          delay(10);
          servo_8.write(i);
          delay(10);
        }
        for (int i = 35; i <= 145; i = i + (1)) {
          servo_9.write(i);
          delay(10);
          servo_8.write(i);
          delay(10);
        }
        for (int i = 90; i <= 150; i = i + (1)) {
        servo_11.write(i);
        delay(15);
        }
          for (int i = 90; i <= 150; i = i + (1)) {
        servo_10.write(i);
        delay(15);
      }
      
  //Mingquan Yang Part
        for (int i = 145; i >= 90; i = i + (-1)) {
          servo_9.write(i);
          delay(10);
          servo_8.write(i);
          delay(10);
        }
 
      for (int i = 150; i >= 90; i = i + (-1)) {
        servo_11.write(i);
        delay(15);
        servo_10.write(i);
        delay(15);
      }
    

    }

  }

//Yuyan Zhang Part
  if (checkdistance_A4_A5() < 50) {
    for (int i = 90; i <= 150; i = i + (1)) {
      servo_11.write(i);
      delay(15);
    }
    for (int i = 150; i >= 90; i = i + (-1)) {
      servo_11.write(i);
      delay(15);
      servo_10.write(i);
      delay(15);
    }
    for (int i = 90; i <= 150; i = i + (1)) {
      servo_10.write(i);
      delay(15);
    }

 
  Serial.println(checkdistance_A4_A5());

}
  }
}
