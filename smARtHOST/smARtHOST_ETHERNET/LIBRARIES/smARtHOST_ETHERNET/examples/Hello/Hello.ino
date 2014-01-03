// A simple web server that always just says "Hello World"
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
    ethernet.print("<H1><p><center>smARtMAKER</center></p></H1>");
    ethernet.print("<H1><p><center>OpenSystem</center></p></H1>");
    ethernet.print("<H1><p><center>Hello World</center></p></H1>");
    ethernet.respond();
  }
  delay(100);
}

