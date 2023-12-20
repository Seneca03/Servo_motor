#include <Servo.h>

// C++ code
//
Servo ctrlservo;
int B=0;
bool mode=0;
const int inter=2;
 int delayT=0;


void setup()
{
   Serial.begin(9600);
  ctrlservo.attach(3);


pinMode(4,INPUT_PULLUP);
pinMode(5,INPUT_PULLUP);
pinMode(6,INPUT_PULLUP);
pinMode(7,INPUT_PULLUP);
pinMode(inter,INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(inter),getbutton , FALLING);

}
void getbutton()
{
  if(digitalRead(4)==0)
    B= 1;
  
  if(digitalRead(5)==0)
    B=2;
  if(digitalRead(6)==0)
    B= 3;
  if(digitalRead(7)==0)
    B=4;
  
  delayT=speed();
  Serial.println(B);
  
  
}
int speed()
{

  switch(B)
    
  {  case 1:
  	mode=1;
  	return 100;
  	
  case 2:
  	mode=1;
  	return 50;
  
  case 3:
  	mode=1;
  	return 25;
  
  case 4:
  	mode=1;
  	return 5;
   default:
   mode=0;
   return 0;
  }
   
}

void loop()
{
  
  
  
 
    
if(mode==1)
  {
 for(int i=0;i<180;i++)
 {
   
   ctrlservo.write(i);
   delay(delayT);
 }
  
   for(int i=180;i>=0;i--)
 {
   ctrlservo.write(i);
   delay(delayT);
   }
  }
  
    
}
