#include <Servo.h>
 const int trig=10;
 const int echo=9;
 long data;
 int cm;
 Servo servo_bin;
 void setup()
 {
 Serial.begin(9600);
 pinMode(trig,OUTPUT);
 pinMode(echo,INPUT);
 servo_bin.attach(8);
 }
 
 void loop()
 {
 digitalWrite(trig,LOW);
 delayMicroseconds(2);
 digitalWrite(trig,HIGH);
 delayMicroseconds(10);
 digitalWrite(trig,LOW);
 data = pulseIn(echo,HIGH);
 cm = data*0.035/2;
 Serial.println(cm);
 
 if(cm<=15)
 {
 servo_bin.write(90); 
 }
 else
 {
 servo_bin.write(0);
 }
 }
