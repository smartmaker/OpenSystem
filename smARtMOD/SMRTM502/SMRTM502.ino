void setup()
{
  for(int i = 2; i <= 6; i++)
  {
    pinMode(i,OUTPUT);
  } 
  
}
void loop()
{
  // runs smartBlink function
  // smartBlink(pin, time);
  for(int i = 2; i <= 6; i++)
  {
    smartBlink(i,100);
  }
}

void smartBlink(int pin, int time)
{
  // turns LED on
  digitalWrite(pin, HIGH);
  // delay is = to the time argument
  delay(time);
  // turns LED off
  digitalWrite(pin, LOW);
  delay(time);
}
