/*
 * Thruster.cpp
 *
 *  Created on: Mar 18, 2018
 *      Author: andrew
 */

#include "Thruster.h"


Thruster::Thruster(int channelNum) {
	channelNumber = channelNum;
	maestro.setTarget(channelNum, ZERO);
}

Thruster::~Thruster() {

}

bool Thruster::setSpeed(int speed){
	try{
		maestro.setSpeed(channelNumber, 20);

		if(speed < -1880 || speed > 1880){
			return false;
		}

		if(speed < 0){
			maestro.setTarget(channelNumber, MIN_REV + speed);
			currentSpeed = speed;
			return true;
		}else if(speed > 0){
			maestro.setTarget(channelNumber, MIN_FWD + speed);
			currentSpeed = speed;
			return true;
		}else{
			return stop();
		}

	}catch(int e){
		return false;
	}
}

bool Thruster::stop(){
	try{
		maestro.setSpeed(channelNumber, 20);
		maestro.setTarget(channelNumber, ZERO);
		return true;
	}catch(int e){
		return false;
	}
}

int Thruster::getSpeed(){
	return currentSpeed;
}

