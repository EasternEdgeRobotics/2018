/*
 * MPX4250AP.h
 *
 *  Created on: Mar 3, 2018
 *      Author: Charity
 */
//using namespace observable;

#ifndef MPX4250AP_H_
#define MPX4250AP_H_

class MPX4250AP
{
public:
	MPX4250AP();
	virtual ~MPX4250AP();

#endif /* MPX4250AP_H_ */
/**
 * Scalar value for calculating pressure from voltage.
 */
double PressureScalar = 0.264909785f;
/**
 * Offset value for calculating pressure from voltage.
 */
double PressureOffset = 54.20054200f;

//observable::Transformer (double, double)

};
