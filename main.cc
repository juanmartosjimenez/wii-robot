#include <iostream>
#include "WiimoteAccel.h"
#include "RoboticArm.h"
#include "WiimoteBtns.h"
#include <cmath>
using namespace std;
class WiiToRoboticArm: public WiimoteAccel, public WiimoteBtns
{
	private:
		RoboticArm *roboticarm;
	public:
		WiiToRoboticArm(RoboticArm *robotic_arm){
		roboticarm=robotic_arm;
		}
		void AccelerationEvent(int code, short acceleration){
		if (code==4){
		if (acceleration>=50){
		roboticarm->MoveServo(3, 0, 100);
		}
		else if (acceleration<=-50){
		roboticarm->MoveServo(3,180,100);
		} 
		else {
		roboticarm->MoveServo(3,0,0);
		}
		}
/*
		if (code==3){
                if (acceleration>=30){
                roboticarm->MoveServo(0, 0, 70);
                }
		else if (acceleration<=-30){
                roboticarm->MoveServo(0,180,70);
                } 
		else {
                roboticarm->MoveServo(0,0,0);
                }

                }
*/

		}
		//0=Base, 1=Bicep, 2=Elbo, 3=Wrist, 4=Gripper
		
		
		void  ButtonEvent(int code, int value){
		//up
		if (code==103&&value==1){
		roboticarm->MoveServo(1, 180, 40);
		}
		else if (value==0){
		roboticarm->MoveServo(0, 180, 0);
		roboticarm->MoveServo(1, 180, 0);
		roboticarm->MoveServo(2, 180, 0);
		roboticarm->MoveServo(3, 180, 0);
		roboticarm->MoveServo(4, 180, 0);
		}
		//down
		else if (code==108&&value==1){
                roboticarm->MoveServo(1, 0, 40);
                }
		//B open gripper
		else if (code==49&&value==1){
		cout<<"HERE"<<endl;
                roboticarm->MoveServo(4, 180, 100);
                }
		//A close gripper
		else if (code==48&&value==1){
		cout<<"Received"<<endl;;
                roboticarm->MoveServo(4, 0, 100);
                }
		//Right
		else if (code==106&&value==1){
                roboticarm->MoveServo(0, 180, 40);
                }
		//Left
		else if (code==105&&value==1){
                roboticarm->MoveServo(0, 0, 40);
                }
		//1
		else if (code==1&&value==1){
                roboticarm->MoveServo(2, 180, 30);
                }
		//2
                else if (code==2&&value==1){
                roboticarm->MoveServo(2, 0, 30);
		}
		//home
		else if (code==60&&value==1){
                roboticarm->MoveServo(0, 90, 100);
		roboticarm->MoveServo(1, 90, 100);
		roboticarm->MoveServo(2, 90, 100);
		roboticarm->MoveServo(3,90, 100);
		roboticarm->MoveServo(4, 0, 100);

                }
 
	}
};
int main()
{

RoboticArm roboticArm;
WiiToRoboticArm  wii_mote_robot(&roboticArm);
while(true){
wii_mote_robot.Listen();
wii_mote_robot.ButtonVal();
}

return 0;
}
