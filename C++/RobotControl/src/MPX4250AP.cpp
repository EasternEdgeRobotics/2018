/*
 * MPX4250AP.cpp
 *
 *  Created on: Mar 3, 2018
 *      Author: Charity
 */

#include "MPX4250AP.h"
#include "maestro.h"

MPX4250AP::MPX4250AP() {
	// TODO Auto-generated constructor stub

}

MPX4250AP::~MPX4250AP() {
	// TODO Auto-generated destructor stub
}

#include <observable/property.hpp>
using namespace observable;

#ifndef MPX4250AP_H_
#define MPX4250AP_H_
/**
 * MPX4250AP Pressure Sensor
 */
class MPX4250AP
{
public:
	MPX4250AP();
	virtual ~MPX4250AP();

#endif /* MPX4250AP_H_ */
/**
 * PressureScalar - Scalar value for calculating pressure from voltage.
 * PressureOffset - Offset value for calculating pressure from voltage.
 */
private:
	double pressureScalar = 0.264909785f;
	double pressureOffset = 54.20054200f;

public: 
	observable::Transformer (double, double)
	calibration = source -> source.map(x = 0.83060f*x + 10.0445f);

private:
	ADC channel; 
/*
 * constructs a new MPX4250AP sensor on the given channel
 */
public:
	MPX4250AP;
	this.channel = channel;

/* read
 * 
 * returns the pressure
 * 
 * @output --- returns the pressure
 */
public double read();
{
return channel.voltage()*pressureOffset-pressureScalar;	
}
}