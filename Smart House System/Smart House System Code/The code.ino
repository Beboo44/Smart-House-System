#include<Servo.h>
Servo servoo;
const int led=5; 
const int trig=9; //change pin 2
const int echo = 10; //4
const int trig2=6; //A5
const int echo2=4 ; //A4
const int ldr=A7;
float time, distance;
float time2,distance2;
void setup() 
{  
  pinMode(5,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(trig2,OUTPUT);
  pinMode(echo2,INPUT);
  pinMode(ldr,INPUT);
  Serial.begin(9600);
  servoo.attach(11);
  servoo.write(0);
}
int people = 0;
void loop() {
  // put your main code here, to run repeatedly:
  int ldrreading=analogRead(ldr);
  if(people>0)
    analogWrite(led,(600-ldrreading)/4);
  Serial.println(ldrreading);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  time = pulseIn(echo,HIGH);
  distance = (time * 0.0343) / 2;
  Serial.println(distance);
  delay(200);
  digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  time2 = pulseIn(echo2,HIGH);
  distance2 = (time2 * 0.0343)/2;
  delay(200);
  if(distance<5.0)
  {
    if(people>0)
      analogWrite(led,(600-ldrreading)/4);
    ++people;
    servoo.write(90);
    delay(1000);
    servoo.write(0);
  }
  else if (distance2<5.0)
  {
    --people;
    servoo.write(90);              
    delay(1000);
    servoo.write(0);
    delay(1000);
  }
  if(people==0)
    digitalWrite(5,LOW);
  Serial.println(people);
  delay(100);  
}
