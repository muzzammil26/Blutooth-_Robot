#include<stdio.h>

int RightMotor1= 7;
int RightMotor2= 8;
int RightMotorSpeed= 6;
int LeftMotor1= 12;
int LeftMotor2= 13;
int LeftMotorSpeed= 11;
int S0 = 2, S1 = 3, S2 = 4; 
int S0sensor,S1sensor,S2sensor; 
void fwd();
void bckwd();
void turnright();
void turnleft();
void motorstop();
void setup() {
Serial.begin(9600);
pinMode(S0, INPUT);
pinMode(S1, INPUT);
pinMode(S2, INPUT);
pinMode(RightMotor1,OUTPUT);
pinMode(RightMotor2,OUTPUT);
pinMode(RightMotorSpeed,OUTPUT);
pinMode(LeftMotor1,OUTPUT);
pinMode(LeftMotor2,OUTPUT);
pinMode(LeftMotorSpeed,OUTPUT);
}
void loop() {
S0sensor = digitalRead(2);
S2sensor = digitalRead(3);
S1sensor = digitalRead(4);    
  if ((S0sensor == LOW)&&(S1sensor == HIGH)&&(S2sensor == LOW))
{
fwd();
}
else if ((S0sensor == HIGH)&&(S1sensor == LOW)&&(S2sensor== LOW))
{
turnright();
}
else if ((S0sensor == LOW)&&(S1sensor == LOW)&&(S2sensor == HIGH))
{
turnleft(); 
}
else if ((S0sensor == HIGH)&&(S1sensor == HIGH)&&(S2sensor == HIGH))
{
motorstop();
}
}
void fwd()
{ //Motor moving forward
  digitalWrite(RightMotor1, LOW);
  digitalWrite(RightMotor2, HIGH);
  analogWrite(RightMotorSpeed, 250);
  digitalWrite(LeftMotor1, LOW);
  digitalWrite(LeftMotor2, HIGH);
  analogWrite(LeftMotorSpeed, 250);
  }
  void turnleft()
  {                      //Right Motor on and Left Motor Off
    digitalWrite(RightMotor1, LOW);
    digitalWrite(RightMotor2, HIGH);
    analogWrite(RightMotorSpeed, 250);
    digitalWrite(LeftMotor1, HIGH);
    digitalWrite(LeftMotor2, HIGH);
}
void turnight()
{  //Right Motor Of, Left Motor On
  digitalWrite(RightMotor1, HIGH);
  digitalWrite(RightMotor2, HIGH);
  digitalWrite(LeftMotor1, LOW);
  digitalWrite(LeftMotor2, HIGH);
  analogWrite(LeftMotorSpeed, 250);}
  void bckwd()
  {
    digitalWrite(RightMotor1, LOW);
    digitalWrite(RightMotor2, HIGH);
    analogWrite(RightMotorSpeed, 250);
    digitalWrite(LeftMotor1, LOW);
    digitalWrite(LeftMotor2, HIGH);
    analogWrite(LeftMotorSpeed, 250);
    }
 void motorstop()
 {
      digitalWrite(RightMotor1, LOW);
      digitalWrite(RightMotor2, LOW);
      digitalWrite(LeftMotor1, LOW);
      digitalWrite(LeftMotor2, LOW);
      }
   
