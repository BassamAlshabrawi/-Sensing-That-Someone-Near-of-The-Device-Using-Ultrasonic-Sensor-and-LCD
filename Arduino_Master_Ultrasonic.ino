#include <Wire.h>  //fetching serial comunication of Arduino boards

int trigger = 9;   //declare trigger pin 
int echo = 6;      //declare echo pin

int time;          //declare variable called time
int distance;      //declare variable called distance
int range=100;     //declare variable called range(1m)

void setup()
{ 
  Wire.begin();     //set data transfer between 2 boards
  Serial.begin(9600);  //start serial monitor
  pinMode (trigger,OUTPUT); 
  pinMode (echo,INPUT);     
}
void loop()
{ Wire.beginTransmission(1); //begine data transfer between 2 boards
  digitalWrite(trigger,HIGH);//turn trigger on
  delayMicroseconds(10);     
  digitalWrite(trigger,LOW); //turn off trigger
  time = pulseIn(echo,HIGH); //time equals the echo
  distance = (time * 0.034) / 2; // distance equation
  
  if (distance <= range)     //if distance less than 1m from the sensor
  {Serial.println(distance); //print distance in serial monitor first time
   delay(1000);              //delay for second
   digitalWrite(trigger,HIGH); //repeate the reading echo and distance equation
   delayMicroseconds(10);
   digitalWrite(trigger,LOW);
   time = pulseIn(echo,HIGH);
   distance = (time * 0.034) / 2;
       
     if (distance <= range)        //if distance less than 1m from the sensor
     {Serial.println(distance);  //print distance in serial monitor second time
      delay(1000);        
      digitalWrite(trigger,HIGH);//repeate the reading echo and distance equation
      delayMicroseconds(10);
      digitalWrite(trigger,LOW);
      time = pulseIn(echo,HIGH);
      distance = (time * 0.034) / 2;
      
      if (distance <= range)        //if distance less than 1m from the sensor
     {Serial.println(distance);  //print distance in serial monitor third time
      delay(1000);         
      digitalWrite(trigger,HIGH);//repeate the reading echo and distance equation
      delayMicroseconds(10);
      digitalWrite(trigger,LOW);
      time = pulseIn(echo,HIGH);
      distance = (time * 0.034) / 2;
                
       

        if (distance <= range)       //if distance less than 1m from the sensor
        {Serial.println(distance);//print distance in serial monitor
         Wire.write (HIGH);     //send HIGH signal to board 2
         Wire.endTransmission();  //end data transmission between boards
         delay(3000);            
        }}}}
  
  else { Serial.println(distance);//print distance in serial monitor
         Wire.write (LOW);      //send HIGH signal to board 2
         Wire.endTransmission();  //end data transmission between boards
         delay(500);        
       }
}
