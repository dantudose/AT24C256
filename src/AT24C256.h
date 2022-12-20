// 24C256 EEPROM driver header file
#ifndef AT24C256_h
#define AT24C256_h

#include "Arduino.h"
#include "Wire.h"

class AT24C256
{
public: 
		AT24C256(byte address);
		void write(unsigned short writeAddress, byte* data, byte len);
		void read(unsigned short readAddress, byte* data, byte len);

private:
		byte _address;

};

#endif