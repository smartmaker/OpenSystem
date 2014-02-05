#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);

// button pin and RGB LED pin assignments 
int buttonPin = A0;
// (r, g, b)
int RGBLED[] = {
  9,10,11};

// Button value variable
int val = 0;
// this holds all of the LEDs intensity values (r, g, b)
int RGBinten[] = {
  0,0,0};

// used to store the index of both the RGBLED[] and RGBinten[] arrays 
int i = 0;
int j = 0;

void setup()
{
  // start serial communication
  Serial.begin(9600);

  lcd.begin(16, 2);

  // set buttonpin to an input
  pinMode(buttonPin, INPUT); 

  // set all of the LEDs inside the RGB to an Output
  for(int i = 0; i <= 2; i++)
  {
    pinMode(RGBLED[i], OUTPUT); 
  }

}

void loop()
{  
  // read the value of the analog reading found on buttonPin (A0)
  val = analogRead(buttonPin);

  lcd.setCursor(0, 0);
  lcd.print(RGBinten[0]);
  lcd.print("R");
  lcd.setCursor(4, 0);
  lcd.print(RGBinten[1]);
  lcd.print("G");
  lcd.setCursor(8, 0);
  lcd.print(RGBinten[2]);
  lcd.print("B");

  // first if statment is checking whether the right button was pressed.
  if (val <= 67 && val >= 54)
  {
    // move index of arrays +1 if i is greater than or equal to 2
    if (i >= 2)
    {
      // if the value is greater than or equal to 2 then index i and J are set to 2
      i = j = 2;
    }
    else
    {
      i++;
      j++;
    }

    // set both arrays with their current indexes
    RGBLED[i];
    RGBinten[j];       

    // print indexes to the serial monitor it starts with 0 , 0 and goes until 2 , 2
    Serial.print(i);
    Serial.print(" , ");
    Serial.println(j);

    // you can only move one value at a time because of this while loop if you want to be able
    // to increment or decrement your values quicker you can remove this and add a delay (exp. 100ms)
    while(val <= 67 && val >= 54)
    {
      val = analogRead(buttonPin);
      delay(100);
    }
  }
  
  // Checks if the left button has been pressed
  if (val <= 115 && val >= 100)
  {
    // move index of arrays -1 if i greater than 0.
    if (i <= 0)
    {
      // if this if statment executes then indexes i and j are set to 0
      i = j = 0;
    }
    else
    {
      i--;
      j--;
    }
    
    // set both arrays with their current indexes
    RGBLED[i];
    RGBinten[j];

    // print indexes to the serial monitor it starts with 0 , 0 and goes until 2 , 2
    Serial.print(i);
    Serial.print(" , ");
    Serial.println(j);

    // you can only move one value at a time because of this while loop if you want to be able
    // to increment or decrement your values quicker you can remove this and add a delay (exp. 100ms)
    while(val <= 115 && val >= 100)
    {
      val = analogRead(buttonPin);
      delay(100);
    }
  }

  // this if statement will start if the up button is pressed
  if (val <= 179 && val >= 177)
  {
    delay(100);

    // 
    if (RGBinten[j] >= 255)
    {
      RGBinten[j] = 255;
    }
    else
    {
      RGBinten[j]++;
    }
    analogWrite(RGBLED[i], RGBinten[j]);     

    Serial.println(RGBinten[j]);

    while(val <= 185 && val >= 170)
    {
      val = analogRead(buttonPin);
      delay(100);
    }
  }

  if (val <= 85 && val >= 70)
  {
    // DOWN

    delay(100);

    if (RGBinten[j] <= 0)
    {
      RGBinten[j] = 0;
    }
    else
    {
      RGBinten[j]--;
    }
    analogWrite(RGBLED[i], RGBinten[j]);     

    Serial.println(RGBinten[j]);

    while(val <= 85 && val >= 70)
    {
      val = analogRead(buttonPin);
      delay(100);
    }
  }

}

