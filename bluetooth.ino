#include <AFMotor.h>

char command;
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600);
}

void loop(){
  if(Serial.available() > 0){
    command = Serial.read();
    Stop();
    switch(command){
    case 'F':
      forward();
      break;
    case 'B':
      back();
      break;
    case 'L':
      left();
      break;
    case 'R':
      right();
      break;
    }
  }
}
void right() {
  motor1.setSpeed(150);
  motor1.run(BACKWARD);
  motor2.setSpeed(150);
  motor2.run(FORWARD);
  motor3.setSpeed(150);
  motor3.run(FORWARD);
  motor4.setSpeed(150);
  motor4.run(BACKWARD);
}

void left() {
  motor1.setSpeed(150);
  motor1.run(FORWARD);
  motor2.setSpeed(150);
  motor2.run(BACKWARD);
  motor3.setSpeed(150);
  motor3.run(BACKWARD);
  motor4.setSpeed(150);
  motor4.run(FORWARD);
}

void forward() {
  motor4.setSpeed(150);
  motor4.run(FORWARD);
  motor2.setSpeed(150);
  motor2.run(FORWARD);
  motor3.setSpeed(150);
  motor3.run(BACKWARD);
  motor1.setSpeed(150);
  motor1.run(BACKWARD);
}

void back() {
  motor3.setSpeed(150);
  motor3.run(FORWARD);
  motor1.setSpeed(150);
  motor1.run(FORWARD);
  motor4.setSpeed(150);
  motor4.run(BACKWARD);
  motor2.setSpeed(150);
  motor2.run(BACKWARD);
}

void Stop() {
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}
