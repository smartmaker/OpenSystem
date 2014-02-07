void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
}

void loop()
{
  int val0 = analogRead(A0);
  int val1 = analogRead(A1);
  int val2 = analogRead(A2);
  int val3 = analogRead(A3);
  int val4 = analogRead(A4);
  
  /*
  Serial.println(val0);
  Serial.println(val1);
  Serial.println(val2);
  Serial.println(val3);
  Serial.println(val4);
  */
  
  
  // which button has been pressed?
  if (val2 == 0)
  {
    Serial.println("LEFT"); 
  }
  if (val4 == 0)
  {
    Serial.println("RIGHT"); 
  }
  if (val1 == 0)
  {
    Serial.println("UP"); 
  }
  if (val3 == 0)
  {
    Serial.println("DOWN"); 
  }
  if (val0 == 0)
  {
    Serial.println("CENTER"); 
  }
  
  delay(500);
  
}
