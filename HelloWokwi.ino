#include <Wire.h> 

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);


const int currentPin = A0;
double adccurrent = 0;
double currentValue = 0;

const int rel = 2;

double power ; 

void setup() 
{lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(rel, OUTPUT);

 lcd.setCursor(0, 0);
  lcd.print("Battery cooloing sys");
  delay(2000);
}
 
void loop()
{
  
  adccurrent = analogRead(currentPin);
  currentValue = (adccurrent / 3) ;


  
 lcd.setCursor(0, 0);
  lcd.print("temp=");
  lcd.setCursor(6, 0);
  lcd.print(currentValue);
   lcd.setCursor(11, 0);
  lcd.print("Deg");
 
  if (currentValue>=50)
  {    digitalWrite(rel, HIGH);
 lcd.setCursor(0, 1);
  lcd.print("High tem pump on");
 
  

  }
  else{   digitalWrite(rel,LOW);
      
 lcd.setCursor(0, 1);
  lcd.print("nor tem pump off");
  
  
  }
  
 

}