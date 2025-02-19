
#include <stdio.h>
#include <fcntl.h>   // File Control Definitions
#include <termios.h> // POSIX Terminal Control Definitions
#include <unistd.h>  // UNIX Standard Definitions
#include <errno.h>   // ERROR Number Definitions
#include <iostream>
#include <string>

#include "SerialPort.h"
using namespace std;


void SerialPort::encodeData(int stepperState[], int stepperDir[], int stepperCount[], int servo[], int aPulse, int eMag)
{
    string data ("EER");
    for (int i = 0; i < 4; i++)
    {
        data += to_string(stepperState[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        data += to_string(stepperDir[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        if (stepperCount[i] < 10)
            data += '0';
        if (stepperCount[i] < 100)
            data += '0';
        data += to_string(stepperCount[i]);
    }
    for (int i = 0; i < 2; i++)
    {
        if (servo[i] < 10)
            data += '0';
        if (servo[i] < 100)
            data += '0';
        data += to_string(servo[i]);
    }
    data += to_string(aPulse);
    data += to_string(eMag);
    data += 'e';

    int temp = data.size();
    for (int a = 0; a <= temp; a++)
    {
        write_buffer[a] = data[a];
    }
}


void SerialPort::writeSerial()
{
    int fd;

    fd = open("/dev/ttyUSB0",O_RDWR | O_NOCTTY | O_NDELAY);         // change to appropriate device port

    if(fd == -1)                                                    // Error Checking
        printf("\n  Error! in Opening ttyUSB0  ");
    else
        printf("\n  ttyUSB0 Opened Successfully ");

    // Setting the Attributes of the serial port using termios structure

    struct termios SerialPortSettings;	                             // Create the structure

    tcgetattr(fd, &SerialPortSettings);	                             // Get the current attributes of the Serial port

    cfsetispeed(&SerialPortSettings,B115200);                        // Set Read  Speed as 9600
    cfsetospeed(&SerialPortSettings,B115200);                        // Set Write Speed as 9600

    SerialPortSettings.c_cflag &= ~PARENB;                           // Disables the Parity Enable bit(PARENB),So No Parity
    SerialPortSettings.c_cflag &= ~CSTOPB;                           // CSTOPB = 2 Stop bits,here it is cleared so 1 Stop bit
    SerialPortSettings.c_cflag &= ~CSIZE;	                         // Clears the mask for setting the data size
    SerialPortSettings.c_cflag |=  CS8;                              // Set the data bits = 8

    SerialPortSettings.c_cflag &= ~CRTSCTS;                          // No Hardware flow Control
    SerialPortSettings.c_cflag |= CREAD | CLOCAL;                    // Enable receiver,Ignore Modem Control lines


    SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY);           // Disable XON/XOFF flow control both i/p and o/p
    SerialPortSettings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);   // Non Cannonical mode

    SerialPortSettings.c_oflag &= ~OPOST;                            // No Output Processing

    if((tcsetattr(fd,TCSANOW,&SerialPortSettings)) != 0)             // Set the attributes to the termios structure
        printf("\n  ERROR ! in Setting attributes");
    else
                printf("\n  BaudRate = 9600 \n  StopBits = 1 \n  Parity   = none");

    // Write data to serial port

    int  bytes_written  = 0;  	                                     // Value for storing the number of bytes written to the port

    bytes_written = write(fd,write_buffer,sizeof(write_buffer));    // use write() to send data to port
                                    							    // "fd"                   - file descriptor pointing to the opened serial port
                                    							    //	"write_buffer"        - address of the buffer containing data
                                    							    // "sizeof(write_buffer)" - No of bytes to write

    printf("\n  %s written to ttyUSB0",write_buffer);
    printf("\n  %d Bytes written to ttyUSB0", bytes_written);
    printf("\n +----------------------------------+\n\n");

    close(fd); //Close the Serial port
}

/*
void SerialPort::readSerial()
{
    int fd; //File Descriptor

    printf("\n +----------------------------------+");
    printf("\n |        Serial Port Read          |");
    printf("\n +----------------------------------+");

    // Opening the Serial Port

    // Change /dev/ttyUSB0 to the one corresponding to your system
    fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);   // O_RDWR - Read/Write access to serial port, O_NOCTTY - No terminal will control the proces, O_NDELAY - Open in blocking mode,read will wait




    if(fd == -1)						                            // Error Checking
        printf("\n  Error! in Opening ttyUSB0  ");
    else
        printf("\n  ttyUSB0 Opened Successfully ");


    // Setting the Attributes of the serial port using termios structure

    struct termios SerialPortSettings;	                            // Create the structure

    tcgetattr(fd, &SerialPortSettings);	                            // Get the current attributes of the Serial port

    // Setting the Baud rate
    cfsetispeed(&SerialPortSettings,B9600);
    cfsetospeed(&SerialPortSettings,B9600);

    // 8N1 Mode
    SerialPortSettings.c_cflag &= ~PARENB;                          // Disables the Parity Enable bit(PARENB),So No Parity
    SerialPortSettings.c_cflag &= ~CSTOPB;                          // CSTOPB = 2 Stop bits,here it is cleared so 1 Stop bit
    SerialPortSettings.c_cflag &= ~CSIZE;	                        // Clears the mask for setting the data size
    SerialPortSettings.c_cflag |=  CS8;                             // Set the data bits = 8

    SerialPortSettings.c_cflag &= ~CRTSCTS;                         // No Hardware flow Control
    SerialPortSettings.c_cflag |= CREAD | CLOCAL;                   // Enable receiver,Ignore Modem Control lines


    SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY);          // Disable XON/XOFF flow control both i/p and o/p
    SerialPortSettings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);  // Non Cannonical mode

    SerialPortSettings.c_oflag &= ~OPOST; //No Output Processing

    // Setting Time outs
    SerialPortSettings.c_cc[VMIN] = 10; // Read at least 10 characters
    SerialPortSettings.c_cc[VTIME] = 0; // Wait indefinetly


    if((tcsetattr(fd,TCSANOW,&SerialPortSettings)) != 0) // Set the attributes to the termios structure
        printf("\n  ERROR ! in Setting attributes");
    else
                printf("\n  BaudRate = 9600 \n  StopBits = 1 \n  Parity   = none");

    // Read data from serial port

    tcflush(fd, TCIFLUSH);   // Discards old data in the rx buffer

    char read_buffer[32];   // Buffer to store the data received
    int  bytes_read = 0;    // Number of bytes read by the read() system call
    int i = 0;

    bytes_read = read(fd,&read_buffer,32); // Read the data

    printf("\n\n  Bytes Rxed -%d", bytes_read); // Print the number of bytes read
    printf("\n\n  ");

    for(i=0;i<bytes_read;i++)	 //printing only the received characters
        printf("%c",read_buffer[i]);

    printf("\n +----------------------------------+\n\n\n");

    close(fd); // Close the serial port

}

*/
