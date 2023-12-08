#include <Servo.h>
 // Banghu Part
#define echoPin 12
#define trigPin 13

long duration;
int distance;


Servo servos[6];
const int servoPins[] = {8, 9, 10, 11, A0, A1};


Servo servo1 = servos[0];
Servo servo2 = servos[1];
Servo servo3 = servos[2];
Servo servo4 = servos[3];
Servo servo5 = servos[4];
Servo servo6 = servos[5];


void smoothMove(Servo servo, int targetAngle);

void setup() {
  // Yuyan Zhang Part
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Banghu Part
  for (int i = 0; i < 6; i++) {
    servos[i].attach(servoPins[i]);
  }

  Serial.begin(9600);
}

// Yuyan Zhang Part
void smoothMove(Servo servo, int targetAngle) {
  int currentAngle = servo.read();
  int step = (targetAngle > currentAngle) ? 1 : -1;

  while (currentAngle != targetAngle) {
    currentAngle += step;
    servo.write(currentAngle);
    delay(10); 
  }
}

void loop() {
  // Banghu Part
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Yuyan Zhang Part
  duration = pulseIn(echoPin, HIGH);

 
  float speedOfSound = 0.034; // 根据需要调整此值
  distance = duration * speedOfSound / 2;


  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Yuyan Zhang+Banghu
  if (distance < 100) {
   
    for (int i = 2; i <= 8; i++) {
      digitalWrite(i, HIGH);
    }

    smoothMove(servos[0], 45); // 舵机1旋转到30度
    smoothMove(servos[3], 45); // 舵机4旋转到45度
    smoothMove(servos[1], 45); // 舵机3旋转到30度
    smoothMove(servos[2], 45); // 舵机2旋转到45度
    smoothMove(servos[4], 30); // 舵机5旋转到90度
    smoothMove(servos[5], 30); // 舵机6旋转到20度
    delay(100);
  } else {
  
    for (int i = 2; i <= 8; i++) {
      digitalWrite(i, LOW);
    }

 
    for (int i = 0; i < 6; i++) {
      smoothMove(servos[i], 0); // 舵机复位到0度
    }
  }
}
