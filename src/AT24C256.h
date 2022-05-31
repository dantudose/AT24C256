// 24C256 EEPROM driver header file
#ifndef AT24C256_h
#define AT24C256_h

#include "Arduino.h"
#include "Wire.h"

class AT24C256
{
public: 
		AT24C256(unsigned char address);
		void write(unsigned short writeAddress, char* data, unsigned char len);
		void read(unsigned short readAddress, char* data, unsigned char len);

private:
		unsigned char _address;

};

#endif