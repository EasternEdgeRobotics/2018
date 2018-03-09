//============================================================================
// Name        : RobotControl.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "control/RapaPololuMaestro/RPMSerialInterface.h"
using namespace std;

int main() {
	// Create the interface
	    RPM::SerialInterface* serialInterface = RPM::SerialInterface::createSerialInterface( "COM5", 9600 );
	    if ( !serialInterface->isOpen() ){
	        cout << "nahfam";
	    	return -1;
	    }

	    // Set the value of channel 0 to 6000 quarter-of-microseconds (i.e. 1.5 milliseconds)
	    serialInterface->setTargetCP( 0, 6000 );

	    unsigned int sleep(200);

	    // Delete the interface
	    delete serialInterface;

	    return 0;
}
