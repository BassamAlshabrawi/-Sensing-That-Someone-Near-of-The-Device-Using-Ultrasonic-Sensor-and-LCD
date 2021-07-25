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
  
