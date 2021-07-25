# Sensing-That-Someone-Near-of-The-Device-Using-Ultrasonic-Sensor-and-LCD

## Introduction 

Sometimes when we come in the mall entrance, we ask ourselves how the automatic door knows if there is a person in front of the door or not, the answer to the question is by using different techniques of detection as an inductive loop, infrared, etc.
In this project, we will see how we can apply the same idea of the detection of the person using the ultrasound technique to detect if someone is in front of the device or not to take suitable action as (https://www.tinkercad.com/things/9glqIBpPR3G-sensing-that-someone-near-of-the-device-using-ultrasonic-sensor/editel) . 


## Components

*	2x Arduino UNO.
*	Ultrasonic Sensor.
*	16x2 LCD.
*	3x 220 ohm Resistor.
*	Potentiometer. 
*	2x LEDs.


## Principle of work


## Two Arduino Communication

The project needs to use the Bluetooth wireless communication technique to make the communication between the Ultrasonic sensor and LCD.
However, the problem is we do not have the Bluetooth module to achieve that, so we have used Two Arduino Communication to achieve the communication technique.
Two Arduino Communication is technique that make two Arduino communicate together as Master and Slave, in this project, the Master is the Arduino that connected with the sensor, and the other is Slave .

In order to achieve the Two Arduino Communication technique, we have connected two Arduino together by:

1-	Unification the ground point by connect the ground of the two Arduino together.

2-	Connect Analog pin A4 of the Master with Analog pin A4 of the Slave.

3-	Connect Analog pin A5 of the Master with Analog pin A5 of the Slave.

## Ultrasonic Sensor

In order to send the information to the Arduino (Master) for checking if there is anyone in front of the device or not, the ultrasonic sensor is used.
The ultrasonic sensor is a sensor that unleashes ultrasound wave from the trigger pin then return from the point that the sensor strikes to the echo pin, the connection of the sensor to the Arduino as:
Vcc pin >> 5V pin.
Trig pin >> Digital 9 pin.
Echo pin >> Digital 6 pin.
GND pin >> GND pin.


In this project, we have programmed the Arduino to obtain the distance between the point of the object (person) that stroked by the ultrasound wave to the sensor, then check if the person remains in the range of the distance for 3 seconds or not and based on that the LCD will play or not.  


## LCD

LCD (Liquid Crystal Display) is a monitor that displays what the programmer wants to display in different areas.
The project contains a video that starts playing when the person approaches the device for 3 seconds. Therefore, the LCD is used to simulate the video shown to the person connected with Arduino (Slave) as shown in figure (1) below.

![The Electronic Circuit](https://user-images.githubusercontent.com/85504873/126889646-7fabea48-477e-4e49-a7eb-db878fcd2203.png)

                                                                          figure (1)

When we see figure (1) above, we will find that the potentiometer is connected with the LCD, the purpose of that is to control the light of the LCD by changing the resistance of the potentiometer.

As we mentioned before, the ultrasonic sensor chick if there is any person in front of the device or not, if there is a person in the allowed distance range (1m) from the sensor for 3 seconds, the LCD will start playing “WELCOME TO YOU “, in the same time the green LED will be ON and red LED will be OFF as shown in figure (2) below.

![ON state Sensing That Someone Near of The Device Using Ultrasonic Sensor](https://user-images.githubusercontent.com/85504873/126889431-8bbac025-621b-4ce5-96f7-924c642baac0.png)

                                                                          figure (2)

Else, the LCD will stop playing, at the same time the red LED will be ON and the green LED will be OFF as shown in figure (3) below.

![OFF state Sensing That Someone Near of The Device Using Ultrasonic Sensor](https://user-images.githubusercontent.com/85504873/126889631-4be29c3b-76c4-43a6-a25a-39c5cd734e79.png)

                                                                          figure (3)
## Code

## 1- Arduino Master Code

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

}

}

}

}


else { Serial.println(distance);//print distance in serial monitor

Wire.write (LOW);      //send HIGH signal to board 2

Wire.endTransmission();  //end data transmission between boards

delay(500);        
}

}



## 2- Arduino Slave Code


#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

#include <Wire.h> //fetching serial comunication of Arduino boards

int x=0;         //declare variable called x

int RED_LED=10;  // declare red LED pin

int GREEN_LED=13; // declare green LED pin

void setup()

{

Wire.begin(1);  //set data transfer between 2 boards

Wire.onReceive(receiveEvent); //begine data receiving between 2 boards

lcd.begin (16,2);

pinMode (RED_LED,OUTPUT);

pinMode (GREEN_LED,OUTPUT);


}


void loop()

{

delay(100); 

}


void receiveEvent(int howMany){    //start receiving void

x = Wire.read();          //read from transmitter board to x

if (x==1){          //if x equals to 1 then...

lcd.setCursor (4,0);      // set the LCD Cursor at colume 5 row 1

lcd.print ("WELCOME");

lcd.setCursor (4,1);

lcd.print("TO YOU");

digitalWrite(GREEN_LED,HIGH); 

digitalWrite(RED_LED,LOW);

delay(2000);

}

else{

lcd.clear();

digitalWrite(GREEN_LED,LOW);

digitalWrite(RED_LED,HIGH);

delay(2000);

}


}
