#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <string>


class SerialPort
{

private:
    char write_buffer[32];

public:
    void encodeData(int stepperState[], int stepperDir[], int stepperCount[], int servo[], int aPulse, int eMag);
    void writeSerial();
    void readSerial();

};

#endif
