#include <AFMotor.h>
#include <IRremote.h>

int RECV_PIN = 23;
AF_DCMotor motor(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

IRrecv irrecv(RECV_PIN);
decode_results results;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Motor test!");
  irrecv.enableIRIn();
  motor.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);

  motor.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  moveAllForward();
  delay(500);
  AllRelease();
  delay(1000);
  moveAllReverse();
  delay(500);
  AllRelease();
  delay(1000);
  turnStationeryLeft();
  delay(500);
  AllRelease();
  delay(1000);
  turnStationeryRight();
  delay(500);
  AllRelease();
  delay(2000);
}
void moveAllForward() {
  Serial.print("All forward");
  motor.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void moveAllReverse() {
  Serial.print("All Reverse");
  motor.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void AllRelease() {
  Serial.print("All Release");
  motor.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void turnLeft() {
  Serial.print("Turn Left");
  motor.run(RELEASE);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(RELEASE);
}
void turnRight() {
  Serial.print("Turn Right");
  motor.run(FORWARD);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(FORWARD);
}
void turnStationeryLeft() {
  Serial.print("All Stationery Left");
  motor.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}
void turnStationeryRight() {
  Serial.print("All Stationery Right");
  motor.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}
