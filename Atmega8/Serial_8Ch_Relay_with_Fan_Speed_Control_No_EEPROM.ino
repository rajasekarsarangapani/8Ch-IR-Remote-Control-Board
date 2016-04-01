#include <TimerOne.h>
int serial;
volatile int i=0;
volatile boolean zero_cross=0;
int dim = 64;
int pas = 8;
int freqStep = 75; 
int on1;
int on2;
int on3;
int on4;
int on5;
int on6;
int on7;
int on8;
int Relay1 =8;
int Relay2 =7;
int Relay3 =3;
int Relay4 =4;
int Relay5 =20;
int Relay6 =21;
int Relay7 =5;
int Relay8 =6;
int AC_pin = 10;

void setup() {
  Serial.begin(9600);
pinMode(Relay1, OUTPUT);
pinMode(Relay2, OUTPUT);
pinMode(Relay3, OUTPUT);
pinMode(Relay4, OUTPUT);
pinMode(Relay5, OUTPUT);
pinMode(Relay6, OUTPUT);
pinMode(Relay7, OUTPUT);
pinMode(Relay8, OUTPUT);
pinMode(AC_pin, OUTPUT);
attachInterrupt(0, zero_cross_detect, RISING);
Timer1.initialize(freqStep);
Timer1.attachInterrupt(dim_check, freqStep);
 
delay(100);
}

void zero_cross_detect() {
zero_cross = true;
digitalWrite(AC_pin, LOW);  
}

void dim_check() { 
 if(zero_cross == true) { 
  if(i>=dim) {
    digitalWrite(AC_pin, HIGH);
    i=0;
    zero_cross=false;
    }
    else {
      i++;
  }
 }
}

void loop() {
  
   if (Serial.available()) 
  {
    serial= Serial.read();
    translateSR(); 
 
  } 
}


void translateSR() 
{

  switch(serial)

  {

  case 'A':  
         on1 = !on1;
         digitalWrite(Relay1, on1 ? HIGH : LOW);
         delay(100);
  break;
       
 case 'B':  
         on2 = !on2;
         digitalWrite(Relay2, on2 ? HIGH : LOW);
         delay(100);
  break;
       
 case 'C':  
         on3 = !on3;
         digitalWrite(Relay3, on3 ? HIGH : LOW);
         delay(100);
  break;
       
 case 'D':  
         on4 = !on4;
         digitalWrite(Relay4, on4 ? HIGH : LOW);
         delay(100);
  break;   
       
 case 'E':  
         on5 = !on5;
         digitalWrite(Relay5, on5 ? HIGH : LOW);
         delay(100);
  break; 

 case 'F':  
         on6 = !on6;
         digitalWrite(Relay6, on6 ? HIGH : LOW);
         delay(100);
  break; 

 case 'G':  
         on7 = !on7;
         digitalWrite(Relay7, on7 ? HIGH : LOW);
         delay(100);
  break; 
       
 case 'H':  
         on8 = !on8;
         digitalWrite(Relay8, on8 ? HIGH : LOW);
         delay(100);
  break;
       
        
case 'N':  
  // if(on2==1){      
  if (dim<127)  
  {
    dim = dim + pas;
    if (dim>127) 
    {
      dim=128;
    }}
   // }
   delay(100);
    break;

    case 'U':
//if(on2==1) {
    if (dim>5)  
  {
     dim = dim - pas;
  if (dim<0) 
    {
      dim=0;
    }}
   //}
   delay(100);
   break;

     
 case 'I':  
         on1 = 0;
         on2 = 0;
         on3 = 0;
         on4 = 0;
         on5 = 0;
         on6 = 0;
         on7 = 0;
         on8 = 0;
         digitalWrite(Relay1, LOW);
         digitalWrite(Relay2, LOW);
         digitalWrite(Relay3, LOW);
         digitalWrite(Relay4, LOW);
         digitalWrite(Relay5, LOW);
         digitalWrite(Relay6, LOW);
         digitalWrite(Relay7, LOW);
         digitalWrite(Relay8, LOW);
         delay(100);
 break;   

default:
break;    
  }
  delay (100);
  }
