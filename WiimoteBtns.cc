#include <iostream>
#include "WiimoteBtns.h"
#include <stdlib.h>                                                              
#include <fcntl.h>                                                               
#include <unistd.h>
using namespace std;

WiimoteBtns::WiimoteBtns()
{
  fd = open("/dev/input/event2", O_RDONLY|O_NONBLOCK);
  //return fd;
  if (fd == -1)                                                             
        {                                                                         
             std::cerr << "Error: Could not open event file  forgot sudo?\n";
             exit(1);                                                          
        }            	
}

void WiimoteBtns::ButtonVal()
{
   char buffer[32];                                                  
   read(fd, buffer, 32);                                             
                                                                                  
                // Extract code (byte 10) and value (byte 12) from packet        
   int code = buffer[10];                                            
   int value = buffer[12];
  
   ButtonEvent(code, value);


}

void WiimoteBtns::ButtonEvent(int code, int value) 
{
   

 //cout<<"The Code Is "<<code<<" and the Value is "<<value<<'\n';


}
WiimoteBtns::~WiimoteBtns()
{
 close(fd);
}
