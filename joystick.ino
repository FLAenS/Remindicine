#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1 // Arduino pin connected to VRY pin
#define SW_PIN   2  // Arduino pin connected to SW  pin

// #define COMMAND_NO     0x00
// #define COMMAND_LEFT   0x01
// #define COMMAND_RIGHT  0x02
// #define COMMAND_UP     0x04
// #define COMMAND_DOWN   0x08

// bool switchstate = false;
int xValue = 0; // To store value of the X axis
int yValue = 0; // To store value of the Y axis
int bValue = 0; // To store value of the button
// int command = COMMAND_NO;
int xdigit = 0;
int ydigit = 0;



void setup()
{
  lcd.init(); // initialize the lcd
  lcd.backlight();
}

void loop()
{
  // switchstate=false;
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);

  if (xValue < 250) {
    if ((xdigit-1)>=0) {
      xdigit -= 1;
    }
    else {
      xdigit = 23;
    }
  }
  else if (xValue > 750) {
    if ((xdigit+1)<=23) {
      xdigit += 1;
    }
    else{
      xdigit = 0;
    }
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  if (xdigit<10) {
    lcd.print("0");
    lcd.setCursor(1, 0)
    lcd.print(xdigit);
  }
  else {
    lcd.print(xdigit);
  }
  
  lcd.setCursor(2, 0);
  lcd.print(":");

  if (yValue > 750) {
    if ((ydigit-1)>=0) {
      ydigit -= 1;
    }
    else {
      ydigit = 59;
    }
  }
  else if (yValue < 250) {
    if ((ydigit+1)<=59) {
      ydigit += 1;
    }
    else{
      ydigit = 0;
    }
  }
  
  lcd.setCursor(3, 0); 
  if (ydigit<10) {
    lcd.print("0");
    lcd.setCursor(4, 0);
    lcd.print(ydigit);
  }
  else {
    lcd.print(ydigit);
  }
  

  // if(digitalRead(2)){
  //   switchstate=true;
  // }
  delay(1000/4); 
}


