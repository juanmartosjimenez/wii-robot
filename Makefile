main: WiimoteAccel.o WiimoteBtns.o RoboticArm.o  main.o

	g++ WiimoteAccel.o RoboticArm.o WiimoteBtns.o main.o -o main

WiimoteAccel.o: WiimoteAccel.cc WiimoteAccel.h

	g++ -c WiimoteAccel.cc

RoboticArm.o: RoboticArm.cc RoboticArm.h

	g++ -c RoboticArm.cc

WiimoteBtns.o: WiimoteBtns.cc WiimoteBtns.h

	g++ -c WiimoteBtns.cc 

main.o: main.cc RoboticArm.h WiimoteAccel.h WiimoteBtns.h

	g++ -c main.cc

clean:

	rm main main.o WiimoteAccel.o RoboticArm.o WiimoteBtns.o
