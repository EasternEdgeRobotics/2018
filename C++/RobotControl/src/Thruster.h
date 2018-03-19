/*
 * Thruster.h
 *
 *  Created on: Mar 18, 2018
 *      Author: andrew
 */

#ifndef THRUSTER_H_
#define THRUSTER_H_

#include "maestro.h"

class Thruster {
private:

	const int MAX_FWD = 7992;
//1880
	const int MIN_FWD = 6112;

	const int MAX_REV = 4022;
//1880
	const int MIN_REV = 5902;

	const int ZERO = 6000;

	const int ACCERLERATION = 20;

	int currentSpeed = 0;

	Maestro maestro;



public:

	int channelNumber;

	Thruster(int channelNum);


	virtual ~Thruster();


	/** getDirection
	 *
	 * returns the direction of the ROV.
	 *
	 * @output - the direction in integer form
	 * 			1: ROV is moving forward
	 * 			-1: ROV is moving backwards
	 **/
	int getDirection();



	/* getSpeed
	 *
	 * returns the current speed of the ROV in integer form
	 *
	 * @output  --- returns the integer value for the speed.
	 * 					-negative number is reverse, positive is forwards
	 *
	 */
	int getSpeed();




	/* setSpeed
	 *
	 *	sets the desired speed of the ROV. ROV will then accelerate to match the speed given.
	 *
	 * @input - speed: integer for desired speed of thruster
	 * 					- -1888 <= speed <=1888
	 * 					- negative number is reverse, positive is forward
	 *
	 * @output - success: bool for confirmation of success or failure
	 * 					- true: speed was set successfully
	 * 					- false: speed was not set
	 */

	bool setSpeed(int speed);


	/* stop
	 *
	 * stops the motor (AKA zeros it)
	 *
	 * @output - success: bool for confirmation of success or failure
	 * 					- true: stopped successfully
	 * 					- false: failed to stop
	 */
	bool stop();
};

#endif /* THRUSTER_H_ */
