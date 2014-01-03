// A simple Web Server that read value of the Analog Inputs
// and return a table with the results as content
// enc28j60.c modified for OpenSystem (Multi platform ready)
// 2013 www.smartmaker.com

#include "etherShield.h"
#include "ETHER_28J60.h"

static uint8_t mac[6] = {0x23, 0x23, 0x23, 0x23, 0x23, 0x23};   //This just needs to be unique for your network, 
                                                                //So unless you have more than one of these boards
                                                                //Connected, you should be fine with this value.
                                                           
static uint8_t ip[4] = {192, 168, 1, 23};                       //The IP address for your board. Check your home hub
                                                                //To find an IP address not in use and pick that
                                                                //This or 10.0.0.15 are likely formats for an address
                                                                //That will work.

static uint16_t port = 80;                                      //Use port 80 - the standard for HTTP

ETHER_28J60 ethernet;

void setup()
{ 
  ethernet.setup(mac, ip, port);
}

void loop()
{
  if (ethernet.serviceRequest())
  {
    ethernet.print("<H1>smARtMAKER<br/>Open System<br/>Analog Values</H1><br/><table>");
    ethernet.print("<tr><th>Input</th><th>Value</th></tr>");
    for (int i = 0; i < 6; i++)
    {
      ethernet.print("<tr><td>");
      ethernet.print(i);
      ethernet.print("</td><td>");
      ethernet.print(analogRead(i));
      ethernet.print("</td></tr>");
    }
    ethernet.print("</table>");
    ethernet.respond();
  }
  delay(100);
}

