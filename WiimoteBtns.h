#include <iostream>
#ifndef WIIMOTEBTNS_H
#define WIIMOTEBTNS_H

class WiimoteBtns
{
private:
	int fd;
public:
	WiimoteBtns();
	~WiimoteBtns();
	void ButtonVal();
 	virtual void ButtonEvent(int code, int value);
};
#endif
