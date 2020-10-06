#include <SoftwareSerial.h>
SoftwareSerial mySerial(52, 53);
String BT_input;
int LED = 13;

#include <Servo.h>
Servo s;
Servo s2;

#include <AFMotor.h>
AF_DCMotor motor(1);
AF_DCMotor motor1(4);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

  s.attach(10);
  s2.attach(9);
  s2.write(0);
  s.write(0);

  pinMode(LED, OUTPUT);

  motor.setSpeed(255);
  motor1.setSpeed(255);
  motor.run(RELEASE);
  motor1.run(RELEASE);
}

void loop() {
  if (mySerial.available())
    {
        BT_input = mySerial.read();
        Serial.println(BT_input);
        if (BT_input=="1")
        {
          front();
        }
        if (BT_input=="3")
        {
          back();
        }
        if (BT_input=="2")
        {
          right();
        }
        if (BT_input=="4")
        {
          left();
        }
        if (BT_input=="5")
        {
          stop();
        }
        if (BT_input=="6")
        {
          shoot();
        }
        if (BT_input=="7")
        {
          shoot2();
        }
    }
}

void front(){
  motor.run(FORWARD);
  motor1.run(FORWARD);
}

void back(){
  motor.run(BACKWARD);
  motor1.run(BACKWARD);
}

void left(){
  motor.run(BACKWARD);
  motor1.run(FORWARD);
}

void right(){
  motor.run(FORWARD);
  motor1.run(BACKWARD);
}

void stop(){
  motor.run(RELEASE);
  motor1.run(RELEASE);
}

void shoot(){
  s.write(120);
  delay(100);
  s.write(0);
}

void shoot2(){
  s2.write(120);
  delay(100);
  s2.write(0);
}
