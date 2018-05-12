#include <AFMotor.h>

int alarm = 5;

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
}

void loop() {
  Stop();

  int soundRec = analogRead(A2);
  Serial.println(soundRec);
  if(soundRec > 500) {
    forward();
    analogWrite(alarm, 100);
    delay(500);
    analogWrite(alarm, 255);
    delay(1500);
  }
  
  int lightLeft = analogRead(A0);
  int lightRight = analogRead(A1);

//  Serial.print(lightLeft);
//  Serial.print(" + ");
//  Serial.println(lightRight);

  if (lightLeft > 700 || lightRight > 700) {
    int sub = lightLeft - lightRight;
    if (abs(sub) < 100) {
      forward();
    } else if (sub > 100) {
      left();
    } else {
      right();
    }
  }

  delay(250);
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
