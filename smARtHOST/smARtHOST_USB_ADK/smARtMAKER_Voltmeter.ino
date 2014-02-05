#include <SPI.h>
#include <Adb.h>

Connection * connection;

// Elapsed time for sensor sampling
long lastTime;

// Event handler for shell connection; called whenever data sent from Android to Microcontroller
void adbEventHandler(Connection * connection, adb_eventType event, uint16_t length, uint8_t * data)
{
  // Unused in this case
}

void setup()
{
  // Record time for sensor polling timer
  lastTime = millis();

  // Init the ADB subsystem.
  ADB::init();

  // Open an ADB stream to the phone's shell. Auto-reconnect. Use port number 4568
  connection = ADB::addConnection("tcp:4568", true, adbEventHandler);  
}

void loop()
{
  //Check if sensor should be sampled.
  if ((millis() - lastTime) > 20)
  {
    uint16_t data = analogRead(A0);

    //Send the sensor value to Android as two bytes of data.
    connection->write(2,(uint8_t*)&data);

    Serial.println(data,DEC);   // Output debugging to serial

    // Update timer for sensor check
    lastTime = millis();
  }

  // Poll the ADB subsystem.
  ADB::poll();
}
