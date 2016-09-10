#include <Boards.h>
#include <Firmata.h>

int pwm1= 10;// M1 - Top right
int dir1= 13;
int pwm2= 11;// M2 - Top Left
int dir2= 12;
int pwm3= 9;// M3 - Bottom Right
int dir3= 8;

int pwm4= 6;// M4 - Bottom Left
int dir4= 7;

void setup() {
  Serial.begin(9600);
  pinMode(pwm1,OUTPUT);
  pinMode(dir1,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(pwm3,OUTPUT);
  pinMode(dir3,OUTPUT);
  pinMode(pwm4,OUTPUT);
  pinMode(dir4,OUTPUT);
}

void loop() {
  char a;
  if(Serial.available())
  {
    a=Serial.read();
   Serial.println(a);
  
   
  if (a=='w')
  {
    forward();
    delay(1000);
    brake();
 
  }  
  else if(a=='s')
  {
    reverse();
    delay(1000);
    brake();
  }
  else if(a=='d')
  {left();
  delay(1000);
  brake();
  }
  else if(a=='a')
  { right();
  delay(1000);
  brake();
  }
   else if(a=='l')
  { slightleft();
  delay(1000);
  brake();
  }
   else if(a=='r')
  { slightright();
  delay(1000);
  brake();
  }
  else if(a=='b')
  {brake();}
}
}

void forward()
{
  //digitalWrite(dir1,LOW);
  digitalWrite(dir2,HIGH);
  //digitalWrite(dir3,HIGH);
  digitalWrite(dir4,HIGH);
    
  analogWrite(pwm1,0);
  analogWrite(pwm2,70);
  analogWrite(pwm3,0);
  analogWrite(pwm4,70);
}

void reverse()
{
  //digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
 // digitalWrite(dir3,LOW);
  digitalWrite(dir4,LOW);
    
  analogWrite(pwm1,0);
  analogWrite(pwm2,70);
  analogWrite(pwm3,0);
  analogWrite(pwm4,70);
}

void left()
{
  digitalWrite(dir1,HIGH);
  //digitalWrite(dir2,HIGH);
  digitalWrite(dir3,HIGH);
  //digitalWrite(dir4,HIGH);
    
  analogWrite(pwm1,70);
 analogWrite(pwm2,0);
  analogWrite(pwm3,70);
  analogWrite(pwm4,0);
}
void right()
{
  digitalWrite(dir1,LOW);
  //digitalWrite(dir2,LOW);
  digitalWrite(dir3,LOW);
 //digitalWrite(dir4,LOW);
    
  analogWrite(pwm1,70);
 analogWrite(pwm2,0);
  analogWrite(pwm3,70);
  analogWrite(pwm4,0);
}

void brake(){
  analogWrite(pwm1,0);
  analogWrite(pwm2,0);
  analogWrite(pwm3,0);
  analogWrite(pwm4,0);
}

