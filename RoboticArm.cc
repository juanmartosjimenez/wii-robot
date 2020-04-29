#include "RoboticArm.h"                                                          
#include <fcntl.h>                                                               
#include <stdlib.h>                                                              
#include <sys/mman.h>                                                            
#include <iostream>                                                              
                                                                                 
RoboticArm::RoboticArm()                                                          
{                                                                                 
    fd = open("/dev/mem", O_RDWR); // Open memory mapped I/O                                       
    // Map physical memory                                                   
    pBase = (char *) mmap(NULL, gpio_size, PROT_READ | PROT_WRITE,                   
                        MAP_SHARED, fd, gpio_address);                              
                                                                                  
    if (pBase == (void *) 1)  {      // Check success                                             
            std::cerr << "Error mapping memory  fogot sudo?\n";              
            exit(1);           }                                                                   
                                                                                  
        for (int i = 0; i < 5; i++)  // Initial servo positions                                    
                MoveServo(i, 90, 180);                                            
}                                                                                 
                                                                                  
RoboticArm::~RoboticArm() {                                                                        
     munmap(pBase, 0xff);   // Unmap physical memory                                               
     close(fd);  // Close memory mapped I/O                                                  
}                                                                                 
                                                                                  
void RoboticArm::RegisterWrite(unsigned offset, unsigned value)                   
  { * (volatile unsigned *) (pBase + offset) = value; }  
                                                                                
int RoboticArm::RegisterRead (unsigned offset)                   
  { return * (volatile unsigned *) (pBase + offset);  }                                            
                                                                                                   
void RoboticArm::MoveServo(int id, int angle, int speed)                          
{  
   if (id < 0 || id > 4) // Check valid servo                                                     
        {                                                                         
           std::cerr << "Invalid servo ID\n";                                
           exit(1);                                                          
        }                                                                         
                                                                                  
        // Verify valid angle                                                    
        if (angle < 0 || angle > 180)                                             
        {                                                                         
                std::cerr << "Invalid angle\n";                                   
                exit(1);                                                          
        }                                                                         
                                                                                  
        // Set memory locations                                                  
        RegisterWrite(base_angle_offset + id * 8, angle);                                     
        RegisterWrite(base_angle_offset + id * 8 + 4, speed);                                 
}
