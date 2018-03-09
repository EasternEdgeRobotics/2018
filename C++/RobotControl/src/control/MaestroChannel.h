/*
 * MaestroChannel.h
 *
 *  Created on: Mar 3, 2018
 *      Author: Andrew
 */

#ifndef CONTROL_MAESTROCHANNEL_H_
#define CONTROL_MAESTROCHANNEL_H_

#define COMMAND_MASK = 127; //0x7F
//0xAA, device number byte, command byte with MSB cleared, any necessary data bytes

/*The beggining byte to recognize pololu protocall*/
#define START_BYTE = 170;  //0xAA

/*Deafult device number for the maestro is 12. This can be changed and it might not equal 12*/
//TODO: confirm number
#define DEVICE_NUMBER = 12 //0x0c

class MaestroChannel {
public:
	MaestroChannel();
	virtual ~MaestroChannel();
};

bool sendSerial(int COMMAND);

#endif /* CONTROL_MAESTROCHANNEL_H_ */
