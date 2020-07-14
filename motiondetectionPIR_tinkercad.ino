// Motion Detection using PIR sensor and Arduino UNO// 
//This code will only work using the tinkercad.com starter circuits of LCD

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensor = 9;  // the pin that the sensor is atteched to
int state = LOW; // by default, no motion detected
int val = 0;
int buzzer= 7;  // the pin that the buzzer is atteched to

void setup() 
{
  pinMode(sensor, INPUT);    // initialize sensor as an input
  pinMode(buzzer, OUTPUT); //initialize buzzer as an OUTPUT
  lcd.begin(16, 2);
  lcd.print("TechnicalUpdate");
}

void loop() 
{
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH)
  {
  delay(100);                // delay 100 milliseconds 
    if (state == LOW) 
      {
    lcd.setCursor(0, 1);
    lcd.print("Motion Detected!");
    digitalWrite(buzzer, HIGH);   // turn the LED/Buzz ON
    state = HIGH;       // update variable state to HIGH
       }  
     }
  else
   {
     delay(200);             // delay 200 milliseconds 
      if (state == HIGH)
     {
        lcd.setCursor(0, 1);
        lcd.print("Motion Stopped!");
        digitalWrite(buzzer, LOW);   // turn the Buzzer ON
        state = LOW;       // update variable state to LOW
     }
   }
}
