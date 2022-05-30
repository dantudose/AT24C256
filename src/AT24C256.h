// 24C256 EEPROM driver header file
#ifndef AT24C256_h
#define AT24C256_h

#include "Arduino.h"
#include "Wire.h"

class AT24C256
{
public: 
		AT24C256(uint8_t address);
		void write(uint16_t writeAddress, uint8_t* data, uint8_t len);
		void read(uint16_t readAddress, uint8_t* data, uint8_t len);

private:
		unsigned short int _address;

};

#endif