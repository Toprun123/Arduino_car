#include <SoftwareSerial.h>
SoftwareSerial mySerial(52, 53); // RX and TX can be edited 
String BT_input;
int LED = 13;
#include <Servo.h>
Servo s;
Servo s2;
#include <AFMotor.h>
AF_DCMotor motor(1);
AF_DCMotor motor1(4);
const int Motor_L_F = 2;
const int Motor_L_B = 3;
const int Motor_R_F = 4;
const int Motor_R_B = 5;
void setup() {
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
void Forward(){
 digitalWrite(Motor_L_F, HIGH);
 digitalWrite(Motor_L_B, LOW);
 digitalWrite(Motor_R_F, HIGH);
 digitalWrite(Motor_R_B, LOW);
 }
void Right(){
 digitalWrite(Motor_R_F, LOW);
 digitalWrite(Motor_R_B, HIGH);
 digitalWrite(Motor_L_F, HIGH);
 digitalWrite(Motor_L_B, LOW);
 }
void Left(){
 digitalWrite(Motor_L_F, LOW);
 digitalWrite(Motor_L_B, HIGH);
 digitalWrite(Motor_R_F, HIGH);
 digitalWrite(Motor_R_B, LOW);
 }
void Back(){
 digitalWrite(Motor_L_F, LOW);
 digitalWrite(Motor_L_B, HIGH);
 digitalWrite(Motor_R_F, LOW);
 digitalWrite(Motor_R_B, HIGH);
 }
void Stop(){
 digitalWrite(Motor_L_F, LOW);
 digitalWrite(Motor_L_B, LOW);
 digitalWrite(Motor_R_F, LOW);
 digitalWrite(Motor_R_B, LOW);
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
