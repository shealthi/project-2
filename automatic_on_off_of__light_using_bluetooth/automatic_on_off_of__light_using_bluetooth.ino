#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
LiquidCrystal lcd(10, 11, 4, 5, 6, 7);
const int irPin = 3;
const int relay1Pin = A4; 
int relay1State = 0;
int pinNumber;
int irState = 0;


SoftwareSerial bluetooth(12, 13);                                                                    
  

void setup()
{
  pinMode(relay1Pin, OUTPUT);
   pinMode(irPin, INPUT);
  relay1State = LOW; //initally relay will be off state
  digitalWrite(relay1Pin, relay1State);
  Serial.begin(9600);
  bluetooth.begin(9600);
  lcd.begin(16, 2);
  lcd.print("control the device using bluetooth");  
  lcd.setCursor(0, 1);
  lcd.print("Bluetooth connection");   
  delay(3000);
}
void loop()
{
   lcd.clear();
  lcd.print("Checking Data...");
  delay(200);

  while (bluetooth.available())  //check if any data received 
  {
    if (bluetooth.find("s"))
    {
      char d = bluetooth.read();
 
      if (d== '1')  //relay will be on if u enter 's1' in ur mobile using "bluetooth terminal app"
    {
  relay1State = HIGH;
  digitalWrite(relay1Pin, relay1State);
  lcd.clear();
  lcd.print(" light is ON"); //relay's output can be light,fan,tv,etc......
  delay(2000);

    }
   if (d== '2')
    {
  relay1State = LOW;
  digitalWrite(relay1Pin, relay1State);
  lcd.clear();
  lcd.print(" light is OFF"); 
  delay(2000);
  
}
    }
  }


//==============================================================


  irState = digitalRead(irPin);   // if u touch the ir-sensor light will be on for 10sec after 10sec it will off automatically

  if (irState == LOW)
  {
    lcd.clear();
   
    Serial.begin(9600);
     relay1State = HIGH;
  digitalWrite(relay1Pin, relay1State);
  lcd.clear();
  lcd.print(" light is  ON"); 
  delay(10000);
  }
   //delay(1000);
   if (irState == LOW)
  {
    lcd.clear();
   
    Serial.begin(9600);
     relay1State = LOW;
  digitalWrite(relay1Pin, relay1State);
  lcd.clear();
  lcd.print(" light is OFF"); 
  delay(5000);
   
   
    lcd.clear();
  }
}
 
