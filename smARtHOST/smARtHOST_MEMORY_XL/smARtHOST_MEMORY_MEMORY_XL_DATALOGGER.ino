/*

   smARtHOST MEMORY and MEMORY XL Example
   by:Harold Timmis
   
   This is a keylogger program that will keep track of which button is pressed on a smARtMOD BUTTON 5TO1A.
   
   Hardware Used:
   smARtCORE U,L,Z
   smARtHOST POWER PLUS, or HIGH POWER
   smARtHOST MEMORY or MEMORY XL
   smARtMOD BUTTON 5TO1A

*/

#include <SD.h>

// Pin 10 is used as the CS Pin
const int chipSelect = 10;

// holds the pin location of analog 0
int buttonPin = A0;

// this value will be written to the SD card later in the program
int val=0;

void setup()
{
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
  
  // set analog pin 0 to an Input
  pinMode(buttonPin, INPUT);

  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(10, OUTPUT);
  
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
}

void loop()
{
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    
    val = analogRead(buttonPin);
    
    
    //Keeps track of all of the buttons being pressed (UP,DOWN,RIGHT,LEFT,CENTER)
    if(val <= 179 && val >= 177)
    {
      dataFile.println("UP");

      delay(100);
    }
    if(val <= 85 && val >= 70)
    {
      dataFile.println("DOWN");

      delay(100);
    }
    if(val <= 115 && val >= 100)
    {
      dataFile.println("LEFT");

      delay(100);
    }
    if(val <= 67 && val >= 54)
    {
      dataFile.println("RIGHT");

      delay(100);
    }
    if(val <= 320 && val >= 310)
    {
      dataFile.println("CENTER");

      delay(100);
    }
 
    dataFile.close();

  }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  } 
}
