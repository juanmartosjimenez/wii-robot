#include <iostream>
#ifndef WIIMOTEACCEL_H
#define WIIMOTEACCEL_H
using namespace std;
class WiimoteAccel{
private:
int fd;
public:
WiimoteAccel();
~WiimoteAccel();
virtual void AccelerationEvent(int code, short acceleration);
void Listen();
};
#endif

